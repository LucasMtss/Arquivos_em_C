#include "funcionario.h"
#include "departamentos.c"
#include <string.h>

int pesquisarFuncionario(FILE *arquivo, int id){
     int posicao = 0;
    fseek(arquivo, 0, SEEK_SET);
    TFuncionario func;
    while (fread(&func, sizeof(TFuncionario), 1, arquivo) == 1)
    {
        if(func.id == id)
            return posicao;
        posicao++;
    }

    return -1;
}

void listarFuncionarios(FILE *arquivo){
    fseek(arquivo, 0, SEEK_SET);
    TFuncionario func;
    printf("\n\nFuncionários: \n");
    while(fread(&func, sizeof(TFuncionario), 1, arquivo) == 1){
        printf("\nID: %i\nNome: %s\nID departamento: %d\n Nome departamento: %s", func.id, func.nome, func.departamento.id, func.departamento.nome);
    }
}
int alterarFuncionario(FILE *arquivoFuncionarios, FILE* arquivoDepartamentos, int idFuncionario){
    int posicaoDepartamento, posicaoFuncionario;
    TFuncionario func;
    TDepartamento dp;
    posicaoFuncionario = pesquisarFuncionario(arquivoFuncionarios, idFuncionario);
    if(posicaoFuncionario == -1){
        printf("O ID informado não pertence a nenhum funcionario!");
        return -1;
    }
    fseek(arquivoFuncionarios, posicaoFuncionario * sizeof(TFuncionario), SEEK_SET);
    fread(&func, sizeof(TFuncionario), 1, arquivoFuncionarios);
    printf("\nID: %d\t\tNome: %s\nID departamento: %d\t\tNome departamento: %s", func.id, func.nome, func.departamento.id, func.departamento.nome);

    fseek(arquivoFuncionarios, posicaoFuncionario * sizeof(TFuncionario), SEEK_SET);

    setbuf(stdin, NULL);
    printf("\nInforme o nome do funcionario: ");
    fgets(dp.nome, 20, stdin);
    setbuf(stdin, NULL);

    do{
        printf("\nInfome o ID do departamento do funcionário: ");
        scanf("%d", &func.departamento.id);
        if(pesquisarDepartamento(arquivoDepartamentos, func.departamento.id) == -1)
            printf("\nO departamento informado não existe!");
        else{
            posicaoDepartamento = pesquisarDepartamento(arquivoDepartamentos, func.departamento.id);
            fseek(arquivoDepartamentos, posicaoDepartamento * sizeof(TDepartamento), SEEK_SET);
            fread(&dp, sizeof(TDepartamento), 1, arquivoDepartamentos);
            strcpy(func.departamento.nome, dp.nome);
        }
    }while(pesquisarDepartamento(arquivoDepartamentos, func.departamento.id) == -1);


    fwrite(&func, sizeof(TFuncionario), 1, arquivoFuncionarios);

    listarFuncionarios(arquivoFuncionarios);
    return 1;
}

int cadastrarFuncionario(FILE *arquivoFuncionarios, FILE *arquivoDepartamentos){
    fseek(arquivoFuncionarios, 0, SEEK_SET);
    TFuncionario func;
    TDepartamento dp;
    int posicaoDepartamento;

    do{
    printf("\nInforme o ID do funcionario: ");
    setbuf(stdin, NULL);
    scanf("%d", &func.id);
    setbuf(stdin, NULL);
    if(pesquisarFuncionario(arquivoFuncionarios, func.id) != -1)
        printf("\nO ID informado ja existe!");
    }while(pesquisarFuncionario(arquivoFuncionarios, func.id) != -1);

    setbuf(stdin, NULL);
    printf("\nInforme o nome do funcionario: ");
    fgets(func.nome, 20, stdin);
    setbuf(stdin, NULL);

    listarDepartamentos(arquivoDepartamentos);
    do{
        printf("\nInfome o ID do departamento do funcionário: ");
        scanf("%d", &func.departamento.id);
        if(pesquisarDepartamento(arquivoDepartamentos, func.departamento.id) == -1)
            printf("\nO departamento informado não existe!");
        else{
            posicaoDepartamento = pesquisarDepartamento(arquivoDepartamentos, func.departamento.id);
            fseek(arquivoDepartamentos, posicaoDepartamento * sizeof(TDepartamento), SEEK_SET);
            fread(&dp, sizeof(TDepartamento), 1, arquivoDepartamentos);
            strcpy(func.departamento.nome, dp.nome);
        }
    }while(pesquisarDepartamento(arquivoDepartamentos, func.departamento.id) == -1);

    fwrite(&func, sizeof(TFuncionario), 1, arquivoFuncionarios);
    return 1;
}


