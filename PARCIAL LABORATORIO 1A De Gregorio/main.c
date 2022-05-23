#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascotas.h"
#include "colores.h"
#include "servicio.h"
#include "trabajo.h"
#include "tipo.h"
#include "fecha.h"


#define TAM 5
#define TAMC 5
#define TAMTR 10
#define TAMS 3
#define TAMT 5
#define TAMCL 5

#define CRITERIONOMBRE 1
#define CRITERIOTIPO 0


int main()
{


    char salir = 'n';
    int idMascota = 300;
    eMascota mascota[TAM];
    int idTrabajo = 200;
    int flagAlta = 0;
    int flagModificar = 0;
    float pPromedio;

    eTrabajo trabajos[TAMTR];

    eTipo tipo[TAMT] =
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Pez"},
        {1003, "Gato"},
        {1004, "Roedor"}
    };
      eColor color[TAMC] =
    {
        {5000, "Negro"},
        {5001, "Rojo"},
        {5002, "Blanco"},
        {5003, "Azul"},
        {5004, "Gris"}
    };
       eServicio serv[TAMS] =
    {
        {20000, "Desparasitado", 800},
        {20001, "Castrado", 600},
        {20002, "Corte",450}
    };

     eCliente clientes[TAMCL] =
    {
        {900, "Juan"},
        {901, "Mario"},
        {902, "James"},
        {903, "Lucas"},
        {904, "Mariano"}
    };


    inicializarMascotas(mascota, TAM);

    inicializarTrabajo(trabajos, TAMTR);

    //inicializarClientes(clientes, TAMCL);

    hardcodearMascotas(mascota, TAM, 4, &idMascota);

    do {
		switch (menu()) {
		case 1:

			if( altaMascota(mascota, TAM, tipo, TAMT, color, TAMC, clientes, TAMCL, &idMascota))
            {
                printf("Mascota agregada con exito!!!\n");
                flagAlta = 1;
            }

			break;
		case 2:

            if(flagAlta == 1){

            if( modificarMascota(mascota, TAM, tipo, TAMS, color, TAMC, clientes, TAMCL) == 0)
            {
                printf("Problema al hacer la modificacion\n");
            }

            }else{

                printf("\nPrimero debe cargar una mascota para modificar!\n\n");

            }
            flagModificar = 1;
			break;
		case 3:

			 if(flagAlta == 1 && flagModificar == 1){

                if( bajaMascota(mascota, TAM, tipo, TAMT, color, TAMC, clientes, TAMCL) == 0)
            {
                printf("Problema al hacer la baja\n");
            }
			 }else{
                printf("\nprimero debe cargar una mascota para dar de baja!\n\n");
			 }
			break;
		case 4:
                if(flagAlta == 1){

                    ordenarTipoYNombre(mascota, TAM, CRITERIONOMBRE);
                    listarMascota(mascota, TAM, tipo, TAMT, color, TAMC, clientes, TAMCL);
                }
                else{

                    printf("\nPara listar debe agregar por lo menos una(1) mascota\n\n");

                }
			break;
		case 5:

			listarTipo(tipo, TAMT);

			break;
        case 6:

			listarColor(color, TAMC);

			break;
        case 7:

			listarServicio(serv, TAMS);

			break;
        case 8:

			 if(flagAlta == 1){

                altaTrabajo(trabajos, TAMTR, mascota, TAM, tipo, TAMT, color, TAMC, serv, TAMS, clientes, TAMCL, &idTrabajo);

			 }else{

                printf("\nPara cargar un trabajo primero debe agregar una mascota!\n\n");

			 }

			break;
        case 9:

			listarTrabajo(trabajos, TAMTR, mascota, TAM, tipo, TAMT, color, TAMC, serv, TAMS);

			break;
        case 10:
                informarMascotasColor(mascota, tipo, color, clientes, TAMC);
            break;
        case 11:
                informarMascotaMenorEdad(mascota, tipo, color, clientes, TAM);
            break;
        case 12:
                informarMascotasXTipo(mascota, tipo, color, clientes, TAM, TAMT);
            break;
        case 13:
                informarMascotasColorYTipo(mascota, tipo, color, clientes, TAMC, TAMT);
            break;
        case 14:
                cantidadColoresPorMascota(mascota, TAM, color, TAMC);
            break;
        case 15:
                printf("...");
                //promedioVacunados(mascota, TAM, &pPromedio);
                //no funciona
            break;
        case 0:
			salir = 's';
			break;
		default:
			printf("Opcion invalida!\n");
		}
		system("pause");
	} while (salir != 's');


    return 0;
}










