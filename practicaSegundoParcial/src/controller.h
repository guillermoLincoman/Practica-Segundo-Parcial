/*
 * controller.h
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "inputs.h"
#include "LinkedList.h"
#include "vuelos.h"
#include "pilotos.h"
#include "parser.h"

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromTextVuelos(char* path , LinkedList* pArrayListVuelos);
int controller_loadFromTextPilotos(char* path , LinkedList* pArrayListPilotos);
int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);
int controller_cantPasajeros(LinkedList* pArrayListVuelos);
int controller_cantPasajerosChina(LinkedList* pArrayListVuelos);
int controller_cantPasajerosChina(LinkedList* pArrayListVuelos);
int controller_vuelosCortos(LinkedList* pArrayListVuelos);
int controller_vuelosChina(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);
int controller_filtrarAlex(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);
int controller_saveAsText(char* path , LinkedList* pArrayListVuelos);

#endif /* CONTROLLER_H_ */
