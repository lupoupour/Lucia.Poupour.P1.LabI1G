#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct
{
    int idTipo;
    char descripcion[21];
    int isEmpty;
}eTipo;


#endif // TIPO_H_INCLUDED
void mostrarTipo(eTipo p);
int mostrarTipos(eTipo listaTipo[], int tamEstruc);
int buscarTipoPorId(eTipo listaTipo[], int tamTipo, int idTipo);
int inicializarTipo(eTipo listaTipo[], int tamEstruc);
int modificarTipo(eTipo listaTipo[], int tamTipo, int id);
