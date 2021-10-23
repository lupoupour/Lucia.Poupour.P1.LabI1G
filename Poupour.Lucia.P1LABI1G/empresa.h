#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED
typedef struct
{
    int idEmpresa;
    char descripcion[20];
    int isEmpty;
}eEmpresa;


#endif // EMPRESA_H_INCLUDED

int altaEmpresa(eEmpresa listaEmpresa[], int tamEstruc, int* idEmpresa);
int inicializarEmpresa(eEmpresa listaEmpresa[], int tamEstruc);
int buscarLugarLibreEmpresa(eEmpresa listaEmpresa[], int tamEstruc);
void mostrarEmpresa(eEmpresa p);
int mostrarEmpresas (eEmpresa listaEmpresa[], int tamEstruc);
int buscarEmpresaPorId(eEmpresa listaEmpresa[], int tamEstruc, int idEmpresa);
int validarIdEmpresa(eEmpresa listaEmpresa[], int tamEmp, int idEmpresa);
