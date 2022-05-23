#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"


int inicializarTrabajo(eTrabajo vec[], int tam)
{
int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
{
int todoOk = 0;

    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }


    return todoOk;
}




int altaTrabajo(eTrabajo trabajo[], int tamTr, eMascota mascota[], int tamM, eTipo tipo[], int tamT, eColor color[], int tamC, eServicio serv[], int tamS, eCliente cliente[], int tamcl, int* pIdTrabajo){

int todoOk = 0;
int indice;
eTrabajo trabajoN;
eFecha fecha;

    if(trabajo != NULL && mascota != NULL && tipo != NULL && color != NULL && serv != NULL && pIdTrabajo != NULL && tamTr> 0 && tamM > 0 && tamT > 0 && tamC > 0&& tamS > 0 && tamcl > 0)
    {

        system("cls");
        printf("  *** Alta Trabajos ***\n");

        if( buscarTrabajoLibre(trabajo, tamTr, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {

                listarMascota(mascota, tamM, tipo, tamT, color, tamC, cliente, tamcl );

                printf("Ingrese id Mascota\n");
                scanf("%d", &trabajoN.idMascota);

                buscarMascota(mascota, tamM, trabajoN.idMascota, &indice);

                while( indice == -1){

                printf("Error. Ingrese id Mascota\n");
                scanf("%d", &trabajoN.idMascota);

                buscarMascota(mascota, tamM, trabajoN.idMascota, &indice);
                }

                listarServicio(serv, tamS );

                printf("Ingrese Id del Servicio\n");
                scanf("%d", &trabajoN.idServicio);

                while( !validarServicio(serv, tamS, trabajoN.idServicio )){

                printf("Error, Servicio invalido. Ingrese Id Servicio\n");
                scanf("%d", &trabajoN.idServicio);

                }

                printf("Ingrese Fecha  dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                trabajoN.fecha = fecha;

                trabajoN.isEmpty = 0;
                trabajoN.id = *pIdTrabajo;
                *pIdTrabajo = *pIdTrabajo + 1;
                trabajo[indice] = trabajoN;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema\n");
        }
    }



    return todoOk;
}

int listarTrabajo(eTrabajo trabajo[], int tamTr, eMascota mascota[], int tamM, eTipo tipo[], int tamT,eColor color[],int tamC, eServicio serv[], int tamS)
{

int todoOk = 0;
int flag = 0;

     if(trabajo != NULL && mascota != NULL && tipo != NULL && color != NULL && serv != NULL &&  tamTr> 0 && tamM > 0 && tamT > 0 && tamC > 0&& tamS > 0)
    {


        system("cls");
        printf("          *** LISTADO DE TRABAJOS ***                         \n\n");
        printf("  ID    ID MASCOTA       NOMBRE      SERVICIO          FECHA       \n");
        printf("----------------------------------------------------------------------------\n");

        for(int i=0; i < tamTr; i++)
        {
            if( !trabajo[i].isEmpty )
            {

            printf("%5d     %5d      %10s      %5d          %02d/%02d/%02d \n",
                       trabajo[i].id,
                       trabajo[i].idMascota,
                       mascota[i].nombre,
                       trabajo[i].idServicio,
                       trabajo[i].fecha.dia,
                       trabajo[i].fecha.mes,
                       trabajo[i].fecha.anio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay Mascotas  ");
        }
        printf("\n\n");

        todoOk = 1;
    }



    return todoOk;
}
