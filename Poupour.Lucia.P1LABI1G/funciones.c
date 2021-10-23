#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

char menu()
{
    char opcion;

    system("cls");
    printf("A - Alta micro.\n");
    printf("B - Modificar micro.\n");
    printf("C - Baja micro.\n");
    printf("D - Listar micros.\n");
    printf("E - Listar empresas.\n");
    printf("F - Listar tipos.\n");
    printf("G - SALIR.\n");
   /* printf("H - Opcion 8.\n");
    printf("I - Opcion 8.\n");
    printf("J - Salir.\n");*/
    printf("Ingrese la opcion que desea: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

int menuModificar()
{
    int opcion;

    system("cls");
    printf("1 - Modificar capacidad.\n");
    printf("2 - Modificar tipo.\n");
    printf("10 - Salir.\n");
    printf("Ingrese la opcion que desea: ");
    scanf("%d", &opcion);

    return opcion;
}


