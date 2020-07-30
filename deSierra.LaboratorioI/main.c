#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "pais.h"
#include "controller.h"
#include "validaciones.h"
#include "parser.h"
#include "informes.h"

int main()
{
    srand (time(NULL));
    char seguir = 's';
    char archivo[20];
    int flag = 0;
    int flag3 = 0;
    LinkedList* lista = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese el nombre del archivo que desea cargar: (pandemia.csv)\n");
            scanf("%s", archivo);
            controller_loadFromText(archivo, lista);
            flag = 1;
            system("pause");
            break;
        case 2:
            if( flag == 1 &&  !ll_isEmpty(lista))
            {
                controller_Listar(lista);
            }
            else
            {
                printf("La lista de paises esta vacia. Primero debe cargar el archivo\n");
            }
            system("pause");
            break;
        case 3:
            if( flag == 1  &&  !ll_isEmpty(lista))
            {
                lista = ll_map(lista, asignarEstadisticas);
                flag3 = 1;
                controller_Listar(lista);
            }
            else
            {
                printf("No se pudo asignar nuevas estadisticas ya que la lista esta vacia. Primero debe cargar el archivo\n");
            }
            system("pause");
            break;
        case 4:
            if( !ll_isEmpty(lista))
            {
                filtrarPorPaisesExitosos(lista);
            }
            else
            {
                printf("La lista de paises esta vacia. Primero debe cargar el archivo\n");
            }
            system("pause");
            break;
        case 5:
            if( !ll_isEmpty(lista))
            {
                filtrarPorPaisesEnElHorno(lista);
            }
            else
            {
                printf("La lista de paises esta vacia. Primero debe cargar el archivo\n");
            }
            system("pause");
            break;
        case 6:
            if(flag3 == 1 &&  !ll_isEmpty(lista))
            {
                if (controller_sort(lista) != -1)
                {
                    controller_Listar(lista);
                }
            }
            else
            {
                printf("La lista de paises esta vacia. Primero debe cargar el archivo\n");
            }
            system("pause");
            break;
        case 7:
            if( !ll_isEmpty(lista))
            {
                controller_masCastigado(lista);
            }
            else
            {
                printf("La lista de paises esta vacia. Primero debe cargar el archivo\n");
            }
            system("pause");
            break;
        case 8:
            seguir = 'n';
            break;
        default:
            printf("Ingreso una opcion invalida. Reingrese\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');
    ll_deleteLinkedList(lista);
    return 0;
}
