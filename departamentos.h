#ifndef DEPARTAMENTOS_H_INCLUDED
#define DEPARTAMENTOS_H_INCLUDED

#include <stdio.h>

typedef struct
{
    int id;
    char nome[20];
}TDepartamento;

int pesquisarDepartamento(FILE*, int);
int cadastrarDepartamento(FILE*);
void listarDepartamentos(FILE*);
int alterarDepartamento(FILE*, int);

#endif // DEPARTAMENTOS_H_INCLUDED
