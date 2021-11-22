/*
 * parser.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */

#include "parser.h"

/** \brief Parsea los datos los datos de los vuelos desde el archivo vuelos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int parser_VuelosFromText(FILE* pFile , LinkedList* pArrayListVuelos)
{
	int error;
	char aIdVuelo[60];
	char aIdPiloto[60];
	char aIdAvion[60];
	char aFecha[60];
	char aFechaDia[60];
	char aFechaMes[60];
	char aFechaAnio[60];
	char aDestino[128];
	char aCantPasajeros[60];
	char aHoraDespegue[60];
	char aHoraLlegada[60];
	eVuelos* vuelo;
	int aux;
	error = 1;


	if(pFile != NULL && pArrayListVuelos != NULL)
	{
		//1. Tomo la cabecera del archivo
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",aIdVuelo,aIdAvion,aIdPiloto,aFecha,aDestino,aCantPasajeros,aHoraDespegue,aHoraLlegada);
		//2. Repito hasta llegar al final de archivo
		while(!feof(pFile))
		{
			//3. cuento que lea los datos necesarios y los cargo en aux
			aux =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n",aIdVuelo,aIdAvion,aIdPiloto,aFechaDia, aFechaMes, aFechaAnio,aDestino,aCantPasajeros,aHoraDespegue,aHoraLlegada);
			if(aux == 10)
			{
				//4. cargo los datos leidos en el empleado
				vuelo = vuelos_newParametros(aIdVuelo,aIdAvion,aIdPiloto,aFechaDia, aFechaMes, aFechaAnio,aDestino,aCantPasajeros,aHoraDespegue,aHoraLlegada);
				//5. valido que el empleado no sea nulo
				if(vuelo!=NULL)
				{
					//6. en caso de cargar el empleado retorna 0
					aux = ll_add(pArrayListVuelos, vuelo);
					if(aux != 0)
					{
						//7. Si retorna un numero diferente a 0 borro el empleado y rompo la condicion while
						vuelos_delete(vuelo);
						error = 1;
						break;
					}else{
						error = 0;
					}
				}
			}else{
				break;
			}
		}

	}

    return error;
}

/** \brief Parsea los datos los datos de los pilotos desde el archivo pilotos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int parser_PilotosFromText(FILE* pFile , LinkedList* pArrayListPilotos)
{
	int error;
	char aId[60];
	char aNombre[128];
	ePilotos* pilotos;
	int aux;
	error = 1;

	if(pFile != NULL && pArrayListPilotos != NULL)
	{

		//1. Cabecera del archivo
		fscanf(pFile,"%[^,],%[^\n]\n",aId,aNombre);
		//2. Repito hasta llegar al final de archivo
		while(!feof(pFile))
		{

			//3. cuento que lea los datos necesarios y los cargo en aux
			aux = fscanf(pFile,"%[^,],%[^\n]\n",aId,aNombre);
			if(aux == 2)
			{
				//4. cargo los datos leidos en el empleado
				pilotos = pilotos_newParametros(aId, aNombre);
				//5. valido que el empleado no sea nulo
				if(pilotos != NULL)
				{
					//6. en caso de cargar el empleado retorna 0
					aux = ll_add(pArrayListPilotos, pilotos);
					if(aux != 0)
					{
						//7. Si retorna un numero diferente a 0 borro el empleado y rompo la condicion while
						pilotos_delete(pilotos);
						error = 1;
						break;
					}else{
						error = 0;
					}
				}
			}else{
				break;
			}
		}

	}

    return error;
}

