#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "micro.h"


int altaEmpresa(eEmpresa listaEmpresa[], int tamEstruc, int* idEmpresa)
{
    int todoOk = 0;
    eEmpresa auxEmpresa;
    int indice;

    if(listaEmpresa != NULL && tamEstruc > 0 && idEmpresa != NULL)
    {
        indice = buscarLugarLibreEmpresa(listaEmpresa, tamEstruc); //debo igualar mi indice al primer indice que encuentre libre mi programa, ah� se dar� de alta mi persona

        if(indice == -1)
        {
            printf("No se encontr� un lugar libre y no se puede dar de alta.\n");
        }
        else
        {
            auxEmpresa.idEmpresa = *idEmpresa;
            (*idEmpresa)++;

            printf("Ingrese la descripcion: \n");
            fflush(stdin);
            gets(auxEmpresa.descripcion);

            auxEmpresa.isEmpty = 0;
            listaEmpresa[indice] = auxEmpresa;


            todoOk = 1;
        }

    }

    return todoOk;
}

int inicializarEmpresa(eEmpresa listaEmpresa[], int tamEstruc)
{
    int todoOk = 0;

    if(listaEmpresa != NULL && tamEstruc > 0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            listaEmpresa[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarLugarLibreEmpresa(eEmpresa listaEmpresa[], int tamEstruc)
{
    int indice = -1;

    if(listaEmpresa != NULL && tamEstruc >0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            if(listaEmpresa[i].isEmpty == 1)
            {
                indice = i;
                break; //para que no siga buscando una posici�n libre en el array cuando ya la encontr�
            }
        }
    }
    return indice;
}

void mostrarEmpresa(eEmpresa p)
{
    printf("%d    %s   \n",
           p.idEmpresa,
          p.descripcion
          );
}

int mostrarEmpresas (eEmpresa listaEmpresa[], int tamEstruc)
{
    int todoOk = 0;
    int flag = 1;

    if(listaEmpresa != NULL && tamEstruc > 0)
    {

        system("cls");
        printf("        LISTADO DE EMPRESAS\n\n");
        printf("------------------------------------------------\n\n");
        printf("ID MICRO ID EMPRESA   ID TIPO   CAPACIDAD \n");
        printf("------------------------------------------------\n\n");

        for(int i = 0; i < tamEstruc; i++)
        {
            if(!listaEmpresa[i].isEmpty)  //para mostrar algo, primero tengo que validar que no est� vac�a la posici�n
            {
                mostrarEmpresa(listaEmpresa[i]); //si la posici�n no est� vac�a, muestro ese registro y pongo la bandera en 0
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


int buscarEmpresaPorId(eEmpresa listaEmpresa[], int tamEmpr, int idEmpresa)
{
    int indice = -1;

    if(listaEmpresa != NULL && tamEmpr >0)
    {
        for(int i = 0; i < tamEmpr; i++)
        {
            if(listaEmpresa[i].isEmpty == 0 && listaEmpresa[i].idEmpresa == idEmpresa) //busca una posicion en la que hay informacion y dice que el id pasado por parametro es igual al que tiene un salon en una posicion determinada
            {
                indice = i;
                break; //para que no siga buscando una posici�n libre en el array cuando ya la encontr�
            }
        }
    }
    return indice;
}

int validarIdEmpresa(eEmpresa listaEmpresa[], int tamEmp, int idEmpresa)
{
    int todoOk = 0;
    int indice;

    if(listaEmpresa != NULL && tamEmp > 0)
    {
        indice = buscarEmpresaPorId(listaEmpresa, tamEmp, idEmpresa);

        if(indice == -1)
        {
            printf("No existe el Id del registro.\n");
        }
        else
        {
            todoOk = 1;
        }
    }



    return todoOk;
}
