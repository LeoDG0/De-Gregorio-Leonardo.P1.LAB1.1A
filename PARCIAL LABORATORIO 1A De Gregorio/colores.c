#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colores.h"


int listarColor(eColor colores[], int tam)
{
    int todoOk = 0;

    if(colores != NULL && tam > 0)
    {
        system("cls");


        printf("   *** LISTADO DE COLORES *** \n\n");
        printf("  ID           DESCRIPCION            \n");
        printf("---------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %4d         %10s              \n", colores[i].id, colores[i].descripcion);
        }


        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int cargarNombreColor(eColor colores[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarColor(colores,tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {

        strcpy(descripcion, colores[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}


int buscarColor (eColor colores[],int tam, int id, int* pIndice)
{
    int todoOk = 0;

    if(colores != NULL && tam > 0 && pIndice != NULL )
    {
        *pIndice= - 1;
        for(int i=0; i < tam; i++)
        {
            if(colores[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;

}

int validarColor(eColor  colores[], int tam, int id){

    int esValido=0;
    int indice;

    buscarColor(colores, tam, id , &indice);

    if (indice != -1){
        esValido = 1;
    }

    return esValido;
}

