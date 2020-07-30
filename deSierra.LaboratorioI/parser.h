#include "LinkedList.h"

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED


/** \brief Parsea los datos los datos de los objetos desde el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int 1(si pudo parsearlo)
               0(si no pudo)
 *
 */
 int parser_FromText(FILE* pFile, LinkedList* pArrayList);

