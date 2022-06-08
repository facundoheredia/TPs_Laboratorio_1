/// FUNCIONES CONTROLLER
/// Controller.h
/// @date 19 may. 2022
/// @author Maru
///	Modificado por: Heredia Facundo - 1F - 1C 2022

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "Controller.h"

//	======================
//	> FUNCIONES CONTROLLER
//	======================
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	//ARCHIVO PARA LISTA CON DATOS DE LOS PASAJEROS
	FILE* pArchivoPasajeros = NULL;

	retorno = -1;
	//PREGUNTAR SI LISTA PASAJEROS ES DISTINTO DE NULL
	if(pArrayListPassenger != NULL)
	{
		//ABRO ARCHIVO "DATA.CSV" EN MODO LECTURA
		pArchivoPasajeros = fopen(path, "r");
		//VERIFICO QUE NO SEA NULL LA LISTA DE PASAJEROS
		if(pArchivoPasajeros != NULL)
		{
			//PARSEO LOS DATOS DE LOS PASAJEROS EN LA LISTA DEL ARCHIVO
			parser_PassengerFromText(pArchivoPasajeros, pArrayListPassenger);
			//LLAMO A MI FUNCION DE CARGAR ID
			controller_loadFromTextId(pArrayListPassenger);
			retorno = 1;
		}
		//CIERRO ARCHIVO
		fclose(pArchivoPasajeros);
	}
	return retorno;
}

//	================================================================================================================
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivoPasajeros = NULL;

	retorno = -1;
	//PREGUNTAR SI LISTA PASAJEROS ES DISTINTO DE NULL
	if(pArrayListPassenger != NULL)
	{
		//ABRO ARCHIVO "DATA.BIN" Y LEO
		pArchivoPasajeros = fopen(path, "rb");
		//VERIFICO QUE NO SEA NULL
		if(pArchivoPasajeros != NULL)
		{
			//PARSEO LOS DATOS DE LOS PASAJEROS EN LA LISTA DEL ARCHIVO
			parser_PassengerFromBinary(pArchivoPasajeros, pArrayListPassenger);
			//LLAMO A MI FUNCION DE CARGAR ID
			controller_loadFromTextId(pArrayListPassenger);
			retorno = 1;
		}
		else
		{
			retorno = -2;
		}
		//CIERRO ARCHIVO
		fclose(pArchivoPasajeros);
	}
    return retorno;
}

//	================================================================================================================
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* pPasajeroAuxiliar = NULL;
	//DATOS AUXILIARES PARA PEDIR
	int idAuxiliar;
	int idValido;
	char nombreAuxiliar[LONGITUD_NOMBRE];
	int nombreValido;
	char apellidoAuxiliar[LONGITUD_NOMBRE];
	int apellidoValido;
	int precioValido;
	float precioIngresado;
	char codigoVueloAuxiliar[LONGITUD_CODIGOVUELO];
	char tipoPasajeroAuxiliar[LONGITUD_NOMBRE];
	char estadoVueloAuxiliar[LONGITUD_NOMBRE];
	int opcionCodigoDeVuelo;
	int opcionTipoPasajero;

	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		//OBTENGO EL ULTIMO ID
		idValido = Passenger_getUltimoId(&idAuxiliar);
		//PIDO LOS DATOS
			//NOMBRE
		nombreValido = entrada_obtenerCadena(nombreAuxiliar, "INGRESE EL NOMBRE: ", "[ERROR] -> INGRESE UN NOMBRE VALIDO: ", LONGITUD_NOMBRE);
			//APELLIDO
		apellidoValido = entrada_obtenerCadena(apellidoAuxiliar, "INGRESE EL APELLIDO: ", "[ERROR] -> INGRESE UN APELLIDO VALIDO: ", LONGITUD_NOMBRE);
			//PRECIO
		precioValido = entrada_obtenerFlotante(&precioIngresado, "INGRESE EL PRECIO: ", "[ERROR] -> INGRESE UN NOMBRE VALIDO: ", PRECIO_MINIMO, PRECIO_MAXIMO);
			//CODIGO DE VUELO
		Passenger_ImprimirCodigosDeVuelo();
		opcionCodigoDeVuelo = entrada_obtenerEnteroEntreRango("INGRESE LA OPCION DEL CODIGO DE VUELO CORRESPONDIENTE AL PASAJERO: ", "[ERROR] -> INGRESE UNA OPCION VALIDA: ", "[ERROR] -> DATO FUERA DE RANGO: ", CODIGO_DE_VUELO_MINIMO, CODIGO_DE_VUELO_MAXIMO);
		Passenger_AsignarCodigosDeVueloTxt(opcionCodigoDeVuelo, codigoVueloAuxiliar, estadoVueloAuxiliar);
			//TIPO PASAJERO
		Passenger_ImprimirTipoPasajero();
		opcionTipoPasajero = entrada_obtenerEnteroEntreRango("INGRESE LA OPCION DEL TIPO PASAJERO: ", "[ERROR] -> INGRESE UNA OPCION VALIDA: ", "[ERROR] -> DATO FUERA DE RANGO: ", TIPO_PASAJERO_MINIMO, TIPO_PASAJERO_MAXIMO);
		Passenger_AsignarTipoPasajeroTxt(opcionTipoPasajero, tipoPasajeroAuxiliar);

		if(idValido == 0 && nombreValido == 0 && apellidoValido == 0 && precioValido == 0 && codigoVueloAuxiliar != NULL && estadoVueloAuxiliar != NULL && tipoPasajeroAuxiliar != NULL)
		{
			pPasajeroAuxiliar = Passenger_newParametrosModificada(&idAuxiliar, nombreAuxiliar, apellidoAuxiliar, &precioIngresado, tipoPasajeroAuxiliar, codigoVueloAuxiliar, estadoVueloAuxiliar);

			if(pPasajeroAuxiliar != NULL && ll_add(pArrayListPassenger, (Passenger*)pPasajeroAuxiliar) == 0)
			{
				retorno = 1;
				//SI EL ALTA SE DIO CORRECTAMENTE YA SUMO AL ULTIMO ID PARA LA PROXIMA ALTA
				Passenger_setUltimoId(idAuxiliar);
			}
		}
	}
	//RETORNO SI PUDO O ERROR
    return retorno;
}
//	================================================================================================================
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* pPasajeroAuxiliar;
	//DATOS AUXILIARES
	int idPasajeroBuscado;
	int indice;
	int idMaximo;

	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		//MUESTRO LA LISTA DE PASAJEROS CARGADOS
		controller_ListPassenger(pArrayListPassenger);

		//PREGUNTO EL ID DEL PASAJERO A MODIFICAR
		if(Passenger_getUltimoId(&idMaximo) == 0 && entrada_obtenerEntero(&idPasajeroBuscado, "INGRESE EL ID DEL PASAJERO A MODIFICAR: ", "[ERROR] -> DATO INVALIDO, REINTENTE: ", 1, idMaximo) == 0)
		{
			//AHORA DEBERIA BUSCAR ESTE ID BUSCADO EN LA LINKEDLIST?
			indice = Passenger_encontrarId(pArrayListPassenger, &idPasajeroBuscado);

			//SI EXISTE OBTENGO ESE PASAJERO CON EL ll_Get?
			pPasajeroAuxiliar = (Passenger*) ll_get(pArrayListPassenger, indice);

			//PREGUNTO SI ES DISTINTO DE NULL ESE PASAJERO? SE SUPUNE QUE ESTA CARGADO CON DATOS
			if(pPasajeroAuxiliar != NULL)
			{
				Passenger_modificarUno(pPasajeroAuxiliar);
				retorno = 0;
			}
		}
		else
		{
			mostrarMensaje("NO SE ENCONTRO EL ID DEL PASAJERO");
		}
	}
    return retorno;
}

//	================================================================================================================
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int idMaximo;
	int idPasajeroBuscado;
	int indice;
	Passenger* pPasajeroAuxiliar;

	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		//MUESTRO LA LISTA DE PASAJEROS CARGADOS
		controller_ListPassenger(pArrayListPassenger);

		if(Passenger_getUltimoId(&idMaximo)== 0)
		{
			//PREGUNTO EL ID DEL PASAJERO A MODIFICAR
			do
			{
				entrada_obtenerEntero(&idPasajeroBuscado, "INGRESE EL ID DEL PASAJERO A REMOVER: ", "[ERROR] -> DATO INVALIDO, REINTENTE: ", 1, idMaximo);
				//AHORA DEBERIA BUSCAR ESTE ID BUSCADO EN LA LINKEDLIST?
				indice = Passenger_encontrarId(pArrayListPassenger, &idPasajeroBuscado);
			}while (indice == -1);

			//SI EXISTE OBTENGO ESE PASAJERO CON EL ll_Get?
			pPasajeroAuxiliar = (Passenger*) ll_get(pArrayListPassenger, indice);

			//PREGUNTO SI ES DISTINTO DE NULL ESE PASAJERO? SE SUPUNE QUE ESTA CARGADO CON DATOS
			if(pPasajeroAuxiliar != NULL && entrada_respuestaUsuario("¿DESEA BORRAR AL PASAJERO? [S] o [N]") == 'S')
			{
				if(ll_remove(pArrayListPassenger, indice) == 0)
				{
					Passenger_delete(pPasajeroAuxiliar);
					pPasajeroAuxiliar = NULL;
					retorno = 0;
				}
			}
		}
	}
    return retorno;
}

//	================================================================================================================
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* pPasajeroAuxiliar;
	int i;
	int largoDeLista;

	retorno = -1;
	//LEO EL LARGO DE LA LISTA ACA
	largoDeLista = ll_len(pArrayListPassenger);
	//VERIFICO SI LA LISTA NO ES NULL Y SI EL LARGO DE LA LISTA ES MAYOR O IGUAL A 0
	if(pArrayListPassenger != NULL && largoDeLista > 0)
	{
		encabezadoTabla ();
		for(i = 0 ; i < largoDeLista; i++)
		{
			pPasajeroAuxiliar = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_mostrarUnPasajero (pPasajeroAuxiliar);
		}
		PieDePaginaTabla ();
	}
    return retorno;
}

//	================================================================================================================
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int opcionMenu;
	int opcionOrdenamiento;

	retorno = -1;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		do
		{
			opcionMenu = menuOrdenar();

			if(opcionMenu <= 7)
			{
				opcionOrdenamiento = entrada_obtenerEnteroEntreRango("INGRESE EL FORMATO DE ORDENAMIENTO ([1]ASCENDENTE - [0]DESCENDENTE): ", "[ERROR] -> DATO NO VALIDO, REINTENTE: ", "[ERROR] -> DATO FUERA DE RANGO, REINTENTE: ", 0, 1);
				mostrarMensaje("AGUARDE UNOS SEGUNDOS, SE ESTA PROCESANDO EL ORDENAMIENTO DE LA LISTA");

				switch(opcionMenu)
				{
					case 1:	// [ ORDENAR POR ID ]
						if(ll_sort(pArrayListPassenger, Passenger_ordenarPorId,opcionOrdenamiento) == 0)
						{
							controller_ListPassenger(pArrayListPassenger);
							mostrarMensajeParaContinuar("MOSTRANDO LISTA ORDENADA POR ID");
						}
						break;
					case 2:	// [ ORDENAR POR NOMBRE ]
						if(ll_sort(pArrayListPassenger, Passenger_ordenarPorNombre,opcionOrdenamiento) == 0)
						{
							controller_ListPassenger(pArrayListPassenger);
							mostrarMensajeParaContinuar("MOSTRANDO LISTA ORDENADA POR NOMBRES");
						}
						break;
					case 3:	// [ ORDENAR POR APELLIDO ]
						if(ll_sort(pArrayListPassenger, Passenger_ordenarPorApellido,opcionOrdenamiento) == 0)
						{
							controller_ListPassenger(pArrayListPassenger);
							mostrarMensajeParaContinuar("MOSTRANDO LISTA ORDENADA POR APELLIDOS");
						}
						break;
					case 4:	// [ ORDENAR POR PRECIO ]
						if(ll_sort(pArrayListPassenger, Passenger_ordenarPorPrecio,opcionOrdenamiento) == 0)
						{
							controller_ListPassenger(pArrayListPassenger);
							mostrarMensajeParaContinuar("MOSTRANDO LISTA ORDENADA POR PRECIOS");
						}
						break;
					case 5:	// [ ORDENAR POR CODIGO DE VUELO ]
						if(ll_sort(pArrayListPassenger, Passenger_ordenarPorCodigoVuelo,opcionOrdenamiento) == 0)
						{
							controller_ListPassenger(pArrayListPassenger);
							mostrarMensajeParaContinuar("MOSTRANDO LISTA ORDENADA POR CODIGO DE VUELO");
						}
						break;
					case 6:	// [ ORDENAR POR TIPO DE PASAJERO ]
						if(ll_sort(pArrayListPassenger, Passenger_ordenarPorTipoPasajero,opcionOrdenamiento) == 0)
						{
							controller_ListPassenger(pArrayListPassenger);
							mostrarMensajeParaContinuar("MOSTRANDO LISTA ORDENADA POR TIPO DE PASAJERO");
						}
						break;
					case 7:	// [ ORDENAR POR ESTADO DE VUELO ]
						if(ll_sort(pArrayListPassenger, Passenger_ordenarPorEstadoVuelo,opcionOrdenamiento) == 0)
						{
							controller_ListPassenger(pArrayListPassenger);
							mostrarMensajeParaContinuar("MOSTRANDO LISTA ORDENADA POR ESTADO DE VUELO");
						}
						break;
				}
			}
			else
			{
				mostrarMensajeParaContinuar("VOLVIENDO AL MENU PRINCIPAL");
				system("cls");
			}

		}while(opcionMenu != 8);
	}

    return retorno;
}

//	================================================================================================================
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivoAuxiliar = NULL;
	int i;
	int largoDeLista;
	Passenger* pPasajeroAuxiliar;
	//AUXILIARES PARA GUARDAR LOS GET Y LUEGO PODER IMPRIMIRLOS
	int idAuxiliar;
	char nombreAuxiliar[LONGITUD_NOMBRE];
	char apellidoAuxiliar[LONGITUD_NOMBRE];
	float precioAuxiliar;
	char tipoPasajeroAuxiliar[LONGITUD_NOMBRE];
	char codigoDeVueloAuxiliar[LONGITUD_CODIGOVUELO];
	char estadoDeVueloAuxiliar[LONGITUD_NOMBRE];

	retorno = -1;

	//RECIEN ACA VEO EL LARGO DE LA LISTA?
	largoDeLista = ll_len(pArrayListPassenger);

	//PREGUNTO SI EL PUNTERO A LA RUTA DEL ARCHIVO Y LA LISTA NO ES NULL Y SI EL LARGO DE LISTA ES MAYOR O IGUAL A CERO
	if(path != NULL && pArrayListPassenger != NULL && largoDeLista >= 0)
	{
		//ABRO EL ARCHIVO EN pArchivo EN MODO ESCRITURA
		pArchivoAuxiliar = fopen(path, "w");
		//PREGUNTO SI EL ARCHIVO ES DISTINTO DE NULL
		if(pArchivoAuxiliar != NULL)
		{
			//IMPRIMIR ENCABEZADO PARA LA PROXIMA FALSA LECTURA CUANDO SE ABRA NUEVAMENTE EL ARCHIVO?
			fprintf(pArchivoAuxiliar, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");

			for(i = 0; i < largoDeLista; i++)
			{
				pPasajeroAuxiliar = (Passenger*)ll_get(pArrayListPassenger, i);
				//UNA VEZ QUE OBTUVE LA INFO EN pPasajeroAuxiliar LO ESCRIBO EN EL ARCHIVO
				if(pPasajeroAuxiliar != NULL)
				{
					Passenger_getId(pPasajeroAuxiliar, &idAuxiliar);
					Passenger_getNombre(pPasajeroAuxiliar, nombreAuxiliar);
					Passenger_getApellido(pPasajeroAuxiliar, apellidoAuxiliar);
					Passenger_getPrecio(pPasajeroAuxiliar, &precioAuxiliar);
					Passenger_getTipoPasajero(pPasajeroAuxiliar, tipoPasajeroAuxiliar);
					Passenger_getCodigoVuelo(pPasajeroAuxiliar, codigoDeVueloAuxiliar);
					Passenger_getEstadoDeVuelo(pPasajeroAuxiliar, estadoDeVueloAuxiliar);

					//LOS IMPRIMO EN EL ARCHIVO
					if(fprintf(pArchivoAuxiliar,"%d,%s,%s,%.2f,%s,%s,%s\n", idAuxiliar, nombreAuxiliar, apellidoAuxiliar, precioAuxiliar,codigoDeVueloAuxiliar,tipoPasajeroAuxiliar,estadoDeVueloAuxiliar) == -1)
					{
						break;
					}
				}
			}
			//SI LLEGO AL LARGO TOTAL DE LA LISTA SALIO OK
			if(i == largoDeLista)
			{
				retorno = 0;
				//SI GUARDA EL ARCHIVO, DEBERIA OBTENER EL ULTIMO ID SI NO, SE DESCARTA
				Passenger_setUltimoId(idAuxiliar);
			}
			//CIERRO EL ARCHIVO
			fclose(pArchivoAuxiliar);
		}
	}
	//RETORNO OK u ERROR
    return retorno;
}
//	================================================================================================================
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivoAuxiliar = NULL;
	int largoDeLista;
	Passenger* pPasajeroAuxiliar;
	int i;
	int idAuxiliar;

	retorno = -1;

	largoDeLista = ll_len(pArrayListPassenger);

	if(path != NULL && pArrayListPassenger != NULL && largoDeLista >= 0)
	{
		pArchivoAuxiliar = fopen(path, "wb");

		if(pArchivoAuxiliar != NULL)
		{
			for(i = 0; i < largoDeLista; i++)
			{
				pPasajeroAuxiliar = (Passenger*)ll_get(pArrayListPassenger, i);

				Passenger_getId(pPasajeroAuxiliar, &idAuxiliar);
				fwrite(pPasajeroAuxiliar,sizeof(Passenger),1,pArchivoAuxiliar);
				//REVISAR ACA CON PRINTF POR QUE FALLA AL GUARDAR EN BINARIO
				/*
				if(pPasajeroAuxiliar != NULL || fwrite(pPasajeroAuxiliar,sizeof(Passenger),1,pArchivoAuxiliar) == -1)
				{
					break;
				}
				*/
			}
			//SI LLEGO AL LARGO TOTAL DE LA LISTA SALIO OK
			if(i == largoDeLista)
			{
				retorno = 0;
				//SI GUARDA EL ARCHIVO, DEBERIA OBTENER EL ULTIMO ID SI NO, SE DESCARTA
				Passenger_setUltimoId(idAuxiliar);
			}
			//CIERRO EL ARCHIVO
			fclose(pArchivoAuxiliar);
		}
	}

    return retorno;
}
//	================================================================================================================
int controller_loadFromTextId(LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pArchivoId = NULL;
	int largoDeLista;
	int i;
	Passenger* pPasajeroAuxiliar;
	int idMaximo;

	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		pArchivoId = fopen(ARCHIVO_ULTIMO_ID_GENERADO,"r");

		if(pArchivoId == NULL)
		{
			//SI NO LO PUDO LEER(POR QUE NO EXISTE) LO ABRO EN MODO ESCRITURA PARA QUE LO CREE
			pArchivoId = fopen(ARCHIVO_ULTIMO_ID_GENERADO,"w");

			largoDeLista = ll_len(pArrayListPassenger);

			for(i = 0; i < largoDeLista; i++)
			{
				pPasajeroAuxiliar = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pPasajeroAuxiliar, &idMaximo);
			}
			//IMPRIMO EN EL ARCHIVO
			fprintf(pArchivoId,"%d\n",idMaximo + 1);
		}
		fclose(pArchivoId);

	}

	return retorno;
}
//	================================================================================================================
