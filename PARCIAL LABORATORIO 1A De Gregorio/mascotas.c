#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascotas.h"

int menu()
{

    int opcion;

    system("cls");

    printf(" \n*** VETERINARIA ***\n\n");
    printf("1-ALTA MASCOTA\n");
    printf("2-MODIFICAR MASCOTA\n");
    printf("3-BAJA MASCOTA\n");
    printf("4-LISTAR MASCOTA\n");
    printf("5-LISTAR TIPO\n");
    printf("6-LISTAR COLORES\n");
    printf("7-LISTAR SERVICIOS\n");
    printf("8-ALTA TRABAJO\n");
    printf("9-LISTAR TRABAJO\n");
    printf("10-INFORMAR MASCOTAS POR COLOR\n");
    printf("11-INFORMAR MASCOTAS POR MENOR EDAD\n");
    printf("12-INFORMAR MASCOTAS POR TIPO\n");
    printf("13-INFORMAR POR COLOR Y TIPO\n");
    printf("14-INFORMAR CANTIDAD DE COLORES POR TIPO\n");
    printf("15-PROMEDIO DE MASCOTAS VACUNADAS\n");
    printf("0-SALIR\n");

    printf("\nIngrese Opcion: ");
    scanf("%d", &opcion);


    return opcion;
}

int inicializarMascotas(eMascota vec[], int tam)
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


int buscarLibre(eMascota vec[], int tam, int* pIndex)
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



int listarMascota(eMascota vec[], int tam, eTipo tipo[], int tamT, eColor color[], int tamC, eCliente cliente[], int tamcl)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("                   *** LISTADO DE MASCOTAS ***                        \n\n");
        printf(" ID         NOMBRE        TIPO       COLOR    EDAD   VACUNAS   DUENIO   F.INGRESO \n");
        printf("-------------------------------------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarMascota(vec[i], tipo, color, cliente, tamC);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("      No hay Mascotas     ");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMascota(eMascota mascota, eTipo tipo[], eColor color[], eCliente cliente[], int tam)
{
    int todoOk = 0;
    char auxTipo[10];
    char auxColor[10];
    char auxCliente[10];

    if((tipo != NULL && tam > 0 ) || (color != NULL && tam > 0))
    {


        cargarNombreColor(color, tam, mascota.idColor, auxColor);

        cargarNombreTipo( tipo, tam, mascota.idTipo, auxTipo);

        cargarNombreCliente(cliente, tam, mascota.idCliente, auxCliente);


        printf("%4d   %10s     %8s   %10s   %2d      %c   %10s     %02d/%02d/%d \n",
               mascota.id,
               mascota.nombre,
               auxTipo,
               auxColor,
               mascota.edad,
               mascota.vacunado,
               auxCliente,
               mascota.fIngreso.dia,
               mascota.fIngreso.mes,
               mascota.fIngreso.anio
              );
        todoOk = 1;
    }
    return todoOk;
}


int menuModificarMascota()
{

    int opcion;

    printf("\n*** MODIFICAR ***\n\n");
    printf("1-NOMBRE\n");
    printf("2-TIPO\n");
    printf("3-COLOR\n");
    printf("4-EDAD\n");
    printf("5-VACUNAS\n");
    printf("6-SALIR\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}


int hardcodearMascotas(eMascota vec[], int tam, int cant, int* pId)
{

    int todoOk = 0;
    eMascota hardoceadas[] =
    {
        {0, "Lola", 1000, 5004, 6, {3,7,2022}, 's', 900},
        {0, "Molly", 1003, 5002, 12, {2,9,2022}, 's', 901},
        {0, "Coco", 1002, 5001, 15, {31,5,2021}, 's', 902},
        {0, "Thor", 1003, 5002, 4, {1,1,2022}, 'n', 904},
        {0, "Toby", 1004, 5004, 6, {22,5,2021}, 'n', 901},
        {0, "Rocky", 1003, 5002, 2, {19,8,2022}, 'n', 901},
        {0, "Simba", 1004, 5001, 4, {1,9,2021}, 's', 903},
        {0, "Zeus", 1002, 5000, 2, {7,4,2022}, 's', 902},
        {0, "Kiara", 1001, 5003, 3, {27,2,2021}, 'n', 904},
        {0, "Trufa", 1004, 5001, 6, {24,12,2019}, 's', 902}
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = hardoceadas[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;

}


int buscarMascota(eMascota vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionMascota(eMascota mascota[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarMascota(mascota,tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {

        strcpy(descripcion, mascota[indice].nombre);
        todoOk = 1;
    }
    return todoOk;
}


int bajaMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente cliente[], int tamcl)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec != NULL && tam > 0)
    {
        listarMascota(vec, tam, tipos, tamTip, colores, tamCol, cliente, tamcl);
        printf("Ingrese ID: ");
        scanf("%d", &id);
        if( buscarMascota(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay Mascotas con ese Id %d\n", id);
            }
            else
            {
                mostrarMascota(vec[indice], tipos, colores, cliente, tam);
                printf("Confirmar baja?: s o n ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' || confirma != 's')
                {
                    printf("Baja cancelada!\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar la mascota! \n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int altaMascota(eMascota vec[], int tam, eTipo tipo[], int tamT,eColor color[],int tamC, eCliente cliente[], int tamcl,  int* pIdMascota)
{
    int todoOk = 0;
    int indice;
    eMascota mascotaN;
    eFecha fecha;
    char auxCad[100];
    char auxCadC[100];

    if(vec != NULL && tam > 0 && pIdMascota != NULL)
    {
        if( buscarLibre(vec, tam, &indice) )
        {

            if(indice == - 1)
            {
                printf("\nNo hay lugar disponible\n\n");
            }
            else
            {
                printf("Ingrese el nombre de la Mascota: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(mascotaN.nombre, auxCad);

                printf("Ingrese edad: ");
                fflush(stdin);
                scanf("%d", &mascotaN.edad);


                printf("Esta vacunado: s o n   ");
                fflush(stdin);
                scanf("%c", &mascotaN.vacunado);

                listarTipo(tipo, tamT);

                printf("Ingrese Id Tipo: ");
                scanf("%d", &mascotaN.idTipo);

                while( !validarTipo(tipo, tamT, mascotaN.idTipo))
                {
                    printf("Tipo invalido.Ingrese Id Tipo: ");
                    scanf("%d", &mascotaN.idTipo);
                }


                printf("Ingrese Fecha ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                validarFecha(fecha);

                mascotaN.fIngreso = fecha;


                listarColor(color, tamC);

                printf("Ingrese Id del color: ");
                scanf("%d", &mascotaN.idColor);

                while( !validarColor(color, tamC, mascotaN.idColor))
                {
                    printf("Color invalido.Ingrese Id color: ");
                    scanf("%d", &mascotaN.idColor);
                }

                listarCliente(cliente, tamcl);

                printf("Ingrese Id Cliente: ");
                scanf("%d", &mascotaN.idCliente);

                while( !validarTipo(cliente, tamcl, mascotaN.idCliente))
                {
                    printf("cliente invalido. Reingrese: ");
                    scanf("%d", &mascotaN.idCliente);
                }


                mascotaN.isEmpty = 0;
                mascotaN.id = *pIdMascota;
                *pIdMascota = *pIdMascota + 1;
                vec[indice] = mascotaN;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int modificarMascota(eMascota vec[], int tam, eTipo tipo[], int tamT, eColor color[], int tamC, eCliente cliente[], int tamcl)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    char auxCad[100];

    if(vec != NULL && tam > 0)
    {
        listarMascota(vec, tam, tipo, tamT, color, tamC, cliente, tamcl);

        printf("Ingrese ID: ");
        scanf("%d", &id);

        if( buscarMascota(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una Mascota con Id %d\n", id);
            }
            else
            {
                mostrarMascota(vec[indice], tipo, color, cliente, tam);


                do
                {
                    switch(menuModificarMascota())
                    {

                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(vec[indice].nombre, auxCad);
                        printf("Se ha modificado el nombre\n");
                        break;

                    case 2:
                        listarTipo(tipo, tamT);
                        printf("Ingrese Id Tipo: ");
                        fflush(stdin);
                        scanf("%d", &vec[indice].idTipo);

                        while( !validarTipo(tipo, tamT, vec[indice].idTipo))
                        {
                            printf("Tipo invalido.Ingrese Id Tipo: ");
                            scanf("%d", &vec[indice].idTipo);
                        }

                        printf("Se ha modificado el Tipo de la mascota\n");
                        break;

                    case 3:
                        listarColor(color, tamC);

                        printf("Ingrese Id del color: ");
                        fflush(stdin);
                        scanf("%d", &vec[indice].idColor);

                        while( !validarColor(color, tamC, vec[indice].idColor))
                        {
                            printf("Color invalido.Ingrese Id color: ");
                            scanf("%d", &vec[indice].idColor);
                        }

                        printf("Se ha modificado el Color de la mascota\n");

                        break;
                    case 4:
                        printf("Ingrese nuevo edad: ");
                        fflush(stdin);
                        scanf("%d", &vec[indice].edad);
                        printf("Se ha modificado la edad\n");

                        break;
                    case 5:
                        printf("Ingrese si esta vacunada la mascota : s or  n ");
                        fflush(stdin);
                        scanf("%c", &vec[indice].vacunado);
                        printf("Se ha modificado la vacuna\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Problema al buscar mascota\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarTipoYNombre(eMascota mascota[], int tam, int criterio)
{

    int todoOk = 0;
    eMascota auxOrdenar;


    if(mascota != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(strcmp(mascota[i].nombre, mascota[j].nombre) >= 0 && criterio == 1)
                {
                    auxOrdenar = mascota[i];
                    mascota[i] = mascota[j];
                    mascota[j] = auxOrdenar;
                }
                if (mascota[i].idTipo > mascota[j].idTipo && (criterio == 0))
                {
                    auxOrdenar = mascota[i];
                    mascota[i] = mascota[j];
                    mascota[j] = auxOrdenar;
                }

            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int informarMascotasColor(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tamc)
{
    int todoOk = 0;
    int idColor;
    int flag = 0;
    char nombre[20];


    if(vec != NULL && color != NULL && tamc > 0 && tamc > 0)
    {


        listarColor(color, tamc);

        printf("Ingrese Id color: ");
        scanf("%d", &idColor);

        while( !validarColor(color, tamc, idColor))
        {
            printf("Color invalido.Reingrese: ");
            scanf("%d", &idColor);
        }

        system("cls");
        printf("\n   *** LISTADO DE MASCOTAS POR COLOR ***\n");
        printf("---------------------------------------------------\n");
        printf(" ID         NOMBRE        TIPO       COLOR    EDAD   VACUNAS   DUENIO   F.INGRESO \n\n");
        printf("-------------------------------------------------------------------------------------\n");

        for(int i=0; i < tamc; i++)
        {
            if( !vec[i].isEmpty && vec[i].idColor == idColor)
            {

                mostrarMascota(vec[i], tipo, color, cliente, tamc);

                flag = 1;
            }
        }
        if(flag == 0)
        {
            cargarNombreColor(color, tamc, idColor, nombre);
            printf("No hay msacotas registradas con el color %10s\n", color);
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}


int informarMascotaMenorEdad(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tam)
{
    int todoOk = 0;
    int menorEdad;
    int flag = 0;

    if(vec != NULL && tam > 0 )
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && (vec[i].edad < menorEdad || !flag)  )
            {
                menorEdad = vec[i].edad;
                flag = 1;
            }
        }

        system("cls");
        printf("     *** INFORME DE MENOR EDAD MASCOTAS   ***\n");
        printf("------------------------------------------\n\n");
        printf(" ID         NOMBRE        TIPO       COLOR    EDAD   VACUNAS   DUENIO   F.INGRESO \n\n");
        printf("-------------------------------------------------------------------------------------\n");
        if(flag == 0)
        {
            printf("No hay mascotas cargadas en el sistema\n\n");
        }
        else
        {

            for(int i=0; i < tam; i++)
            {
                if( !vec[i].isEmpty && vec[i].edad == menorEdad)
                {
                    mostrarMascota(vec[i], tipo, color, cliente, tam);
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarMascotasXTipo(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tamt, int tam)
{
    int todoOk = 0;
    int flag;

    if(vec != NULL && tipo != NULL && tam > 0 && tamt > 0)
    {
        system("cls");
        printf("    *** LISTADO DE MASCOTAS POR TIPO  ***\n");
        printf("-----------------------------------------------------\n");

        for(int j=0; j < tamt; j++)
        {
            printf("TIPO: %s\n\n", tipo[j].descripcion);
            printf(" ID         NOMBRE        TIPO       COLOR    EDAD   VACUNAS   DUENIO   F.INGRESO \n\n");
            printf("-------------------------------------------------------------------------------------\n");

            flag = 1;
            for(int i = 0; i < tamt; i++)
            {
                if( !vec[i].isEmpty && vec[i].idTipo == tipo[j].idTipo)
                {
                    mostrarMascota(vec[i], tipo, color, cliente, tamt);
                    flag = 0;
                }
            }
            if(flag)
            {
                printf("No hay mascotas\n");
            }
            printf("\n\n");

        }
        todoOk = 1;
    }
    return todoOk;
}


//int promedioVacunados(eMascota vec[], int tam, float* pPromedio)
//{
//    int todoOk = 0;
//    int cantidad;
//    float promedio;
//    int contMascotas = 0;
//    float acumVacunados = 0;
//
//    if(vec != NULL && tam > 0 && tam > 0)
//    {
//        system("cls");
//        printf("    *** PROMEDIO DE VACUNADOS  ***\n");
//        printf("----------------------------------------\n");
//
//
//        cantidad = 0;
//        for(int i = 0; i < tam; i++)
//        {
//
//            printf("vacunados: %f: ", vec[a].vacunado);
//
//            if( !vec[i].isEmpty && vec[i].vacunado == "s")
//            {
//                acumVacunados += vec[i].vacunado;
//                contMascotas++;
//            }
//        }
//
//        if(contMascotas != 0)
//        {
//            promedio = acumVacunados/contMascotas;
//        }
//
//        *pPromedio = promedio;
//
//        printf(" %f\n\n", promedio);
//
//    }
//    todoOk = 1;
//
//    return todoOk;
//}//no funciona


int informarMascotasColorYTipo(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tamc, int tamt)
{
    int todoOk = 0;
    int idColor;
    int idTipo;
    int flag = 0;
    char nombre[20];
    char nombreTipo[20];


    if(vec != NULL && color != NULL && tipo != NULL && tamc > 0 && tamc > 0)
    {


        listarColor(color, tamc);

        printf("Ingrese Id color: ");
        scanf("%d", &idColor);

        while( !validarColor(color, tamc, idColor))
        {
            printf("Color invalido.Reingrese: ");
            scanf("%d", &idColor);
        }

        listarTipo(tipo, tamt);

        printf("Ingrese Id tipo: ");
        scanf("%d", &idTipo);

        while( !validarTipo(tipo, tamt, idTipo))
        {
            printf("Tipo invalido.Reingrese: ");
            scanf("%d", &idTipo);
        }


        system("cls");
        printf("\n   *** LISTADO DE MASCOTAS POR COLOR Y TIPO ***\n");
        printf("---------------------------------------------------\n");
        printf(" ID         NOMBRE        TIPO       COLOR    EDAD   VACUNAS   DUENIO   F.INGRESO \n\n");
        printf("-------------------------------------------------------------------------------------\n");

        for(int i=0; i < tamc; i++)
        {
            if( !vec[i].isEmpty && vec[i].idColor == idColor && !vec[i].isEmpty && vec[i].idTipo == idTipo)
            {

                mostrarMascota(vec[i], tipo, color, cliente, tamc);

                flag = 1;
            }
        }
        if(flag == 0)
        {
            cargarNombreColor(color, tamc, idColor, nombre);
            cargarNombreTipo(tipo, tamt, idTipo, nombreTipo);
            printf("No hay mascotas registradas con el color %10s y con el tipo %10s\n", color, tipo);

        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}

int cantidadColoresPorMascota(eMascota vec[], int tam, eColor colores[], int tamc)
{
    int todoOk = 0;
    int cantidad;

    if(vec != NULL && colores != NULL && tam > 0 && tamc > 0)
    {
        system("cls");
        printf("    *** CANTIDAD COLORES POR MASCOTA  ***\n");
        printf("-----------------------------------------------------\n");

        for(int i=0; i < tamc; i++)
        {
            cantidad = 0;
            printf("color: %s: ", colores[i].descripcion);


            for(int a = 0; a < tam; a++)
            {
                if( !vec[a].isEmpty && vec[a].idColor == colores[i].id)
                {
                    cantidad++;
                }
            }

            printf(" %d\n\n",cantidad);

        }
        todoOk = 1;
    }
    return todoOk;
}
