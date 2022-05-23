#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "cliente.h"
#include "mascotas.h"



int cargarNombreCliente(eCliente vec[], int tamcl, int id, char nombre[])
{
    int todoOk = 0;
    int indice;

    buscarCliente(vec,tamcl, id, &indice);

    if(nombre != NULL && indice != -1)
    {

        strcpy(nombre, vec[indice].nombre);
        todoOk = 1;
    }
    return todoOk;
}



int buscarCliente(eCliente vec[],int tamcl, int id, int* pIndice)
{
    int todoOk = 0;

    if(vec != NULL && tamcl > 0 && pIndice != NULL )
    {
        *pIndice= - 1;
        for(int i=0; i < tamcl; i++)
        {
            if(vec[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;

}


int listarCliente(eCliente vec[], int tamcl)
{
    int todoOk = 0;

    if(vec != NULL && tamcl > 0)
    {
        system("cls");
        printf("   *** LISTADO DE CLIENTES *** \n\n");
        printf("  ID                 DESCRIPCION            \n\n");
        for(int i=0; i < tamcl ;i++)
        {
            printf("  %4d             %10s          \n", vec[i].id, vec[i].nombre);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarCliente(eCliente vec[], int tamcl, int id){
    int auxVal=0;
    int indice;

    buscarCliente(vec, tamcl, id , &indice);

    if (indice != -1){
        auxVal = 1;
    }

    return auxVal;
}








