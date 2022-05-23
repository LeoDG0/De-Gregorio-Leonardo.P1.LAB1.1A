#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"




int buscarTipo (eTipo vec[],int tam, int id, int* pIndice)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndice != NULL )
    {
        *pIndice= - 1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].idTipo == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;

}




int validarTipo(eTipo vec[], int tam, int id){
    int auxVal=0;
    int indice;

    buscarTipo(vec, tam, id , &indice);

    if (indice != -1){
        auxVal = 1;
    }

    return auxVal;
}


int listarTipo(eTipo vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("   *** LISTADO DE TIPOS *** \n\n");
        printf("  ID                 DESCRIPCION            \n");
        printf("------------------------------------------------\n");
        for(int i=0; i < tam ;i++)
        {
            printf("  %4d             %10s          \n", vec[i].idTipo, vec[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}


int cargarNombreTipo(eTipo vec[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarTipo(vec, tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {

        strcpy(descripcion, vec[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}





