/// FUNCIONES PASSENGER
/// Passenger.h
/// @date 19 may. 2022
/// @author Maru
///	Modificado por: Heredia Facundo - 1F - 1C 2022

#ifndef PASSENGER_H_
#define PASSENGER_H_

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "inputs.h"
#include "LinkedList.h"
#include "hud_menu.h"
#include "mensajes.h"

//	=========
//	> DEFINES
//	=========
//	>> DATOS DE ESTRUCTURA
#define LONGITUD_NOMBRE 50
#define LONGITUD_CODIGOVUELO 10
#define LONGITUD_ID 10
#define LONGITUD_PRECIO 50
#define PRECIO_MINIMO 0
#define PRECIO_MAXIMO 1000000
//	>> DEFINEs CODIGO DE VUELO
#define CODIGO_DE_VUELO_MINIMO 1
#define CODIGO_DE_VUELO_MAXIMO 8
//	>> DEFINEs TIPO PASAJERO
#define TIPO_PASAJERO_MINIMO 1
#define TIPO_PASAJERO_MAXIMO 3
//	>> ARCHIVO DE GUARDADO DE ULTIMO ID CREADO POR EL PROGRAMA
#define ARCHIVO_ULTIMO_ID_GENERADO "..\\ultimoIdGenerado.txt"

//	======================
//	> ESTRUCTURA PASSENGER
//	======================
//	>> ESTRUCTURA DADA
/*
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;
}Passenger;
*/
//	>> ESTRUCTURA MODIFICADA
typedef struct
{
	int id;
	char nombre[LONGITUD_NOMBRE];
	char apellido[LONGITUD_NOMBRE];
	float precio;
	char codigoVuelo[LONGITUD_CODIGOVUELO];
	char tipoPasajero[LONGITUD_NOMBRE];
	char statusFlight[LONGITUD_NOMBRE];
}Passenger;

//	=====================
//	> FUNCIONES PASSENGER
//	=====================
/// @brief Constructor que obtiene un espacio en memoria para una estructura de Pasajero
///
/// @return retorno un puntero a la estructura o NULL en caso de no poder
Passenger* Passenger_new();

//ORIGINAL
//Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr);
//MODIFICADA
/// @brief Nueva estructura de Pasajero donde se ingresan los datos por parametros
///
/// @param idStr puntero a donde guardar el id
/// @param nombreStr puntero a donde guardar el nombre
/// @param apellidoStr puntero a donde guardar el apellido
/// @param precioStr puntero a donde guardar el precio
/// @param tipoPasajeroStr puntero a donde guardar el tipo de pasajero
/// @param codigoVueloStr puntero a donde guardar el codigo de vuelo
/// @param statusFlightStr puntero a donde guardar el estado de vuelo
/// @return Devuelve un puntero al Pasajero creado sino NULL
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlightStr);

/// @brief Libera el espacio en memoria ocupado por el pasajero
///
/// @param this el puntero donde se guarda el pasajero a borrar
void Passenger_delete(Passenger* this);

/// @brief Encuentra el id en la lista segun el id pasado por parametro
///
/// @param pArrayListPassenger puntero a la lista donde buscar
/// @param id el puntero al id a buscar dentro de la lista
/// @return Si lo encuentra retorna el id encontrado, si no -1 [ERROR]
int Passenger_encontrarId(LinkedList* pArrayListPassenger, int* id);

/// @brief Muestra los datos de un pasajero
///
/// @param this el puntero al pasajero a mostrar
void Passenger_mostrarUnPasajero (Passenger* this);

/// @brief Modifica los datos de un pasajero
///
/// @param this el puntero al pasajero a modificar
void Passenger_modificarUno(Passenger* this);

/// @brief Muestra los tipos de pasajeros
///
void Passenger_ImprimirTipoPasajero(void);

/// @brief Muestra los codigos de vuelo
///
void Passenger_ImprimirCodigosDeVuelo(void);

/// @brief Asigna el codigo de vuelo seleccionado al pasajero
///
/// @param this el puntero al pasajero donde se asigna el codigo
/// @param opcion la opcion del codigo elegida
void Passenger_AsignarCodigosDeVuelo(Passenger* this, int opcion);

/// @brief Asigna el codigo de vuelo con su estado al pasajero version char
///
/// @param opcion la opcion del codigo elegida
/// @param codigoVuelo el puntero donde se guarda el codigo
/// @param estadoVuelo el puntero donde se guarda el estado
void Passenger_AsignarCodigosDeVueloTxt(int opcion, char* codigoVuelo, char* estadoVuelo);

/// @brief Asigna el tipo de pasajero seleccionado al pasajero
///
/// @param this el puntero al pasajero donde se asigna el tipo de pasajero
/// @param opcion la opcion del tipo pasajero elegida
void Passenger_AsignarTipoPasajero(Passenger* this, int opcion);

/// @brief Asigna el tipo de pasajero seleccionado al pasajero en version char
///
/// @param opcion del tipo de pasajero a asignar
/// @param tipoPasajero el puntero donde se va a guardar el tipo de pasajero
void Passenger_AsignarTipoPasajeroTxt(int opcion, char* tipoPasajero);

/// @brief Nueva estructura de Pasajero donde se ingresan los datos por parametros para el alta individual
///
/// @param idStr puntero a donde guardar el id
/// @param nombreStr puntero a donde guardar el nombre
/// @param apellidoStr puntero a donde guardar el apellido
/// @param precioStr puntero a donde guardar el precio
/// @param tipoPasajeroStr puntero a donde guardar el tipo de pasajero
/// @param codigoVueloStr puntero a donde guardar el codigo de vuelo
/// @param statusFlightStr puntero a donde guardar el estado de vuelo
/// @return Devuelve un puntero al Pasajero creado sino NULL
Passenger* Passenger_newParametrosModificada(int* id, char* nombreStr, char* apellidoStr, float* precio, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlightStr);

/// @brief Funcion que ordena por id de pasajero
///
/// @param pElementoUno puntero a void del primer "pasajero" a comparar
/// @param pElementoDos puntero a void del segundo "pasajero" a comparar
/// @return Retorna -1, 0 ,1 segun el resultado de la comparacion
int Passenger_ordenarPorId(void* pElementoUno, void* pElementoDos);

/// @brief Funcion que ordena por nombre
///
/// @param pElementoUno puntero a void del primer "pasajero" a comparar
/// @param pElementoDos puntero a void del segundo "pasajero" a comparar
/// @return Retorno numero igual a 0, menor a 0 o mayor a 0 segun resultado de la comparacion
int Passenger_ordenarPorNombre(void* pElementoUno, void* pElementoDos);

/// @brief Funcion que ordena por apellido
///
/// @param pElementoUno puntero a void del primer "pasajero" a comparar
/// @param pElementoDos puntero a void del segundo "pasajero" a comparar
/// @return Retorno numero igual a 0, menor a 0 o mayor a 0 segun resultado de la comparacion
int Passenger_ordenarPorApellido(void* pElementoUno, void* pElementoDos);

/// @brief Funcion que ordena por precio
///
/// @param pElementoUno puntero a void del primer "pasajero" a comparar
/// @param pElementoDos puntero a void del segundo "pasajero" a comparar
/// @return Retorna -1, 0 ,1 segun el resultado de la comparacion
int Passenger_ordenarPorPrecio(void* pElementoUno, void* pElementoDos);

/// @brief Funcion que ordena por codigo de vuelo
///
/// @param pElementoUno puntero a void del primer "pasajero" a comparar
/// @param pElementoDos puntero a void del segundo "pasajero" a comparar
/// @return Retorno numero igual a 0, menor a 0 o mayor a 0 segun resultado de la comparacion
int Passenger_ordenarPorCodigoVuelo(void* pElementoUno, void* pElementoDos);

/// @brief Funcion que ordena por Tipo de Pasajero
///
/// @param pElementoUno puntero a void del primer "pasajero" a comparar
/// @param pElementoDos puntero a void del segundo "pasajero" a comparar
/// @return Retorno numero igual a 0, menor a 0 o mayor a 0 segun resultado de la comparacion
int Passenger_ordenarPorTipoPasajero(void* pElementoUno, void* pElementoDos);

/// @brief Funcion que ordena por estado de vuelo
///
/// @param pElementoUno puntero a void del primer "pasajero" a comparar
/// @param pElementoDos puntero a void del segundo "pasajero" a comparar
/// @return Retorno numero igual a 0, menor a 0 o mayor a 0 segun resultado de la comparacion
int Passenger_ordenarPorEstadoVuelo(void* pElementoUno, void* pElementoDos);

//	=====================
//	> FUNCIONES SET Y GET
//	=====================
//ORIGINAL
/// @brief Ingresa el id del pasajero pasado en modo entero
///
/// @param this el puntero al pasajero
/// @param id int el id del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setId(Passenger* this,int* id);
//MODIFICADA
/// @brief Ingresa el id del pasajero pasado en modo texto
///
/// @param this el puntero al pasajero
/// @param id char el id del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setIdTxt(Passenger* this,char* id);
//ORIGINAL
/// @brief Obtiene el id del pasajero pasado en modo entero
///
/// @param this el puntero al pasajero
/// @param id int el id del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getId(Passenger* this,int* id);
//MODIFICADA
/// @brief Obtiene el id del pasajero pasado en modo texto
///
/// @param this el puntero al pasajero
/// @param id char el id del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getIdTxt(Passenger* this,char* id);

/// @brief Ingresa el nombre del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param nombre el nombre del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief Obtiene el nombre del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param nombre el nombre del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief Ingresa el apellido del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param apellido el apellido del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief Obtiene el apellido del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param apellido el apellido del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief Ingresa el codigo de vuelo del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param codigoVuelo el codigo de vuelo del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Obtiene el codigo de vuelo del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param codigoVuelo el codigo de vuelo del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Ingresa el tipo de pasajero del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param tipoPasajero el tipo de pasajero del pasaje
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

/// @brief Obtiene el tipo de pasajero del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param tipoPasajero el tipo de pasajero del pasaje
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/// @brief Ingresa el precio del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param precio el valor del pasaje
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setPrecio(Passenger* this,float* precio);

/// @brief Ingresa el precio del pasajero pasado en char
///
/// @param this el puntero al pasajero
/// @param precio el valor del pasaje
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setPrecioTxt(Passenger* this,char* precio);

/// @brief Obtiene el precio del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param precio el valor del pasaje
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief Ingresa el estado de Vuelo del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param statusFlight estado de vuelo del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_setEstadoDeVuelo(Passenger* this, char* statusFlight);

/// @brief Obtiene el estado de Vuelo del pasajero pasado
///
/// @param this el puntero al pasajero
/// @param statusFlight estado de vuelo del pasajero
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getEstadoDeVuelo(Passenger* this, char* statusFlight);

/// @brief Obtiene el ultimo id generado
///
/// @param id el puntero donde se va a guardar el ultimo id generado
/// @return retorno -1 [Error] o 0 [Ok]
int Passenger_getUltimoId(int* id);

/// @brief Pone el ultimo id generado
///
/// @param id int el id generado para cargarlo en el archivo
/// @return
int Passenger_setUltimoId(int id);

#endif /* PASSENGER_H_ */
