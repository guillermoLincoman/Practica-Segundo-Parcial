/*
 * controller.c
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */

#include "controller.h"

int controller_loadFromTextVuelos(char* path , LinkedList* pArrayListVuelos)
{
	int error;
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListVuelos != NULL)
	{
		//1. Abro el archivo en modo escritura

		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			error = parser_VuelosFromText(pArchivo, pArrayListVuelos);
		}

		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

int controller_loadFromTextPilotos(char* path , LinkedList* pArrayListPilotos)
{
	int error;
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListPilotos != NULL)
	{
		//1. Abro el archivo en modo escritura

		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			error = parser_PilotosFromText(pArchivo, pArrayListPilotos);
		}

		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	int error;
	int i;
	int j;
	int len;
	int lenPiloto;
	eVuelos* newVuelos;
	newVuelos = vuelos_new();
	ePilotos* newPiloto;
	newPiloto = pilotos_new();
	int idPiloto;
	int auxIdPiloto;
	error = 1;
	if(newVuelos != NULL && pArrayListVuelos != NULL)
	{
		len = ll_len(pArrayListVuelos);
		lenPiloto = ll_len(pArrayListVuelos);
		if(len > 1)
		{
			error = 0;
			printf("\n _________________________________________________________________________________________________________\n");
			printf("|=========================================================================================================|\n");
			printf("|==============================================AEROLINEAS UTN=============================================|\n");
			printf("|_________________________________________________________________________________________________________|\n");
			printf("| ID VUELO | ID AVION |       PILOTO       |   FECHA    |    DESTINOS    | PASAJEROS | DESPEGUE | LLEGADA |\n");
			printf("|__________|__________|____________________|____________|________________|___________|__________|_________|\n");


			for (i = 0; i < len; ++i) {
				newVuelos = ll_get(pArrayListVuelos, i);
				vuelos_getIdPiloto(newVuelos, &idPiloto);
				for (j = 0; j < lenPiloto; ++j) {
					newPiloto = ll_get(pArrayListPilotos, j);
					pilotos_getIdPilotos(newPiloto, &auxIdPiloto);
					if(idPiloto == auxIdPiloto){
						break;
					}
				}
				printf("|----------|----------|--------------------|------------|----------------|-----------|----------|---------|\n");
				vuelos_printVuelos(newVuelos, newPiloto);
				if(len-1 == i){
					printf("|__________|__________|____________________|____________|________________|___________|__________|_________|\n");
				}
			}

		}
	}

    return error;
}

int controller_ListPilotos(LinkedList* pArrayListPilotos)
{
	int error;
	int i;
	int len;
	ePilotos* newPiloto;
	newPiloto = pilotos_new();
	error = 1;
	if(newPiloto != NULL && pArrayListPilotos != NULL)
	{
		len = ll_len(pArrayListPilotos);
		if(len > 1)
		{
			error = 0;
			printf("\n ___________________________\n");
			printf("|                           |\n");
			printf("|======= PILOTOS UTN =======|\n");
			printf("|___________________________|\n");
			printf("| ID VUELO |     PILOTO     |\n");
			printf("|__________|________________|\n");

			for (i = 0; i < len; ++i) {
				newPiloto = ll_get(pArrayListPilotos, i);
				printf("|----------|----------------|\n");
				pilotos_printPilotos(newPiloto);
				if(len-1 == i){
				printf("|__________|________________|\n");
				}
			}

		}
	}

    return error;
}

int controller_cantPasajeros(LinkedList* pArrayListVuelos)
{
	int error;
	int cantidad;
	cantidad = 0 ;
	error = 1;
	if(pArrayListVuelos != NULL)
	{
		error = 0;
		cantidad = ll_count(pArrayListVuelos, vuelos_cantPasajes);
		printf("\nLa cantidad de pasajeros es: %d\n", cantidad);

	}
	return error;
}

int controller_cantPasajerosChina(LinkedList* pArrayListVuelos)
{
	int error;
	int cantidad;
	cantidad = 0 ;
	error = 1;
	if(pArrayListVuelos != NULL)
	{
		error = 0;
		cantidad = ll_count(pArrayListVuelos, vuelos_cantPasajesChina);
		printf("\nLa cantidad de pasajeros a china es: %d\n", cantidad);
	}
	return error;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* = Direccion del archivo
 * \param pArrayListEmployee LinkedList* = Lista donde se van a guardar los datos
 *
 * \return int error = Si los datos se guardan correctamente retorna 0, en caso de error retorna 1
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListVuelos)
{
	int aIdVuelo;
	int aIPiloto;
	int aIdAvion;
	int dia;
	int mes;
	int anio;
	char aDestino[128];
	int aCantPasajeros;
	int aHoraDespegue;
	int aHoraLlegada;
	int len;
	int i;
	int error;
	eVuelos* newVuelo;
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListVuelos != NULL)
	{
		printf("*--------------------------*\n");
		printf("| GUARDAR ARCHIVO DE TEXTO |\n");
		printf("*--------------------------*");
		//1. Abro el archivo en modo escritura
		pArchivo = fopen(path, "w");

		//2. Asigno espacio en memoria para el puntero a empleado
		newVuelo = vuelos_new();

		//3. Obtengo el tamaño de la lista
		len = ll_len(pArrayListVuelos);

		//4. Coloco la cabecera
		fprintf(pArchivo, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
		for(i=0; i<len;i++)
		{
			//5. obtengo el empleado con sus datos
			newVuelo = ll_get(pArrayListVuelos, i);
			if(newVuelo != NULL)
			{
				//6. le paso los datos el empleado a las variables

				vuelos_getIdVuelo(newVuelo, &aIdVuelo);
				vuelos_getIdPiloto(newVuelo, &aIPiloto);
				vuelos_getIdAvion(newVuelo, &aIdAvion);
				vuelos_getFecha(newVuelo, &dia, &mes, &anio);
				vuelos_getDestino(newVuelo, aDestino);
				vuelos_getCantPasajeros(newVuelo, &aCantPasajeros);
				vuelos_getHoraDespegue(newVuelo, &aHoraDespegue);
				vuelos_getHoraLlegada(newVuelo, &aHoraLlegada);
				//7. Escribo los datos del empleado en el archivo
				fprintf(pArchivo, "%d,%d,%d,%d/%d/%d,%s,%d,%d,%d\n", aIdVuelo,aIPiloto,aIdAvion,dia,mes,anio,aDestino,aCantPasajeros,aHoraDespegue,aHoraLlegada);
				error = 0;
			}else{
				error = 1;
				break;
			}
		}
		fclose(pArchivo);
	}

    return error;
}

int controller_vuelosCortos(LinkedList* pArrayListVuelos)
{
	int error;
	LinkedList* vuelosCortos = NULL;
	error = 1;
	if(pArrayListVuelos != NULL)
	{
		vuelosCortos = ll_newLinkedList();
		if(vuelosCortos != NULL)
		{
			vuelosCortos = ll_filter(pArrayListVuelos, vuelos_vuelosCortos);
			error = controller_saveAsText("vuelosCortos.csv", vuelosCortos);
			if(error == 0){
				printf("\nEl archivo con vuelos cortos fue creado con exito...\n");
			}
		}

	}
	return error;
}

int controller_vuelosChina(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	int error;
	LinkedList* vuelosChina = NULL;
	error = 1;
	if(pArrayListVuelos != NULL)
	{
		vuelosChina = ll_newLinkedList();
		if(vuelosChina != NULL)
		{
			vuelosChina = ll_filter(pArrayListVuelos, vuelos_vuelosChina);
			error = controller_saveAsText("vuelosChina.csv", vuelosChina);
			if(error == 0){
				printf("\nEl archivo con vuelos a china fue creado con exito...\n");
			}
		}

	}
	return error;
}

int controller_filtrarAlex(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	int error;
	LinkedList* vuelosCortos = NULL;
	error = 1;
	if(pArrayListVuelos != NULL)
	{
		vuelosCortos = ll_newLinkedList();
		if(vuelosCortos != NULL)
		{
			error = 0;
			vuelosCortos = ll_filter(pArrayListVuelos, vuelos_filtrarAlex);
			controller_ListVuelos(vuelosCortos, pArrayListPilotos);
		}

	}
	return error;
}
