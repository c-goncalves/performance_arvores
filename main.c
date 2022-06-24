#include <stdio.h>
#include <stdlib.h>
#include "tree_performance.h"
#include "arvAVL.h"
#include <time.h>
int main()
{


    FUNCIONARIO *dados;
    clock_t tic = clock();
   dados= lerArquivo();
   int count = n_linhas_file();

    //Teste vetor
//   printf("\n\n Into the struct");
//
//    for(int i=0;i<count;i++)
//        printf("\n%dº = %d;%s;%d;%s;%s;%.2f\n",
//        i+1,
//        dados[i].p,
//        dados[i].nome,
//        dados[i].idade,
//        dados[i].empresa,
//        dados[i].departamento,
//        dados[i].salario);
//
//    printf("\n");

    // Inserindo na AVL
    int x;
    ArvAVL *raiz;
    raiz= cria_arvAVL(raiz);
    printf("\n");
    printf("Arvore AVL");
    printf("\n\n");

    printf("Estado da Arvore 1: ");
    //Se esta vazia (sim)
    if(vazia_arvAVL(raiz)){
        printf("A arvore esta vazia");
    }else{
        printf("A arvore possui elementos");
    }
    printf("\n");

    float tempos[10], media = 0, clock_media = 0;
    double deltaT;
    //Inserindo elementos
    int i, elem_arv = 0;

    for(i=0;i<count;i++){
        x = insere_arvAVL(raiz, dados[i]);     // x = remove_arvbin(raiz, 150);
        if(x) elem_arv++;
    }
     clock_t toc = clock();
    clock_media += (double)(toc - tic) / CLOCKS_PER_SEC;
    printf(" %dº loop: Tempo de execução -> %f secondos\n", i+1,(double)(toc - tic) / CLOCKS_PER_SEC);
    printf("\n Média do tempo de execucao : %f segundos\n", clock_media/10);

     printf("\n\n");

    // Confirindo inserção
    printf("Estado da Arvore 2: ");
    if(vazia_arvAVL(raiz)){
        printf("A arvore esta vazia %d",x);
    }else{
        printf("A arvore possui %d elementos", elem_arv);
    }
    printf("\n");


    //Percorer em ordem
//    printf("\nVisitando a arvore em pre-ordem: \n\n");
//    emOrdem_arvAVL(raiz);
//    printf("\n");

    printf("\nRemovendo a Arvore Binaria\n\n");

    for(i=0;i<count;i++){
        x = remove_arvAVL(raiz, dados[i]);
    }

     //Liberar a memoria da lista dinamica
    liberar_arvAVL(raiz);

    printf("\n\n\n");



    return 0;
}
