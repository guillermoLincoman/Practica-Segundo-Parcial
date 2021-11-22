/*
 * parser.h
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "stdio.h"
#include "stdlib.h"
#include "LinkedList.h"
#include "vuelos.h"
#include "pilotos.h"
#ifndef PARSER_H_
#define PARSER_H_

int parser_VuelosFromText(FILE* pFile , LinkedList* pArrayListVuelos);
int parser_PilotosFromText(FILE* pFile , LinkedList* pArrayListPilotos);
#endif /* PARSER_H_ */
