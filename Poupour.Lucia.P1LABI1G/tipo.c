#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "tipo.h"


void mostrarTipo(eTipo p)
{
    printf("%d    %s    \n",
           p.idTipo,
          p.descripcion
          );
}

int mostrarTipos(eTipo listaTipo[], int tamEstruc)
{
    int todoOk = 0;
    int flag = 1;

    if(listaTipo != NULL && tamEstruc > 0)
    {

        system("cls");
        printf("        LISTADO DE TIPOS\n\n");
        printf("------------------------------------------------\n\n");
        printf("ID DESCRIPCION \n");
        printf("------------------------------------------------\n\n");

        for(int i = 0; i < tamEstruc; i++)
        {
            if(!listaTipo[i].isEmpty)  //para mostrar algo, primero tengo que validar que no esté vacía la posición
            {
                mostrarTipo(listaTipo[i]); //si la posición no está vacía, muestro ese registro y pongo la bandera en 0
                flag = 0;                    //para despues poder decir qué pasa si nunca entró al if(o sea que no hubo rgistros para mostrar)
            }

        }

        if(flag == 1) //es decir que nunca entró al anterior if, o sea que no encontró nada con datos.
        {
            printf("No hay registros para mostrar.\n");
        }
        todoOk = 1;
    }

    return todoOk;
}

int modificarTipo(eTipo listaTipo[], int tamTipo, int id)
{
    int todoOk = 0;
    eTipo auxTipo;
    int j;

    if(listaTipo != NULL && tamTipo > 0)
    {
        j = buscarTipoPorId(listaTipo, tamTipo, id);

        mostrarTipos(listaTipo, tamTipo);
        printf("Ingrese nuevo nombre del tipo: ");
        fflush(stdin);
        gets(auxTipo.descripcion);

        strcpy(listaTipo[j].descripcion, auxTipo.descripcion);

        todoOk = 1;

    }



    return todoOk;
}

int inicializarTipo(eTipo listaTipo[], int tamEstruc)
{
    int todoOk = 0;

    if(listaTipo != NULL && tamEstruc > 0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            listaTipo[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}

int buscarTipoPorId(eTipo listaTipo[], int tamTipo, int idTipo)
{
    int indice = -1;

    if(listaTipo != NULL && tamTipo >0)
    {
        for(int i = 0; i < tamTipo; i++)
        {
            if(listaTipo[i].isEmpty == 0 && listaTipo[i].idTipo == idTipo) //busca una posicion en la que hay informacion y dice que el id pasado por parametro es igual al que tiene un salon en una posicion determinada
            {
                indice = i;
                break; //para que no siga buscando una posición libre en el array cuando ya la encontró
            }
        }
    }
    return indice;
}
