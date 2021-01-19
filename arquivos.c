#include "arquivos.h"


void abrirArquivo(FILE *arquivo){
    arquivo = fopen("departamentos.dat", "r+");
    if(!arquivo)
        arquivo = fopen("departamentos.dat", "w+");
    if(!arquivo)
        printf("Erro ao abrir o arquivo!");
}
