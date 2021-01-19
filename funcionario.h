#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

#include <stdio.h>
#include "departamentos.h"

typedef struct
{
    int id;
    char nome[20];
    TDepartamento departamento;
}TFuncionario;

int pesquisarFuncionario(FILE*, int);
int cadastrarFuncionario(FILE*, FILE*);
void listarFuncionarios(FILE*);
int alterarFuncionario(FILE*, FILE*, int);

#endif // FUNCIONARIO_H_INCLUDED
