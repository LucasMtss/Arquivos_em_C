#include "arquivos.h"
#include "ferramentas.h"

int main(){
    FILE *arquivoDepartamentos, *arquivoFuncionarios;

    arquivoDepartamentos = fopen("departamentos.dat", "rb+");
    if(!arquivoDepartamentos)
        arquivoDepartamentos = fopen("departamentos.dat", "wb+");
    if(!arquivoDepartamentos)
        printf("Erro ao abrir o arquivo!");

    arquivoFuncionarios = fopen("funcionarios.dat", "rb+");
    if(!arquivoFuncionarios)
        arquivoFuncionarios = fopen("funcionarios.dat", "wb+");
    if(!arquivoFuncionarios)
        printf("Erro ao abrir o arquivo!");

    menu(arquivoDepartamentos, arquivoFuncionarios);
    fclose(arquivoDepartamentos);
    fclose(arquivoFuncionarios);

    return 0;
}
