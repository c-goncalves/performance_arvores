#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
int main()
{
    // Gerando arquivo ordenado
    ordenar_file();

    // Variaveis do menu
    char str_opc[30], str_arv[30], str_continuar[5];
    strcpy(str_continuar, "s");
    int opc = 0, opc_arv = 0;


    while (opc != 3){

        // MENU
        printf("\n\n\tTeste de Desempenho AVL x Rubro-Negra\n\n");
        printf("\n\tEscola uma opção:\n");
        printf("\t(1)Arquivo original:\n");
        printf("\t(2)Arquivo ordenado:\n");
        printf("\t(3)Finalizar a aplicacao\n");
        printf("\t");
        gets(str_opc);
        opc = atoi(str_opc);


        if(opc == 3)break;
        if(opc != 2 && opc != 1) printf("\n\tOpcao invalida\n\n");
        else{
            // MENU 2
            printf("\n\tEscola uma Arvore:\n");
            printf("\t(1)Arvore AVL:\n");
            printf("\t(2)Arvore Rubro-Negra:\n");
            printf("\t(3)Finalizar a aplicacao?\n");
            printf("\t");
            gets(str_arv);
            opc_arv = atoi(str_arv);
            if(opc_arv == 3) break;
            if(opc_arv != 2 && opc_arv != 1)printf("\n\tOpcao invalida\n\n");
            else if(opc_arv == 1){

                //     Inicialiando
                    FUNCIONARIO *dados_AVL, *dados_LLRB;
                    int i, elem_arv = 0, res;
                    int x, elem_llrb = 0, res2;

                    //float tempos[10], media = 0, clock_media = 0;

                //   Criando a AVL
                    ArvAVL *raiz_AVL;
                    raiz_AVL= cria_arvAVL();

                //   Obtendo o numero de linhas do arquivo
                   int n_linhas = n_linhas_file();

                //   Inicio da contagem de tempo AVL
                    clock_t tic_AVL = clock();

                //   Lendo os dados do arquivo para a AVL
                    dados_AVL= ler_dados(opc);

                //   Inserindo dados na AVL
                    for(i=0;i<n_linhas;i++){
                        res = insere_arvAVL(raiz_AVL, dados_AVL[i]);
                        if(res) elem_arv++;
                    }

                //   Fim da leitura de tempo da AVL
                    clock_t toc_AVL = clock();
       //
                //    Remocao de elementos da AVL
                    for(i=0;i<n_linhas;i++){
                        res = remove_arvAVL(raiz_AVL, dados_AVL[i]);
                    }
                //  Liberar a memoria da AVL
                    liberar_arvAVL(raiz_AVL);


                //  Print resultados
                    printf("\n");
                    if(opc== 1) printf("\n\tVetor original\n");
                    else printf("\n\tVetor ordenado\n");
                    printf("\tTempo de execução AVL: %f secondos\n", (double)(toc_AVL - tic_AVL) / CLOCKS_PER_SEC);
                    printf("\n\n");



            }else{
                // Testando a RN
                FUNCIONARIO *dados;
            //   Inicio da contagem de tempo
                float tempos[10], media = 0, clock_media = 0;
                clock_t tic = clock();

            //   Lendo os dados do arquivo
                dados= ler_dados(opc);


            //   Obtendo o numero de linhas do arquivo
               int n_linhas = n_linhas_file();
            //   Criando a AVL
                ArvLLRB *raiz;
                raiz= cria_ArvLLRB();

            //   Inserindo dados na AVL
                int i, elem_arv = 0, res;
                for(i=0;i<20;i++){
                    res = insere_ArvLLRB(raiz, dados[i]);
                    if(res) elem_arv++;
                }

            //   Fim da leitura de tempo
                clock_t toc = clock();

            //    emOrdem_ArvLLRB(raiz,0);

            //  Print resultados
                printf("\n");
                if(opc== 1) printf("\n\tVetor original\n");
                else printf("\n\tVetor ordenado\n");
                printf("\tTempo de execução Rubro-Negra: %f secondos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
                printf("\n\n");


            //    Destruindo a AVL
            //    Remocao de elementos
                for(i=0;i<20;i++){
                    res = remove_ArvLLRB(raiz, dados[i]);
                }
            //  Liberar a memoria da lista dinamica
                libera_ArvLLRB(raiz);
            }

        }
        printf("\n\tPrecione um tecla para continuar");
                gets(str_continuar);
                system("cls"); // Windows
                system("clear"); // Unix
            }


    return;
}
