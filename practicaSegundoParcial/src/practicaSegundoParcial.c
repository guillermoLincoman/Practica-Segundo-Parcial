/*
 ============================================================================
 Name        : practicaSegundoParcial.c
 Author      : Guillermo Lincoman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "menu.h"

int main(void) {
{
		setbuf(stdout, NULL);
		LinkedList* vuelos = ll_newLinkedList();
		LinkedList* pilotos = ll_newLinkedList();
		int error;
		int flagPiloto;
		int flagVuelo;
		int opcion;
		flagPiloto = 1;
		flagVuelo = 1;
		do{
			menuPrincipal();
			opcion = cargarUnEntero("Ingrese una opcion: ", "Error, ingrese una opcion", 1, 9, 4);
			switch(opcion)
			{
				case 1:
					printf("=============================\n");
					printf("| CARGAR ARCHIVO DE PILOTOS |\n");
					printf("=============================\n");
					error= controller_loadFromTextPilotos("pilotos.csv", pilotos);
					if(error == 0){
						printf("\nEl archivo fue cargado con exito....\n");
						flagPiloto = 0;
					}else{
						printf("\nHubo un error al cargar el archivo....\n");
					}
					limpiar();
					break;
				case 2:
					if(flagPiloto == 0)
					{
						printf("============================\n");
						printf("| CARGAR ARCHIVO DE VUELOS |\n");
						printf("============================\n");
						error = controller_loadFromTextVuelos("Vuelos.csv", vuelos);
						if(error == 0){
							printf("\nEl archivo fue cargado con exito....\n");
							flagVuelo = 0;
						}else{
							printf("\nHubo un error al cargar el archivo....\n");
						}
					}else{
						printf("\nNo se pueden cargar los Vuelos sin antes cargar los Pilotos....\n");
					}
					limpiar();
					break;
				case 3:
					if(flagVuelo == 0){
						controller_ListVuelos(vuelos, pilotos);
					}else{
						printf("\nPara Imprimir Vuelos, cargue el archivo de Vuelos....\n");
					}
					limpiar();
					break;
				case 4:
					if(flagVuelo == 0){
						controller_cantPasajeros(vuelos);
					}else{
						printf("\nPara Calcular la Cantidad de Pasajeros, cargue el archivo de Vuelos....\n");
					}
					limpiar();
					break;
				case 5:
					if(flagVuelo == 0){
						controller_cantPasajerosChina(vuelos);
					}else{
						printf("\nPara Calcular la Cantidad de Pasajeros a China, cargue el archivo de Vuelos....\n");
					}
					limpiar();
					break;
				case 6:
					if(flagVuelo == 0){
						controller_vuelosCortos(vuelos);
					}else{
						printf("\nPara Filtrar los vuelos cortos, cargue el archivo de Vuelos....\n");
					}
					limpiar();
					break;
				case 7:
					if(flagVuelo == 0){
						controller_vuelosChina(vuelos, pilotos);
					}else{
						printf("\nPara Filtrar los vuelos a china, cargue el archivo de Vuelos....\n");
					}
					limpiar();
					break;
				case 8:
					if(flagVuelo == 0){
						controller_filtrarAlex(vuelos, pilotos);
					}else{
						printf("\nPara imprimir los vuelos Filtrando a Alex Lifeson, cargue el archivo de Vuelos....\n");
					}
					limpiar();
					break;
			}
		}while(opcion != 9);

	    return 0;
	}
}
