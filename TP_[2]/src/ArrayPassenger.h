/// Funciones ArrayPassenger.h
/// @author HEREDIA, FACUNDO GASTON
///
/// @date 23-04-2022

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include <stdio.h>
#include <string.h>
#include "hud_menu.h"
#include "mensajes.h"
#include "inputs.h"

//	==============
//	> DEFINICIONES
//	==============
#define ID_MINIMO 1001
#define CANTIDAD_MAXIMA_PASAJEROS 2000	// MODIFICAR SEGUN LIMITE REQUERIDO DE PASAJEROS
#define INICIALIZACION_PASAJERO 1000
#define LIBRE 0							// USADA EN .isEmpty -> TRUE = libre
#define OCUPADO 1
#define LONGITUD_CODIGO_VUELO 64
#define LONGITUD_NOMBRE_PASAJERO 51
//Tipos pasajeros						EJECUTIVA | PRIMERA CLASE | ECONOMICA
#define LONGITUD_DE_TIPO_PASAJERO 3
#define EJECUTIVO 2
#define PRIMERA_CLASE 1
#define ECONOMICO 0
//Estados de vuelo						CANCELADO | REPROGRAMADO | ABORDANDO | ARRIBO | A TIEMPO
#define LONGITUD_ESTADO_VUELO 5
#define A_TIEMPO 0
#define	ABORDANDO 1
#define ARRIBO 2
#define	REPROGRAMADO 3
#define	CANCELADO 4
//Precios
#define MONTO_MINIMO_PRECIO 0
#define MONTO_MAXIMO_PRECIO 1000000
//Ordenar
#define UP 1
#define DOWN 0

//	==============
//	> ESTRUCTURAS
//	==============
struct
{
	int id;
	char name[LONGITUD_NOMBRE_PASAJERO];
	char lastname[LONGITUD_NOMBRE_PASAJERO];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;

struct
{
	int idEstadoVuelo;
	char estadoVuelo[20];
}typedef EstadosDeVuelo;

struct
{
	int idTiposDePasajeros;
	char tiposDePasajeros[20];
}typedef TiposPasajeros;

//	=========================================
//	> FUNCIONES DADAS POR EL TRABAJO PRACTICO
//	=========================================

/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in all
/// position of the array
/// @param list Passenger* Pointer to array of passenger
/// @param len int Array length
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initPassengers(Passenger* list, int len);

/// @brief add in a existing list of passengers the values received as parameters
/// in the first empty position
/// @param list passenger*
/// @param len int
/// @param id int
/// @param name[] char
/// @param lastName[] char
/// @param price float
/// @param typePassenger int
/// @param flycode[] char
/// @return int Return (-1) if Error [Invalid length or NULL pointer or without
/// free space] - (0) if Ok
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight, int indiceLibreEncontrado);

/// @brief find a Passenger by Id en returns the index position in array.
///
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or passenger not found]
int findPassengerById(Passenger* list, int len,int id);

/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
///
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return int Return (-1) if Error [Invalid length or NULL pointer or if can't
/// find a passenger] - (0) if Ok
int removePassenger(Passenger* list, int len, int id, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

/// @brief Sort the elements in the array of passengers, the argument order
/// indicate UP or DOWN order
///
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengers(Passenger* list, int len, int order);

/// @brief print the content of passengers array
///
/// @param list Passenger*
/// @param length int
/// @return int
int printPassenger(Passenger* list, int length, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

//	============================================
//	> FUNCIONES CREADAS PARA EL TRABAJO PRACTICO
//	============================================

//	FUNCION PRINCIPAL HARDCODEO DE ALBUM (PARA TESTEOS) <-- COMENTAR EN EL MAIN SI NO SE USA
/// @brief FUNCION QUE INGRESA AUTOMATICAMENTE DATOS DE PASAJEROS
///
/// @param array Passenger Listado de pasajeros
/// @param longitud int Largo del array de pasajeros
void ePassenger_hardcodeados(Passenger array[], int longitud);

//	> FUNCION MOSTRAR UN PASAJERO
/// @brief FUNCION PARA MOSTRAR UN SOLO PASAJERO EN TABLA
///
/// @param pasajero Passenger el pasajero a ser mostrado
/// @param listadoEstadosDeVuelo EstadosDeVuelo La lista de los estados de vuelos ingresados
/// @param longitudListaEstadosDeVuelos int El largo de la lista de estados de vuelo
/// @param listaDeTipoPasajeros TiposPasajeros La lista de los diferentes tipos de pasajeros que puede haber
/// @param longitudListaDeTipoPasajero int El largo de la lista de los tipos de pasajeros
void mostrarUnPasajero (Passenger pasajero, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);


//	> FUNCION MOSTRAR TIPO PASAJERO
/// @brief FUNCION QUE MUESTRA EL LISTADO DE TIPOS DE PASAJEROS
///
/// @param listaDeTipoPasajeros array de tipos pasajeros
/// @param longitudListaDeTipoPasajero int El largo del array de tipoPasajero
void TipoPasajero_mostrarTodos (TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

//	> OBTENER ESTADO VUELO
/// @brief FUNCION QUE MUESTRA EL LISTADO DE LOS ESTADOS DE VUELO
///
/// @param listaEstadosDeVuelos array de los estados de vuelos
/// @param longitudListaEstadosDeVuelos int El largo del array de estadosDeVuelos
void EstadoVuelo_mostrarTodos (EstadosDeVuelo listaEstadosDeVuelos[], int longitudListaEstadosDeVuelos);

//	> FUNCION CARGAR UN PASAJERO EN LISTA
/// @brief FUNCION PRINCIPAL PARA DAR DE ALTA UN PASAJERO DONDE PIDE LOS DATOS NECESARIOS PARA EL ALTA
///
/// @param listaPasajeros array de la lista de pasajeros
/// @param longitudPasajeros int el largo de la lista de pasajero
/// @param listaEstadosDeVuelos array de la lista de estados de Vuelo
/// @param longitudEstadosDeVuelos int el largo del array de estados de vuelo
/// @param listaDeTipoPasajeros array de la lista de tiposPasajero
/// @param longitudDeTipoPasajero int el largo del array de tipos de pasajero
/// @return Si salio Ok devuelve un 0 sino Error 1
int Passenger_Alta (Passenger listaPasajeros[], int longitudPasajeros, EstadosDeVuelo listaEstadosDeVuelos[], int longitudEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudDeTipoPasajero);

//	> FUNCION MOSTRAR DATOS DEL PASAJERO
/// @brief FUNCION PARA MOSTRAR LOS DATOS DEL PASAJERO AGREGADO
///
/// @param unPasajero el indice del pasajero agregado
void mostrarPasajeroAgregado (Passenger unPasajero);

//	> FUNCION BUSCAR INDICE LIBRE
/// @brief FUNCION QUE BUSCAR UN INDICE LIBRE Y LO DEVUELVE EN CASO DE ENCONTRARLO
///
/// @param list Passenger el array donde debe buscar el indice libre
/// @param len int el largo del array
/// @return en caso de encontrar libre lo devuelve, sino error -1
int buscarIndiceLibre(Passenger* list, int len);

//	> FUNCION CONTAR ID ACTIVOS
/// @brief FUNCION QUE CUENTA A LOS ID OCUPADOS
///
/// @param list el array donde debe contar
/// @param length int el largo del array
/// @return devuelve la cantidad
int Passenger_contar_id(Passenger list[], int length);

//	> FUNCION DAR BAJA A UN PASAJERO
/// @brief FUNCION PARA DAR DE BAJA UN PASAJERO
///
/// @param list el array de pasajeros
/// @param length int el largo del array de pasajeros
/// @param listadoEstadosDeVuelo el array de estados de vuelo
/// @param longitudListaEstadosDeVuelos int el largo del array de estados de vuelo
/// @param listaDeTipoPasajeros el array de tipos de pasajeros
/// @param longitudListaDeTipoPasajero int el largo del array de tipo de pasajeros
/// @return
int Passenger_Baja(Passenger list[], int length, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

//	> FUNCION BUSCAR TIPO PASAJERO POR ID
/// @brief FUNCION QUE BUSCA EL TIPO DE PASAJERO POR ID
///
/// @param listaDeTipoPasajeros el array de tipos de pasajeros
/// @param longitudListaDeTipoPasajero int el largo de tipo de pasajeros
/// @param id int el id que debe buscar
/// @return Devuelve el id encontrado
int TipoPasajero_buscarPorId(TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero, int id);

//	> FUNCION BUSCAR ESTADOS DE VUELO POR ID
/// @brief FUNCION QUE BUSCA EL ESTADO DE VUELO POR ID
///
/// @param listadoEstadosDeVuelo el array de estados de vuelo
/// @param longitudListaEstadosDeVuelos int el largo de estdos de vuelos
/// @param id int el id que debe buscar
/// @return Devuelve el id encontrado
int EstadosDeVuelo_buscarPorId(EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, int id);

//	> FUNCION MODIFICAR DATOS DE PASAJERO
/// @brief FUNCION PARA MODIFICAR LOS DATOS DE PASAJEROS
///
/// @param list el array de pasajeros
/// @param length int el largo del array de pasajeros
/// @param listadoEstadosDeVuelo el array de estos de vuelo
/// @param longitudListaEstadosDeVuelos int el largo del array de estados de vuelo
/// @param listaDeTipoPasajeros el array de tipos de pasajeros
/// @param longitudListaDeTipoPasajero int el largo del array de tipos de pasajeros
/// @return
int Passenger_Modificar(Passenger list[], int length, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

//	> FUNCION MODIFICAR UNO
/// @brief FUNCION PARA MODIFICAR UN PASAJERO
///
/// @param pasajero el pasajero a ser modificado
/// @param listadoEstadosDeVuelo el array de estados de vuelo
/// @param longitudListaEstadosDeVuelos int el largo del array de estados de vuelo
/// @param listaDeTipoPasajeros el array de tipos de pasajeros
/// @param longitudListaDeTipoPasajero int el largo del array de tipos de pasajero
/// @return
Passenger Passenger_ModificarUno (Passenger pasajero, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

//	> FUNCION LISTAR PASAJEROS
/// @brief FUNCION LISTAR PASAJEROS
///
/// @param list el array de pasajeros
/// @param length int el largo del array de pasajeros
/// @param order int el orden en que se quiere listar
/// @param cantidadAltas int la cantidad de altas generadas hasta el momento
/// @param listadoEstadosDeVuelo el array de estados de vuelo
/// @param longitudListaEstadosDeVuelos int el largo del array de estados de vuelo
/// @param listaDeTipoPasajeros el array de tipos de pasajeros
/// @param longitudListaDeTipoPasajero int el largo del array de tipos de pasajero
void Passenger_Listado(Passenger list[], int length, int order, int cantidadAltas, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

//	> FUNCION TOTAL Y PROMEDIO DE PASAJES
/// @brief FUNCION PARA MOSTRAR EL TOTAL Y PROMEDIO DEL PRECIO
///
/// @param list el array de pasajeros
/// @param length int el largo del array de pasajeros
/// @param cantidadAltas int la cantidad de altas hasta el momento
/// @param listadoEstadosDeVuelo el array de estados de vuelos
/// @param longitudListaEstadosDeVuelos int el largo del array de estados de vuelos
/// @param listaDeTipoPasajeros el array de tipos de pasajeros
/// @param longitudListaDeTipoPasajero int el largo de tipos de pasajero
void Passenger_mayorAlPromedio (Passenger list[], int length, int cantidadAltas, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero);

//	> FUNCION SECUNDARIA MOSTRAR TOTAL IMPORTE
/// @brief FUNCION PARA MOSTRAR EL TOTAL DEL IMPORTE DE PASAJES
///
/// @param list el listado de pasajeros
/// @param length int el largo del array de pasajeros
/// @return Devuelve el monto total
float Passenger_ImporteTotal(Passenger list[], int length);

//	> FUNCION SECUNDARIA MOSTRAR PROMEDIO IMPORTE TOTAL
/// @brief FUNCION PARA SACAR EL IMPORTE PROMEDIO DE LOS PASAJES
///
/// @param importeTotal float el importe total calculado previamente
/// @param cantidadAltas int la cantidad de altas hasta el momento
/// @return float Devuelve el promedio
float Passenger_PromedioImporte (float importeTotal, int cantidadAltas);

//	> FUNCION CANTIDAD DE PASAJEROS MAYOR AL PRECIO PROMEDIO
/// @brief FUNCION PARA VER LA CANTIDAD DE PASAJEROS QUE SUPERAN EL PROMEDIO DEL MONTO
///
/// @param list el array de pasajeros
/// @param length int el largo del array de pasajeros
/// @param promedioImporteTotal float el promedio del monto de pasajes calculado previamente
/// @return Devuelve la cantidad
int Passenger_cantidadMayorAlPromedio(Passenger list[], int length, float promedioImporteTotal);

//	> FUNCION SORT PASSENGER POR CODIGO
/// @brief FUNCION PARA ORDENAR PASAJEROS POR CODIGO DE VUELO
///
/// @param list el array de pasajeros
/// @param len int el largo del array de pasajeros
/// @param order int el orden en que se quiere mostrar
/// @return
int sortPassengersByCode(Passenger* list, int len, int order);

#endif /* ARRAYPASSENGER_H_ */
