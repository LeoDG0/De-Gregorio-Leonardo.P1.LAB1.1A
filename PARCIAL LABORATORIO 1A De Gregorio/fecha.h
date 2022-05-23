#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{

int dia;
int mes;
int anio;

}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief se utiliza para validar las fechas en su mayoria
 *
 * \param fecha eFecha array de fechas
 * \return int retorna todoOk si se cumplen las condiciones
 *
 */
int validarFecha(eFecha fecha);
