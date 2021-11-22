/*
 * pilotos.h
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#ifndef PILOTOS_H_
#define PILOTOS_H_
#include "inputs.h"
#include "LinkedList.h"
typedef struct
{
	int Id;
	char Nombre[128];
}ePilotos;

ePilotos* pilotos_new();
ePilotos* pilotos_newParametros(char* id,char* Nombre);

void pilotos_delete(ePilotos* this);

int pilotos_setNombre(ePilotos* this,char* nombre);
int pilotos_getNombre(ePilotos* this,char* nombre);

int pilotos_setIdPilotos(ePilotos* this,int id);
int pilotos_getIdPilotos(ePilotos* this,int* id);

void pilotos_printPilotos(ePilotos* this);
#endif /* PILOTOS_H_ */
