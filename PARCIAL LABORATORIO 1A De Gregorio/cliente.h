#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

int id;
char nombre[20];
char sexo;
int isEmpty;

}eCliente;

#endif // CLIENTE_H_INCLUDED


/** \brief
 *
 * \param vec[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int inicializarClientes(eCliente vec[], int tamcl);

int buscarCliente(eCliente vec[],int tamcl, int id, int* pIndice);

int listarCliente(eCliente vec[], int tamcl);

int validarCliente(eCliente vec[], int tamcl, int id);
