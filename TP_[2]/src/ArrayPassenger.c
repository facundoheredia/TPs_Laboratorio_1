/// Funciones ArrayPassenger.c
/// @author HEREDIA, FACUNDO GASTON
///
/// @date 23-04-2022

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "ArrayPassenger.h"


//	=====================
//	> FUNCIONES Passenger
//	=====================

//	> FUNCION OBTENER ID AUTOMATICO
static int obtenerIdAutomatico ();

static int obtenerIdAutomatico ()
{
	static int pasajero_idIncremental = 1000;

	pasajero_idIncremental++;

	return pasajero_idIncremental;
}

//	================================================================================================================
//	> FUNCION DE ESTRUCTURA PASAJERO VACIO	<<<<<<VERIFICAR FUNCIONAMIENTO>>>>>>
static Passenger listaPasajeroVacio (void);

static Passenger listaPasajeroVacio (void)
{
	Passenger pasajeroAuxiliar;
	//CARGA DATOS INVALIDOS SIN BASURA
	pasajeroAuxiliar.id = -1;
	strcpy(pasajeroAuxiliar.name, "NULL");
	strcpy(pasajeroAuxiliar.lastname, "NULL");
	pasajeroAuxiliar.price = -1;
	strcpy(pasajeroAuxiliar.flycode, "NULL");
	pasajeroAuxiliar.typePassenger = -1;
	pasajeroAuxiliar.statusFlight = -1;
	pasajeroAuxiliar.isEmpty = LIBRE;

	return pasajeroAuxiliar;
}

//	================================================================================================================
//	> FUNCION INICIALIZAR LISTA PASAJEROS
int initPassengers(Passenger* list, int len)
{
	int retorno;
	int i;
	//ERROR SI NO PUDO INICIALIZAR
	retorno = -1;
	//RECORRO EL ARRAY MARCANDO TODAS LAS POSICIONES LIBRES
	if (list != NULL && len > 0 && len <= CANTIDAD_MAXIMA_PASAJEROS)
	{
		for (i = 0 ; i < len ; i++)
		{
			list[i].isEmpty = LIBRE;
		}
		// SI LLEGO AL FINAL LA FUNCION TERMINO CORECTAMENTE
		if(i == len)
		{
			retorno = 0;
		}
	}
	//SI NO LLEGO AL FINAL [ERROR = -1], SI COMPLETO EL ARRAY HASTA EL FINAL [CORRECTO = 0]
	return retorno;
}

//	================================================================================================================
//	> FUNCION HARDCODEO DE PASAJEROS (PARA TESTEOS) <-- COMENTAR EN EL MAIN SI NO SE USA
void ePassenger_hardcodeados(Passenger array[], int longitud)
{
	int indexHardcodeMax = 9;

	Passenger listaAuxiliar[] = {
								//ID - NOMBRE - APELLIDO - PRECIO - CODIGO - TIPO - ESTADOVUELO - ESTADOPOSICION
	        				 {obtenerIdAutomatico(),"FACUNDO", 	"HEREDIA", 	12500, 		"A102R", 2, 0, OCUPADO},
							 {obtenerIdAutomatico(),"LUCIANA", 	"PROSTY", 	10250.50, 	"B052E", 1, 3, OCUPADO},
							 {obtenerIdAutomatico(),"SANDRA", 	"CENTRON", 	5524.23, 	"J529B", 0, 4, OCUPADO},
							 {obtenerIdAutomatico(),"LAUTARO", 	"RAPOSO", 	32120, 		"Z446S", 2, 3, OCUPADO},
							 {obtenerIdAutomatico(),"SONIA", 	"BEZOS", 	65325.30, 	"Y002N", 2, 2, OCUPADO},
							 {obtenerIdAutomatico(),"SANTIAGO", "HEREDIA", 	36120, 		"N984M", 1, 1, OCUPADO},
							 {obtenerIdAutomatico(),"AGUSTINA",	"BARBEITO",	89650, 		"J873P", 2, 0, OCUPADO},
							 {obtenerIdAutomatico(),"EMANUEL", 	"PROSTY", 	75420, 		"K765X", 0, 0, OCUPADO},
							 {obtenerIdAutomatico(),"KAROLINA",	"BENITEZ", 	9560, 		"L098V", 0, 4, OCUPADO},
							 {obtenerIdAutomatico(),"ESTABAN", 	"FALLONE", 	65822.65, 	"Z453T", 2, 2, OCUPADO}};

	if(array != NULL && longitud > 0 && longitud <= CANTIDAD_MAXIMA_PASAJEROS)
	{
	   for (int i = 0; i < longitud; i++)
	   {
	      if(i <= indexHardcodeMax)
	      {
	    	  array[i] = listaAuxiliar[i];
	      }
	      else
	      {
	    	  array[i] = listaPasajeroVacio();
	      }
	   }
	}
}

//	================================================================================================================
//	> FUNCION AGREGAR PASAJERO
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight, int indiceLibreEncontrado) // <-- Int indiceEncontrado y int statusFlight = agregado a la funcion
{
	int retorno;

	Passenger pasajeroAuxiliar;

	retorno = -1;

	if (list != NULL && len > 0 && len <= CANTIDAD_MAXIMA_PASAJEROS)
	{

		pasajeroAuxiliar.id = id;
		strcpy(pasajeroAuxiliar.name, name);
		strcpy(pasajeroAuxiliar.lastname, lastName);
		pasajeroAuxiliar.price = price;
		pasajeroAuxiliar.typePassenger = typePassenger;
		strcpy(pasajeroAuxiliar.flycode, flycode);
		pasajeroAuxiliar.statusFlight = statusFlight;
		// ESTADO A OCUPADO
		pasajeroAuxiliar.isEmpty = OCUPADO;
		//COPIO A ORIGINAL
		list[indiceLibreEncontrado] = pasajeroAuxiliar;
		//SALIO OK
		retorno = 0;
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION CARGAR UN PASAJERO EN LISTA
int Passenger_Alta (Passenger listaPasajeros[], int longitudPasajeros, EstadosDeVuelo listaEstadosDeVuelos[], int longitudEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudDeTipoPasajero)
{
	int retorno;
	int indiceLibreEncontrado;
	Passenger pasajeroAuxiliar;

	retorno = -1;

	if(listaPasajeros != NULL && longitudPasajeros > 0 && longitudPasajeros <= CANTIDAD_MAXIMA_PASAJEROS)
	{
		indiceLibreEncontrado = buscarIndiceLibre(listaPasajeros, longitudPasajeros);

		if (indiceLibreEncontrado != -1)
		{
			// NOMBRE
			entrada_obtenerCadena(pasajeroAuxiliar.name, "INGRESE EL NOMBRE DEL PASAJERO: ", "ERROR! INTENTE NUEVAMENTE: ", LONGITUD_NOMBRE_PASAJERO); // <-- REVISAR FUNCION PARA QUE NO SE PASE DEL LIMITE
			// APELLIDO
			entrada_obtenerCadena(pasajeroAuxiliar.lastname, "INGRESE EL APELLIDO DEL PASAJERO: ", "ERROR! INTENTE NUEVAMENTE: ", LONGITUD_NOMBRE_PASAJERO);
			// PRECIO
			entrada_obtenerFlotante(&pasajeroAuxiliar.price, "INGRESE EL PRECIO DEL VUELO $: ", "ERROR! INTENTE NUEVAMENTE: ", MONTO_MINIMO_PRECIO, MONTO_MAXIMO_PRECIO);
			// TIPO PASAJERO
			TipoPasajero_mostrarTodos (listaDeTipoPasajeros, longitudDeTipoPasajero);
			entrada_obtenerEntero(&pasajeroAuxiliar.typePassenger, "INGRESE EL ID DEL TIPO DE PASAJERO: ", "ERROR! INTENTE NUEVAMENTE: ", ECONOMICO, EJECUTIVO);
			// ESTADO DEL VUELO
			EstadoVuelo_mostrarTodos (listaEstadosDeVuelos, longitudEstadosDeVuelos);
			entrada_obtenerEntero(&pasajeroAuxiliar.statusFlight, "INGRESE EL ID DEL ESTADO DEL VUELO: ", "ERROR! INTENTE NUEVAMENTE: ", A_TIEMPO, CANCELADO);
			// CODIGO DE VUELO
			entrada_obtenerCadenaAlfaNumerica("INGRESE EL CODIGO DE VUELO (ej: R456g):", "ERROR! VUELVA A INTENTARLO: ", pasajeroAuxiliar.flycode);
			// ID AUTOMATICO
			pasajeroAuxiliar.id = obtenerIdAutomatico ();

			// LLAMO A LA FUNCION ADDPASSENGER PARA CARGAR LOS DATOS
			if(addPassenger(listaPasajeros, longitudPasajeros, pasajeroAuxiliar.id, pasajeroAuxiliar.name,pasajeroAuxiliar.lastname, pasajeroAuxiliar.price, pasajeroAuxiliar.typePassenger, pasajeroAuxiliar.flycode, pasajeroAuxiliar.statusFlight, indiceLibreEncontrado) == 0)
			{
				retorno = 0;
			}
			else
			{
				mostrarMensaje("ERROR! HUBO UN ERROR VUELVA A CARGAR LOS DATOS");
			}
		}
		else
		{
			mostrarMensaje("NO QUEDAN INDICES LIBRES PARA DAR DE ALTA UNA NUEVA PERSONA\n");
		}
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION BUSCAR UN INDICE LIBRE
int buscarIndiceLibre(Passenger listaPasajeros[], int longitudListaPasajeros)
{
	int retorno;
	int i;
	// RETORNO ERROR
	retorno = -1;
	// RECORRO EL ARRAY DE PASAJEROS
	for(i = 0; i < longitudListaPasajeros; i++)
	{
		if(listaPasajeros[i].isEmpty == LIBRE)
		{	// SI ENCUENTRA UN ESPACIO LIBRE DEVUELVE EL INCIDE
			retorno = i;
			break;
		}
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION BUSCAR PASAJERO POR ID
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;
	int i;

	retorno = -1;

	if (list != NULL && len > 0 && len <= CANTIDAD_MAXIMA_PASAJEROS)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == OCUPADO && list[i].id == id)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION REMOVE PASSENGER
int removePassenger(Passenger* list, int len, int id, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero) // <-- SE AGREGARON MAS PARAMETROS
{
	int retorno;
	int indiceEncontrado;
	char respuesta;

	retorno = -1;

	if (list != NULL && len > 0 && len <= CANTIDAD_MAXIMA_PASAJEROS)
	{
		encabezadoDarDeBaja();

		indiceEncontrado = findPassengerById(list, len, id);
		mostrarUnPasajero (list[indiceEncontrado], listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);

		PieDePaginaTabla ();

		respuesta = entrada_respuestaUsuario ("ฟDESEA BORRAR PASAJERO? S/N");

		if(respuesta == 'S')
		{
			list[indiceEncontrado].isEmpty = LIBRE;
			retorno = 0;
		}
		system("cls");
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION SORT PASSENGER
int sortPassengers(Passenger* list, int len, int order)
{
	int retorno;
	int i;
	int j;
	Passenger listaAuxiliar;

	retorno = -1;

	// ORDENADOS POR CODIGO DE VUELO Y ESTADOS DE VUELOS "ACTIVO"
	if(list != NULL && len > 0 && len <= CANTIDAD_MAXIMA_PASAJEROS && (order == UP || order == DOWN))
	{
		for (i = 0; i < len; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(order == UP)
					{
						if(strcmp(list[i].lastname, list[j].lastname) > 0 || (strcmp(list[i].lastname, list[j].lastname) == 0 && list[i].typePassenger < list[j].typePassenger))
						{
							listaAuxiliar = list[i];
							list[i] = list[j];
							list[j] = listaAuxiliar;
						}
					}
					else
					{
						if(strcmp(list[i].lastname, list[j].lastname) < 0 || (strcmp(list[i].lastname, list[j].lastname) == 0 && list[i].typePassenger < list[j].typePassenger))
						{
							listaAuxiliar = list[i];
							list[i] = list[j];
							list[j] = listaAuxiliar;
						}
					}
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

//	================================================================================================================
//	> FUNCION PRINT PASSENGER
int printPassenger(Passenger* list, int length, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero) // <-- SE AGREGARON PARAMETROS
{
	int retorno;
	int i;

	retorno = -1;


	if (list != NULL && length > 0 && length <= CANTIDAD_MAXIMA_PASAJEROS)
	{
		encabezadoTabla ();
		for (i = 0; i < length; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				mostrarUnPasajero (list[i], listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
				retorno = 0;
			}
		}
		PieDePaginaTabla ();
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION DAR BAJA A UN PASAJERO
int Passenger_Baja(Passenger list[], int length, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero)
{
	int retorno;
	int idPasajeroBaja;
	//int contadorId;

	retorno = -1;

	//IMPRIMO LISTA DE PASAJEROS
	printPassenger(list, length, listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
	//contadorId = Passenger_contar_id(list, length);

	//PIDO DATO DEL ID DEL PASAJERO
	entrada_obtenerEnteroSinRango(&idPasajeroBaja, "INGRESE EL ID DEL PASAJERO A DAR DE BAJA:", "ERROR! INTENTE NUEVAMENTE");
	//entrada_obtenerEntero(&idPasajeroBaja, "INGRESE EL ID DEL PASAJERO A DAR DE BAJA:", "ERROR! INTENTE NUEVAMENTE", ID_MINIMO, contadorId);

	while(findPassengerById(list, length,idPasajeroBaja) == -1)
	{
		mostrarMensaje("NO SE ENCONTRO EL ID, REINTENTE");
		entrada_obtenerEnteroSinRango(&idPasajeroBaja, "INGRESE EL ID DEL PASAJERO A DAR DE BAJA:", "ERROR! INTENTE NUEVAMENTE");
		//entrada_obtenerEntero(&idPasajeroBaja, "INGRESE EL ID DEL PASAJERO A DAR DE BAJA:", "ERROR! INTENTE NUEVAMENTE", ID_MINIMO, contadorId);
	}

	if(findPassengerById(list, length,idPasajeroBaja) != -1)
	{
		//LLAMO A LA FUNCION REMOVER
		if(removePassenger(list, length, idPasajeroBaja, listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero) == 0)
		{
			retorno = 0;
		}
		else
		{
			mostrarMensaje("HUBO UN ERROR EN LA BAJA DEL PASAJERO, REINTENTE");
		}

	}
	else
	{
		mostrarMensaje (MENSAJE_PASAJERO_BAJA_CANCELADA);
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION CONTAR ID ACTIVOS
int Passenger_contar_id(Passenger list[], int length)
{
	int contador;

	contador = ID_MINIMO;

	for(int i = 0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			contador++;
		}
	}

	return contador;
}

//	================================================================================================================
//	> FUNCION MOSTRAR TIPO PASAJERO
void TipoPasajero_mostrarTodos (TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero)
{
	printf("ษอออออออออออออออออออออออป\n");
	for(int i = 0; i < longitudListaDeTipoPasajero; i++)
	{
		printf("บ %d | %s \tบ\n", listaDeTipoPasajeros[i].idTiposDePasajeros, listaDeTipoPasajeros[i].tiposDePasajeros);
	}
	printf("ศอออออออออออออออออออออออผ\n");
}

//	================================================================================================================
//	> OBTENER ESTADO VUELO
void EstadoVuelo_mostrarTodos (EstadosDeVuelo listaEstadosDeVuelos[], int longitudListaEstadosDeVuelos)
{
	printf("ษอออออออออออออออออออออออป\n");
	for(int i = 0; i < longitudListaEstadosDeVuelos; i++)
	{
		printf("บ %d | %s \tบ\n", listaEstadosDeVuelos[i].idEstadoVuelo, listaEstadosDeVuelos[i].estadoVuelo);
	}
	printf("ศอออออออออออออออออออออออผ\n");
}

//	================================================================================================================
//	> FUNCION BUSCAR TIPO PASAJERO POR ID
int TipoPasajero_buscarPorId(TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(listaDeTipoPasajeros != NULL && longitudListaDeTipoPasajero > 0 && longitudListaDeTipoPasajero <= LONGITUD_DE_TIPO_PASAJERO)
	{
		for(i = 0; i < longitudListaDeTipoPasajero; i++)
		{
			if(listaDeTipoPasajeros[i].idTiposDePasajeros == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION BUSCAR ESTADOS DE VUELO POR ID
int EstadosDeVuelo_buscarPorId(EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, int id)
{
	int retorno;
	int i;

	retorno = -1;

	if(listadoEstadosDeVuelo != NULL && longitudListaEstadosDeVuelos > 0 && longitudListaEstadosDeVuelos <= LONGITUD_ESTADO_VUELO)
	{
		for(i = 0; i < longitudListaEstadosDeVuelos; i++)
		{
			if(listadoEstadosDeVuelo[i].idEstadoVuelo == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

//	================================================================================================================
//	> FUNCION MOSTRAR PASAJERO
void mostrarUnPasajero (Passenger pasajero, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero)
{
	int indiceTipoPasajero;
	int indiceEstadoVuelo;

	indiceTipoPasajero = TipoPasajero_buscarPorId(listaDeTipoPasajeros, longitudListaDeTipoPasajero, pasajero.typePassenger);
	indiceEstadoVuelo = EstadosDeVuelo_buscarPorId(listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, pasajero.statusFlight);

    printf("บ %-4d \t| %-15s | %-15s | $ %10.2f | %-4s \t| %-8s \t| %-14s บ\n", pasajero.id, pasajero.name, pasajero.lastname, pasajero.price, pasajero.flycode, listaDeTipoPasajeros[indiceTipoPasajero].tiposDePasajeros, listadoEstadosDeVuelo[indiceEstadoVuelo].estadoVuelo);
}

//	================================================================================================================
//	> FUNCION MODIFICAR DATOS DE PASAJERO
int Passenger_Modificar(Passenger list[], int length, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero)
{
	int retorno;
	int idPasajero;
	int indicePasajero;
	Passenger pasajeroAuxiliar;
	char respuesta;
	//int contadorId;

	retorno = -1;

	//IMPRIMO LISTA DE PASAJEROS
	printPassenger(list, length, listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
	//contadorId = Passenger_contar_id(list, length);
	entrada_obtenerEnteroSinRango(&idPasajero, "INGRESE EL ID DEL PASAJERO A MODIFICAR:", "ERROR! INTENTE NUEVAMENTE");
	//entrada_obtenerEntero(&idPasajero, "INGRESE EL ID DEL PASAJERO A MODIFICAR:", "ERROR! INTENTE NUEVAMENTE", ID_MINIMO, contadorId);

	indicePasajero = findPassengerById(list, length, idPasajero);

	if(indicePasajero != -1)
	{
		pasajeroAuxiliar = Passenger_ModificarUno(list[indicePasajero], listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);

		respuesta = entrada_respuestaUsuario("ฟDESEA MODIFICAR ESTE PASAJERO? S/N");

		if(respuesta == 'S')
		{
			list[indicePasajero] = pasajeroAuxiliar;
			retorno = 0;
		}
	}
	else
	{
		mostrarMensaje("NO SE HA ENCONTRADO EL ID DEL PASAJERO, REINTENTE\n");
	}


	return retorno;
}

//	================================================================================================================
//	> FUNCION MODIFICAR UN PASAJERO
Passenger Passenger_ModificarUno (Passenger pasajero, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero)
{
	Passenger pasajeroAuxiliar;
	int opcionModificacion;
	pasajeroAuxiliar = pasajero;

	do
	{
		system("cls");
		encabezadoTabla ();
		mostrarUnPasajero (pasajeroAuxiliar, listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
		PieDePaginaTabla ();

		switch (opcionModificacion = menuModificacion ())
		{
			case 1: //	[ OPCION MODIFICACION NOMBRE ]
				entrada_obtenerCadena(pasajeroAuxiliar.name, "INGRESE EL NOMBRE DEL PASAJERO: ", "ERROR! INTENTE NUEVAMENTE: ", LONGITUD_NOMBRE_PASAJERO);
				break;
			case 2: //	[ OPCION MODIFICACION APELLIDO ]
				entrada_obtenerCadena(pasajeroAuxiliar.lastname, "INGRESE EL APELLIDO DEL PASAJERO: ", "ERROR! INTENTE NUEVAMENTE: ", LONGITUD_NOMBRE_PASAJERO);
				break;
			case 3: //	[ OPCION MODIFICACION PRECIO ]
				entrada_obtenerFlotante(&pasajeroAuxiliar.price, "INGRESE EL PRECIO DEL VUELO $: ", "ERROR! INTENTE NUEVAMENTE: ", MONTO_MINIMO_PRECIO, MONTO_MAXIMO_PRECIO);
				break;
			case 4: //	[ OPCION MODIFICACION TIPO DE PASAJERO ]
				TipoPasajero_mostrarTodos (listaDeTipoPasajeros, longitudListaDeTipoPasajero);
				entrada_obtenerEntero(&pasajeroAuxiliar.typePassenger, "INGRESE EL ID DEL TIPO DE PASAJERO: ", "ERROR! INTENTE NUEVAMENTE: ", ECONOMICO, EJECUTIVO);
				break;
			case 5: //	[ OPCION MODIFICACION CODIGO DE VUELO ]
				entrada_obtenerCadenaAlfaNumerica("INGRESE EL CODIGO DE VUELO (ej: R456g):", "ERROR! VUELVA A INTENTARLO: ", pasajeroAuxiliar.flycode);
				break;
		}
			}while(opcionModificacion != 6);

	return pasajeroAuxiliar;
}

//	================================================================================================================
//	> FUNCION LISTAR PASAJEROS
void Passenger_Listado(Passenger list[], int length, int order, int cantidadAltas, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero)
{
	int opcionListar;
	//MOSTRAR MENU
	do
	{
		switch(opcionListar = menuListado())
		{
			case 1: //	[ LISTADO POR APELLIDO Y TIPO PASAJERO ]
				sortPassengers(list, length, order);
				printPassenger(list, length, listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
				mostrarMensajeParaContinuar("ESTOS SON LOS PASAJEROS ORDENADOS POR APELLIDO Y TIPO DE PASAJERO");
				break;
			case 2: //	[ TOTAL Y PROMEDIO DE LOS PASAJES ]
				Passenger_mayorAlPromedio (list, length, cantidadAltas, listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
				break;
			case 3: //	[ LISTADO POR CODIGO DE VUELO Y ESTADO ACTIVO ]
				sortPassengersByCode(list, length, order);
				printPassenger(list, length, listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
				mostrarMensajeParaContinuar("ESTOS SON LOS PASAJEROS ORDENADOS POR CODIGO DE VUELO Y ESTADO DE VUELO");
				break;
		}

	}while(opcionListar != 4);
}

//	================================================================================================================
//	> FUNCION TOTAL Y PROMEDIO DE PASAJES
void Passenger_mayorAlPromedio (Passenger list[], int length, int cantidadAltas, EstadosDeVuelo listadoEstadosDeVuelo[], int longitudListaEstadosDeVuelos, TiposPasajeros listaDeTipoPasajeros[], int longitudListaDeTipoPasajero)
{
	int i;
	float importeTotal;
	float promedioImporteTotal;
	int cantidadMayorAlPromedio;

	importeTotal = Passenger_ImporteTotal(list, length);
	promedioImporteTotal = Passenger_PromedioImporte(importeTotal, cantidadAltas);
	cantidadMayorAlPromedio = Passenger_cantidadMayorAlPromedio(list, length, promedioImporteTotal);

	printf("EL IMPORTE TOTAL DE LA LISTA DE PASAJEROS ES DE $ %.2f\n", importeTotal);
	printf("EL PROMEDIO DEL IMPORTE TOTAL DE LA LISTA DE PASAJEROS ES DE $ %.2f\n", promedioImporteTotal);
	printf("LA CANTIDAD DE PASAJEROS MAYOR AL PROMEDIO ES DE %d\n", cantidadMayorAlPromedio);

	encabezadoTabla();
	for(i = 0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].price > promedioImporteTotal)
		{
			mostrarUnPasajero(list[i], listadoEstadosDeVuelo, longitudListaEstadosDeVuelos, listaDeTipoPasajeros, longitudListaDeTipoPasajero);
		}
	}
	PieDePaginaTabla();
	mostrarMensajeParaContinuar("ESTOS SON LOS PASAJEROS QUE SUPERAN EL PROMEDIO\n");
}

//	================================================================================================================
//	> FUNCION SECUNDARIA MOSTRAR TOTAL IMPORTE
float Passenger_ImporteTotal(Passenger list[], int length)
{
	int i;
	int acumulador;

	acumulador = 0;

	for (i = 0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			acumulador += list[i].price;
		}
	}

	return acumulador;
}

//	================================================================================================================
//	> FUNCION SECUNDARIA MOSTRAR PROMEDIO IMPORTE TOTAL
float Passenger_PromedioImporte (float importeTotal, int cantidadAltas)
{
	float promedio;

	promedio = importeTotal / cantidadAltas;

	return promedio;
}

//	================================================================================================================
//	> FUNCION CANTIDAD DE PASAJEROS MAYOR AL PRECIO PROMEDIO
int Passenger_cantidadMayorAlPromedio(Passenger list[], int length, float promedioImporteTotal)
{
	int i;
	int contador;

	contador = 0;

	for(i = 0; i < length; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].price > promedioImporteTotal)
		{
			contador++;
		}
	}

	return contador;
}

//	================================================================================================================
//	> FUNCION SORT PASSENGER POR CODIGO
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno;
	int i;
	int j;
	Passenger listaAuxiliar;

	retorno = -1;

	// ORDENADOS POR CODIGO DE VUELO Y ESTADOS DE VUELOS "ACTIVO"
	if(list != NULL && len > 0 && len <= CANTIDAD_MAXIMA_PASAJEROS && (order == UP || order == DOWN))
	{
		for (i = 0; i < len; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(order == UP)
					{
						if(strcmp(list[i].flycode, list[j].flycode) > 0 || (strcmp(list[i].flycode, list[j].flycode) == 0 && list[i].statusFlight < list[j].statusFlight))
						{
							listaAuxiliar = list[i];
							list[i] = list[j];
							list[j] = listaAuxiliar;
						}
					}
					else
					{
						if(strcmp(list[i].flycode, list[j].flycode) < 0 || (strcmp(list[i].flycode, list[j].flycode) == 0 && list[i].statusFlight < list[j].statusFlight))
						{
							listaAuxiliar = list[i];
							list[i] = list[j];
							list[j] = listaAuxiliar;
						}
					}
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
