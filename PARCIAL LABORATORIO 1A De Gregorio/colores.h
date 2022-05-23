#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{

int id;
char descripcion[20];

} eColor;

#endif // COLORES_H_INCLUDED


/** \brief se encarga de mostrar la lista de colores de mascotas
 *
 * \param colores[] eColor array de colores
 * \param tam int tamaño de array
 * \return int retorna todoOk si se cumple todo
 *
 */
int listarColor(eColor colores[], int tam);



/** \brief se encarga de cargar los nombres mediante el id
 *
 * \param colores[] eColor array de colores
 * \param tam int tamaño de array
 * \param id int carga el nombre que corresponde al id
 * \param descripcion[] char nombre del color
 * \return int todoOk si se cumplen las condiciones
 *
 */
int cargarNombreColor(eColor colores[], int tam, int id, char descripcion[]);


/** \brief valida con 1 o -1
 *
 * \param colores[] eColor array de colores
 * \param tam int tamaño de array
 * \param id int id del color
 * \return int retorna esvalido si se cumplen las condiciones
 *
 */
int validarColor(eColor colores[], int tam, int id);




/** \brief se utiliza en conjunto para validar los colores
 *
 * \param tam int tamaño de array de color
 * \param id int id del color
 * \return devuelve todoOk si se cumplen las condiciones;
 *
 */
int buscarColor (eColor colores[],int tam, int id, int* pIndice);


int cargarNombreColorAux(eColor colores[], int tam, int id, char descripcion[]);
