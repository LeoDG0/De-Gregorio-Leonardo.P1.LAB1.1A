#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"
#include "mascotas.h"



//RECORD: llevar validarFechas a validacion.h

int validarFecha(eFecha fecha){

int todoOk = 0;

    while((fecha.anio < 1990 || fecha.anio > 2022)
          || (fecha.mes < 1 || fecha.mes > 12)
          || (fecha.dia < 1 || fecha.dia > 31)
          || (fecha.mes == 2 && fecha.dia >= 29)
          || (fecha.mes == 1 && fecha.dia >= 32)
          || (fecha.mes == 3 && fecha.dia >= 32)
          || (fecha.mes == 5 && fecha.dia >= 32)
          || (fecha.mes == 7 && fecha.dia >= 32)
          || (fecha.mes == 8 && fecha.dia >= 32)
          || (fecha.mes == 10 && fecha.dia >= 32)
          || (fecha.mes == 12 && fecha.dia >= 32)
          || (fecha.mes == 4 && fecha.dia >= 31)
          || (fecha.mes == 6 && fecha.dia >= 31)
          || (fecha.mes == 9 && fecha.dia >= 31)
          || (fecha.mes == 11 && fecha.dia >= 30)
          ){
            printf("Error, reingrese fecha: ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
            }

    return todoOk;
}


