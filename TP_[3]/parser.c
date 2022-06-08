/// FUNCIONES PARSER
/// parser.c
/// @date 19 may. 2022
/// @author Maru
///	Modificado por: Heredia Facundo - 1F - 1C 2022

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "parser.h"

//	==================
//	> FUNCIONES PARSER
//	==================
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	//CREO UN PUNTERO DE ESTRUCTURA AUXILIAR
	Passenger* pasajeroAuxiliar = NULL;
	//CREO DATOS AUXILIARES DE LA ESTRUCTURA
	char idAuxiliar[LONGITUD_ID];
	char nombreAuxiliar[LONGITUD_NOMBRE];
	char apellidoAuxiliar[LONGITUD_NOMBRE];
	char precioAuxiliar[LONGITUD_PRECIO];
	char codigoVueloAuxiliar[LONGITUD_CODIGOVUELO];
	char tipoPasajeroAuxiliar[LONGITUD_NOMBRE];
	char statusFlight[LONGITUD_NOMBRE];
	//PARA FALSA LECTURA DE ENCABEZADO
	int flagEncabezado;

	retorno = -1;
	flagEncabezado = 0;
	//PREGUNTO SI EL ARCHIVO Y LISTA VIENEN DISTINTO DE NULL
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		//RECORRO EL ARCHIVO HASTA EL FINAL CON LA FUNCION FEOF...
		do
		{
			//PRIMER LECTURA EN FALSO PARA EL ENCABEZADO
			if(flagEncabezado == 0)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAuxiliar, nombreAuxiliar, apellidoAuxiliar, precioAuxiliar, codigoVueloAuxiliar, tipoPasajeroAuxiliar, statusFlight);
				flagEncabezado = 1;
			}
			//LEO LOS DATOS DE CADA PASAJERO, DEVUELVE LA CANTIDAD DE VARIABLES QUE LEYO... 7 en este caso
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAuxiliar, nombreAuxiliar, apellidoAuxiliar, precioAuxiliar, codigoVueloAuxiliar, tipoPasajeroAuxiliar, statusFlight) == 7)
			{
				//SI LEYO TODAS ENTRO Y CONSTRUYO UN NUEVO PASAJERO CON ESOS DATOS
				pasajeroAuxiliar = Passenger_newParametros(idAuxiliar, nombreAuxiliar, apellidoAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, codigoVueloAuxiliar, statusFlight);
				//PREGUNTO SI ES DISTINTO DE NULL
				if(pasajeroAuxiliar != NULL)
				{
					//SI SALE OK LO AGREGO CON EL ll_Add?
					ll_add(pArrayListPassenger, pasajeroAuxiliar);
					//PARA SU PROXIMO USO
					pasajeroAuxiliar = NULL;
					//RETORNO OK ACA
					retorno = 0;
				}
			}
		}while(!feof(pFile));
	}
    return retorno;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	//CREO UN PUNTERO DE ESTRUCTURA AUXILIAR
	Passenger* pasajeroAuxiliar = NULL;

	retorno = -1;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			pasajeroAuxiliar = Passenger_new();

			if(fread(pasajeroAuxiliar,sizeof(Passenger),1,pFile) == 1)
			{
				if(pasajeroAuxiliar != NULL)
				{
					//SI SALE OK LO AGREGO CON EL ll_Add
					ll_add(pArrayListPassenger, pasajeroAuxiliar);
					//PARA SU PROXIMO USO
					pasajeroAuxiliar = NULL;
					//RETORNO OK ACA
					retorno = 0;
				}
			}
		}while(!feof(pFile));
	}

    return retorno;
}
