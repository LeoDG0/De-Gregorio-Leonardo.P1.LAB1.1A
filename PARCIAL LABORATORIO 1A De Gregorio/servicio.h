#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{

int id;
char descripcion[20];
float precio;

} eServicio;


#endif // SERVICIO_H_INCLUDED


/** \brief se encarga de Listar los servicios de la veterinaria
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return int
 *
 */
int listarServicio(eServicio servicios[], int tam);



/** \brief carga el nombre del tipo de color de la mascota
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);



/** \brief  valida el servicio que se eliga
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarServicio(eServicio servicios[], int tam, int id);




/** \brief busca el servicio que se ofrecen
 *
 * \param
 * \param
 * \return
 *
 */
int buscarServicio (eServicio servicios[],int tam, int id, int* pIndice);
