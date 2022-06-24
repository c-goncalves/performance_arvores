
typedef struct{
    int p;
    char nome[30];
    int idade;
    char empresa[15];
    char departamento[30];
    double salario;
}FUNCIONARIO;


int *lerArquivo();
int n_linhas_file();

// ARVORE AVL

typedef struct NO *ArvAVL;

ArvAVL *cria_arvAVL();
int insere_arvAVL(ArvAVL *raiz, FUNCIONARIO info);
int remove_arvAVL(ArvAVL *raiz, FUNCIONARIO info);
void liberar_arvAVL(ArvAVL *raiz);

int vazia_arvAVL(ArvAVL *raiz);
int altura_arvAVL(ArvAVL *raiz);
int totalNO_arvAVL(ArvAVL *raiz);
void preOrdem_arvAVL(ArvAVL *raiz);
void emOrdem_arvAVL(ArvAVL *raiz);
void posOrdem_arvAVL(ArvAVL *raiz);




