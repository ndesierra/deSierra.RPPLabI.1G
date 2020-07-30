#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    int recuperados;
    int infectados;
    int muertos;

}ePais;

#endif // PAIS_H_INCLUDED

/** \brief muestra opciones y devuelve la elegida por el usuario
 *
 * \return opcion elegida por el usuario
 *
 */
int menu();

/** \brief constructor de ePais
 *
 * \return un puntero a un ePais
 *
 */
ePais* newObjeto();

/** \brief constructor de ePais con atributos pasados por parametro
 *
 * \param char id del pais a crear
 * \param char nombre del pais a crear
 * \param char recuperados a crear
 * \param char infectados a crear
 * \param char muertos a crear
 * \return ePais creado
 *
 */
 ePais* newObjetoParam(char* idStr, char* nombre, char* recuperadosStr, char* infectadosStr, char* muertosStr);

/** \brief recibe por parametro el valor del id que le asignara al ePais recibido
 *
 * \param ePais* puntero a la ePais a modificar
 * \param int id que se le asignara al ePais recibido
 * \return 1 (si pudo asignarla) 0 (si no)
 *
 */
int pais_setId(ePais* this, int id);

/** \brief  recibe un puntero a pais y un puntero a una variable del tipo cadena de caracteres, asignada al atributo nombre del ePais recibido
 *
 * \param puntero a un ePais
 * \param puntero a variable del tipo char
 * \return  devuelve 1 (si pudo asignarle nombre al pais)
                     0 (si el puntero a ePais es nulo o si el nombre recibido no se encuentra en el rango esperado)
 *
 */
int pais_setNombre(ePais* this, char* nombre);

/** \brief recibe un puntero a pais y una variable del tipo entero, asigna al atributo recuperados del ePais recibido
 *
 * \param puntero a un ePais
 * \param variable del tipo entero
 * \return devuelve 1 (si pudo asignarle las tipo al pais)
                    0 (si el puntero a ePais es nulo o si los recuperados recibidos no se encuentran en el rango solicitado)
 *
 */
int pais_setRecuperados(ePais* this, int recuperados);

/** \brief recibe un puntero a pais y una variable del tipo entero, asigna al atributo infectados del ePais recibido
 *
 * \param puntero a un ePais
 * \param recibe variable del tipo int
 * \return devuelve 1 (si pudo asignarle el infectados al pais)
                    0 (si el puntero a pais es nulo o si los infectados recibido no se encuentran en el rango solicitado)
 *
 */
int pais_setInfectados(ePais* this, int infectados);

/** \brief recibe un puntero a pais y una variable del tipo entero, asigna al atributo muertos del ePais recibido
 *
 * \param puntero a un ePais
 * \param recibe variable del tipo float
 * \return devuelve 1 (si pudo asignarle el infectados al pais)
                    0 (si el puntero a pais es nulo o si los muertos recibidos no se encuentra en el rango solicitado)
 *
 */
int pais_setMuertos(ePais* this, int muertos);

/** \brief  recibe un puntero a un dato y el puntero a una variable entero, obtiene el  id del dato recibido y se lo asigna a la variable id recibida
 *
 * \param  puntero a un ePais
 * \param  puntero a una variable id del tipo int
 * \return  devuelve  0 (si el dato es nulo o el puntero a id es nulo)
                      1 (si pudo realizar la accion)
 *
 */
int pais_getId(ePais* this,int* id);

 /** \brief recibe un puntero a un ePais y el puntero a una variable del tipo cadena de caracteres, obtiene el valor del nombre del ePais recibido y se lo asigna a la variable nombre recibida
 *
 * \param puntero a un ePais
 * \param puntero a variable del tipo char
 * \return  devuelve  0 (si el pais es nulo o el puntero a nombre es nulo)
                      1 (si pudo realizar la accion)
 *
 */
int pais_getNombre(ePais* this, char* nombre);

 /** \brief recibe un puntero a un ePais y el puntero a una variable del tipo entero, obtiene el recuperados del ePais recibido y se lo asigna a la variable recuperados recibida
 *
 * \param puntero a un ePais
 * \param puntero a variable del tipo inr
 * \return devuelve  0 (si el pais es nulo o el puntero a recuperados es nulo)
                     1 (si pudo realizar la accion)
 *
 */
int pais_getRecuperados(ePais* this, int* recuperados);

/** \brief recibe un puntero a un ePais y el puntero a una variable del tipo entero, obtiene el infectados del ePais recibido y se lo asigna a la variable infectados recibida
 *
 * \param puntero a un ePais
 * \param puntero a variable del tipo int
 * \return devuelve  0 (si el pais es nulo o el puntero a infectados es nulo)
                     1 (si pudo realizar la accion)
 *
 */
int pais_getInfectados(ePais* this, int* infectados);

/** \brief recibe un puntero a un ePais y el puntero a una variable del tipo entero, obtiene el muertos del pais recibido y se lo asigna a la variable muertos recibida
 *
 * \param puntero a un ePais
 * \param puntero a variable del tipo inr
 * \return devuelve  0 (si el pais es nulo o el puntero a muertos es nulo)
                     1 (si pudo realizar la accion)
 *
 */
int pais_getMuertos(ePais* this, int* muertos);

/** \brief recibe un puntero a ePais y libera la zona de memoria que ocupaba
 *
 * \param puntero a ePais
 *
 */
void borrarObjeto(ePais* this );

/** \brief recibe un puntero a ePais y lo muestra por pantalla
 *
 * \param puntero a un ePais
 * \return  devuelve 1 (si el puntero recibido es distinto de nulo)
                     0 (si el puntero recibido es nulo)
 *
 */
int mostrarObjeto(ePais* this);
