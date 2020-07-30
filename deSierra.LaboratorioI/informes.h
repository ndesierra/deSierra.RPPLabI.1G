#include "LinkedList.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Asigna estadisticas aleatorias
 *
 * \param this void*
 * \return retorno (con las estadisticas asignadas)
 *
 */
 void* asignarEstadisticas(void* this);

/** \brief Filtra los paises exitosos y los guarda en un archivo CSV
   *
   * \param this Linkedlist*
   * \return
   *
   */
void filtrarPorPaisesExitosos(LinkedList* this);

/** \brief Indica si el pais es exitoso
 *
 * \param this void*
 * \return 1 (si el pais es exitoso) 0 (si no lo es)
 *
 */
int esExitoso(void* this);

/** \brief Filtra los paises al horno y los guarda en un archivo CSV
   *
   * \param this Linkedlist*
   * \return
   *
   */
void filtrarPorPaisesEnElHorno(LinkedList* this);

/** \brief Indica si el pais esta al horno
 *
 * \param this void*
 * \return 1 (si el pais es no exitoso) 0 (si no lo es)
 *
 */
int esAlHorno(void* this);

/** \brief Compara los paises segun la cantidad de infectados
 *
 * \param A void*
 * \param B void*
 * \return retorno 0 (si A y B son NULL)
                   1 (si A es mayor que B)
                  -1 (si A es menor que B)
 *
 */
int compararPaisesXInfeccion(void* a,void* b);
