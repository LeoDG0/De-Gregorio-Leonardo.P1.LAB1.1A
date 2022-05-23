#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{

int idTipo;
char descripcion[20];

} eTipo;

#endif // TIPO_H_INCLUDED


/** \brief encargada de Listar los tipos de mascotas
 *
 * \param tipos[] eTipo array de mascotas
 * \param tam int tamaño de la estructura
 * \return int retorna un todoOk si las condiciones se cumplen
 *
 */
int listarTipo(eTipo tipos[], int tam);


/** \brief sirve para cargar el nombre del tipo de la mascota
 *
 * \param tipos[] eTipo se hace uso de la estructura del tipo de mascota
 * \param tam int tamaño de la estructura
 * \param id int identificacion del tipo de mascota
 * \param descripcion[] char descripcion del tipo de mascota
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int cargarNombreTipo(eTipo tipos[], int tam, int id, char descripcion[]);


/** \brief valida el tipo de mascota
 *
 * \param tipos[] eTipo usa estructura del tipo de mascota
 * \param tam int tamaño de la estructura
 * \param id int id del tipo de mascota
 * \return int retorna un todo ok si las condiciones se cumplen
 *
 */
int validarTipo(eTipo tipos[], int tam, int id);



/** \brief busca el tipo de mascota en la estructura
 *
 * \param tipos[] eTipo se usa la estructura del tipo de mascota
 * \param tam int tamaño de la estructura
 * \param id int id del tipo de mascota
 * \param int* usa el puntero para confirmar que hay datos cargados
 * \return
 *
 */
int buscarTipo (eTipo tipos[],int tam, int id, int* pIndice);
