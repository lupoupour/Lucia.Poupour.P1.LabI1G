#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int inicializarFecha(eFecha listaFecha[], int tamEstruc)
{
    int todoOk = 0;

    if(listaFecha != NULL && tamEstruc > 0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            listaFecha[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}



int buscarLugarLibreFecha(eFecha listaFecha[], int tamEstruc)
{
    int indice = -1;

    if(listaFecha != NULL && tamEstruc >0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            if(listaFecha[i].isEmpty == 1)
            {
                indice = i;
                break; //para que no siga buscando una posici�n libre en el array cuando ya la encontr�
            }
        }
    }
    return indice;
}

int altaFecha(eFecha listaFecha[], int tamEstruc, int* idFecha)
{
    int todoOk = 0;
    eFecha auxFecha;
    int indice;

    if(listaFecha != NULL && tamEstruc > 0 && idFecha != NULL)
    {
        indice = buscarLugarLibreFecha(listaFecha, tamEstruc); //debo igualar mi indice al primer indice que encuentre libre mi programa, ah� se dar� de alta mi persona

        if(indice == -1)
        {
            printf("No se encontr� un lugar libre y no se puede dar de alta una fecha.\n");
        }
        else
        {
            auxFecha.idFecha = *idFecha;
            (*idFecha)++;

            printf("Ingrese dia: \n");
            scanf("%d", &auxFecha.dia);

            printf("Ingrese mes: \n");
            scanf("%d", &auxFecha.mes);

            printf("Ingrese anio: \n");
            scanf("%d", &auxFecha.anio);

            auxFecha.isEmpty = 0;
            listaFecha[indice] = auxFecha;


            todoOk = 1;
        }

    }

    return todoOk;
}

void mostrarFecha(eFecha p)
{
    printf("%d  /  %d  /  %d   \n",
           p.dia,
          p.mes,
          p.anio
          );
}

int mostrarFechas(eFecha listaFecha[], int tamEstruc)
{
    int todoOk = 0;
    int flag = 1;

    if(listaFecha != NULL && tamEstruc > 0)
    {

        system("cls");
        printf("        LISTADO DE FECHAS\n\n");
        printf("------------------------------------------------\n\n");
        printf("------------------------------------------------\n\n");

        for(int i = 0; i < tamEstruc; i++)
        {
            if(!listaFecha[i].isEmpty)  //para mostrar algo, primero tengo que validar que no est� vac�a la posici�n
            {
                mostrarFecha(listaFecha[i]); //si la posici�n no est� vac�a, muestro ese registro y pongo la bandera en 0
                flag = 0;                    //para despues poder decir qu� pasa si nunca entr� al if(o sea que no hubo rgistros para mostrar)
            }

        }

        if(flag == 1) //es decir que nunca entr� al anterior if, o sea que no encontr� nada con datos.
        {
            printf("No hay registros para mostrar.\n");
        }
        todoOk = 1;
    }

    return todoOk;
}
