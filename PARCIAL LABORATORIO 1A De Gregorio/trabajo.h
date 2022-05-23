#include "fecha.h"
#include "mascotas.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{

int id;
int idMascota;
int idServicio;
eFecha fecha;
int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED


/** \brief
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int inicializarTrabajo(eTrabajo vec[], int tam);

/** \brief se encarga de buscar si hay espacio en el sistema
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \param pIndex int*
 * \return int
 *
 */
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);

/** \brief se encarga de recibir los datos de los trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param mascotas[] eMascota
 * \param tamMas int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param colores[] eColor
 * \param tamCol int
 * \param servicios[] eServicio
 * \param tamSer int
 * \param pIdTrabajo int*
 * \return int
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamTra, eMascota mascotas[], int tamMas, eTipo tipos[], int tamTip,eColor colores[],int tamCol, eServicio servicios[], int tamSer, eCliente cliente[], int tamcl, int* pIdTrabajo);

/** \brief se encarga de mostrar los trabajos(si es que hay) en forma de lista
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param mascotas[] eMascota
 * \param tamMAs int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param colores[] eColor
 * \param tamCol int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int listarTrabajo(eTrabajo trabajos[], int tamTra, eMascota mascotas[], int tamMAs, eTipo tipos[], int tamTip,eColor colores[],int tamCol, eServicio servicios[], int tamSer);
