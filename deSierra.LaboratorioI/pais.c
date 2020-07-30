#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pais.h"
#include "validaciones.h"
#include "Controller.h"
#include "LinkedList.h"
#include "informes.h"

int menu()
{
    int opcion;

    system("cls");
    printf("**** Menu principal **** \n\n");
    printf("1.   Cargar archivo. \n");
    printf("2.   Imprimir Lista. \n");
    printf("3.   Asignar estadisticas.\n");
    printf("4.   Filtrar por paises exitosos.\n");
    printf("5.   Filtrar por paises en el horno.\n");
    printf("6.   Ordenar por nivel de infeccion. \n");
    printf("7.   Mostrar mas castigado.\n");
    printf("8.   Salir.\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

ePais* newObjeto()
{
    return (ePais*) calloc(sizeof(ePais),1);
}

ePais* newObjetoParam(char* idStr, char* nombre, char* recuperadosStr, char* infectadosStr, char* muertosStr)
{
    ePais* nuevoObjeto;
    int id;
    int recuperados;
    int infectados;
    int muertos;

    nuevoObjeto = newObjeto();

    if(nuevoObjeto != NULL && idStr != NULL && nombre != NULL && recuperadosStr != NULL && infectadosStr != NULL && muertosStr != NULL)
    {
        id = atoi(idStr);
        recuperados = atoi(recuperadosStr);
        infectados = atoi(infectadosStr);
        muertos = atoi(muertosStr);

        pais_setId(nuevoObjeto, id);
        pais_setNombre(nuevoObjeto, nombre);
        pais_setRecuperados(nuevoObjeto, recuperados);
        pais_setInfectados(nuevoObjeto, infectados);
        pais_setMuertos(nuevoObjeto, muertos);
    }
    return nuevoObjeto;
}

int pais_setId(ePais* this, int id)
{
    int retorno = 0;

    if ( this != NULL && id > 1 && id <= 1000)
    {
        this-> id = id;
        retorno = 1;
    }
    return retorno;
}

int pais_setNombre(ePais* this, char* nombre)
{
    int retorno = 0;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 30)
    {
        strcpy(this -> nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int pais_setRecuperados(ePais* this, int recuperados)
{
    int retorno = 0;

    if ( this != NULL && recuperados >= 50000 && recuperados <= 1000000)
    {
        this-> recuperados = recuperados;
        retorno = 1;
    }
    return retorno;
}

int pais_setInfectados(ePais* this, int infectados)
{
    int retorno = 0;

    if ( this != NULL && infectados >= 40000 && infectados <= 2000000)
    {
        this-> infectados = infectados;
        retorno = 1;
    }
    return retorno;
}

int pais_setMuertos(ePais* this, int muertos)
{
    int retorno = 0;

    if ( this != NULL && muertos >= 1000 && muertos <= 50000)
    {
        this-> muertos = muertos;
        retorno = 1;
    }
    return retorno;
}

int pais_getId(ePais* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int pais_getNombre(ePais* this, char* nombre)
{
    int retorno = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this -> nombre);
        retorno = 1;
    }
    return retorno;

}

int pais_getRecuperados(ePais* this,int* recuperados)
{
    int retorno = 0;
    if(this != NULL && recuperados!=NULL)
    {
        *recuperados = this->recuperados;
        retorno = 1;
    }
    return retorno;
}

int pais_getInfectados(ePais* this,int* infectados)
{
    int retorno = 0;
    if(this != NULL && infectados!=NULL)
    {
        *infectados = this->infectados;
        retorno = 1;
    }
    return retorno;
}
int pais_getMuertos(ePais* this,int* muertos)
{
    int retorno = 0;
    if(this != NULL && muertos!=NULL)
    {
        *muertos = this->muertos;
        retorno = 1;
    }
    return retorno;
}

void borrarObjeto(ePais* this )
{
    if ( this != NULL)
    {
        free(this);
    }
}

int mostrarObjeto(ePais* this)
{
    int retorno = 0;
    int id;
    char nombre[30];
    int recuperados;
    int infectados;
    int muertos;

    if(this != NULL)
    {
        pais_getId(this, &id);
        pais_getNombre(this, nombre);
        pais_getRecuperados(this, &recuperados);
        pais_getInfectados(this, &infectados);
        pais_getMuertos(this, &muertos);

        printf("%4d  %20s  %10d  %10d  %10d\n", id, nombre, recuperados, infectados, muertos);
        retorno = 1;
    }
    return retorno;
}
