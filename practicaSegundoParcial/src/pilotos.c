/*
 * pilotos.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "pilotos.h"


/** \brief Inicializa un nuevo piloto
 *
 *
 * \return Retorna un vuelo con sus campos inicializados
  */
ePilotos* pilotos_new()
{
	ePilotos* newPiloto = (ePilotos*)malloc(sizeof(ePilotos));
	//inicializo las variables
	if(newPiloto != NULL)
	{
		pilotos_setIdPilotos(newPiloto, 0);
		pilotos_setNombre(newPiloto, " ");

	}

	return newPiloto;
}

/** \brief Carga un vuelo con parametros recibidos
 *
 * \param char* idVuelo = idVuelo a cargar en la estructura.
 * \param char* idAvion = idAvion a cargar en la estructura.
 * \param char* idPiloto = idPiloto trabajadas a cargar en la estructura.
 * \param char* dia = dia a cargar en la estructura.
 * \param char* mes = mes a cargar en la estructura.
 * \param char* anio = anio a cargar en la estructura.
 * \param char* destino = destino a cargar en la estructura.
 * \param char* cantPasajeros = cantPasajeros a cargar en la estructura.
 * \param char* horaDespegue = horaDespegue a cargar en la estructura.
 * \param char* horaLlegada = horaLlegada trabajadas a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
ePilotos* pilotos_newParametros(char* id,char* Nombre)
{
	ePilotos* vuelo = pilotos_new();
	if(id != NULL && Nombre != NULL)
	{
		pilotos_setIdPilotos(vuelo, atoi(id));
		pilotos_setNombre(vuelo, Nombre);
	}

	return vuelo;
}

/** \brief Borra un piloto de la estructura
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 *
 */
void pilotos_delete(ePilotos* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/** \brief Carga un nombre en el campo de la estructura ePilotos
 *
 * \param ePilotos* this = puntero a estructura de pilotos
 * \param char* nombre = nombre a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int pilotos_setNombre(ePilotos* this,char* nombre)
{
	int error;
	error=1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->Nombre, nombre, 128);
		error = 0;
	}
	return error;
}

/** \brief Obtiene un nombre del campo de una estructura ePilotos
 *
 * \param ePilotos* this = puntero a estructura de pilotos
 * \param char* nombre = nombre obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int pilotos_getNombre(ePilotos* this,char* nombre)
{
	int error;
	error=1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->Nombre,128);
		error = 0;
	}
	return error;
}

/** \brief Carga un id en el campo de la estructura ePilotos
 *
 * \param eVuelos* this = puntero a estructura de ePilotos
 * \param int id = id a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int pilotos_setIdPilotos(ePilotos* this,int id)
{
	int error;
	error = 1;
	if(this != NULL && id > 0)
	{
		this->Id = id;
		error = 0;
	}
	return error;
}

/** \brief Obtiene una id del campo de una estructura ePilotos
 *
 * \param eVuelos* this = puntero a estructura de ePilotos
 * \param int* id = id obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int pilotos_getIdPilotos(ePilotos* this,int* id)
{
	int error;
	error = 1;
	if(this != NULL && id != NULL)
	{
		*id = this->Id;
		error = 0;
	}
	return error;
}


/** \brief Imprime un vuelo sin cabecera, Complementaria de funcion controller_ListEmployee
 *
 * \param Employee* this = puntero a empleado que se va a mostrar
 *
 */
void pilotos_printPilotos(ePilotos* this)
{
	int aIdPiloto;
	char aNombre[128];

	if(this != NULL )
	{
		pilotos_getIdPilotos(this, &aIdPiloto);
		pilotos_getNombre(this, aNombre);

		printf("|   %4d   | %14s |\n", aIdPiloto, aNombre);
	}
}
