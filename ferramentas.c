#include "ferramentas.h"
#include "departamentos.h"
#include "funcionario.h"
#include <stdio.h>

void menu(FILE *arquivoDepartamentos, FILE *arquivoFuncionarios) {
    int opcao=0, idDepartamento, idFuncionario;
    do{
        printf("\n\t\tMenu\t\t");
        printf("\n1-Cadastrar departamento\n2-Listar departamentos\n3-Alterar departamento");
        printf("\n4-Cadastrar funcionario\n5-Listar funcionarios\n6-Alterar funcionario");
        printf("\n7-Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarDepartamento(arquivoDepartamentos);
            break;

        case 2:
            listarDepartamentos(arquivoDepartamentos);
            break;
        case 3:
            listarDepartamentos(arquivoDepartamentos);
            printf("\nInforme o ID do departamento que deseja alterar: ");
            scanf("%d", &idDepartamento);
            alterarDepartamento(arquivoDepartamentos, idDepartamento);
            break;
        case 4:
            cadastrarFuncionario(arquivoFuncionarios ,arquivoDepartamentos);
            break;
        case 5:
            listarFuncionarios(arquivoFuncionarios);
            break;
        case 6:
            listarFuncionarios(arquivoFuncionarios);
            printf("\nInforme o ID do funcionario que deseja alterar: ");
            scanf("%d", &idFuncionario);
            alterarFuncionario(arquivoFuncionarios, arquivoDepartamentos, idFuncionario);
        case 7:
            break;

        default:
            printf("\nOpcao invalida!");

        }
    }while(opcao != 7);

}
