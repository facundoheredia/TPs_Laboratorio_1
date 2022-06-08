/// FUNCIONES PASSENGER
/// Passenger.c
/// @date 19 may. 2022
/// @author Maru
///	Modificado por: Heredia Facundo - 1F - 1C 2022


//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "Passenger.h"

//	===================
//	> FUNCIONES STATICs
//	===================
//	>> NOMBRE VALIDO
/// @brief Verifica si la cadena ingresada es un nombre valido
///
/// @param cadena char* cadena de caracteres a ser analizada
/// @param longitud int largo de la cadena recibida
/// @return retorno int Retorno 1 (OK) si la cadena es valida y 0 (ERROR) si no lo es
static int esNombreValido(char* cadena, int longitud)
{
	int retorno;
	int i;

	retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		retorno = 0;
		for(i = 0; i < longitud; i++)
		{
			if((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
			{
				retorno = -2;
				break;
			}
		}
	}
	return retorno;
}
//	================================================================================================================
//	>> NUMERO ENTERO VALIDO
/// @brief Verifica si la cadena ingresada es numerica
///
/// @param cadena char* cadena de caracteres a ser analizada
/// @param limite int largo de la cadena
/// @return retorno int Retorna 1 (OK) si la cadena es numerica y 0 (No es numerica) si no lo es y -1 en caso de Error
static int esNumeroValido(char* cadena, int limite)
{
	int retorno;
	int i;

	retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] <= '0' || cadena[i] >= '9')
			{
				retorno = 0;
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}
//	================================================================================================================
//	>> NUMERO FLOTANTE VALIDO
/// @brief Verifica si la cadena ingresada es numerica flotante
///
/// @param cadenaRecibida char* cadena de caracteres a ser analizada
/// @return retorno int Retorna 0 [OK] o -1 [ERROR]
static int esFlotanteValido(char* cadena)
{
	int retorno;
	int i;
	int contadorPuntos;

	retorno = -1;
	contadorPuntos = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i = 0; cadena[i] != '\0'; i++)
		{
			if(i== 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}

			if(cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
    return retorno;
}
//	================================================================================================================
//	>> ALFANUMERICO VALIDO
/// @brief Verifica si la cadena ingresada es Alfanumerica
///
/// @param cadena char* cadena de caracteres a ser analizada
/// @param longitud int largo de la cadena
/// @return retorno int Retorna 1 (OK) si la cadena es numerica y 0 (No es numerica) si no lo es y -1 en caso de Error
static int esAlfaNUmericoValido(char* cadena, int longitud)
{
	int retorno;
	int i;

	retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		for(i = 0; i < longitud; i++)
		{
			if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//	=====================
//	> FUNCIONES PASSENGER
//	=====================
Passenger* Passenger_new()
{
	//CREO EL ESPACIO EN MEMORIA DE UN PASAJERO Y LO RETORNO
	return (Passenger*) malloc(sizeof(Passenger));
}
//	================================================================================================================
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlightStr)
{
	//ESTRUCTURA DE PASAJERO AUXILIAR
	Passenger* pPasajeroAuxiliar = NULL;
	//VARIABLES AUXILIARES PARA LA CARGA DE DATOS
	int idAuxiliar;

	//ACA DEBERIA CREAR EL ESPACIO PARA UNA ESTRUCTURA DE UN NUEVO PASAJERO
	pPasajeroAuxiliar = Passenger_new();

	//VERIFICO SI ES DISTINTO DE NULL TANTO EL PUNTERO AUXILIAR COMO LOS PARAMETROS RECIBIDOS
	if(pPasajeroAuxiliar != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && statusFlightStr != NULL)
	{
		//PASAR LOS DATOS A LOS TIPOS CORRESPONDIENTES Y ASIGNARLOS A LA ESTRUCTURA
		idAuxiliar = atoi(idStr);

		//VERIFICO QUE SE PUEDAN APLICAR LOS VALORES A CADA CAMPO DE LA ESTRUCTURA
		if(Passenger_setId(pPasajeroAuxiliar, &idAuxiliar) ||
		   Passenger_setNombre(pPasajeroAuxiliar, cadena_PrimeraMayusculas(nombreStr, LONGITUD_NOMBRE)) ||
		   Passenger_setApellido(pPasajeroAuxiliar, cadena_PrimeraMayusculas(apellidoStr, LONGITUD_NOMBRE)) ||
		   Passenger_setPrecioTxt(pPasajeroAuxiliar, precioStr) ||
		   Passenger_setCodigoVuelo(pPasajeroAuxiliar, codigoVueloStr) ||
		   Passenger_setTipoPasajero(pPasajeroAuxiliar, tipoPasajeroStr) ||
		   Passenger_setEstadoDeVuelo(pPasajeroAuxiliar, statusFlightStr))
		{
			//LIBERO EL ESPACIO EN MEMORIA PARA SU POSTERIOR USO SI LO SIGO NECESITANDO
			Passenger_delete(pPasajeroAuxiliar);
			//APUNTO A NULL PARA SU PROXIMO USO
			pPasajeroAuxiliar = NULL;
		}
	}
	//RETORNO EL PASAJERO CREADO
	return pPasajeroAuxiliar;
}
//	================================================================================================================
Passenger* Passenger_newParametrosModificada(int* id, char* nombreStr, char* apellidoStr, float* precio, char* tipoPasajeroStr, char* codigoVueloStr, char* statusFlightStr)
{
	//ESTRUCTURA DE PASAJERO AUXILIAR
	Passenger* pPasajeroAuxiliar = NULL;

	//ACA DEBERIA CREAR EL ESPACIO PARA UNA ESTRUCTURA DE UN NUEVO PASAJERO
	pPasajeroAuxiliar = Passenger_new();

	//VERIFICO SI ES DISTINTO DE NULL TANTO EL PUNTERO AUXILIAR COMO LOS PARAMETROS RECIBIDOS
	if(pPasajeroAuxiliar != NULL && id > 0 && nombreStr != NULL && apellidoStr != NULL && precio > 0 && tipoPasajeroStr != NULL && codigoVueloStr != NULL && statusFlightStr != NULL)
	{
		//VERIFICO QUE SE PUEDAN APLICAR LOS VALORES A CADA CAMPO DE LA ESTRUCTURA
		if(Passenger_setId(pPasajeroAuxiliar, id) ||
		   Passenger_setNombre(pPasajeroAuxiliar, cadena_PrimeraMayusculas(nombreStr, LONGITUD_NOMBRE)) ||
		   Passenger_setApellido(pPasajeroAuxiliar, cadena_PrimeraMayusculas(apellidoStr, LONGITUD_NOMBRE)) ||
		   Passenger_setPrecio(pPasajeroAuxiliar, precio) ||
		   Passenger_setCodigoVuelo(pPasajeroAuxiliar, codigoVueloStr) ||
		   Passenger_setTipoPasajero(pPasajeroAuxiliar, tipoPasajeroStr) ||
		   Passenger_setEstadoDeVuelo(pPasajeroAuxiliar, statusFlightStr))
		{
			//LIBERO EL ESPACIO EN MEMORIA PARA SU POSTERIOR USO SI LO SIGO NECESITANDO
			Passenger_delete(pPasajeroAuxiliar);
			//APUNTO A NULL PARA SU PROXIMO USO
			pPasajeroAuxiliar = NULL;
		}
	}
	//RETORNO EL PASAJERO CREADO
	return pPasajeroAuxiliar;
}
//	================================================================================================================
void Passenger_delete(Passenger* this)
{
	//VERIFICO QUE SEA DISTINTO DE NULL. Para no liberar un null y rompa el programa
	if(this != NULL)
	{
		//LIBERO ESTE PASAJERO
		free(this);
	}
}
//	================================================================================================================
int Passenger_encontrarId(LinkedList* pArrayListPassenger, int* id)
{
	int retorno;
	Passenger* pPasajeroAuxiliar;
	int largoDeListaPasajeros;
	int i;
	int idPasajeroExistente;

	retorno = -1;

	if(pArrayListPassenger != NULL && id > 0)
	{
		largoDeListaPasajeros = ll_len(pArrayListPassenger);

		for(i = 0; i < largoDeListaPasajeros; i++)
		{
			pPasajeroAuxiliar = ll_get(pArrayListPassenger, i);
			Passenger_getId(pPasajeroAuxiliar, &idPasajeroExistente);

			if(pPasajeroAuxiliar != NULL && idPasajeroExistente == *id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
//	================================================================================================================
void Passenger_mostrarUnPasajero (Passenger* this)
{
	int idAuxiliar;
	char nombreAuxiliar[LONGITUD_NOMBRE];
	char apellidoAuxiliar[LONGITUD_NOMBRE];
	float precioAuxiliar;
	char codigoVueloAuxiliar[LONGITUD_NOMBRE];
	char tipoPasajeroAuxiliar[LONGITUD_NOMBRE];
	char estadoVueloAuxiliar[LONGITUD_NOMBRE];

	if(this != NULL &&
	   !Passenger_getId(this, &idAuxiliar) &&
	   !Passenger_getNombre(this, nombreAuxiliar) &&
	   !Passenger_getApellido(this, apellidoAuxiliar) &&
	   !Passenger_getPrecio(this, &precioAuxiliar) &&
	   !Passenger_getCodigoVuelo(this, codigoVueloAuxiliar) &&
	   !Passenger_getTipoPasajero(this, tipoPasajeroAuxiliar) &&
	   !Passenger_getEstadoDeVuelo(this, estadoVueloAuxiliar))
	{
		printf("º %-4d \t| %-15s | %-15s | $ %10.2f | %-4s \t| %-20s \t| %-14s º\n",idAuxiliar, nombreAuxiliar, apellidoAuxiliar, precioAuxiliar, codigoVueloAuxiliar, tipoPasajeroAuxiliar, estadoVueloAuxiliar);
	}
}
//	================================================================================================================
void Passenger_modificarUno(Passenger* this)
{
	int opcionMenu;
	char nombreAuxiliar[LONGITUD_NOMBRE];
	char apellidoAuxiliar[LONGITUD_NOMBRE];
	float precioAuxiliar;
	int opcionCodigoDeVuelo;
	int opcionTipoPasajero;

	do
	{
		//MUESTRO AL PASAJERO CON LOS DATOS
		encabezadoTabla ();
		Passenger_mostrarUnPasajero (this);
		PieDePaginaTabla ();
		//LLAMO A MI FUNCION DE MENU DE MODIFICACIONES
		//SEGUN OPCION HACE LA MODIFICACION Y LO SETEA NUEVAMENTE CON EL DATO NUEVO
		switch(opcionMenu = menuModificacion())
		{
			case 1:	// [ OPCION MODIFICAR NOMBRE ]
				entrada_obtenerCadena(nombreAuxiliar, "INGRESE EL NUEVO NOMBRE: ", "[ERROR] -> INGRESE UN NOMBRE VALIDO: ", LONGITUD_NOMBRE);
				if(!Passenger_setNombre(this, cadena_PrimeraMayusculas(nombreAuxiliar, LONGITUD_NOMBRE)))
				{
					mostrarMensaje("SE MODIFICO EL NOMBRE CORRECTAMENTE");
				}
				else
				{
					mostrarMensaje("[ERROR] -> NO SE PUDO MODIFICAR EL NOMBRE");
				}
				break;
			case 2:	// [ OPCION MODIFICAR APELLIDO ]
				entrada_obtenerCadena(apellidoAuxiliar, "INGRESE EL NUEVO APELLIDO: ", "[ERROR] -> INGRESE UN APELLIDO VALIDO: ", LONGITUD_NOMBRE);
				if(!Passenger_setApellido(this, cadena_PrimeraMayusculas(apellidoAuxiliar, LONGITUD_NOMBRE)))
				{
					mostrarMensaje("SE MODIFICO EL APELLIDO CORRECTAMENTE");
				}
				else
				{
					mostrarMensaje("[ERROR] -> NO SE PUDO MODIFICAR EL APELLIDO");
				}
				break;
			case 3:	// [ OPCION MODIFICAR PRECIO ]
				entrada_obtenerFlotante(&precioAuxiliar, "INGRESE EL NUEVO PRECIO: ", "[ERROR] -> INGRESE UN PRECIO VALIDO: ", PRECIO_MINIMO, PRECIO_MAXIMO);
				if(!Passenger_setPrecio(this, &precioAuxiliar))
				{
					mostrarMensaje("SE MODIFICO EL PRECIO CORRECTAMENTE");
				}
				else
				{
					mostrarMensaje("[ERROR] -> NO SE PUDO MODIFICAR EL PRECIO");
				}
				break;
			case 4:	// [ OPCION MODIFICAR CODIGO DE VUELO ]
				Passenger_ImprimirCodigosDeVuelo();
				opcionCodigoDeVuelo = entrada_obtenerEnteroEntreRango("INGRESE UNA OPCION: ", "[ERROR] -> DATO NO VALIDO", "[ERROR] -> DATO FUERA DE RANGO REINTENTE: ", CODIGO_DE_VUELO_MINIMO, CODIGO_DE_VUELO_MAXIMO);
				Passenger_AsignarCodigosDeVuelo(this, opcionCodigoDeVuelo);
				break;
			case 5:	// [ OPCION MODIFICAR TIPO DE PASAJERO ]
				Passenger_ImprimirTipoPasajero();
				opcionTipoPasajero = entrada_obtenerEnteroEntreRango("INGRESE UNA OPCION: ", "[ERROR] -> DATO NO VALIDO", "[ERROR] -> DATO FUERA DE RANGO REINTENTE: ", TIPO_PASAJERO_MINIMO, TIPO_PASAJERO_MAXIMO);
				Passenger_AsignarTipoPasajero(this, opcionTipoPasajero);
				break;
			case 6:	// [ OPCION VOLVER AL MENU PRINCIPAL ]
				mostrarMensajeParaContinuar("VOLVIENDO AL MENU PRINCIPAL");
				break;
		}
	}while(opcionMenu != 6);
}
//	================================================================================================================
int Passenger_ordenarPorId(void* pElementoUno, void* pElementoDos)
{
	int retorno;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;
	int idPasajeroUno;
	int idPasajeroDos;

	//CONVIERTO EL ELEMENTO EN UNA ESTRUCTURA PASAJERO
	pPasajeroUno = (Passenger*) pElementoUno;
	pPasajeroDos = (Passenger*) pElementoDos;

	//VERIFICO QUE SEAN DISTINTO DE NULL
	if(pPasajeroUno != NULL && pPasajeroDos != NULL)
	{
		//OBTENGO AMBOS ID
		Passenger_getId(pPasajeroUno, &idPasajeroUno);
		Passenger_getId(pPasajeroDos, &idPasajeroDos);

		//COMPARO LOS ID
		if(idPasajeroUno > idPasajeroDos)
		{
			retorno = 1;
		}
		else
		{
			if(idPasajeroUno < idPasajeroDos)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}
//	================================================================================================================
int Passenger_ordenarPorNombre(void* pElementoUno, void* pElementoDos)
{
	int retorno;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;
	char nombrePasajeroUno[LONGITUD_NOMBRE];
	char nombrePasajeroDos[LONGITUD_NOMBRE];

	//CONVIERTO EL ELEMENTO EN UNA ESTRUCTURA PASAJERO
	pPasajeroUno = (Passenger*) pElementoUno;
	pPasajeroDos = (Passenger*) pElementoDos;

	//VERIFICO QUE SEAN DISTINTO DE NULL
	if(pPasajeroUno != NULL && pPasajeroDos != NULL)
	{
		//OBTENGO AMBOS NOMBRES
		Passenger_getNombre(pPasajeroUno, nombrePasajeroUno);
		Passenger_getNombre(pPasajeroDos, nombrePasajeroDos);

		//COMPARO LOS NOMBRES
		retorno = strcmp(nombrePasajeroUno,nombrePasajeroDos);
	}
	return retorno;
}
//	================================================================================================================
int Passenger_ordenarPorApellido(void* pElementoUno, void* pElementoDos)
{
	int retorno;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;
	char apellidoPasajeroUno[LONGITUD_NOMBRE];
	char apellidoPasajeroDos[LONGITUD_NOMBRE];

	//CONVIERTO EL ELEMENTO EN UNA ESTRUCTURA PASAJERO
	pPasajeroUno = (Passenger*) pElementoUno;
	pPasajeroDos = (Passenger*) pElementoDos;

	//VERIFICO QUE SEAN DISTINTO DE NULL
	if(pPasajeroUno != NULL && pPasajeroDos != NULL)
	{
		//OBTENGO AMBOS NOMBRES
		Passenger_getApellido(pPasajeroUno, apellidoPasajeroUno);
		Passenger_getApellido(pPasajeroDos, apellidoPasajeroDos);

		//COMPARO LOS NOMBRES
		retorno = strcmp(apellidoPasajeroUno,apellidoPasajeroDos);
	}
	return retorno;
}
//	================================================================================================================
int Passenger_ordenarPorPrecio(void* pElementoUno, void* pElementoDos)
{
	int retorno;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;
	float precioPasajeroUno;
	float precioPasajeroDos;

	retorno = 0;
	//CONVIERTO EL ELEMENTO EN UNA ESTRUCTURA PASAJERO
	pPasajeroUno = (Passenger*) pElementoUno;
	pPasajeroDos = (Passenger*) pElementoDos;

	//VERIFICO QUE SEAN DISTINTO DE NULL
	if(pPasajeroUno != NULL && pPasajeroDos != NULL)
	{
		//OBTENGO AMBOS PRECIOS
		Passenger_getPrecio(pPasajeroUno, &precioPasajeroUno);
		Passenger_getPrecio(pPasajeroDos, &precioPasajeroDos);

		//COMPARO LOS PRECIOS
		if(precioPasajeroUno > precioPasajeroDos)
		{
			retorno = 1;
		}
		else
		{
			if(precioPasajeroUno < precioPasajeroDos)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}
//	================================================================================================================
int Passenger_ordenarPorCodigoVuelo(void* pElementoUno, void* pElementoDos)
{
	int retorno;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;
	char codigoPasajeroUno[LONGITUD_CODIGOVUELO];
	char codigoPasajeroDos[LONGITUD_CODIGOVUELO];

	//CONVIERTO EL ELEMENTO EN UNA ESTRUCTURA PASAJERO
	pPasajeroUno = (Passenger*) pElementoUno;
	pPasajeroDos = (Passenger*) pElementoDos;

	//VERIFICO QUE SEAN DISTINTO DE NULL
	if(pPasajeroUno != NULL && pPasajeroDos != NULL)
	{
		//OBTENGO AMBOS NOMBRES
		Passenger_getCodigoVuelo(pPasajeroUno, codigoPasajeroUno);
		Passenger_getCodigoVuelo(pPasajeroDos, codigoPasajeroDos);

		//COMPARO LOS NOMBRES
		retorno = strcmp(codigoPasajeroUno,codigoPasajeroDos);
	}
	return retorno;
}
//	================================================================================================================
int Passenger_ordenarPorTipoPasajero(void* pElementoUno, void* pElementoDos)
{
	int retorno;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;
	char tipoPasajeroUno[LONGITUD_NOMBRE];
	char tipoPasajeroDos[LONGITUD_NOMBRE];

	//CONVIERTO EL ELEMENTO EN UNA ESTRUCTURA PASAJERO
	pPasajeroUno = (Passenger*) pElementoUno;
	pPasajeroDos = (Passenger*) pElementoDos;

	//VERIFICO QUE SEAN DISTINTO DE NULL
	if(pPasajeroUno != NULL && pPasajeroDos != NULL)
	{
		//OBTENGO AMBOS NOMBRES
		Passenger_getTipoPasajero(pPasajeroUno, tipoPasajeroUno);
		Passenger_getTipoPasajero(pPasajeroDos, tipoPasajeroDos);

		//COMPARO LOS NOMBRES
		retorno = strcmp(tipoPasajeroUno,tipoPasajeroDos);
	}
	return retorno;
}
//	================================================================================================================
int Passenger_ordenarPorEstadoVuelo(void* pElementoUno, void* pElementoDos)
{
	int retorno;
	Passenger* pPasajeroUno;
	Passenger* pPasajeroDos;
	char estadoVueloPasajeroUno[LONGITUD_NOMBRE];
	char estadoVueloPasajeroDos[LONGITUD_NOMBRE];

	//CONVIERTO EL ELEMENTO EN UNA ESTRUCTURA PASAJERO
	pPasajeroUno = (Passenger*) pElementoUno;
	pPasajeroDos = (Passenger*) pElementoDos;

	//VERIFICO QUE SEAN DISTINTO DE NULL
	if(pPasajeroUno != NULL && pPasajeroDos != NULL)
	{
		//OBTENGO AMBOS NOMBRES
		Passenger_getEstadoDeVuelo(pPasajeroUno, estadoVueloPasajeroUno);
		Passenger_getEstadoDeVuelo(pPasajeroDos, estadoVueloPasajeroDos);

		//COMPARO LOS NOMBRES
		retorno = strcmp(estadoVueloPasajeroUno,estadoVueloPasajeroDos);
	}
	return retorno;
}
//	================================================================================================================



//	================================================================================================================
//	================================================================================================================
//	================================================================================================================
//	================================================================================================================
//	>> POR RAZONES DE TIEMPO SE REALIZARON ESTAS FUNCIONES, DEBERIA HABERSE CREADO UNA ESTRUCTURA PARA CODIGOS, ESTADOS Y TIPO DE PASAJERO

void Passenger_ImprimirTipoPasajero(void)
{
	encabezadoTablaTipoPasajero ();
	printf("º  [1] EconomyClass    º\n");
	printf("º  [2] FirstClass      º\n");
	printf("º  [3] ExecutiveClass  º\n");
	PieDePaginaTablaTipoPasajero ();
}
//	================================================================================================================
void Passenger_AsignarTipoPasajero(Passenger* this, int opcion)
{
	char tipoPasajero[LONGITUD_NOMBRE];

	switch(opcion)
	{
		case 1:
			strncpy(tipoPasajero, "EconomyClass", LONGITUD_NOMBRE);
			break;
		case 2:
			strncpy(tipoPasajero, "FirstClass", LONGITUD_NOMBRE);
			break;
		case 3:
			strncpy(tipoPasajero, "ExecutiveClass", LONGITUD_NOMBRE);
			break;
	}

	Passenger_setTipoPasajero(this, tipoPasajero);
}

void Passenger_AsignarTipoPasajeroTxt(int opcion, char* tipoPasajero)
{
	switch(opcion)
	{
		case 1:
			strncpy(tipoPasajero, "EconomyClass", LONGITUD_NOMBRE);
			break;
		case 2:
			strncpy(tipoPasajero, "FirstClass", LONGITUD_NOMBRE);
			break;
		case 3:
			strncpy(tipoPasajero, "ExecutiveClass", LONGITUD_NOMBRE);
			break;
	}
}
//	================================================================================================================
void Passenger_ImprimirCodigosDeVuelo(void)
{
	encabezadoTablaCodigosDeVuelo();
	printf("º  [1] BA2491A  º\n");
	printf("º  [2] IB0800A  º\n");
	printf("º  [3] MM0987B  º\n");
	printf("º  [4] TU6789B  º\n");
	printf("º  [5] GU2345F  º\n");
	printf("º  [6] HY4567D  º\n");
	printf("º  [7] FR5678G  º\n");
	printf("º  [8] BR3456J  º\n");
	PieDePaginaTablaCodigosDeVuelo();
}
//	================================================================================================================
void Passenger_AsignarCodigosDeVuelo(Passenger* this, int opcion)
{
	char codigoVuelo[LONGITUD_CODIGOVUELO];
	char estadoVuelo[LONGITUD_NOMBRE];

	switch(opcion)
	{
		case 1:
			strncpy(codigoVuelo, "BA2491A", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Aterrizado",LONGITUD_NOMBRE);
			break;
		case 2:
			strncpy(codigoVuelo, "IB0800A", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Aterrizado",LONGITUD_NOMBRE);
			break;
		case 3:
			strncpy(codigoVuelo, "MM0987B", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "En Horario",LONGITUD_NOMBRE);
			break;
		case 4:
			strncpy(codigoVuelo, "TU6789B", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Aterrizado",LONGITUD_NOMBRE);
			break;
		case 5:
			strncpy(codigoVuelo, "GU2345F", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "En Vuelo",LONGITUD_NOMBRE);
			break;
		case 6:
			strncpy(codigoVuelo, "HY4567D", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Demorado",LONGITUD_NOMBRE);
			break;
		case 7:
			strncpy(codigoVuelo, "FR5678G", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "En Horario",LONGITUD_NOMBRE);
			break;
		case 8:
			strncpy(codigoVuelo, "BR3456J", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Demorado",LONGITUD_NOMBRE);
			break;
	}

	Passenger_setCodigoVuelo(this, codigoVuelo);
	Passenger_setEstadoDeVuelo(this, estadoVuelo);
}

void Passenger_AsignarCodigosDeVueloTxt(int opcion, char* codigoVuelo, char* estadoVuelo)
{
	switch(opcion)
	{
		case 1:
			strncpy(codigoVuelo, "BA2491A", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Aterrizado",LONGITUD_NOMBRE);
			break;
		case 2:
			strncpy(codigoVuelo, "IB0800A", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Aterrizado",LONGITUD_NOMBRE);
			break;
		case 3:
			strncpy(codigoVuelo, "MM0987B", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "En Horario",LONGITUD_NOMBRE);
			break;
		case 4:
			strncpy(codigoVuelo, "TU6789B", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Aterrizado",LONGITUD_NOMBRE);
			break;
		case 5:
			strncpy(codigoVuelo, "GU2345F", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "En Vuelo",LONGITUD_NOMBRE);
			break;
		case 6:
			strncpy(codigoVuelo, "HY4567D", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Demorado",LONGITUD_NOMBRE);
			break;
		case 7:
			strncpy(codigoVuelo, "FR5678G", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "En Horario",LONGITUD_NOMBRE);
			break;
		case 8:
			strncpy(codigoVuelo, "BR3456J", LONGITUD_CODIGOVUELO);
			strncpy(estadoVuelo, "Demorado",LONGITUD_NOMBRE);
			break;
	}
}
//	================================================================================================================
//	================================================================================================================
//	================================================================================================================
//	================================================================================================================

//	===================
//	> FUNCIONES SETTERS
//	===================
//	>> SET ID -> clase 18 parte 2
int Passenger_setIdTxt(Passenger* this,char* id)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && id != NULL)
	{
		//VERIFICO QUE NO SEA UN DATO INVALIDO
		if(esNumeroValido(id, LONGITUD_ID))
		{
			//LO GUARDO EN EL ID
			this->id = atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}
//	================================================================================================================
//	>> SET ID
int Passenger_setId(Passenger* this,int* id)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && id >= 0)
	{
		//LO GUARDO EN EL ID
		this->id = *id;
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> SET NOMBRE -> clase 18 parte 2
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && nombre != NULL)
	{
		//VERIFICO QUE NO SEA UN DATO INVALIDO
		if(esNombreValido(nombre, LONGITUD_NOMBRE))
		{
			//LO GUARDO EN EL NOMBRE
			strcpy(this->nombre, nombre);
			retorno = 0;
		}
	}
	return retorno;
}
//	================================================================================================================
//	>> SET APELLIDO
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && apellido != NULL)
	{
		//VERIFICO QUE NO SEA UN DATO INVALIDO
		if(esNombreValido(apellido, LONGITUD_NOMBRE))
		{
			//LO GUARDO EN EL NOMBRE
			strcpy(this->apellido, apellido);
			retorno = 0;
		}
	}
	return retorno;
}
//	================================================================================================================
//	>> SET CODIGO DE VUELO
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && codigoVuelo != NULL)
	{
		//VERIFICO QUE NO SEA UN DATO INVALIDO
		if(!esAlfaNUmericoValido(codigoVuelo, LONGITUD_NOMBRE))
		{
			//LO GUARDO EN EL NOMBRE
			strcpy(this->codigoVuelo, codigoVuelo);
			retorno = 0;
		}
	}
	return retorno;
}
//	================================================================================================================
//	>> SET TIPO PASAJERO
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && tipoPasajero != NULL)
	{
		//VERIFICO QUE NO SEA UN DATO INVALIDO
		if(esNombreValido(tipoPasajero, LONGITUD_NOMBRE))
		{
			//LO GUARDO EN EL NOMBRE
			strcpy(this->tipoPasajero, tipoPasajero);
			retorno = 0;
		}
	}
	return retorno;
}
//	================================================================================================================
//	>> SET PRECIO
int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int retorno;
	float auxiliarPrecio;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && precio != NULL)
	{
		if(esFlotanteValido(precio))
		{
			auxiliarPrecio = atof(precio);
			if(auxiliarPrecio >= 0)
			{
				//LO GUARDO EN EL PRECIO
				this->precio = auxiliarPrecio;
				retorno = 0;
			}
		}
	}
	return retorno;
}
//	================================================================================================================
//	>> SET PRECIO
int Passenger_setPrecio(Passenger* this,float* precio)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && precio >= 0)
	{
		//LO GUARDO EN EL PRECIO
		this->precio = *precio;
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> SET ESTADO DE VUELO
int Passenger_setEstadoDeVuelo(Passenger* this,char* statusFlight)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && statusFlight != NULL)
	{
		//VERIFICO QUE NO SEA UN DATO INVALIDO
		if(esNombreValido(statusFlight, LONGITUD_NOMBRE))
		{
			//LO GUARDO EN EL NOMBRE
			strcpy(this->statusFlight, statusFlight);
			retorno = 0;
		}
	}
	return retorno;
}
//	================================================================================================================
//	===================
//	> FUNCIONES GETTERS
//	===================
//	>> GET ID -> clase 18 parte 2
int Passenger_getIdTxt(Passenger* this,char* id)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && id != NULL)
	{
		//LO GUARDO EN EL ID
		sprintf(id, "%d", this->id);
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> GET ID
int Passenger_getId(Passenger* this,int* id)
{
	int retorno;

	retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
//	================================================================================================================
//	>> GET NOMBRE
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && nombre != NULL)
	{
		//LO GUARDO EN EL NOMBRE
		strncpy(nombre, this->nombre,LONGITUD_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> GET APELLIDO
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && apellido != NULL)
	{
		//LO GUARDO EN EL NOMBRE
		strncpy(apellido, this->apellido,LONGITUD_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> GET CODIGO DE VUELO
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && codigoVuelo != NULL)
	{
		//LO GUARDO EN EL NOMBRE
		strncpy(codigoVuelo, this->codigoVuelo,LONGITUD_CODIGOVUELO);
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> GET TIPO DE PASAJERO
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && tipoPasajero != NULL)
	{
		//LO GUARDO EN EL NOMBRE
		strncpy(tipoPasajero, this->tipoPasajero,LONGITUD_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> GET PRECIO
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && precio != NULL)
	{
		//LO GUARDO EN EL PRECIO
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> GET ESTADO DE VUELO
int Passenger_getEstadoDeVuelo(Passenger* this, char* statusFlight)
{
	int retorno;

	retorno = -1;
	//VERIFICO QUE NO SEAN NULL
	if(this != NULL && statusFlight != NULL)
	{
		//LO GUARDO EN EL NOMBRE
		strncpy(statusFlight, this->statusFlight,LONGITUD_NOMBRE);
		retorno = 0;
	}
	return retorno;
}
//	================================================================================================================
//	>> GET ULTIMO ID
int Passenger_getUltimoId(int* id)
{
	int retorno;
	FILE* pArchivoId = NULL;
	int ultimoId;

	retorno = -1;

	//ABRO EL ARCHIVO DE ULTIMO ID
	pArchivoId = fopen(ARCHIVO_ULTIMO_ID_GENERADO, "r");

	//VERIFICO QUE NO SEA NULL
	if(pArchivoId != NULL)
	{
		//LEO EL ARCHIVO
		if(fscanf(pArchivoId,"%d",&ultimoId) == 1)
		{
			//ME GUARDO EL ULTIMO ID PARA USAR YA SUMADO CON ANTERIORIDAD
			*id = ultimoId;
			retorno = 0;
		}
	}
	//CIERRO EL ARCHIVO
	fclose(pArchivoId);

	return retorno;
}
//	================================================================================================================
//	>> SET ULTIMO ID
int Passenger_setUltimoId(int id)
{
	int retorno;
	FILE* pArchivoId = NULL;
	int siguienteId;

	retorno = -1;

	//SUMO 1 PARA EL PROXIMO ID
	siguienteId = id + 1;

	//ABRO EL ARCHIVO DE IDs
	pArchivoId = fopen(ARCHIVO_ULTIMO_ID_GENERADO, "w");

	//VERIFICO QUE NO SEA NULL
	if(pArchivoId != NULL)
	{
		//IMPRIMO EN EL ARCHIVO EL ULTIMO ID
		fprintf(pArchivoId,"%d\n",siguienteId);
		retorno = 0;
	}
	//CIERRO EL ARCHIVO
	fclose(pArchivoId);

	return retorno;
}
