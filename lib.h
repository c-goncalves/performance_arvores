
// Estrutura dos dados lidos
typedef struct{
    int p;
    char nome[30];
    int idade;
    char empresa[15];
    char departamento[30];
    double salario;
}FUNCIONARIO;

//  Leitura do arquivo
void ordenar_file();
int *ler_dados(int opc);
int n_linhas_file();
int *lerArquivo(int opc);


// ARVORE AVL
typedef struct NO *ArvAVL;

ArvAVL *cria_arvAVL();
int insere_arvAVL(ArvAVL *raiz, FUNCIONARIO info);
int remove_arvAVL(ArvAVL *raiz, FUNCIONARIO info);
void liberar_arvAVL(ArvAVL *raiz);
void emOrdem_arvAVL(ArvAVL *raiz);
int vazia_arvAVL(ArvAVL *raiz);

int altura_arvAVL(ArvAVL *raiz);
int totalNO_arvAVL(ArvAVL *raiz);
void preOrdem_arvAVL(ArvAVL *raiz);
void posOrdem_arvAVL(ArvAVL *raiz);


// ABB RUBRO NEGRO 2-3
typedef struct NO* ArvLLRB;

ArvLLRB *cria_ArvLLRB();
void libera_ArvLLRB(ArvLLRB* raiz);
int insere_ArvLLRB(ArvLLRB* raiz,FUNCIONARIO valor);
int remove_ArvLLRB(ArvLLRB *raiz, FUNCIONARIO valor);
void emOrdem_ArvLLRB(ArvLLRB *raiz,int H);

int estaVazia_ArvLLRB(ArvLLRB *raiz);
int totalNO_ArvLLRB(ArvLLRB *raiz);
int altura_ArvLLRB(ArvLLRB *raiz);
void preOrdem_ArvLLRB(ArvLLRB *raiz, int H);

void posOrdem_ArvLLRB(ArvLLRB *raiz, int H);
