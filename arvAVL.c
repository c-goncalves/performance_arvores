#include <stdio.h>
#include <stdlib.h>
#include "tree_performance.h"

struct NO{
    FUNCIONARIO dados;
    int alt;
    struct NO *esq;
    struct NO *dir;
};
//  Funcoes auxiliares
int alt_no(struct NO *no){
    if(no==NULL){
        return -1;
    }else{
        return no->alt;
    }

}
int fatorBalanceamento_NO(struct NO *no){
    return labs(alt_no(no->esq)- alt_no(no->dir));
}
int maior(int x, int y){
    if(x>y){
        return(x);
    }else{
        return(y);
    }
}
//  Rotacoes
void rotacaoLL(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir))+1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt+1);
    *raiz = no;
}
void rotacaoRR(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir))+1;
    no->alt = maior(alt_no(no->dir), (*raiz)->alt)+1;
    (*raiz) = no;
}
void rotacaoLR(ArvAVL *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}
void rotacaoRL(ArvAVL *raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

//Criar a arvore
ArvAVL *cria_arvAVL(){
    ArvAVL *raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
    if(raiz != NULL){
        *raiz=NULL;
    }
    return raiz;
};

//  Inserindo elementos
int insere_arvAVL(ArvAVL *raiz, FUNCIONARIO info){
    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL){
            return 0;
        }
        novo->dados = info;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(info.p < atual->dados.p){
        if((res = insere_arvAVL(&(atual->esq), info))==1){
            if(fatorBalanceamento_NO(atual)>=2){
                if(info.p < (*raiz)->esq->dados.p){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }

    }else{
        if(info.p > atual->dados.p){
            if((res = insere_arvAVL(&(atual->dir), info))==1){
                if(fatorBalanceamento_NO(atual)>=2){
                    if((*raiz)->dir->dados.p < info.p){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!\n");
            return 0;
        }

    }

    atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir))+1;
    return res;


}

//  Removendo elementos
struct NO *procuramenor(struct NO *atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2!= NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;

}
int remove_arvAVL(ArvAVL *raiz, FUNCIONARIO info){
    if(*raiz == NULL){
        return 0;
    }
    int res;
    if(info.p < (*raiz)->dados.p){
        if( (res = remove_arvAVL(&(*raiz)->esq, info)) == 1){
            if(fatorBalanceamento_NO(*raiz)>=2){
                if(alt_no((*raiz)->dir->esq)<= alt_no((*raiz)->dir->dir)){
                    rotacaoRR(raiz);
                }else{
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->dados.p < info.p){
        if((res=remove_arvAVL(&(*raiz)->dir, info))==1){
            if(fatorBalanceamento_NO(*raiz)>=2){
                if(alt_no((*raiz)->esq->dir)<= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }
    if((*raiz)->dados.p == info.p){
        if(((*raiz)->esq == NULL) || (*raiz)->dir==NULL){
            struct NO *no_velho = (*raiz);
            if((*raiz)->esq !=NULL){
                *raiz = (*raiz)->esq;
            }else{
                *raiz = (*raiz)->dir;
            }
            free(no_velho);
        }else{
            struct NO* temp = procuramenor((*raiz)->dir);
            (*raiz)->dados.p = temp->dados.p;
            remove_arvAVL(&(*raiz)->dir, temp->dados);
            if(fatorBalanceamento_NO(*raiz)>=2){
                if(alt_no((*raiz)->esq->dir)<= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
        if(*raiz != NULL){
            (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir))+1;
        }
        return 1;

    }
    if(*raiz !=NULL){
        (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir))+1;
    }
    return res;
}


//Liberar a memoria da lista dinamica
void libera_NO(struct NO *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
};

void liberar_arvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;

    }
    libera_NO(*raiz);
    free(raiz);
};


//  Contagem de nós
int totalNO_arvAVL(ArvAVL *raiz){
     if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_arvAVL(&((*raiz)->esq));
    int alt_dir = altura_arvAVL(&((*raiz)->dir));
    return (alt_esq + alt_dir+1);
}

//Percorer em pre-ordem
void preOrdem_arvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("[%d] ", (*raiz)->dados.p);
        preOrdem_arvAVL((&((*raiz)->esq)));
        preOrdem_arvAVL(&((*raiz)->dir));
    }
}



//Percorer em-ordem
void emOrdem_arvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_arvAVL(&((*raiz)->esq));
        printf("[%d] ", (*raiz)->dados.p);
        emOrdem_arvAVL(&((*raiz)->dir));
    }
}


//Percorer em pos-ordem
void posOrdem_arvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_arvAVL(&((*raiz)->esq));
        posOrdem_arvAVL(&((*raiz)->dir));
        printf("%d", (*raiz)->dados.p);
    }
}



struct NO *remove_atual(struct NO *atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

//  Estado da AVL
int vazia_arvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
};

// Altura da AVL
int altura_arvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }

    int alt_esq = altura_arvAVL(&((*raiz)->esq));
    int alt_dir = altura_arvAVL(&((*raiz)->dir));
    if(alt_esq>alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir+1);
    }

}


