/*
 * vuelos.h
 *
 *  Created on: 18 nov. 2021
 *      Author: Compumar
 */
#include "inputs.h"
#include "pilotos.h"
#include "LinkedList.h"
#ifndef VUELOS_H_
#define VUELOS_H_

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    eFecha fecha;
    char destino[128];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}eVuelos;

eVuelos* vuelos_new();
eVuelos* vuelos_newParametros(char* idVuelo,char* idAvion,char* idPiloto, char* dia, char* mes, char* anio, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);
void vuelos_delete(eVuelos* this);

int vuelos_setIdVuelo(eVuelos* this,int idVuelo);
int vuelos_getIdVuelo(eVuelos* this,int* idVuelo);

int vuelos_setIdAvion(eVuelos* this,int idAvion);
int vuelos_getIdAvion(eVuelos* this,int* idAvion);

int vuelos_setIdPiloto(eVuelos* this,int idPiloto);
int vuelos_getIdPiloto(eVuelos* this,int* idPiloto);

int vuelos_setFecha(eVuelos* this,int dia, int mes, int anio);
int vuelos_getFecha(eVuelos* this,int* dia, int* mes, int* anio);

int vuelos_setDestino(eVuelos* this,char* destino);
int vuelos_getDestino(eVuelos* this,char* destino);

int vuelos_setCantPasajeros(eVuelos* this,int cantPasajeros);
int vuelos_getCantPasajeros(eVuelos* this,int* cantPasajeros);

int vuelos_setHoraDespegue(eVuelos* this,int horaDespegue);
int vuelos_getHoraDespegue(eVuelos* this,int* horaDespegue);

int vuelos_setHoraLlegada(eVuelos* this,int horaLlegada);
int vuelos_getHoraLlegada(eVuelos* this,int* horaLlegada);


void vuelos_printVuelos(eVuelos* this, ePilotos* thisPilotos);
int vuelos_cantPasajes(void* pElement);
int vuelos_cantPasajesChina(void* pElement);
int vuelos_vuelosCortos(void* pElement);
int vuelos_vuelosChina(void* pElement);
int vuelos_filtrarAlex(void* pElement);

/*
int employee_compareByName(void* emp1, void* emp2);
int employee_compareById(void* emp1, void* emp2);
int employee_compareBySueldo(void* emp1, void* emp2);
int employee_compareByHoras(void* emp1, void* emp2);
void employee_printOneEmployee(eVuelos* this);
void employee_printEmployee(eVuelos* this);
*/

#endif /* VUELOS_H_ */
