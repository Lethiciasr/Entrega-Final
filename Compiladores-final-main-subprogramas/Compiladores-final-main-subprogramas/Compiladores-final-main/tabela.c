#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Simbolo *tabela_global = NULL;
int t_cont = 1; 
int l_cont = 1;
int tipos_t[1000];
int tamanhos_t[1000];


char* novo_label() {
    char *l = (char*) malloc(10);
    sprintf(l, "L%d", l_cont++);
    return l;
}

char declaracoes[5000] = "";
char instrucoes[5000] = "";
char c_code_decl[5000] = "";   
char c_code_body[5000] = "";   

// Silenciamos o strcat! Agora ele só anota o tipo e o tamanho base.
char* novo_temp(Tipo tipo) {
    char *t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    
    tipos_t[t_cont] = tipo;
    // T_STRING ganha 256 provisório. Outros ganham 0.
    tamanhos_t[t_cont] = (tipo == T_STRING) ? 256 : 0; 
    
    t_cont++;
    return t;
}

// Anota o tamanho cirurgicamente calculado
char* novo_temp_str(int tamanho_exato) {
    char* t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    
    tipos_t[t_cont] = T_STRING;
    tamanhos_t[t_cont] = tamanho_exato; 
    
    t_cont++;
    return t;
}

char* novo_temp_array(Tipo tipo, int tamanho) {
    char* t = (char*) malloc(10);
    sprintf(t, "T%d", t_cont);
    
    tipos_t[t_cont] = tipo;
    tamanhos_t[t_cont] = tamanho; // Registra o tamanho exato da matriz
    
    t_cont++;
    return t;
}

void gerar_declaracoes_finais() {
    for (int i = 1; i < t_cont; i++) {
        char linha[100];
        
        // Se o tamanho for maior que zero e não for string, é uma matriz!
        if (tamanhos_t[i] > 0 && tipos_t[i] != T_STRING) {
            switch(tipos_t[i]) {
                case T_INT:   sprintf(linha, "int T%d[%d];\n", i, tamanhos_t[i]); break;
                case T_FLOAT: sprintf(linha, "float T%d[%d];\n", i, tamanhos_t[i]); break;
            }
        } else {
            // Variável comum ou string
            switch(tipos_t[i]) {
                case T_INT:   sprintf(linha, "int T%d;\n", i); break;
                case T_FLOAT: sprintf(linha, "float T%d;\n", i); break;
                case T_CHAR:  sprintf(linha, "char T%d;\n", i); break;
                case T_BOOL:  sprintf(linha, "int T%d;\n", i); break;
                case T_STRING: sprintf(linha, "char T%d[%d];\n", i, tamanhos_t[i]); break;
            }
        }
        strcat(declaracoes, linha); 
        strcat(c_code_decl, linha); 
    }
}

char* gerar_cast(char* temp_origem, Tipo tipo_destino) {
    char* t_destino = novo_temp(tipo_destino);
    char buf[100];
    const char* label_tipo = (tipo_destino == T_FLOAT) ? "float" : "int";

    sprintf(buf, "%s = (%s) %s;\n", t_destino, label_tipo, temp_origem);
    strcat(instrucoes, buf);
    return t_destino;
}

Simbolo* inserir(char *nome, Tipo tipo, int nivel) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    char *nome_t = novo_temp(tipo); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    novo->tipo = tipo;
    novo->nivel = nivel;
    novo->proximo = tabela_global;
    novo->array = 0;
    novo->tamanho_array = 0;
    novo->eh_funcao = 0;          // Inicializado como 0 (variável normal)
    novo->qtd_parametros = 0;
    tabela_global = novo;
    return novo;
}

Simbolo* inserir_array(char *nome, Tipo tipo, int nivel, int tamanho) {
    if (buscar(nome) != NULL) {
        printf("Erro Semantico: Variavel '%s' ja declarada neste escopo.\n", nome);
        return NULL;
    }

    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);

    char *nome_t = novo_temp_array(tipo, tamanho); 
    strcpy(novo->temp, nome_t); 
    free(nome_t); 
    
    novo->tipo = tipo;
    novo->nivel = nivel;
    novo->proximo = tabela_global;
    novo->array = 1;
    novo->tamanho_array = tamanho;
    novo->eh_funcao = 0;          // Inicializado como 0 (é um array)
    novo->qtd_parametros = 0;
    
    tabela_global = novo;
    return novo;
}

// --- IMPLEMENTAÇÃO DA NOVA FUNÇÃO PARA INSERIR ASSINATURAS DE SUBPROGRAMAS ---
Simbolo* inserir_funcao(char *nome, Tipo tipo_retorno, int qtd_params, Tipo params[]) {
    // Verifica se já existe um símbolo com este nome globalmente
    if (buscar(nome) != NULL) {
        printf("Erro Semantico: O identificador '%s' ja esta sendo utilizado.\n", nome);
        return NULL;
    }

    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(novo->nome, nome);
    
    // Para funções, o identificador de chamada é o próprio nome original
    strcpy(novo->temp, nome); 
    
    novo->tipo = tipo_retorno;
    novo->nivel = 0;              // Funções são declaradas no escopo global (nível 0)
    novo->array = 0;
    novo->tamanho_array = 0;
    novo->eh_funcao = 1;          // Marcamos explicitamente como função
    novo->qtd_parametros = qtd_params;
    
    // Copia a assinatura dos tipos dos parâmetros para validação posterior
    for (int i = 0; i < qtd_params; i++) {
        novo->tipos_parametros[i] = params[i];
    }
    
    novo->proximo = tabela_global;
    tabela_global = novo;
    return novo;
}

Simbolo* buscar(char *nome) {
    Simbolo *atual = tabela_global;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void remover_simbolos_do_nivel(int nivel) {
    while (tabela_global != NULL && tabela_global->nivel == nivel) {
        Simbolo *remover = tabela_global;
        tabela_global = tabela_global->proximo;
        free(remover); 
    }
}