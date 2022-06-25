#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
int main()
{
    int opc = 0, fechar;
    char s[5];
    printf("Programa para teste de desempenho AVL x Rubro-Negra\n\n");
    while (opc != 3){
        //file_ord();
        FUNCIONARIO *dados;
        // MENU
        printf("Escola uma opção:\n");
        printf("(1)Arquivo desordenado:\n");
        printf("(2)Arquivo ordenado:\n");
        printf("(3)Deseja finalizar a aplicacao?\n");
        gets(s);
        opc = atoi(s);
        //GETCHAR
        if(opc == 3)return 0;
        if(opc != 2 && opc != 1){
            printf("\nOpcao invalida");
        }else{
            //   Inicio da contagem de tempo
                float tempos[10], media = 0, clock_media = 0;
                clock_t tic = clock();
            //   Lendo os dados do arquivo
                dados= ler_dados(opc);
            //   Teste 1: Print dados lidos
            //   printf("\n\n Dados lidos: ");
            //    for(int i=0;i<n_linhas;i++)
            //        printf("\n%dº = %d;%s;%d;%s;%s;%.2f\n",
            //        i+1,
            //        dados[i].p,
            //        dados[i].nome,
            //        dados[i].idade,
            //        dados[i].empresa,
            //        dados[i].departamento,
            //        dados[i].salario);
            //   Obtendo o numero de linhas do arquivo
               int n_linhas = n_linhas_file();
            //   Criando a AVL
                ArvAVL *raiz;
                raiz= cria_arvAVL(raiz);
            //   Inserindo dados na AVL
                int i, elem_arv = 0, res;
                for(i=0;i<n_linhas;i++){
                    res = insere_arvAVL(raiz, dados[i]);
                    if(res) elem_arv++;
                }
            //   Fim da leitura de tempo
                clock_t toc = clock();
                printf("\n\n");
                printf("Tempo de execução AVL -> %f secondos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
                printf("\n\n");

            //    Teste 2: AVL possue elementos
            //    if(vazia_arvAVL(raiz)){
            //        printf("\nA arvore esta vazia %d\n",res);
            //    }else{
            //        printf("\nA arvore possui %d elementos\n", elem_arv);
            //    }
            //    Teste 3: Print de elementos da AVL em ordem
            //    printf("\nVisitando a arvore em pre-ordem: \n\n");
            //    emOrdem_arvAVL(raiz);
            //    printf("\n");
            //    Destruindo a AVL
            //    Remocao de elementos
                for(i=0;i<n_linhas;i++){
                    res = remove_arvAVL(raiz, dados[i]);
                }
            //  Liberar a memoria da lista dinamica
                liberar_arvAVL(raiz);
            //  Organidando dados para segunda leitura com o TimSort
                //timSort(vetor, vetor_qtd[tam_vetor]);
           }
    }
    return 0;
}
