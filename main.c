#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"
int main()
{
    // Gerando arquivo ordenado
    ordenar_file();

    // Variaveis do menu
    char str_opc[30], str_continuar[5];
    strcpy(str_continuar, "s");
    int opc = 0;


    while (opc != 3){

        // MENU
        printf("\n\n\tTeste de Desempenho AVL x Rubro-Negra\n\n");
        printf("\n\tEscola uma opção:\n");
        printf("\t(1)Arquivo original:\n");
        printf("\t(2)Arquivo ordenado:\n");
        printf("\t(3)Deseja finalizar a aplicacao?\n");
        printf("\t");
        gets(str_opc);
        opc = atoi(str_opc);

        if(opc == 3)break;
        if(opc != 2 && opc != 1) printf("\n\tOpcao invalida\n\n");
        else{
            FUNCIONARIO *dados;
            //   Inicio da contagem de tempo
                float tempos[10], media = 0, clock_media = 0;
                clock_t tic = clock();

            //   Lendo os dados do arquivo
                dados= ler_dados(opc);

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

            //  Print resultados
                printf("\n");
                if(opc== 1) printf("\n\tVetor original\n");
                else printf("\n\tVetor ordenado\n");
                printf("\tTempo de execução AVL: %f secondos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
                printf("\tTempo de execução Rubro-Negra: %f secondos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
                printf("\n\n");


            //    Destruindo a AVL
            //    Remocao de elementos
                for(i=0;i<n_linhas;i++){
                    res = remove_arvAVL(raiz, dados[i]);
                }
            //  Liberar a memoria da lista dinamica
                liberar_arvAVL(raiz);

           }
            printf("\n\tPrecione um tecla para continuar");
            gets(str_continuar);
            system("cls"); // Windows
            system("clear"); // Unix
    }
    return;
}
