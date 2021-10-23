#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
//ordenar micros por empresa y capacidad
typedef struct
{
    int dia;
    int mes;
    int anio;
    int isEmpty;
    int idFecha;
}eFecha;

#endif // FECHA_H_INCLUDED

int inicializarFecha(eFecha listaFecha[], int tamEstruc);
int buscarLugarLibreFecha(eFecha listaFecha[], int tamEstruc);
int altaFecha(eFecha listaFecha[], int tamEstruc, int* idFecha);
void mostrarFecha(eFecha p);
int mostrarFechas(eFecha listaFecha[], int tamEstruc);
