#include "departamentos.h"


int pesquisarDepartamento(FILE *arquivo, int id){
    int posicao = 0;
    fseek(arquivo, 0, SEEK_SET);
    TDepartamento dp;
    while (fread(&dp, sizeof(TDepartamento), 1, arquivo) == 1)
    {
        if(dp.id == id)
            return posicao;
        posicao++;
    }

    return -1;
}

void listarDepartamentos(FILE *arquivo){
    fseek(arquivo, 0, SEEK_SET);
    TDepartamento dp;
    printf("\n\nDepartamentos: \n");
    while(fread(&dp, sizeof(TDepartamento), 1, arquivo) == 1){
        printf("\nID: %i\nNome: %s", dp.id, dp.nome);
    }
}

int cadastrarDepartamento(FILE *arquivo){
    fseek(arquivo, 0, SEEK_SET);
    TDepartamento dp;

    do{
    printf("\nInforme o ID do departamento: ");
    setbuf(stdin, NULL);
    scanf("%d", &dp.id);
    setbuf(stdin, NULL);
    if(pesquisarDepartamento(arquivo, dp.id) != -1)
        printf("\nO ID informado ja existe!");
    }while(pesquisarDepartamento(arquivo, dp.id) != -1);

    setbuf(stdin, NULL);
    printf("\nInforme o nome do departamento: ");
    fgets(dp.nome, 20, stdin);
    setbuf(stdin, NULL);
    fwrite(&dp, sizeof(TDepartamento), 1, arquivo);

    return 1;
}

int alterarDepartamento(FILE *arquivo, int id){
    int posicao;
    TDepartamento dp;
    posicao = pesquisarDepartamento(arquivo, id);
    if(posicao == -1){
        printf("O ID informado n�o pertence a nenhum departamento!");
        return -1;
    }
    fseek(arquivo, posicao * sizeof(TDepartamento), SEEK_SET);
    fread(&dp, sizeof(TDepartamento), 1, arquivo);
    printf("\nID: %d\t\tNome: %s", dp.id, dp.nome);
    fseek(arquivo, posicao * sizeof(TDepartamento), SEEK_SET);

    setbuf(stdin, NULL);
    printf("\nInforme o nome do departamento: ");
    fgets(dp.nome, 20, stdin);
    setbuf(stdin, NULL);
    fwrite(&dp, sizeof(TDepartamento), 1, arquivo);

    listarDepartamentos(arquivo);
    return 1;
}


