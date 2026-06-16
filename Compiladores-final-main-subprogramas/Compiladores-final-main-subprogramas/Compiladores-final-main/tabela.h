#ifndef TABELA_H
#define TABELA_H

typedef enum { T_INT, T_FLOAT, T_CHAR, T_BOOL, T_STRING } Tipo;

// Estrutura do nó da tabela de símbolos (lista encadeada)
typedef struct Simbolo {
    char nome[50];
    char temp[10]; // codigo intermediario
    Tipo tipo;
    int nivel;
    int array;
    int tamanho_array;
    
    // --- NOVOS CAMPOS PARA SUPORTE A SUBPROGRAMAS/FUNÇÕES ---
    int eh_funcao;              // 1 se for função, 0 se for variável comum/array
    int qtd_parametros;         // Quantidade de parâmetros que a função aceita
    Tipo tipos_parametros[10];  // Array armazenando os tipos de cada parâmetro esperado
    
    struct Simbolo *proximo;
} Simbolo;

// Funções de gerenciamento da tabela e variáveis temporárias
char* novo_temp(Tipo tipo); // gerar um novo nome de variavel temporaria
Simbolo* inserir(char *nome, Tipo tipo, int nivel); // add uma nova variavel na tabela quando declarada
Simbolo* inserir_array(char *nome, Tipo tipo, int nivel, int tamanho);

// --- NOVA FUNÇÃO PARA INSERÇÃO DE ASSINATURA DE FUNÇÕES ---
Simbolo* inserir_funcao(char *nome, Tipo tipo_retorno, int qtd_params, Tipo params[]);

Simbolo* buscar(char *nome); // vê se a variavel ja foi declarada
void remover_simbolos_do_nivel(int nivel);

// Nova função auxiliar para conversão de tipos
char* gerar_cast(char* temp_origem, Tipo tipo_destino);

// Buffers para armazenar o código intermediário gerado
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