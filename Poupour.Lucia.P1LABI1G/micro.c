#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "micro.h"
#include "empresa.h"
#include "tipo.h"


int altaMicro(eMicro listaMicro[], int tamEstruc, int* idMicro, eEmpresa listaEmpresa[], int tamEmp, int idEmp)
{
    int todoOk = 0;
    eMicro auxMicro;
    int indice;

    if(listaMicro != NULL && tamEstruc > 0 && idMicro != NULL)
    {
        indice = buscarLugarLibreMicro(listaMicro, tamEstruc); //debo igualar mi indice al primer indice que encuentre libre mi programa, ahí se dará de alta mi persona

        if(indice == -1)
        {
            printf("No se encontro un lugar libre y no se puede dar de alta un micro.\n");
        }
        else
        {
            auxMicro.idMicro = *idMicro;
            (*idMicro)++;

            printf("Ingrese id de la empresa a la que pertenece el micro: ");
            scanf("%d", &auxMicro.idEmpresa);

            while(auxMicro.idEmpresa != 1000 && auxMicro.idEmpresa != 1001 && auxMicro.idEmpresa != 1002 && auxMicro.idEmpresa != 1003)
            {
                printf("Error. Ingrese id de la empresa a la que pertenece el micro nuevamente: ");
                scanf("%d", &auxMicro.idEmpresa);
            }

            printf("Ingrese el id del tipo de micro: \n");
            scanf("%d", &auxMicro.idTipo);

            while(auxMicro.idTipo != 5000 && auxMicro.idTipo != 5001 && auxMicro.idTipo != 5002 && auxMicro.idTipo != 5003)
            {
                printf("Error. Ingrese id del tipo del micro nuevamente: ");
                scanf("%d", &auxMicro.idTipo);
            }


            printf("Ingrese capacidad del micro: \n");
            scanf("%d", &auxMicro.capacidad);

            while(auxMicro.capacidad < 1 || auxMicro.capacidad > 50)
            {
                printf("Error. Ingrese la capacidad del micro nuevamente: ");
                scanf("%d", &auxMicro.capacidad);
            }

            auxMicro.isEmpty = 0;
            listaMicro[indice] = auxMicro;


            todoOk = 1;
        }

    }

    return todoOk;
}

int inicializarMicro(eMicro listaMicro[], int tamEstruc)
{
    int todoOk = 0;

    if(listaMicro != NULL && tamEstruc > 0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            listaMicro[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarLugarLibreMicro(eMicro listaMicro[], int tamEstruc)
{
    int indice = -1;

    if(listaMicro != NULL && tamEstruc >0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            if(listaMicro[i].isEmpty == 1)
            {
                indice = i;
                break; //para que no siga buscando una posición libre en el array cuando ya la encontró
            }
        }
    }
    return indice;
}

void mostrarMicro(eMicro p)
{
    printf("%d    %d    %d  %d\n",
           p.idMicro,
          p.idEmpresa,
          p.idTipo,
          p.capacidad
          );
}

int mostrarMicros(eMicro listaMicro[], int tamEstruc)
{
    int todoOk = 0;
    int flag = 1;

    if(listaMicro != NULL && tamEstruc > 0)
    {

        system("cls");
        printf("        LISTADO DE MICROS\n\n");
        printf("------------------------------------------------\n\n");
        printf("ID MICRO ID EMPRESA   ID TIPO   CAPACIDAD \n");
        printf("------------------------------------------------\n\n");

        for(int i = 0; i < tamEstruc; i++)
        {
            if(!listaMicro[i].isEmpty)  //para mostrar algo, primero tengo que validar que no esté vacía la posición
            {
                mostrarMicro(listaMicro[i]); //si la posición no está vacía, muestro ese registro y pongo la bandera en 0
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


int buscarMicroPorId(eMicro listaMicro[], int tamEstruc, int idMicro)
{
    int indice = -1;

    if(listaMicro != NULL && tamEstruc >0)
    {
        for(int i = 0; i < tamEstruc; i++)
        {
            if(listaMicro[i].isEmpty == 0 && listaMicro[i].idMicro == idMicro) //busca una posicion en la que hay informacion y dice que el id pasado por parametro es igual al que tiene un salon en una posicion determinada
            {
                indice = i;
                break; //para que no siga buscando una posición libre en el array cuando ya la encontró
            }
        }
    }
    return indice;
}

int modificarMicro(eMicro listaMicro[], int tamEstruc, int idMicro, eEmpresa listaEmpresa[], eTipo listaTipo[], int tamTipo, int idTipo)
{
    int todoOk = 0;
    int indice;

    if(listaMicro != NULL && tamEstruc > 0)
    {
        system("cls");
        mostrarMicros(listaMicro, tamEstruc);
        printf("Ingrese el id del micro que desea modificar: ");
        scanf("%d", &idMicro);

        indice = buscarMicroPorId(listaMicro, tamEstruc, idMicro);

        if(indice == -1)
        {
            printf("No hay registros para modificar.");
        }
        else
        {
            switch(menuModificar())
            {
            case 1:
                modificarCapacidad(listaMicro, tamEstruc, idMicro);
                break;
            case 2:
                modificarTipo(listaTipo, tamTipo, idTipo);
                break;
            }

            todoOk = 1;
        }

    }


    return todoOk;
}

int modificarCapacidad(eMicro listaMicro[], int tamEstruc, int idMicro)
{
    int todoOk = 0;
    eMicro auxMicro;
    int j;

    if(listaMicro != NULL && tamEstruc > 0)
    {
        j = buscarMicroPorId(listaMicro, tamEstruc, idMicro);

        printf("Ingrese nueva capacidad: ");
        scanf("%d", &auxMicro.capacidad);

        listaMicro[j].capacidad = auxMicro.capacidad;
        todoOk = 1;

    }


    return todoOk;
}

int bajaMicro(eMicro listaMicro[], int tamEstruc)
{
    int todoOk = 0;
    int idMicr;
    char confirma = 'n';
    int i;
    int j;

    if(listaMicro != NULL && tamEstruc > 0)
    {
        system("cls");
        printf("        LISTADO DE REGISTROS\n\n");
        printf("------------------------------------------------\n\n");
        printf("ID MICRO ID EMPRESA   ID TIPO   CAPACIDAD \n");
        printf("------------------------------------------------\n\n");
        mostrarMicros(listaMicro, tamEstruc); //baja registro debe mostrar los registros para que se vea el id
        printf("Ingrese el id del registro que desea dar de baja: ");//luego pedir el ingreso del id
        scanf("%d", &idMicr);//y guardarlo en una variable id

        i = buscarMicroPorId(listaMicro, tamEstruc, idMicr); //debe igualar una variable indice a el indice que se obtiene con buscarRegistroPorId


        if(i == -1)
        {
            printf("No existe este registro para darlo de baja.\n"); //segun lo que me devuelva la anterior, si es -1 no existe id
        }

       else
       {
            mostrarMicro(listaMicro[i]); //si no es -1 y existe el id, lo muestro
            printf("Desea dar de baja este registro?: ");
            fflush(stdin);
            scanf("%c", &confirma); //pregunto si quiere darlo de baja y guardo la rta en una variable char

            if(confirma == 's')
       {
           listaMicro[i].isEmpty = 1; //si se da de baja, seteo mi campo isEmpty en 1, o sea vacío y todoOk = 1 xq pude dar la baja
           todoOk = 1;
       }
       else{
        printf("Baja cancelada por el usuario.\n "); //si no confirmo la baja, se cancela
       }
       }

    }
  return todoOk;
}

//ordenar por empresa y capacidad
int ordenarMicros(eMicro listaMicro[], int tamEstruc, int orden, eEmpresa listaEmpresa[])
{
    int todoOk = 0;
    eMicro auxMicro;

    if(listaMicro != NULL && tamEstruc > 0)
    {
        int valor;
        printf("Ingrese 1 si desea ordenar los registros por capacidad de manera ascendente y 0 si desea ordenarlos por capacidad de manera descendente: ");
        scanf("%d", &orden);

        if(orden == 1)
        {
            for (int i = 0; i < tamEstruc-1; i++)
            {
                for (int j = i+1; j < tamEstruc; j++)
                {

                    valor = stricmp(listaEmpresa[i].descripcion,listaEmpresa[j].descripcion);
                    if(listaMicro[i].capacidad > listaMicro[j].capacidad || (listaMicro[i].capacidad == listaMicro[j].capacidad && valor > 0))
                    {
                        auxMicro = listaMicro[i];
                        listaMicro[i] = listaMicro[j];
                        listaMicro[j] = auxMicro;
                    }

                }
            }
            todoOk = 0;
        }
        else if(orden == 0)
        {
            for (int i = 0; i < tamEstruc-1; i++)
            {
                for (int j = i+1; j < tamEstruc; j++)
                {
                    valor = stricmp(listaEmpresa[i].descripcion,listaEmpresa[j].descripcion);
                    if(listaMicro[i].capacidad < listaMicro[j].capacidad || (listaMicro[i].capacidad == listaMicro[j].capacidad && valor > 0))
                    {
                        auxMicro = listaMicro[i];
                        listaMicro[i] = listaMicro[j];
                        listaMicro[j] = auxMicro;
                    }
                }


            }
            todoOk = 0;
        }

    }
    return todoOk;
}
