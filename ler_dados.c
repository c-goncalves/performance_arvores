
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


// Gerar vetor
int *ler_dados(int opc){
int n_linhas = n_linhas_file();
    FUNCIONARIO *dados = (FUNCIONARIO*)malloc(n_linhas*sizeof(FUNCIONARIO));
    dados = lerArquivo(opc);
    return dados;
}

// Insere dados do arquivo no vetor
int *lerArquivo(int opc){
    FILE *file;
    // Numero de linhas do arquivo
    int n_linhas = n_linhas_file();
    FUNCIONARIO *dados = (FUNCIONARIO*)malloc(n_linhas*sizeof(FUNCIONARIO));
    if(opc == 2) {
        file_ord();
        file = fopen("massaDados_ordenado.csv", "r");
    }
    else {
        file = fopen("massaDados.csv", "r");
    }


    if(file == NULL){
        printf("Erro na leitura");
        return 1;
    }



    // Inserindo dados do arquivo no vetor
    int campos_lidos =0, linha=0;

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

// Funcao de comparacado do campo codigo (p)
int compara(FUNCIONARIO *a, FUNCIONARIO *b){

    if(a->p == b->p)
        return 0;
    else if(a->p > b->p)
        return 1;
    else
        return -1;

}

int file_ord(){

    FUNCIONARIO *dados;
    dados = lerArquivo(1);
    int n_linhas = n_linhas_file();
     printf("Ordenado");
    qsort(&(*dados), n_linhas, sizeof(FUNCIONARIO), compara);

    FILE *f_ordenado;
    f_ordenado = fopen("massaDados_ordenado.csv", "w");
    if(f_ordenado == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }
    int linha = 0, campos_lidos = 0;
    do{
       campos_lidos=  fprintf(f_ordenado,
                "%d,%s,%d,%s,%s,%.2f\n",
                dados[linha].p,
                dados[linha].nome,
                dados[linha].idade,
                dados[linha].empresa,
                dados[linha].departamento,
                dados[linha].salario
                );
                if(campos_lidos != 0) linha++;


    }while(linha<=n_linhas-1);
    fclose(f_ordenado);

    return dados;
}





