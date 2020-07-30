#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"

int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    ePais* auxiliar;
    int retorno = 0;
    char id[100];
    char nombre[100];
    char recuperados[100];
    char infectados[100];
    char muertos[100];
    int flag = 1;

    if (pFile != NULL )
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, recuperados, infectados, muertos);
                flag = 0;
            }
            auxiliar = newObjeto();
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, recuperados, infectados, muertos);

            auxiliar = newObjetoParam(id, nombre, recuperados, infectados, muertos);
            if(auxiliar != NULL)
            {
                ll_add(pArrayList, auxiliar);
                retorno = 1;
            }
        }
    }
    else
    {
        printf("Error al parsear el archivo. Es NULL\n");
    }
    return retorno;
}
