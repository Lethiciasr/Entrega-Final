%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabela.h"

int dentro_funcao = 0; // Flag para rastrear se estamos dentro de uma função (Item 2)
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

// Buffer para acumular o Código Intermediário (TAC) das funções (Item 4)
char instrucoes_funcao[10000] = "";

// Função auxiliar para gerenciar se a instrução vai para a main ou para uma função (Item 6)
void adicionar_instrucao(char *texto) {
    if (dentro_funcao)
        strcat(instrucoes_funcao, texto);
    else
        strcat(instrucoes, texto);
}
%}

%union {
    char* valor_str;
    struct {
        char* temp;
        char* c_expr;
        int tipo_val;
        int tam_str;
    } info;
    // Suporte para acumular metadados de listas de parâmetros de funções
    struct {
        int qtd;
        Tipo tipos[10]; 
        char* c_args;
    } lista_params;
}

%token TOKEN_INT TOKEN_FLOAT TOKEN_CHAR TOKEN_BOOL TOKEN_STRING
%token TOKEN_PRINT TOKEN_READ TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_DO TOKEN_FOR
%token TOKEN_SWITCH TOKEN_CASE TOKEN_DEFAULT TOKEN_BREAK TOKEN_CONTINUE TOKEN_MAIN TOKEN_RETURN
%token <valor_str> STRING_LIT BOOL_LIT NUM_INT NUM_FLOAT CHAR_LIT ID

%nonassoc LOWER_THAN_ELSE
%nonassoc TOKEN_ELSE

%type <valor_str> if_inicio
%type <info> expressao termo fator declaracao  atribuicao comando comandos comandos_bloco bloco condicao_if laco_while laco_do_while laco_for estrutura_switch casos caso_default elemento_inicializador lista_inicializadores chamada_argumentos chamada_argumentos_lista
%type <lista_params> parametros_opc parametros_lista

%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left PLUS '-'
%left '*' '/'
%right NOT UMINUS CAST
%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN
%right INC DEC

%%

// O programa agora aceita elementos globais (variáveis ou funções) antes da main
programa 
    : elementos_globais TOKEN_MAIN '(' ')' bloco {
        // Encerra a construção colocando o bloco principal da main no corpo de C
        strcat(c_body, $5.c_expr);
    }
    ;

elementos_globais
    : declaracao ';' elementos_globais
    |
    funcao elementos_globais
    | /* vazio */
    ;

tipo 
    : TOKEN_INT    { $<info>$.tipo_val = T_INT; }
    |
    TOKEN_FLOAT  { $<info>$.tipo_val = T_FLOAT; }
    | TOKEN_CHAR   { $<info>$.tipo_val = T_CHAR; }
    | TOKEN_BOOL   { $<info>$.tipo_val = T_BOOL; }
    |
    TOKEN_STRING { $<info>$.tipo_val = T_STRING; }
    ;

// Definição de Subprograma (Função) - (Item 3)
funcao 
    : tipo ID '(' parametros_opc ')' {
        dentro_funcao = 1; // Ativa a flag de função ao entrar nela
        // Insere a assinatura da função na tabela de símbolos (escopo global 0)
        inserir_funcao($2, $<info>1.tipo_val, $4.qtd, $4.tipos);
        // Inicializa o cabeçalho no buffer C global de declarações externas
        char const* t_nome = ($<info>1.tipo_val == T_INT) ?
                             "int" : 
                             (($<info>1.tipo_val == T_FLOAT) ? "float" : 
                             (($<info>1.tipo_val == T_CHAR) ? "char" : "int"));
        sprintf(buf, "\n%s %s(%s) {\n", t_nome, $2, $4.c_args);
        strcat(c_code_body, buf); 
        
        // Entra no nível interno de escopo para as variáveis locais e parâmetros
        escopo_atual++;
    } 
    bloco_funcao {
        dentro_funcao = 0; // Desativa a flag de função ao sair dela
        escopo_atual--;
        strcat(c_code_body, "}\n\n");
    }
    ;

bloco_funcao 
    : '{' comandos_bloco '}' {
        strcat(c_code_body, instrucoes_funcao);

        instrucoes_funcao[0] = '\0';

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
        char const* t_nome = ($<info>1.tipo_val == T_INT) ?
                             "int" : (($<info>1.tipo_val == T_FLOAT) ? "float" : "char");
        
        // Insere o parâmetro no escopo interno da função (escopo_atual + 1)
        Simbolo* s = inserir($2, $<info>1.tipo_val, escopo_atual + 1);
        sprintf(temp_arg, "%s %s", t_nome, s->temp);
        $$.c_args = strdup(temp_arg);
    }
    |
    tipo ID ',' parametros_lista {
        $$.qtd = $4.qtd + 1;
        $$.tipos[0] = $<info>1.tipo_val;
        for(int i = 0; i < $4.qtd; i++) {
            $$.tipos[i+1] = $4.tipos[i];
        }
        char temp_arg[400];
        char const* t_nome = ($<info>1.tipo_val == T_INT) ?
                             "int" : (($<info>1.tipo_val == T_FLOAT) ? "float" : "char");
        
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
    : comandos { $$ = $1; }
    | /* vazio */ { $$.c_expr = strdup(""); }
    ;

comandos 
    : comando comandos {
        char *res = (char*) malloc(strlen($1.c_expr) + strlen($2.c_expr) + 2);
        sprintf(res, "%s%s", $1.c_expr, $2.c_expr);
        $$.c_expr = res;
    }
    | comando { $$ = $1; }
    ;

comando 
    : declaracao ';'   { $$ = $1; }
    | atribuicao ';'   { $$ = $1; }
    |
    condicao_if      { $$ = $1; }
    |
    laco_while       { $$ = $1; }
    | laco_do_while ';' { $$ = $1; }
    | laco_for         { $$ = $1; }
    | estrutura_switch { $$ = $1; }
    | TOKEN_PRINT '(' expressao ')' ';' {
        char* c_out = (char*) malloc(256);
        if ($3.tipo_val == T_INT) {
            sprintf(buf, "printf(\"%%d\\n\", %s);\n", $3.temp);
            sprintf(c_out, "printf(\"%%d\\n\", %s);\n", $3.c_expr);
        } else if ($3.tipo_val == T_FLOAT) {
            sprintf(buf, "printf(\"%%f\\n\", %s);\n", $3.temp);
            sprintf(c_out, "printf(\"%%f\\n\", %s);\n", $3.c_expr);
        } else if ($3.tipo_val == T_CHAR) {
            sprintf(buf, "printf(\"%%c\\n\", %s);\n", $3.temp);
            sprintf(c_out, "printf(\"%%c\\n\", %s);\n", $3.c_expr);
        } else if ($3.tipo_val == T_BOOL) {
            sprintf(buf, "printf(\"%%s\\n\", %s ? \"true\" : \"false\");\n", $3.temp);
            sprintf(c_out, "printf(\"%%s\\n\", %s ? \"true\" : \"false\");\n", $3.c_expr);
        } else if ($3.tipo_val == T_STRING) {
            sprintf(buf, "printf(\"%%s\\n\", %s);\n", $3.temp);
            sprintf(c_out, "printf(\"%%s\\n\", %s);\n", $3.c_expr);
        }
        adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
        $$.c_expr = c_out;
    }
    | TOKEN_READ '(' ID ')' ';' {
        Simbolo *s = buscar($3);
        char* c_out = (char*) malloc(256);
        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            $$.c_expr = strdup("");
        } else {
            if (s->tipo == T_INT) {
                sprintf(buf, "scanf(\"%%d\", &%s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%d\", &%s);\n", s->nome);
            } else if (s->tipo == T_FLOAT) {
                sprintf(buf, "scanf(\"%%f\", &%s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%f\", &%s);\n", s->nome);
            } else if (s->tipo == T_CHAR) {
                sprintf(buf, "scanf(\" %%c\", &%s);\n", s->temp);
                sprintf(c_out, "scanf(\" %%c\", &%s);\n", s->nome);
            } else if (s->tipo == T_STRING) {
                sprintf(buf, "scanf(\"%%s\", %s);\n", s->temp);
                sprintf(c_out, "scanf(\"%%s\", %s);\n", s->nome);
            }
            adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
            $$.c_expr = c_out;
        }
    }
    | TOKEN_BREAK ';' {
        if (!dentro_switch && topo_laco == 0) {
            yyerror("Erro Semantico: 'break' usado fora de laco ou switch.");
        }
        char* c_out = (char*) malloc(100);
        if (dentro_switch) {
            sprintf(buf, "goto %s;\n", switch_fim);
            sprintf(c_out, "break;\n");
        } else {
            sprintf(buf, "goto %s;\n", pilha_fim[topo_laco - 1]);
            sprintf(c_out, "break;\n");
        }
        adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
        $$.c_expr = c_out;
    }
    |
    TOKEN_CONTINUE ';' {
        if (topo_laco == 0) {
            yyerror("Erro Semantico: 'continue' usado fora de um laco.");
        }
        char* c_out = (char*) malloc(100);
        sprintf(buf, "goto %s;\n", pilha_inicio[topo_laco - 1]);
        sprintf(c_out, "continue;\n");
        adicionar_instrucao(buf); // Substituído para suportar subprogramas (Item 7)
        $$.c_expr = c_out;
    }
    | TOKEN_RETURN expressao ';' {
    char* c_out = (char*) malloc(256);

    sprintf(buf, "return %s;\n", $2.temp);

    if (escopo_atual > 0)
        strcat(instrucoes_funcao, buf);
    else
        strcat(instrucoes, buf);

    sprintf(c_out, "return %s;\n", $2.c_expr);
    $$.c_expr = c_out;
    }
    | expressao ';' {
        char* c_out = (char*) malloc(strlen($1.c_expr) + 5);
        sprintf(c_out, "%s;\n", $1.c_expr);
        $$.c_expr = c_out;
    }
    ;

declaracao 
    : tipo ID {
        if (buscar($2) != NULL && buscar($2)->nivel == escopo_atual) {
            yyerror("Erro Semantico: Variavel ja declarada neste escopo.");
        } else {
            inserir($2, $<info>1.tipo_val, escopo_atual);
        }
        $$.c_expr = strdup("");
    }
    |
    tipo ID ASSIGN expressao {
        Simbolo *s = buscar($2);
        if (s != NULL && s->nivel == escopo_atual) {
            yyerror("Erro Semantico: Variavel ja declarada neste escopo.");
        } else {
            s = inserir($2, $<info>1.tipo_val, escopo_atual);
            char* expr_temp = $4.temp;
            char* expr_c = $4.c_expr;
            if ($<info>1.tipo_val == T_FLOAT && $4.tipo_val == T_INT) {
                expr_temp = gerar_cast($4.temp, T_FLOAT);
                char* cast_c = (char*) malloc(strlen($4.c_expr) + 20);
                sprintf(cast_c, "(float)(%s)", $4.c_expr);
                expr_c = cast_c;
            } else if ($<info>1.tipo_val == T_INT && $4.tipo_val == T_FLOAT) {
                expr_temp = gerar_cast($4.temp, T_INT);
                char* cast_c = (char*) malloc(strlen($4.c_expr) + 20);
                sprintf(cast_c, "(int)(%s)", $4.c_expr);
                expr_c = cast_c;
            }
            if ($<info>1.tipo_val == T_STRING) {
                sprintf(buf, "strcpy(%s, %s);\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "strcpy(%s, %s);\n", s->nome, expr_c);
                $$.c_expr = c_out;
            } else {
                sprintf(buf, "%s = %s;\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "%s = %s;\n", s->nome, expr_c);
                $$.c_expr = c_out;
            }
        }
    }
    |
    tipo ID '[' NUM_INT ']' {
        int tam = atoi($4);
        inserir_array($2, $<info>1.tipo_val, escopo_atual, tam);
        $$.c_expr = strdup("");
    }
    |
    tipo ID '[' NUM_INT ']' ASSIGN {
        int tam = atoi($4);
        simbolo_array_atual = inserir_array($2, $<info>1.tipo_val, escopo_atual, tam);
        idx_array_atual = 0;
        tam_array_atual = tam;
    } '{' lista_inicializadores '}' {
        if (idx_array_atual < tam_array_atual) {
            yyerror("Erro Semantico: Elementos insuficientes na inicializacao da matriz.");
        }
        $$.c_expr = strdup("");
    }
    ;

lista_inicializadores
    : elemento_inicializador ',' lista_inicializadores
    | elemento_inicializador
    ;

elemento_inicializador
    : expressao {
        if (simbolo_array_atual != NULL) {
            if (idx_array_atual < tam_array_atual) {
                char* expr_temp = $1.temp;
                if (simbolo_array_atual->tipo == T_FLOAT && $1.tipo_val == T_INT) {
                    expr_temp = gerar_cast($1.temp, T_FLOAT);
                } else if (simbolo_array_atual->tipo == T_INT && $1.tipo_val == T_FLOAT) {
                    expr_temp = gerar_cast($1.temp, T_INT);
                }
                sprintf(buf, "%s[%d] = %s;\n", simbolo_array_atual->temp, idx_array_atual, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                idx_array_atual++;
            } else {
                yyerror("Erro Semantico: Excesso de elementos na inicializacao da matriz.");
            }
        }
    }
    ;

atribuicao 
    : ID ASSIGN expressao {
        Simbolo *s = buscar($1);
        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            $$.c_expr = strdup("");
        } else {
            char* expr_temp = $3.temp;
            char* expr_c = $3.c_expr;
            if (s->tipo == T_FLOAT && $3.tipo_val == T_INT) {
                expr_temp = gerar_cast($3.temp, T_FLOAT);
                char* cast_c = (char*) malloc(strlen($3.c_expr) + 20);
                sprintf(cast_c, "(float)(%s)", $3.c_expr);
                expr_c = cast_c;
            } else if (s->tipo == T_INT && $3.tipo_val == T_FLOAT) {
                expr_temp = gerar_cast($3.temp, T_INT);
                char* cast_c = (char*) malloc(strlen($3.c_expr) + 20);
                sprintf(cast_c, "(int)(%s)", $3.c_expr);
                expr_c = cast_c;
            }
            if (s->tipo == T_STRING) {
                sprintf(buf, "strcpy(%s, %s);\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "strcpy(%s, %s);\n", s->nome, expr_c);
                $$.c_expr = c_out;
            } else {
                sprintf(buf, "%s = %s;\n", s->temp, expr_temp);
                adicionar_instrucao(buf); // Alterado (Item 7)
                char* c_out = (char*) malloc(256);
                sprintf(c_out, "%s = %s;\n", s->nome, expr_c);
                $$.c_expr = c_out;
            }
        }
    }
    | ID INC {
    Simbolo *s = buscar($1);

    if (s == NULL) {
        yyerror("Erro Semantico: Variavel nao declarada.");
        $$.c_expr = strdup("");
    } else {
        sprintf(buf, "%s = %s + 1;\n", s->temp, s->temp);
        adicionar_instrucao(buf);

        char *c_out = (char*) malloc(100);
        sprintf(c_out, "%s++;\n", s->nome);
        $$.c_expr = c_out;
    }
    }
    | ID DEC {
        Simbolo *s = buscar($1);

        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            $$.c_expr = strdup("");
        } else {
            sprintf(buf, "%s = %s - 1;\n", s->temp, s->temp);
            adicionar_instrucao(buf);

            char *c_out = (char*) malloc(100);
            sprintf(c_out, "%s--;\n", s->nome);
            $$.c_expr = c_out;
        }
    }
    |
    ID PLUS_ASSIGN expressao  { $$.c_expr = strdup(""); }
    |
    ID MINUS_ASSIGN expressao { $$.c_expr = strdup(""); }
    |
    ID MULT_ASSIGN expressao  { $$.c_expr = strdup(""); }
    |
    ID DIV_ASSIGN expressao   { $$.c_expr = strdup(""); }
    |
    ID '[' expressao ']' ASSIGN expressao {
        Simbolo *s = buscar($1);
        if (s == NULL) {
            yyerror("Erro Semantico: Matriz nao declarada.");
            $$.c_expr = strdup("");
        } else if (!s->array) {
            yyerror("Erro Semantico: Identificador nao eh uma matriz.");
            $$.c_expr = strdup("");
        } else {
            char* expr_temp = $6.temp;
            char* expr_c = $6.c_expr;
            if (s->tipo == T_FLOAT && $6.tipo_val == T_INT) {
                expr_temp = gerar_cast($6.temp, T_FLOAT);
                char* cast_c = (char*) malloc(strlen($6.c_expr) + 20);
                sprintf(cast_c, "(float)(%s)", $6.c_expr);
                expr_c = cast_c;
            } else if (s->tipo == T_INT && $6.tipo_val == T_FLOAT) {
                expr_temp = gerar_cast($6.temp, T_INT);
                char* cast_c = (char*) malloc(strlen($6.c_expr) + 20);
                sprintf(cast_c, "(int)(%s)", $6.c_expr);
                expr_c = cast_c;
            }
            sprintf(buf, "%s[%s] = %s;\n", s->temp, $3.temp, expr_temp);
            adicionar_instrucao(buf); // Alterado (Item 7)
            char* c_out = (char*) malloc(256);
            sprintf(c_out, "%s[%s] = %s;\n", s->nome, $3.c_expr, expr_c);
            $$.c_expr = c_out;
        }
    }
    ;

    if_inicio
    : TOKEN_IF '(' expressao ')'
      {
          char *l_false = novo_label();

          sprintf(buf,
                  "if (!%s) goto %s;\n",
                  $3.temp,
                  l_false);

          adicionar_instrucao(buf);

          $$ = strdup(l_false);
      }
    ;

condicao_if
    : if_inicio bloco %prec LOWER_THAN_ELSE
      {
          sprintf(buf, "%s:\n", $1);
          adicionar_instrucao(buf);

          char *c_out = (char*) malloc(
              strlen($2.c_expr) +
              strlen($1) + 200
          );

          sprintf(c_out,
                  "if (...) {\n%s}\n",
                  $2.c_expr);

          $$.c_expr = c_out;
      }

    | if_inicio bloco TOKEN_ELSE
      {
          char *l_fim = novo_label();

          sprintf(buf,
                  "goto %s;\n%s:\n",
                  l_fim,
                  $1);

          adicionar_instrucao(buf);

          $<valor_str>$ = l_fim;
      }
      bloco
      {
          sprintf(buf,
                  "%s:\n",
                  $<valor_str>4);

          adicionar_instrucao(buf);

          $$.c_expr = strdup("");
      }
    ;

laco_while 
    : TOKEN_WHILE {
        char *l_inicio = novo_label();
        char *l_fim = novo_label();
        strcpy(pilha_inicio[topo_laco], l_inicio);
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
        sprintf(buf, "%s:\n", l_inicio);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $<valor_str>$ = l_inicio;
    } '(' expressao ')' bloco {
        char *l_inicio = $<valor_str>2;
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "if (!%s) goto %s;\n", $4.temp, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        char *c_out = (char*) malloc(strlen($4.c_expr) + strlen($6.c_expr) + 200);
        sprintf(c_out, "while (%s) {\n%s}\n", $4.c_expr, $6.c_expr);
        
        sprintf(buf, "goto %s;\n%s:\n", l_inicio, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        topo_laco--;
        $$.c_expr = c_out;
    }
    ;

laco_do_while 
    : TOKEN_DO {
        char *l_inicio = novo_label();
        char *l_fim = novo_label();
        strcpy(pilha_inicio[topo_laco], l_inicio);
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
        sprintf(buf, "%s:\n", l_inicio);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $<valor_str>$ = l_inicio;
    } bloco TOKEN_WHILE '(' expressao ')' {
        char *l_inicio = $<valor_str>2;
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "if (%s) goto %s;\n%s:\n", $6.temp, l_inicio, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        char *c_out = (char*) malloc(strlen($3.c_expr) + strlen($6.c_expr) + 200);
        sprintf(c_out, "do {\n%s} while (%s);\n", $3.c_expr, $6.c_expr);
        topo_laco--;
        $$.c_expr = c_out;
    }
    ;

laco_for 
    : TOKEN_FOR '(' atribuicao ';' {
        char *l_inicio = novo_label();
        char *l_fim = novo_label();
        strcpy(pilha_inicio[topo_laco], l_inicio);
        strcpy(pilha_fim[topo_laco], l_fim);
        topo_laco++;
        sprintf(buf, "%s:\n", l_inicio);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $<valor_str>$ = l_inicio;
    } expressao ';' {
        char *l_corpo = novo_label();
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "if (%s) goto %s;\ngoto %s;\n%s:\n", $6.temp, l_corpo, l_fim, l_corpo);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $<valor_str>$ = l_corpo;
    } atribuicao ')' '{' { escopo_atual++; } comandos_bloco '}' {
        remover_simbolos_do_nivel(escopo_atual);
        escopo_atual--;
        char *l_inicio = $<valor_str>5;
        char *l_fim = pilha_fim[topo_laco - 1];
        sprintf(buf, "goto %s;\n%s:\n", l_inicio, l_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        char *c_out = (char*) malloc(strlen($3.c_expr) + strlen($6.c_expr) + strlen($9.c_expr) + strlen($13.c_expr) + 300);
        sprintf(c_out,
        "for (%s; %s; %s) {\n%s}\n", $3.c_expr, $6.c_expr, $9.c_expr, $13.c_expr);
        topo_laco--;
        $$.c_expr = c_out;
    }
    ;

estrutura_switch 
    : TOKEN_SWITCH '(' expressao ')' {
        dentro_switch = 1;
        char *l_fim = novo_label();
        strcpy(switch_fim, l_fim);
        strcpy(switch_exp, $3.temp);
    } '{' casos caso_default '}' {
        sprintf(buf, "%s:\n", switch_fim);
        adicionar_instrucao(buf); // Alterado (Item 7)
        dentro_switch = 0;
        
        char *c_out = (char*) malloc(strlen($3.c_expr) + strlen($7.c_expr) + strlen($8.c_expr) + 200);
        sprintf(c_out, "switch (%s) {\n%s%s}\n", $3.c_expr, $7.c_expr, $8.c_expr);
        $$.c_expr = c_out;
    }
    ;

casos 
    : TOKEN_CASE expressao ':' {
        char *l_prox = novo_label();
        char *t_cmp = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\nif (!%s) goto %s;\n", t_cmp, switch_exp, $2.temp, t_cmp, l_prox);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $<valor_str>$ = l_prox;
    } comandos casos {
        char *l_prox = $<valor_str>4;
        sprintf(buf, "%s:\n", l_prox);
        adicionar_instrucao(buf); // Alterado (Item 7)
        
        char *c_out = (char*) malloc(strlen($2.c_expr) + strlen($5.c_expr) + strlen($6.c_expr) + 100);
        sprintf(c_out, "case %s:\n%s%s", $2.c_expr, $5.c_expr, $6.c_expr);
        $$.c_expr = c_out;
    }
    |
    /* vazio */ { $$.c_expr = strdup(""); }
    ;

caso_default 
    : TOKEN_DEFAULT ':' comandos {
        char *c_out = (char*) malloc(strlen($3.c_expr) + 50);
        sprintf(c_out, "default:\n%s", $3.c_expr);
        $$.c_expr = c_out;
    }
    | /* vazio */ { $$.c_expr = strdup(""); }
    ;

expressao 
    : expressao PLUS expressao {
        int t_res = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = $1.temp, *e2 = $3.temp;
        if (t_res == T_FLOAT && $1.tipo_val == T_INT) e1 = gerar_cast($1.temp, T_FLOAT);
        if (t_res == T_FLOAT && $3.tipo_val == T_INT) e2 = gerar_cast($3.temp, T_FLOAT);
        sprintf(buf, "%s = %s + %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t;
        $$.tipo_val = t_res;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s + %s", $1.c_expr, $3.c_expr);
        $$.c_expr = c_out;
    }
    | expressao '-' expressao {
        int t_res = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = $1.temp, *e2 = $3.temp;
        if (t_res == T_FLOAT && $1.tipo_val == T_INT) e1 = gerar_cast($1.temp, T_FLOAT);
        if (t_res == T_FLOAT && $3.tipo_val == T_INT) e2 = gerar_cast($3.temp, T_FLOAT);
        sprintf(buf, "%s = %s - %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t;
        $$.tipo_val = t_res;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s - %s", $1.c_expr, $3.c_expr);
        $$.c_expr = c_out;
    }
    | expressao '*' expressao {
        int t_res = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = $1.temp, *e2 = $3.temp;
        if (t_res == T_FLOAT && $1.tipo_val == T_INT) e1 = gerar_cast($1.temp, T_FLOAT);
        if (t_res == T_FLOAT && $3.tipo_val == T_INT) e2 = gerar_cast($3.temp, T_FLOAT);
        sprintf(buf, "%s = %s * %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t;
        $$.tipo_val = t_res;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s * %s", $1.c_expr, $3.c_expr);
        $$.c_expr = c_out;
    }
    | expressao '/' expressao {
        int t_res = ($1.tipo_val == T_FLOAT || $3.tipo_val == T_FLOAT) ? T_FLOAT : T_INT;
        char *t = novo_temp(t_res);
        char *e1 = $1.temp, *e2 = $3.temp;
        if (t_res == T_FLOAT && $1.tipo_val == T_INT) e1 = gerar_cast($1.temp, T_FLOAT);
        if (t_res == T_FLOAT && $3.tipo_val == T_INT) e2 = gerar_cast($3.temp, T_FLOAT);
        sprintf(buf, "%s = %s / %s;\n", t, e1, e2);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t;
        $$.tipo_val = t_res;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s / %s", $1.c_expr, $3.c_expr);
        $$.c_expr = c_out;
    }
    | expressao LE expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s <= %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s <= %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | expressao GE expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s >= %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s >= %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | expressao EQ expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s == %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s == %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | expressao NE expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s != %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s != %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | expressao '<' expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s < %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s < %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | expressao '>' expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s > %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s > %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | expressao AND expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s && %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s && %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | expressao OR expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s || %s;\n", t, $1.temp, $3.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 10);
        sprintf(c_out, "%s || %s", $1.c_expr, $3.c_expr); $$.c_expr = c_out;
    }
    | NOT expressao {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = !%s;\n", t, $2.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        char *c_out = (char*) malloc(strlen($2.c_expr) + 5);
        sprintf(c_out, "!%s", $2.c_expr); $$.c_expr = c_out;
    }
    |
    '-' expressao %prec UMINUS {
        char *t = novo_temp($2.tipo_val);
        sprintf(buf, "%s = -%s;\n", t, $2.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = $2.tipo_val;
        char *c_out = (char*) malloc(strlen($2.c_expr) + 5);
        sprintf(c_out, "-%s", $2.c_expr); $$.c_expr = c_out;
    }
    |
    '(' tipo ')' expressao %prec CAST {
        char *t = novo_temp($<info>2.tipo_val);
        const char* s_tipo = ($<info>2.tipo_val == T_FLOAT) ? "float" : "int";
        sprintf(buf, "%s = (%s) %s;\n", t, s_tipo, $4.temp);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = $<info>2.tipo_val;
        char *c_out = (char*) malloc(strlen($4.c_expr) + 20);
        sprintf(c_out, "(%s)(%s)", s_tipo, $4.c_expr);
        $$.c_expr = c_out;
    }
    | termo { $$ = $1; }
    ;

termo 
    : fator { $$ = $1; }
    ;

fator 
    : ID {
        Simbolo *s = buscar($1);
        if (s == NULL) {
            yyerror("Erro Semantico: Variavel nao declarada.");
            $$.temp = strdup("0"); $$.tipo_val = T_INT; $$.c_expr = strdup("0");
        } else {
            $$.temp = s->temp;
            $$.tipo_val = s->tipo; $$.c_expr = s->nome;
        }
    }
    |
    NUM_INT {
        char *t = novo_temp(T_INT);
        sprintf(buf, "%s = %s;\n", t, $1);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_INT; $$.c_expr = $1;
    }
    |
    NUM_FLOAT {
        char *t = novo_temp(T_FLOAT);
        sprintf(buf, "%s = %s;\n", t, $1);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_FLOAT; $$.c_expr = $1;
    }
    |
    CHAR_LIT {
        char *t = novo_temp(T_CHAR);
        sprintf(buf, "%s = %s;\n", t, $1);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_CHAR; $$.c_expr = $1;
    }
    |
    STRING_LIT {
        int tam = strlen($1) - 2 + 1; // desconta aspas e conta \0
        char *t = novo_temp_str(tam);
        sprintf(buf, "strcpy(%s, %s);\n", t, $1);
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_STRING; $$.c_expr = $1;
    }
    | BOOL_LIT {
        char *t = novo_temp(T_BOOL);
        sprintf(buf, "%s = %s;\n", t, strcmp($1,"true")==0 ? "1" : "0");
        adicionar_instrucao(buf); // Alterado (Item 7)
        $$.temp = t; $$.tipo_val = T_BOOL;
        $$.c_expr = strcmp($1,"true")==0 ? "true" : "false";
    }
    |
    '(' expressao ')' {
        $$.temp = $2.temp; $$.tipo_val = $2.tipo_val;
        char *c_out = (char*) malloc(strlen($2.c_expr) + 5);
        sprintf(c_out, "(%s)", $2.c_expr); $$.c_expr = c_out;
    }
    |
    ID '[' expressao ']' {
        Simbolo *s = buscar($1);
        if (s == NULL) {
            yyerror("Erro Semantico: Matriz nao declarada.");
            $$.temp = strdup("0"); $$.tipo_val = T_INT; $$.c_expr = strdup("0");
        } else if (!s->array) {
            yyerror("Erro Semantico: O identificador nao eh uma matriz.");
            $$.temp = strdup("0"); $$.tipo_val = T_INT; $$.c_expr = strdup("0");
        } else {
            char *t = novo_temp(s->tipo);
            sprintf(buf, "%s = %s[%s];\n", t, s->temp, $3.temp);
            adicionar_instrucao(buf); // Alterado (Item 7)
            $$.temp = t; $$.tipo_val = s->tipo;
            char *c_out = (char*) malloc(strlen(s->nome) + strlen($3.c_expr) + 5);
            sprintf(c_out, "%s[%s]", s->nome, $3.c_expr); $$.c_expr = c_out;
        }
    }
    | ID '(' chamada_argumentos ')' {
        // Regra para Chamada de Funções como Expressões
        Simbolo *s = buscar($1);
        if (s == NULL || !s->eh_funcao) {
            yyerror("Erro Semantico: Funcao nao declarada.");
            $$.temp = strdup("0"); $$.tipo_val = T_INT; $$.c_expr = strdup("0");
        } else {
            char *t = novo_temp(s->tipo);
            $$.temp = t;
            $$.tipo_val = s->tipo;
            
            // Mensagem de log para verificar resolução de nomes de funções (Item 9)
            printf("FUNCAO CHAMADA: %s\n", s->temp);

            // Grava no Código Intermediário de 3 Endereços (TAC)
            sprintf(buf, "%s = %s(%s);\n", t, s->temp, $3.temp);
            adicionar_instrucao(buf); // Alterado (Item 7)
            
            // Grava na expressão traduzida de C
            char *c_out = (char*) malloc(strlen(s->nome) + strlen($3.c_expr) + 5);
            sprintf(c_out, "%s(%s)", s->nome, $3.c_expr);
            $$.c_expr = c_out;
        }
    }
    ;

chamada_argumentos
    : chamada_argumentos_lista { $$ = $1; }
    |
    /* vazio */ { $$.temp = strdup(""); $$.c_expr = strdup(""); }
    ;

chamada_argumentos_lista
    : expressao { 
        $$.temp = strdup($1.temp);
        $$.c_expr = strdup($1.c_expr); 
    }
    | expressao ',' chamada_argumentos_lista {
        char *t_buf = (char*) malloc(strlen($1.temp) + strlen($3.temp) + 5);
        char *c_buf = (char*) malloc(strlen($1.c_expr) + strlen($3.c_expr) + 5);
        sprintf(t_buf, "%s, %s", $1.temp, $3.temp);
        sprintf(c_buf, "%s, %s", $1.c_expr, $3.c_expr);
        $$.temp = t_buf;
        $$.c_expr = c_buf;
    }
    ;

%%

#include <stdlib.h> // Necessário para a função system()

int main() {
    yyparse();
    if (houve_erro) {
        return 1;
    }

    gerar_declaracoes_finais();

    /* 1. VISUALIZAÇÃO DO CÓDIGO INTERMEDIÁRIO (Terminal) */
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    printf("#include <string.h>\n");
    printf("#include <stdbool.h>\n\n");

    // Imprime definições de funções globais fora da main no terminal
    printf("%s", c_code_body);

    printf("int main()\n");
    printf("{\n");
    printf("%s\n", declaracoes);
    printf("%s", instrucoes);
    printf("    return 0;\n");
    printf("}\n");

    /* 2. GERAÇÃO DO CÓDIGO (Arquivo saida.c) */
    FILE *arquivo_c = fopen("saida.c", "w");
    if (!arquivo_c) {
        printf("Erro: Nao foi possivel criar o arquivo saida.c\n");
        return 1;
    }

    fprintf(arquivo_c, "#include <stdio.h>\n");
    fprintf(arquivo_c, "#include <stdlib.h>\n");
    fprintf(arquivo_c, "#include <string.h>\n");
    fprintf(arquivo_c, "#include <stdbool.h>\n\n");

    /* Declaracoes de temporarios */
    fprintf(arquivo_c, "%s\n", c_code_decl);

    /* Funcoes geradas */
    fprintf(arquivo_c, "%s", c_code_body);

    fprintf(arquivo_c, "int main()\n");
    fprintf(arquivo_c, "{\n");

    /* Codigo intermediario da main */
    fprintf(arquivo_c, "%s", declaracoes);
    fprintf(arquivo_c, "%s", instrucoes);

    /* TEMPORARIAMENTE COMENTADO PARA TESTE */
    /* fprintf(arquivo_c, "%s", c_body); */

    fprintf(arquivo_c, "    return 0;\n");
    fprintf(arquivo_c, "}\n");

    fclose(arquivo_c);
    return 0;
    }