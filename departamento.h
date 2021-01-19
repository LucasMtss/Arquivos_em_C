#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED

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

#endif // DEPARTAMENTO_H_INCLUDED
