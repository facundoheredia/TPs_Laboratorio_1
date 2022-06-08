/// FUNCIONES PARSER
/// parser.h
/// @date 19 may. 2022
/// @author Maru
///	Modificado por: Heredia Facundo - 1F - 1C 2022

#ifndef PARSER_H_
#define PARSER_H_

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

//	==================
//	> FUNCIONES PARSER
//	==================
/// @brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
///
/// @param path char*
/// @param pArrayListPassenger LinkedList*
/// @return int
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */
