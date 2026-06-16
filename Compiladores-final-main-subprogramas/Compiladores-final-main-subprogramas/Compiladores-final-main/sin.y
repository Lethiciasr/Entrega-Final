%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabela.h"

int cont_read = 0;
int houve_erro = 0;
int dentro_switch = 0;
extern int yylex();
extern int yylineno;

void yyerror(const char *s) {
    fprintf(stderr, "\n----------------------------------------\n");
    fprintf(stderr, "Erro na linha %d:\n", yylineno);
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "----------------------------------------\n");
    houve_erro = 1;
}

char buf[200];
char c_decl[5000] = "";
char c_body[5000] = "";
char declaracoes_temp[5000] = "";
char inc_3ac[200] = "";
char inc_c[200] = "";   
char switch_exp[50] = "";
char switch_fim[50] = "";
char pilha_inicio[20][50];
char pilha_fim[20][50];
int topo_laco = 0;

Simbolo *simbolo_array_atual = NULL;
int idx_array_atual = 0;
int tam_array_atual = 0;
int escopo_atual = 0;
%}

%union {
    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        int tipo_val;
        int tam_str;
    } info;
    
    struct {
        int qtd;
        Tipo tipos[10];
        char* c_args;
    } lista_params;
}

%token TOKEN_FOR
%token TOKEN_MAIN
%token TOKEN_RETURN
%token <valor_str> ID NUM_INT NUM_FLOAT CHAR_LIT BOOL_LIT STRING_LIT
%token TOKEN_INT TOKEN_FLOAT TOKEN_CHAR TOKEN_BOOL TOKEN_STRING ASSIGN PLUS
%token TOKEN_PRINT TOKEN_READ TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_DO
%token TOKEN_SWITCH TOKEN_CASE TOKEN_DEFAULT TOKEN_BREAK
%token TOKEN_CONTINUE
%token AND OR EQ NE LE GE NOT
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN
%token INC DEC

%define parse.error verbose

%left OR
%left AND
%left EQ NE '<' '>' LE GE
%left PLUS '-'
%left '*' '/'
%right NOT
%right CAST
%right UMINUS

%type <info> expressao termo fator declaracao atribuicao comando comandos_bloco bloco elemento_inicializador lista_inicializadores chamada_argumentos chamada_argumentos_lista
%type <valor_str> if_cond incremento_for for_init
%type <lista_params> parametros_opc parametros_lista

%%

programa 
    : elementos_globais TOKEN_MAIN '(' ')' bloco {
        strcat(c_body, $5.c_expr);
    }
    ;

elementos_globais
    : declaracao ';' elementos_globais
    | funcao elementos_globais
    | /* vazio */
    ;

tipo 
    : TOKEN_INT    { $<info>$.tipo_val = T_INT; }
    | TOKEN_FLOAT  { $<info>$.tipo_val = T_FLOAT; }
    | TOKEN_CHAR   { $<info>$.tipo_val = T_CHAR; }
    | TOKEN_BOOL   { $<info>$.tipo_val = T_BOOL; }
    | TOKEN_STRING { $<info>$.tipo_val = T_STRING; }
    ;

funcao 
    : tipo ID '(' parametros_opc ')' {
        char const* t_nome = ($<info>1.tipo_val == T_INT) ? "int" : 
                             (($<info>1.tipo_val == T_FLOAT) ? "float" : 
                             (($<info>1.tipo_val == T_CHAR) ? "char" : "int"));
                             
        sprintf(buf, "\n%s %s(%s) {\n", t_nome, $2, $4.c_args);
        strcat(c_code_body, buf); 
        
        escopo_atual++; 
    } 
    bloco_funcao {
        escopo_atual--;
    }
    ;

bloco_funcao 
    : '{' comandos_bloco '}' {
        strcat(c_code_body, $2.c_expr);
        strcat(c_code_body, "}\n\n");
        remover_simbolos_do_nivel(escopo_atual);
    }
    ;

parametros_opc 
    : parametros_lista { $$ = $1; }
    | /* vazio */      { $$.qtd = 0; $$.c_args = strdup(""); }
    ;

parametros_lista
    : tipo ID {
        $$.qtd = 1;
        $$.tipos[0] = $<info>1.tipo_val;
        char temp_arg[100];
        char const* t_nome = ($<info>1.tipo_val == T_INT) ? "int" : (($<info>1.tipo_val == T_FLOAT) ? "float" : "char");
        
        Simbolo* s = inserir($2, $<info>1.tipo_val, escopo_atual + 1);
        sprintf(temp_arg, "%s %s", t_nome, s->temp);
        $$.c_args = strdup(temp_arg);
    }
    | tipo ID ',' parametros_lista {
        $$.qtd = $4.qtd + 1;
        $$.tipos[0] = $<info>1.tipo_val;
        for(int i = 0; i < $4.qtd; i++) {
            $$.tipos[i+1] = $4.tipos[i];
        }
        char temp_arg[400];
        char const* t_nome = ($<info>1.tipo_val == T_INT) ? "int" : (($<info>1.tipo_val == T_FLOAT) ? "float" : "char");
        
        Simbolo* s = inserir($2, $<info>1.tipo_val, escopo_atual + 1);
        sprintf(temp_arg, "%s %s, %s", t_nome, s->temp, $4.c_args);
        $$.c_args = strdup(temp_arg);
    }
    ;

bloco 
    : '{' { escopo_atual++; } comandos_bloco '}' { 
        remover_simbolos_do_nivel(escopo_atual);
        escopo_atual--; 
        $$.c_expr = $3.c_expr;
    }
    ;

comandos_bloco 
    : comando comandos_bloco {
        char *res = (char*) malloc(strlen($1.c_expr) + strlen($2.c_expr) + 2);
        sprintf(res, "%s%s", $1.c_expr, $2.c_expr);
        $$.c_expr = res;
    }
    | /* vazio */ { $$.c_expr = strdup(""); }
    ;

if_cond : TOKEN_IF '(' expressao ')' {
    if ($3.tipo_val != T_BOOL) {
        yyerror("Erro Semantico: A condicao do 'if' deve ser booleana.");
    }
    char* l_false = novo_label();
    char* t_inv = novo_temp(T_BOOL);
    sprintf(buf, "%s = !%s;\n", t_inv, $3.temp);
    strcat(instrucoes, buf);
    sprintf(buf, "if (%s) goto %s;\n", t_inv, l_false);
    strcat(instrucoes, buf);
    strcat(instrucoes, "\n");
    
    $<valor_str>$ = l_false; 
}
;

for_init : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) {
        yyerror("Erro: Variavel nao declarada na inicializacao do for.");
        $$ = strdup("");
    } else {
        sprintf(buf, "%s = %s;\n", s->temp, $3.temp);
        strcat(instrucoes, buf);
        char* init_str = (char*) malloc(256);
        sprintf(init_str, "%s = %s", s->temp, $3.temp);
        $$ = init_str;
    }
}
;

incremento_for : ID ASSIGN expressao {
    Simbolo *s = buscar($1);
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
        $$ = strdup("");
    } else {
        sprintf(inc_3ac, "%s = %s;\n", s->temp, $3.temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s = %s", s->temp, $3.temp);
        $$ = inc_str;
    }
}
| ID INC {
    Simbolo *s = buscar($1);
    if (!s) {
        yyerror("Erro: Variavel nao declarada no incremento do for.");
        $$ = strdup("");
    } else {
        sprintf(inc_3ac, "%s = %s + 1;\n", s->temp, s->temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s++", s->temp);
        $$ = inc_str;
    }
}
| ID DEC {
    Simbolo *s = buscar($1);
    if (!s) {
        yyerror("Erro: Variavel nao declarada no decremento do for.");
        $$ = strdup("");
    } else {
        sprintf(inc_3ac, "%s = %s - 1;\n", s->temp, s->temp);
        char* inc_str = (char*) malloc(256);
        sprintf(inc_str, "%s--", s->temp);
        $$ = inc_str;
    }
}
;

casos_lista : caso casos_lista
            | default_caso
            | /* vazio */
            ;

caso : TOKEN_CASE expressao ':' {
        char* l_proximo = novo_label();
        char* t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t_cmp, switch_exp, $2.temp);
        strcat(instrucoes, buf);
        char* t_inv = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t_inv, t_cmp);
        strcat(instrucoes, buf);
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_proximo);
        strcat(instrucoes, buf);

        sprintf(buf, "case %s:\n", $2.temp);
        strcat(c_body, buf);
        $<valor_str>$ = l_proximo;
    } comandos_bloco {
        sprintf(buf, "goto %s;\n", switch_fim);
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", $<valor_str>4);
        strcat(instrucoes, buf);
    }
    ;

default_caso : TOKEN_DEFAULT ':' {
        strcat(c_body, "default:\n");
    } comandos_bloco
    ;

comando 
    : declaracao ';' { $$ = $1; }
    | atribuicao ';' { $$ = $1; }
    | expressao ';' { $$.c_expr = strdup(""); }
    | bloco { $$ = $1; }
    | TOKEN_RETURN expressao ';' {
        char* c_out = (char*) malloc(256);
        sprintf(buf, "return %s;\n", $2.temp);
        strcat(instrucoes, buf);
        sprintf(c_out, "return %s;\n", $2.temp);
        $$.c_expr = c_out;
    }
    | TOKEN_PRINT '(' expressao ')' ';' {
        char* c_out = (char*) malloc(256);
        char* formato = "";
        if ($3.tipo_val == T_INT || $3.tipo_val == T_BOOL) formato = "%d";
        else if ($3.tipo_val == T_FLOAT) formato = "%f";
        else if ($3.tipo_val == T_CHAR) formato = "%c";
        else if ($3.tipo_val == T_STRING) formato = "%s";
        
        sprintf(buf, "printf(\"%s\\n\", %s);\n", formato, $3.temp);
        strcat(instrucoes, buf);
        sprintf(c_out, "printf(\"%s\\n\", %s);\n", formato, $3.temp);
        $$.c_expr = c_out;
    }
    | TOKEN_READ '(' ID ')' ';' {
        char* c_out = (char*) malloc(256);
        Simbolo *s = buscar($3);
        if (!s) {
            yyerror("Erro Semantico: Variavel nao declarada para leitura.");
        } else {
            char* formato = "";
            if (s->tipo == T_INT || s->tipo == T_BOOL) formato = "%d";
            else if (s->tipo == T_FLOAT) formato = "%f";
            else if (s->tipo == T_CHAR) formato = " %c";

            if (s->tipo == T_STRING) {
                sprintf(buf, "scanf(\"%%255s\", %s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%255s\", %s);\n", s->temp);
            } else {
                sprintf(buf, "scanf(\"%s\", &%s);\n", formato, s->temp);
                sprintf(c_out, "scanf(\"%s\", &%s);\n", formato, s->temp);
            }
            strcat(instrucoes, buf);
        }
        $$.c_expr = c_out;
    }
    | if_cond comando {
        char* c_out = (char*) malloc(1024);
        sprintf(buf, "%s:\n", $<valor_str>1);
        strcat(instrucoes, buf);
        sprintf(c_out, "if (%s) {\n%s}\n", $<valor_str>1, $2.c_expr);
        $$.c_expr = c_out;
    }
    | if_cond comando TOKEN_ELSE {
        char* l_fim = novo_label();
        sprintf(buf, "goto %s;\n", l_fim);
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", $<valor_str>1);
        strcat(instrucoes, buf);
        $<valor_str>$ = l_fim;
    } comando {
        char* c_out = (char*) malloc(2048);
        sprintf(buf, "%s:\n", $<valor_str>4);
        strcat(instrucoes, buf);
        sprintf(c_out, "if (...) {\n%s} else {\n%s}\n", $2.c_expr, $5.c_expr);
        $$.c_expr = c_out;
    }
    | TOKEN_WHILE {
        char* l_inicio = novo_label();
        sprintf(buf, "%s:\n", l_inicio);
        strcat(instrucoes, buf);
        $<valor_str>$ = l_inicio; 
        strcpy(pilha_inicio[topo_laco], l_inicio);
    } '(' expressao ')' {
        if ($4.tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao deve ser booleana.");
        char* l_fim = novo_label();
        char* t_inv = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t_inv, $4.temp);
        strcat(instrucoes, buf);
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
        strcat(instrucoes, buf);
        $<valor_str>$ = l_fim; 
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
    } comando { 
        topo_laco--;
        sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco]);
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", pilha_fim[topo_laco]);
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(1024);
        sprintf(c_out, "while (%s) {\n%s}\n", $4.temp, $7.c_expr);
        $$.c_expr = c_out;
    }
    | TOKEN_DO {
        char* l_inicio = novo_label();
        sprintf(buf, "%s:\n", l_inicio);
        strcat(instrucoes, buf);
        $<valor_str>$ = l_inicio;
    } comando TOKEN_WHILE '(' expressao ')' ';' {
        if ($6.tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao do do-while deve ser booleana.");
        sprintf(buf, "if (%s) goto %s;\n", $6.temp, $<valor_str>2);
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(1024);
        sprintf(c_out, "do {\n%s} while (%s);\n", $3.c_expr, $6.temp);
        $$.c_expr = c_out;
    }
    | TOKEN_FOR '(' for_init ';' {
        char* l_inicio = novo_label();
        char* l_incremento = novo_label(); 
        sprintf(buf, "%s:\n", l_inicio);
        strcat(instrucoes, buf);
        $<valor_str>$ = l_inicio; 
        strcpy(pilha_inicio[topo_laco], l_incremento);
    } expressao ';' {
        if ($6.tipo_val != T_BOOL) yyerror("Erro Semantico: Condicao do for deve ser booleana.");
        char* l_fim = novo_label();
        char* t_inv = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t_inv, $6.temp);
        strcat(instrucoes, buf);
        sprintf(buf, "if (%s) goto %s;\n", t_inv, l_fim);
        strcat(instrucoes, buf);
        $<valor_str>$ = l_fim;
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
    } incremento_for ')' comando {
        topo_laco--; 
        sprintf(buf, "%s:\n", pilha_inicio[topo_laco]);
        strcat(instrucoes, buf);
        strcat(instrucoes, inc_3ac);
        sprintf(buf, "goto %s;\n", $<valor_str>5);
        strcat(instrucoes, buf);
        sprintf(buf, "%s:\n", $<valor_str>8);
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(2048);
        sprintf(c_out, "for (%s; %s; %s) {\n%s}\n", $3, $6.temp, $9, $11.c_expr);
        $$.c_expr = c_out;
    }
    | TOKEN_SWITCH '(' expressao ')' {
        dentro_switch++;
        strcpy(switch_exp, $3.temp);
        strcpy(switch_fim, novo_label());
        strcpy(pilha_fim[topo_laco], switch_fim);
        strcpy(pilha_inicio[topo_laco], "ERRO_CONTINUE_SWITCH");
        topo_laco++;
    } '{' casos_lista '}' {
        dentro_switch--;
        topo_laco--;
        sprintf(buf, "%s:\n", switch_fim);
        strcat(instrucoes, buf);
        
        char* c_out = (char*) malloc(512);
        sprintf(c_out, "switch (%s) { /* ... */ }\n", $3.temp);
        $$.c_expr = c_out;
    }
    | TOKEN_BREAK ';' {
        if (topo_laco > 0) {
            sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
            strcat(instrucoes, buf);
        } else if (dentro_switch > 0) {
            sprintf(buf, "goto %s;\n", switch_fim);
            strcat(instrucoes, buf);
        } else {
            yyerror("Erro Semantico: 'break' usado fora de laco ou switch.");
        }
        $$.c_expr = strdup("break;\n");
    }
    | TOKEN_CONTINUE ';' {
        if (topo_laco == 0) {
            yyerror("Erro Semantico: 'continue' usado fora de laco.");
        } else {
            sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
            strcat(instrucoes, buf);
        }
        $$.c_expr = strdup("continue;\n");
    }
    | ID PLUS_ASSIGN expressao ';' {
        Simbolo *s = buscar($1);
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s + %s;\n", t_op, s->temp, $3.temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s += %s;\n", s->temp, $3.temp);
        }
        $$.c_expr = c_out;
    }
    | ID MINUS_ASSIGN expressao ';' {
        Simbolo *s = buscar($1);
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s - %s;\n", t_op, s->temp, $3.temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s -= %s;\n", s->temp, $3.temp);
        }
        $$.c_expr = c_out;
    }
    | ID MULT_ASSIGN expressao ';' {
        Simbolo *s = buscar($1);
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s * %s;\n", t_op, s->temp, $3.temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s *= %s;\n", s->temp, $3.temp);
        }
        $$.c_expr = c_out;
    }
    | ID DIV_ASSIGN expressao ';' {
        Simbolo *s = buscar($1);
        char* c_out = (char*) malloc(256);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            char* t_op = novo_temp(s->tipo);
            sprintf(buf, "%s = %s / %s;\n", t_op, s->temp, $3.temp);
            strcat(instrucoes, buf);
            sprintf(buf, "%s = %s;\n", s->temp, t_op);
            strcat(instrucoes, buf);
            sprintf(c_out, "%s /= %s;\n", s->temp, $3.temp);
        }
        $$.c_expr = c_out;
    }
    | ID INC ';' {
        Simbolo *s = buscar($1);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            sprintf(buf, "%s = %s + 1;\n", s->temp, s->temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s++;\n", s ? s->temp : $1);
        $$.c_expr = c_out;
    }
    | ID DEC ';' {
        Simbolo *s = buscar($1);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            sprintf(buf, "%s = %s - 1;\n", s->temp, s->temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s--;\n", s ? s->temp : $1);
        $$.c_expr = c_out;
    }
    | ID '[' expressao ']' ASSIGN expressao ';' {
        Simbolo *s = buscar($1);
        if (!s) yyerror("Erro Semantico: Matriz nao declarada.");
        else {
            sprintf(buf, "%s[%s] = %s;\n", s->temp, $3.temp, $6.temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s[%s] = %s;\n", s ? s->temp : $1, $3.temp, $6.temp);
        $$.c_expr = c_out;
    }
    ;

declaracao 
    : tipo ID {
        if (buscar($2) != NULL && buscar($2)->nivel == escopo_atual) {
            yyerror("Erro Semantico: Variavel ja declarada.");
        } else {
            inserir($2, $<info>1.tipo_val, escopo_atual);
        }
        $$.c_expr = strdup("");
    }
    | tipo ID ASSIGN expressao {
        Simbolo *s = inserir($2, $<info>1.tipo_val, escopo_atual);
        sprintf(buf, "%s = %s;\n", s->temp, $4.temp);
        strcat(instrucoes, buf);
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s = %s;\n", s->temp, $4.temp);
        $$.c_expr = c_out;
    }
    | tipo ID '[' NUM_INT ']' {
        inserir_array($2, $<info>1.tipo_val, escopo_atual, atoi($4));
        $$.c_expr = strdup("");
    }
    | tipo ID '[' NUM_INT ']' ASSIGN '{' {
        simbolo_array_atual = inserir_array($2, $<info>1.tipo_val, escopo_atual, atoi($4));
        idx_array_atual = 0;
        tam_array_atual = atoi($4);
    } lista_inicializadores '}' {
        $$.c_expr = strdup("");
    }
    ;

lista_inicializadores 
    : elemento_inicializador ',' lista_inicializadores
    | elemento_inicializador
    ;

elemento_inicializador 
    : expressao {
        if (simbolo_array_atual) {
            if (idx_array_atual < tam_array_atual) {
                sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, $1.temp);
                strcat(instrucoes, buf);
                idx_array_atual++;
            } else {
                yyerror("Erro Semantico: Excesso de elementos na matriz.");
            }
        }
    }
    ;

atribuicao 
    : ID ASSIGN expressao {
        Simbolo *s = buscar($1);
        if (!s) yyerror("Erro Semantico: Variavel nao declarada.");
        else {
            sprintf(buf, "%s = %s;\n", s->temp, $3.temp);
            strcat(instrucoes, buf);
        }
        char* c_out = (char*) malloc(256);
        sprintf(c_out, "%s = %s;\n", s ? s->temp : $1, $3.temp);
        $$.c_expr = c_out;
    }
    ;

expressao 
    : expressao PLUS expressao {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s + %s;\n", t, $1.temp, $3.temp);
        strcat(instrucoes, buf);
        $$.temp = t;
        $$.tipo_val = T_INT;
    }
    | expressao '-' expressao {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s - %s;\n", t, $1.temp, $3.temp);
        strcat(instrucoes, buf);
        $$.temp = t;
        $$.tipo_val = T_INT;
    }
    | expressao '*' expressao {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s * %s;\n", t, $1.temp, $3.temp);
        strcat(instrucoes, buf);
        $$.temp = t;
        $$.tipo_val = T_INT;
    }
    | expressao '/' expressao {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s / %s;\n", t, $1.temp, $3.temp);
        strcat(instrucoes, buf);
        $$.temp = t;
        $$.tipo_val = T_INT;
    }
    | termo { $$ = $1; }
    ;

termo 
    : fator { $$ = $1; }
    ;

fator 
    : ID {
        Simbolo *s = buscar($1);
        if (!s) {
            yyerror("Erro Semantico: Identificador nao encontrado.");
            $$.temp = strdup("0");
        } else {
            $$.temp = s->temp;
            $$.tipo_val = s->tipo;
        }
    }
    | NUM_INT {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s;\n", t, $1);
        strcat(instrucoes, buf);
        $$.temp = t;
        $$.tipo_val = T_INT;
    }
    | '(' expressao ')' {
        $$ = $2;
    }
    | ID '(' chamada_argumentos ')' {
        Simbolo *s = buscar($1);
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s(%s);\n", t, $1, $3.temp);
        strcat(instrucoes, buf);
        $$.temp = t;
        $$.tipo_val = T_INT;
    }
    ;

chamada_argumentos
    : chamada_argumentos_lista { $$ = $1; }
    | /* vazio */ { $$.temp = strdup(""); }
    ;

chamada_argumentos_lista
    : expressao { $$.temp = strdup($1.temp); }
    | expressao ',' chamada_argumentos_lista {
        char *t_buf = (char*) malloc(strlen($1.temp) + strlen($3.temp) + 5);
        sprintf(t_buf, "%s, %s", $1.temp, $3.temp);
        $$.temp = t_buf;
    }
    ;

%%

#include <stdlib.h> 

int main() {
    yyparse();
    if (houve_erro) {
        return 1;
    }

    gerar_declaracoes_finais();

    /* 1. IMPRESSÃO NO TERMINAL */
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <string.h>\n");
    printf("#include <stdbool.h>\n\n");
    printf("%s\n", c_code_decl);
    printf("%s", c_code_body);
    printf("int main()\n{\n");
    printf("%s\n", c_body);
    printf("    return 0;\n}\n");

    /* 2. SALVANDO NO ARQUIVO SAIDA.C */
    FILE *arquivo_c = fopen("saida.c", "w");
    if (!arquivo_c) return 1;
    fprintf(arquivo_c, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <stdbool.h>\n\n");
    fprintf(arquivo_c, "%s\n", c_code_decl);
    fprintf(arquivo_c, "%s", c_code_body);
    fprintf(arquivo_c, "int main()\n{\n");
    fprintf(arquivo_c, "%s", c_body);
    fprintf(arquivo_c, "    return 0;\n}\n");
    fclose(arquivo_c);
    return 0;
}