#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pais.h"
#include "validaciones.h"
#include "Controller.h"
#include "informes.h"

void* asignarEstadisticas(void* this)
{
    ePais* auxiliar;
    void * retorno = NULL;
    int aleatorio;
    if( this != NULL)
    {
        auxiliar= (ePais*) this;
        aleatorio = (rand()% 950000)+50000;
        pais_setRecuperados(auxiliar, aleatorio);
        aleatorio = (rand()% 1960000)+40000;
        pais_setInfectados(auxiliar, aleatorio);
        aleatorio = (rand()% 49000)+1000;
        pais_setMuertos(auxiliar, aleatorio);
        retorno = (int*) auxiliar;
    }
    return retorno;
}

void filtrarPorPaisesExitosos(LinkedList* this)
{
    LinkedList* listaFiltrada = ll_newLinkedList();

    listaFiltrada = ll_filter(this, esExitoso);
    if( !ll_isEmpty(listaFiltrada))
    {
        controller_Listar(listaFiltrada);
        controller_saveAsText("paisesExitosos.csv", listaFiltrada);
        printf("Se han guardado satisfactoriamente los paises exitosos en el archivo paisesExitosos.csv\n");
    }
    else
    {
        printf("No hay paises exitosos\n");
    }
    system("pause");
}

int esExitoso(void* this)
{
    ePais* auxiliar;
    int retorno = 0;
    int exitoso = 0;

    if( this != NULL)
    {
        auxiliar= (ePais*) this;

        if (pais_getMuertos(auxiliar, &exitoso) != -1)
        {
            if( exitoso <= 5000 )
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

void filtrarPorPaisesEnElHorno(LinkedList* this)
{
    LinkedList* listaFiltrada = ll_newLinkedList();

    listaFiltrada = ll_filter(this, esAlHorno);
    if( !ll_isEmpty(listaFiltrada))
    {
        controller_Listar(listaFiltrada);
        controller_saveAsText("paisesEnElHorno.csv", listaFiltrada);
        printf("Se han guardado satisfactoriamente los paises al horno en el archivo paisesEnElHorno.csv\n");
    }
    else
    {
        printf("No hay paises en el horno\n");
    }

    system("pause");
}

int esAlHorno(void* this)
{
    ePais* auxiliar;
    int retorno = 0;
    int infectados = 0;
    int recuperados = 0;

    if( this != NULL)
    {
        auxiliar= (ePais*) this;

        if (pais_getInfectados(auxiliar, &infectados) != -1 && pais_getRecuperados(auxiliar, &recuperados) != -1)
        {
            if( infectados >= (recuperados * 3))
            {
                retorno = 1;
            }
        }
    }
    return retorno;
}

int compararPaisesXInfeccion(void* a,void* b)
{
    int retorno = 0;
    int infectadosA;
    int infectadosB;

    if( a != NULL && b != NULL )
    {
        pais_getInfectados(a, &infectadosA);
        pais_getInfectados(b, &infectadosB);

        if( infectadosA > infectadosB)
        {
            retorno = 1;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}
