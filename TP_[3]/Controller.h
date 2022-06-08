/// FUNCIONES CONTROLLER
/// Controller.h
/// @date 19 may. 2022
/// @author Maru
///	Modificado por: Heredia Facundo - 1F - 1C 2022

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
//	>> BIBLIOTECAS DADAS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
//	>> BIBLIOTECAS AGREGADAS
#include "parser.h"
#include "inputs.h"
#include "hud_menu.h"
#include "mensajes.h"

//	======================
//	> FUNCIONES CONTROLLER
//	======================
/// @brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/// @brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief Alta de pasajero
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_addPassenger(LinkedList* pArrayListPassenger);

/// @brief Modificar datos de pasajero
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_editPassenger(LinkedList* pArrayListPassenger);

/// @brief Baja de pasajero
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_removePassenger(LinkedList* pArrayListPassenger);

/// @brief Listar pasajeros
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/// @brief Ordenar pasajeros
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// @brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/// @brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


int controller_loadFromTextId(LinkedList* pArrayListPassenger);

#endif /* CONTROLLER_H_ */
