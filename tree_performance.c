#include <stdio.h>
#include <stdlib.h>
#include "tree_performance.h"


// Insere no inicio da lista
int *lerArquivo(){
    FILE *file;
    file = fopen("massaDados.csv", "r");
    if(file == NULL){
        printf("Erro na leitura");
        return 1;
    }
    // Numero de linhas do arquivo
    int count;
    count = n_linhas_file();
    file = fopen("massaDados.csv", "r");

    // Inserindo dados do arquivo no vetor
    int campos_lidos =0, linha=0;
    FUNCIONARIO *dados = (FUNCIONARIO*)malloc(count*sizeof(FUNCIONARIO));
    do{
        campos_lidos = fscanf(file,
                        "%d,%29[^,],%d,%14[^,],%29[^,],%lf\n",
                        &dados[linha].p,
                        dados[linha].nome,
                        &dados[linha].idade,
                        dados[linha].empresa,
                        dados[linha].departamento,
                        &dados[linha].salario
                        );
        if(campos_lidos == 6) linha++;
        if(campos_lidos !=6 && !feof(file)){
            printf("Arquivo com formato incorreto!\n");
            return 1;
        }


    }while(!feof(file));
    fclose(file);
    return dados;
}

int n_linhas_file(){
    FILE *file;
    file = fopen("massaDados.csv", "r");
    if(file == NULL){
        printf("Erro na leitura");
        return 1;
    }
    // Numero de linhas do arquivo
    int count = 1;
    char c;
    for (c = getc(file); c != EOF; c = getc(file))
        if (c == '\n')
            count = count + 1;

    fclose(file);
    return count;

}


