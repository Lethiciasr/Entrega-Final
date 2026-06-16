#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL, T_STRING } Tipo;

// Estrutura do nó da tabela de símbolos (lista encadeada)
typedef struct Simbolo {
    char nome[100];      // nome original do identificador
    char temp[100];      // nome temporário ou nome da função

    Tipo tipo;
    int nivel;
    int array;
    int tamanho_array;

    // Suporte a funções
    int eh_funcao;
    int qtd_parametros;
    Tipo tipos_parametros[20];

    struct Simbolo *proximo;
} Simbolo;

// Funções de gerenciamento da tabela e variáveis temporárias
char* novo_temp(Tipo tipo);
Simbolo* inserir(char *nome, Tipo tipo, int nivel);
Simbolo* inserir_array(char *nome, Tipo tipo, int nivel, int tamanho);

// Funções
Simbolo* inserir_funcao(char *nome, Tipo tipo_retorno, int qtd_params, Tipo params[]);

Simbolo* buscar(char *nome);
void remover_simbolos_do_nivel(int nivel);

// Conversão de tipos
char* gerar_cast(char* temp_origem, Tipo tipo_destino);

// Buffers globais de geração de código
extern char declaracoes[5000];
extern char instrucoes[5000];
extern char c_code_decl[5000];
extern char c_code_body[5000];

extern int l_cont;

char* novo_label();
char* novo_temp_str(int tamanho_exato);
char* novo_temp_array(Tipo tipo, int tamanho);

extern int tamanhos_t[1000];

void gerar_declaracoes_finais();

#endif