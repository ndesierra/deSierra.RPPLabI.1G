#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


/** \brief Carga los datos de los paises desde el archivo  .csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int 1 (si pudo cargar el archivo)  0 (Error)
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList);

/** \brief Listar los datos de los paises
*
* \param pArrayList LinkedList*
* \return int 1 (si pudo listar el archivo)  0 (Error)
*
*/
int controller_Listar(LinkedList* pArrayList);

/** \brief Guarda los datos de los paises en el archivo  .csv (modo texto).
*
* \param path char*
* \param pArrayList LinkedList*
* \return int 1 (si pudo guardar los datos en el archivo)  0 (Error)
*
*/
int controller_saveAsText(char* path, LinkedList* pArrayList);

 /** \brief Ordenar los datos de los paises
 *
 * \param pArrayList LinkedList*
 * \return int 0 (si pudo ordenar los datos en el archivo)  -1 (Error)
 *
 */
int controller_sort(LinkedList* pArrayList);


/** \brief Compara la cantidad de muertos de los paises y muestra al mas castigado
 *
 * \param pArrayList LinkedList*
 * \return int 1 (si pudo comparar correctamente los paises)  0 (Error)
 *
 */
int controller_masCastigado(LinkedList* pArrayList);
