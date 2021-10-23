#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED
#include "empresa.h"
#include "tipo.h"

typedef struct
{
    int idMicro;
    int capacidad;
    int isEmpty;
    int idEmpresa;
    int idTipo;
}eMicro;

#endif // MICRO_H_INCLUDED

int altaMicro(eMicro listaMicro[], int tamEstruc, int* idMicro, eEmpresa listaEmpresa[], int tamEmp, int idEmp);
int inicializarMicro(eMicro listaMicro[], int tamEstruc);
int buscarLugarLibreMicro(eMicro listaMicro[], int tamEstruc);
void mostrarMicro(eMicro p);
int mostrarMicros(eMicro listaMicro[], int tamEstruc);
int buscarMicroPorId(eMicro listaMicro[], int tamEstruc, int idMicro);
int modificarMicro(eMicro listaMicro[], int tamEstruc, int idMicro, eEmpresa listaEmpresa[], eTipo listaTipo[], int tamTipo, int idTipo);
int modificarCapacidad(eMicro listaMicro[], int tamEstruc, int idMicro);
int bajaMicro(eMicro listaMicro[], int tamEstruc);
int ordenarMicros(eMicro listaMicro[], int tamEstruc, int orden, eEmpresa listaEmpresa[]);
