#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "pais.h"
#include "controller.h"
#include "validaciones.h"
#include "parser.h"
#include "informes.h"

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int retorno = 0;
    FILE* pFile;
    if(path != NULL && pArrayList != NULL)
    {

        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_FromText(pFile, pArrayList))
            {
                retorno = 1;
                printf("Archivo cargado correctamente. \n");
            }
            else
            {
                printf("No se pudo cargar el archivo.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\nEl archivo no pudo abrirse. Es NULL\n");
        }
    }

    return retorno;
}

int controller_Listar(LinkedList* pArrayList)
{
    int retorno = 0;
    int tam;
    int flag = 0;
    ePais* this;

    if( pArrayList != NULL)
    {
        retorno = 1;
        printf("\n  Id               Nombre         Recuperados Infectados  Muertos\n");
        printf("-------------------------------------------------------------------\n");

        tam = ll_len(pArrayList);
        for(int i = 0; i< tam; i++)
        {
            this = ll_get(pArrayList, i);
            if (  this  != NULL )
            {
                mostrarObjeto(this);
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf("\nNo hay datos que mostrar\n");
        }
    }
    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* f = NULL;
    ePais* auxiliar;
    int retorno = 0;
    int id;
    char nombre[30];
    int recuperados;
    int infectados;
    int muertos;
    int tam;

    if(path != NULL &&  pArrayList != NULL)
    {
        f = fopen(path,"w") ;
        fprintf(f,"id,nombre,recuperados,infectados,muertos\n");

        tam =  ll_len(pArrayList);
        for (int i =0; i<tam; i++)
        {
            auxiliar = (ePais*) ll_get(pArrayList, i);
            if (auxiliar !=NULL)
            {
                pais_getId(auxiliar, &id);
                pais_getNombre(auxiliar, nombre);
                pais_getRecuperados(auxiliar, &recuperados);
                pais_getInfectados(auxiliar, &infectados);
                pais_getMuertos(auxiliar, &muertos);

                fprintf(f, "%d,%s,%d,%d,%d\n", id, nombre, recuperados, infectados, muertos);
                retorno = 1;
            }
        }
        fclose(f);
        ll_clear(pArrayList);
    }
    return retorno;
}

int controller_sort(LinkedList* pArrayList)
{
    int retorno = -1;

    if( pArrayList != NULL)
    {
        retorno = ll_sort(pArrayList, compararPaisesXInfeccion, 0);
    }
    return retorno;
}

int controller_masCastigado(LinkedList* pArrayList)
{
    int retorno = 0;
    LinkedList* pCastigado = ll_newLinkedList();
    ePais* auxiliar = NULL;
    int masCastigado;
    int cantidadMuertos;
    int flag = 0;
    int tam;

    if(pArrayList != NULL && pCastigado != NULL)
    {
        tam = ll_len(pArrayList);
        for(int i = 0; i < tam; i++)
        {
            auxiliar = (ePais*) ll_get(pArrayList, i);
            pais_getMuertos(auxiliar, &cantidadMuertos);
            if(flag == 0 || cantidadMuertos > masCastigado)
            {
                masCastigado = cantidadMuertos;
                flag = 1;
            }
        }
        for(int i = 0; i < tam; i++)
        {
            auxiliar = (ePais*) ll_get(pArrayList, i);
            pais_getMuertos(auxiliar, &cantidadMuertos);
            if(cantidadMuertos == masCastigado)
            {
                ll_add(pCastigado, auxiliar);
                retorno = 1;
            }
        }
        printf("Paises mas castigados\n");
        printf("---------------------\n");
        controller_Listar(pCastigado);
    }
    return retorno;
}
