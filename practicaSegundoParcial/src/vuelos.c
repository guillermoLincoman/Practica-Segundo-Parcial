/*
 * vuelos.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "vuelos.h"

/** \brief Inicializa un nuevo vuelo
 *
 *
 * \return Retorna un vuelo con sus campos inicializados
  */
eVuelos* vuelos_new()
{
	eVuelos* newVuelo = (eVuelos*)malloc(sizeof(eVuelos));
	//inicializo las variables
	if(newVuelo != NULL)
	{
		vuelos_setIdVuelo(newVuelo, 0);
		vuelos_setIdAvion(newVuelo, 0);
		vuelos_setIdPiloto(newVuelo, 0);
		vuelos_setFecha(newVuelo, 0, 0 ,0);
		vuelos_setDestino(newVuelo, " ");
		vuelos_setCantPasajeros(newVuelo, 0);
		vuelos_setHoraDespegue(newVuelo, 0);
		vuelos_setHoraLlegada(newVuelo, 0);
	}

	return newVuelo;
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
eVuelos* vuelos_newParametros(char* idVuelo,char* idAvion,char* idPiloto, char* dia, char* mes, char* anio, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
	eVuelos* vuelo = vuelos_new();
	if(vuelo != NULL && idVuelo != NULL && idAvion != NULL && idPiloto != NULL && dia != NULL && mes != NULL && anio != NULL && destino != NULL && cantPasajeros != NULL && horaDespegue != NULL && horaLlegada != NULL)
	{
		vuelos_setIdVuelo(vuelo, atoi(idVuelo));
		vuelos_setIdAvion(vuelo, atoi(idAvion));
		vuelos_setIdPiloto(vuelo, atoi(idPiloto));
		vuelos_setFecha(vuelo, atoi(dia), atoi(mes), atoi(anio));
		vuelos_setDestino(vuelo, destino);
		vuelos_setCantPasajeros(vuelo, atoi(cantPasajeros));
		vuelos_setHoraDespegue(vuelo, atoi(horaDespegue));
		vuelos_setHoraLlegada(vuelo, atoi(horaLlegada));
	}

	return vuelo;
}

/** \brief Borra un vuelo de la estructura
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 *
 */
void vuelos_delete(eVuelos* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



/** \brief Carga un id en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int idVuelo = id a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_setIdVuelo(eVuelos* this,int idVuelo)
{
	int error;
	error = 1;
	if(this != NULL && idVuelo>= 0)
	{
		this->idVuelo = idVuelo;
		error = 0;
	}
	return error;
}

/** \brief Obtiene un id del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int* idVuelo = id obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_getIdVuelo(eVuelos* this,int* idVuelo)
{
	int error;
	error = 1;
	if(this != NULL && idVuelo != NULL)
	{
		*idVuelo = this->idVuelo;
		error = 0;
	}
	return error;
}

/** \brief Carga un id en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int idAvion = id a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_setIdAvion(eVuelos* this,int idAvion)
{
	int error;
	error = 1;
	if(this != NULL && idAvion >= 0)
	{
		this->idAvion = idAvion;
		error = 0;
	}
	return error;
}

/** \brief Obtiene un id del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int* idAvion = id obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_getIdAvion(eVuelos* this,int* idAvion)
{
	int error;
	error = 1;
	if(this != NULL && idAvion != NULL)
	{
		*idAvion = this->idAvion;
		error = 0;
	}
	return error;
}

/** \brief Carga un id en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int idPiloto = id a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_setIdPiloto(eVuelos* this,int idPiloto)
{
	int error;
	error = 1;
	if(this != NULL && idPiloto > 0)
	{
		this->idPiloto = idPiloto;
		error = 0;
	}
	return error;
}

/** \brief Obtiene un id del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int* idPiloto = id obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_getIdPiloto(eVuelos* this,int* idPiloto)
{
	int error;
	error = 1;
	if(this != NULL && idPiloto != NULL)
	{
		*idPiloto = this->idPiloto;
		error = 0;
	}
	return error;
}

/** \brief Carga un id en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int dia = dia a cargar en la estructura.
 * \param int mes = mes a cargar en la estructura.
 * \param int anio = anio a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_setFecha(eVuelos* this,int dia, int mes, int anio)
{
	int error;
	error = 1;
	if(this != NULL)
	{
		 this->fecha.dia = dia;
		 this->fecha.mes = mes;
		 this->fecha.anio = anio;
		error = 0;
	}
	return error;
}

/** \brief Obtiene un id del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int* dia = dia obtenido de la estructura.
 * \param int* mes = mes obtenido de la estructura.
 * \param int* anio = anio obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int vuelos_getFecha(eVuelos* this,int* dia, int* mes, int* anio)
{
	int error;

	error = 1;
	if(this != NULL && dia != NULL && mes != NULL && anio != NULL)
	{

		*dia = this->fecha.dia;
		*mes = this->fecha.mes;
		*anio = this->fecha.anio;
		error = 0;
	}
	return error;
}

/** \brief Carga un destino en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param char* destino = destino a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int vuelos_setDestino(eVuelos* this,char* destino)
{
	int error;
	error=1;
	if(this != NULL && destino != NULL)
	{
		strncpy(this->destino, destino, 128);
		error = 0;
	}
	return error;
}

/** \brief Obtiene un destino del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param char* destino = destino obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int vuelos_getDestino(eVuelos* this,char* destino)
{
	int error;
	error=1;
	if(this != NULL && destino != NULL)
	{
		strncpy(destino, this->destino,128);
		error = 0;
	}
	return error;
}

/** \brief Carga una cantPasajeros en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int cantPasajeros = cantPasajeros a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int vuelos_setCantPasajeros(eVuelos* this,int cantPasajeros)
{
	int error;
	error = 1;
	if(this != NULL && cantPasajeros >= 0)
	{
		this->cantPasajeros = cantPasajeros;
		error = 0;
	}
	return error;
}

/** \brief Obtiene una cantPasajeros del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int* cantPasajeros = cantPasajeros obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int vuelos_getCantPasajeros(eVuelos* this,int* cantPasajeros)
{
	int error;
	error = 1;
	if(this != NULL && cantPasajeros != NULL)
	{
		*cantPasajeros = this->cantPasajeros;
		error = 0;
	}
	return error;
}

/** \brief Carga una horaDespegue en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int horaDespegue = horaDespegue a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int vuelos_setHoraDespegue(eVuelos* this,int horaDespegue)
{
	int error;
	error = 1;
	if(this != NULL && horaDespegue >= 0)
	{
		this->horaDespegue = horaDespegue;
		error = 0;
	}
	return error;
}

/** \brief Obtiene una horaDespegue del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int* horaDespegue = horaDespegue obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int vuelos_getHoraDespegue(eVuelos* this,int* horaDespegue)
{
	int error;
	error = 1;
	if(this != NULL && horaDespegue != NULL)
	{
		*horaDespegue = this->horaDespegue;
		error = 0;
	}
	return error;
}

/** \brief Carga una horaLlegada en el campo de la estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int horaLlegada = horaLlegada a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int vuelos_setHoraLlegada(eVuelos* this,int horaLlegada)
{
	int error;
	error = 1;
	if(this != NULL && horaLlegada >= 0)
	{
		this->horaLlegada = horaLlegada;
		error = 0;
	}
	return error;
}

/** \brief Obtiene una horaLlegada del campo de una estructura eVuelos
 *
 * \param eVuelos* this = puntero a estructura de vuelos
 * \param int* horaLlegada = horaLlegada obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int vuelos_getHoraLlegada(eVuelos* this,int* horaLlegada)
{
	int error;
	error = 1;
	if(this != NULL && horaLlegada != NULL)
	{
		*horaLlegada = this->horaLlegada;
		error = 0;
	}
	return error;
}

/** \brief Imprime un vuelo sin cabecera, Complementaria de funcion controller_ListEmployee
 *
 * \param Employee* this = puntero a empleado que se va a mostrar
 *
 */
void vuelos_printVuelos(eVuelos* this, ePilotos* thisPilotos)
{

	int aIdVuelo;
	int aIPiloto;
	int aIdAvion;
	int dia;
	int mes;
	int anio;
	char aNombrePiloto[128];
	char aDestino[128];
	int aCantPasajeros;
	int aHoraDespegue;
	int aHoraLlegada;
	if(this != NULL )
	{
		vuelos_getIdVuelo(this, &aIdVuelo);
		vuelos_getIdPiloto(this, &aIPiloto);
		vuelos_getIdAvion(this, &aIdAvion);
		vuelos_getFecha(this, &dia, &mes, &anio);
		vuelos_getDestino(this, aDestino);
		vuelos_getCantPasajeros(this, &aCantPasajeros);
		vuelos_getHoraDespegue(this, &aHoraDespegue);
		vuelos_getHoraLlegada(this, &aHoraLlegada);
		pilotos_getNombre(thisPilotos, aNombrePiloto);

		printf("|   %4d   |    %2d    |   %14s   | %2d/%2d/%4d | %14s |    %3d    |   %2d HS  |  %2d HS  |\n", aIdVuelo, aIdAvion, aNombrePiloto,dia, mes, anio, aDestino, aCantPasajeros, aHoraDespegue, aHoraLlegada);
	}
}


int vuelos_cantPasajes(void* pElement)
{
	int rtn;
	int pasajeros;
	rtn = 0;
	eVuelos* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eVuelos*) pElement;
		vuelos_getCantPasajeros(pAuxElement, &pasajeros);
		rtn = pAuxElement->cantPasajeros;
	}

	return rtn;
}

int vuelos_cantPasajesChina(void* pElement)
{
	int rtn;
	char destino[10] = "China";
	int cant;
	char pDestino[128];
	rtn = 0;
	eVuelos* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eVuelos*) pElement;
		vuelos_getDestino(pAuxElement, pDestino);
		if(strcmp(pDestino, destino) == 0)
		{
			vuelos_getCantPasajeros(pAuxElement, &cant);
			rtn = cant;
		}
	}

	return rtn;
}


int vuelos_vuelosCortos(void* pElement)
{
	int rtn;
	int despegue;
	int llegada;
	rtn = 0;
	eVuelos* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eVuelos*) pElement;
		vuelos_getHoraDespegue(pAuxElement, &despegue);
		vuelos_getHoraLlegada(pAuxElement, &llegada);
		despegue = despegue+2;
		if(despegue>= llegada)
		{
			rtn = 1;
		}

	}
	return rtn;
}

int vuelos_vuelosChina(void* pElement)
{
	int rtn;
	char destino[10] = "China";
	char pDestino[128];
	rtn = 0;
	eVuelos* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eVuelos*) pElement;
		vuelos_getDestino(pAuxElement, pDestino);
		if(strcmp(pDestino, destino)==0)
		{
			rtn = 1;
		}
	}
	return rtn;
}

int vuelos_filtrarAlex(void* pElement)
{
	int rtn;
	int idPiloto;
	rtn = 0;
	eVuelos* pAuxElement;
	if(pElement != NULL)
	{
		pAuxElement = (eVuelos*) pElement;
		vuelos_getIdPiloto(pAuxElement, &idPiloto);
		if(idPiloto != 1)
		{
			rtn = 1;
		}
	}
	return rtn;
}
