#include "fecha.h"
#include "tipo.h"
#include "colores.h"
#include "servicio.h"
#include "cliente.h"

#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{

int id;
char nombre[20];
int idTipo;
int idColor;
int edad;
eFecha fIngreso;
char vacunado;
int idCliente;
int isEmpty;

} eMascota;

#endif // MASCOTAS_H_INCLUDED


int menu();

/** \brief inicializa las mascotas
 *
 * \param vec[] eMascota
 * \param tam int
 * \return int
 *
 */
int inicializarMascotas(eMascota vec[], int tam);

/** \brief busca que haya lugar en el sistema
 *
 * \param vec[] eMascota
 * \param tam int
 * \param pIndex int*
 * \return int
 *
 */
int buscarLibre(eMascota vec[], int tam, int* pIndex);

/** \brief pide los datos de la mascota, nombre, edad, vacunas, etc
 *
 * \param vec[] eMascota
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param colores[] eColor
 * \param tamCol int
 * \param pIdMascota int*
 * \return int
 *
 */
int altaMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip,eColor colores[],int tamCol, eCliente cliente[], int tamcl, int* pIdMascota);

/** \brief modifica una mascota existente ya en el sistema
 *
 * \param vec[] eMascota
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param eColor[]
 * \param tamCol int
 * \return int
 *
 */
int modificarMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor[], int tamCol, eCliente cliente[], int tamcl);

/** \brief busca una mascota mediante el id
 *
 * \param vec[] eMascota
 * \param tam int
 * \param id int
 * \param pIndex int*
 * \return int
 *
 */
int buscarMascota(eMascota vec[], int tam,int id, int* pIndex);

int menuModificarMascota();

/** \brief carga las mascotas para mostrarlas en el listar
 *
 * \param mascotas eMascota
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param tam int
 * \return int
 *
 */
int mostrarMascota(eMascota mascotas, eTipo tipos[],eColor colores[], eCliente cliente[], int tam);

/** \brief hace uso de mostrar mascotas para mostrar la lista con datos
 *
 * \param vec[] eMascota
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param colores[] eColor
 * \param tamCol int
 * \return int
 *
 */
int listarMascota(eMascota vec[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eCliente cliente[], int tamcl);

/** \brief se encarga de recibir y eliminar la mascota
 *
 * \param vec[] eMascota
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param colores[] eColor
 * \param tamCol int
 * \return int
 *
 */
int bajaMascota(eMascota vec[], int tam,eTipo tipos[], int tamTip,eColor colores[],int tamCol, eCliente cliente[], int tamcl);

/** \brief
 *
 * \param vec[] eMascota
 * \param tam int
 * \param cant int
 * \param pId int*
 * \return int
 *
 */
int hardcodearMascotas(eMascota vec[], int tam, int cant, int* pId);

/** \brief
 *
 * \param mascota[] eMascota
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionMascota(eMascota mascota[], int tam, int id, char descripcion[]);





/** \brief ayuda a ordenar de la forma que se quiera a las mascotas
 *
 * \param mascota[] eMascota
 * \param tam int
 * \param criterio int 1 para ordenar por nombre y 0 para ordenar por tipo
 * \return int
 *
 */
int ordenarTipoYNombre(eMascota mascota[], int tam, int criterio);


/** \brief se usa como un auxiliar para los informes
 *
 * \param color[] eColor
 * \param tamc int
 * \return int
 *
 */
int mostrarMascotaAux(eMascota mascota[], eColor color[], int tamc);


/** \brief informa las masctas por el color que se pida
 *
 * \param vec[] eMascota
 * \param tam int
 * \param color[] eColor
 * \param tamc int
 * \return int
 *
 */
int informarMascotasColor(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tam);




/** \brief informa las mascotas con menor edad
 *
 * \param vec[] eMascota
 * \param tipo[] eTipo
 * \param color[] eColor
 * \param cliente[] eCliente
 * \param tam int
 * \return int
 *
 */
int informarMascotaMenorEdad(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tam);



/** \brief informa las mascotas por el tipo que se le eliga
 *
 * \param vec[] eMascota
 * \param tipo[] eTipo
 * \param color[] eColor
 * \param cliente[] eCliente
 * \param tamt int
 * \param tam int
 * \return int
 *
 */
int informarMascotasXTipo(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tamt, int tam);





/** \brief calcula el promedio de las mascotas vacunadas sobre el total
 *
 * \param vec[] eMascota
 * \param tam int
 * \param pPromedio float*
 * \return int
 *
 */
int promedioVacunados(eMascota vec[], int tam, float* pPromedio);


/** \brief se informa por el color y el tipo que se le pida
 *
 * \param vec[] eMascota
 * \param tipo[] eTipo
 * \param color[] eColor
 * \param cliente[] eCliente
 * \param tamc int
 * \param tamt int
 * \return int
 *
 */
int informarMascotasColorYTipo(eMascota vec[], eTipo tipo[], eColor color[], eCliente cliente[], int tamc, int tamt);



/** \brief muestra la cantidad de mascotas con ese color
 *
 * \param vec[] eMascota
 * \param tam int
 * \param colores[] eColor
 * \param tamc int
 * \return int
 *
 */
int cantidadColoresPorMascota(eMascota vec[], int tam, eColor colores[], int tamc);
