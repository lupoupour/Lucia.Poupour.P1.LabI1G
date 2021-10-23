#include <stdio.h>
#include <stdlib.h>
#include "micro.h"
#include "funciones.h"
#include "empresa.h"
#include "tipo.h"
#define TAM_MICRO 10
#define TAM_EMP 4
#define TAM_TIP 4
#define NADA 0
#define ALTA 1

int main()
{
    eMicro listaMicro[TAM_MICRO];
    eEmpresa listaEmpresa[TAM_EMP];
    int nextIdMicro = 1;
    int nextIdEmp = 1000;
    int nextIdTipo = 5000;
    //int nextIdArcEstrucDos = 1;
    char seguir = 's';
    int orden = -1;
    int flag = NADA;

    eEmpresa listaEmpresas[TAM_EMP] =
    {
        { 1000, "Plusmar" },
        { 1001, "Flecha Bus" },
        { 1002, "Tas" },
        { 1003, "El Rapido" }
    };

    eTipo listaTipos[TAM_TIP] =
    {
        { 5000, "Comun" },
        { 5001, "CocheCama" },
        { 5002, "Doble" },
        { 5003, "VIP" }
    };

    if(inicializarMicro(listaMicro, TAM_MICRO))
    {
        printf("Posiciones inicializadas y listas para operar!\n");
    }
    else
    {
        printf("Problema al inicializar posiciones!\n");
    }

     if(inicializarEmpresa(listaEmpresa, TAM_EMP))
    {
        printf("Posiciones inicializadas y listas para operar!\n");
    }
    else
    {
        printf("Problema al inicializar posiciones!\n");
    }


    do
    {
        switch(menu())
        {
        case 'A':
        if(altaMicro(listaMicro, TAM_MICRO, &nextIdMicro, listaEmpresa, TAM_EMP, nextIdEmp))
        {
            printf("Alta exitosa!");
            flag = ALTA;
        }
        else
        {
            printf("No se pudo realizar el alta.");
        }
        break;
        case 'B':
            if(flag == ALTA)
            {
                modificarMicro(listaMicro, TAM_MICRO, nextIdMicro, listaEmpresas, listaTipos, TAM_TIP, nextIdTipo);
            }
            else{
                printf("No puede modificar sin primero realizar el alta.");
            }

        break;
       case 'C':
           if(flag == ALTA)
           {
               if(bajaMicro(listaMicro, TAM_MICRO))
                {
                    printf("Baja exitosa!\n");
                }
                else
                {
                    printf("No se pudo realizar la baja.\n");
                }
           }
           else{
            printf("No puede dar de baja sin primero realizar el alta.");
           }

            break;
        case 'D':
        ordenarMicros(listaMicro, TAM_MICRO, orden, listaEmpresa);
        mostrarMicros(listaMicro, TAM_MICRO);
        break;
        case 'E':
        mostrarEmpresas(listaEmpresas, TAM_EMP);
        break;
        case 'F':
        mostrarTipos(listaTipos, TAM_TIP);
        break;
        case 'G':
            printf("Selecciono salir. Desea calcelar la salida?:\n ");
            fflush(stdin); //SIEMPRE CON CHARS
            scanf("%c", &seguir);
        break;
        default:
            printf("Opcion invalida.");
        }

        system("pause");

    }while(seguir == 's');

    return 0;
}
