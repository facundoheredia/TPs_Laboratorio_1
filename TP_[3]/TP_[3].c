/*
==============================================================================================
																					1C - 2022
										TRABAJO PRACTICO N°3
									Programación I – Laboratorio I

								 Tecnicatura Superior en Programación
											  UTN-FRA
AUTORES		MARINA CARDOZO
REVISORES	LAURA CARELLI

ALUMNO		HEREDIA FACUNDO
DIVISION	1F
==============================================================================================
*/

//					POR FAVOR, EJECUTAR DESDE EL .EXE DE LA CARPETA DEBUG
//					PARA SU CORRECTAR VISUALIZACION
//					MUCHAS GRACIAS

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
//	>> BIBLIOTECAS DADAS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
//	>> BIBLIOTECAS AGREGADAS
#include "hud_menu.h"
#include "mensajes.h"

//	========
//	> DEFINE
//	========
#define ARCHIVO_TEXTO "..\\data.csv" // <- Para correrlo desde el .exe se necesita esta ruta
#define ARCHIVO_BINARIO "..\\data.bin"


//	==========================
//	> INICIO FUNCION PRINCIPAL
//	==========================
int main()
{
	//	================
	setbuf(stdout,NULL);

	//	===========
	//	> VARIABLES
	//	===========
		//	>> Nueva lista cuando inicia el programa
    LinkedList* listaPasajeros = ll_newLinkedList();
		//	>> variables [ presentacion ]
    char respuesta;
 		//	>> variables [ menu principal ]
    int opcionMenuPrincipal;
    	//	>> variables [ opcion 1 ]
    int cantidadPasajeros;
    int flagArchivoTxt;
    	//	>> variables [ opcion 2 ]
    int flagArchivoBinario;
    //	>> variables [ opcion 10 ]
    int flagModificacionRealizada;

    //	> INICIALIZACION DE VARIABLES
    cantidadPasajeros = 0;
		//	>> variables [ opcion 1 ]
    flagArchivoTxt = 0;
    	//	>> variables [ opcion 2 ]
    flagArchivoBinario = 0;
    	//	>> variables [ opcion 10 ]
    flagModificacionRealizada = 0;

	//	====================================
	//	> INICIO DEL PROGRAMA - PRESENTACION
	//	====================================
	respuesta = iniciarPrograma();

	if(respuesta == 'S')
	{
		//	=============================
		//	> MENU PRINCIPAL DEL PROGRAMA
		//	=============================
		do
		{
			switch(opcionMenuPrincipal = menuPricipal ())
			{
				case 1:	// [ CARGAR LOS DATOS DE LOS PASAJEROS DESDE ARCHIVO data.csv (modo texto) ]
					if(flagArchivoTxt == 0 && flagArchivoBinario == 0)
					{
						if(controller_loadFromText(ARCHIVO_TEXTO,listaPasajeros))
						{
							cantidadPasajeros = ll_len(listaPasajeros);
							mostrarMensajeConEntero("SE HAN CARGADO CON EXITO A LOS PASAJEROS DESDE EL ARCHIVO DE TEXTO CON TOTAL DE: ", cantidadPasajeros);
							flagArchivoTxt = 1;
						}
						else
						{
							mostrarMensajeParaContinuar("[ ERROR ] -> NO SE HAN PODIDO CARGAR LOS PASAJEROS DESDE EL ARCHIVO DE TEXTO");
						}
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> YA SE HA CARGADO UN ARCHIVO");
					}
					system("cls");
					break;
				case 2:	// [ CARGAR LOS DATOS DE LOS PASAJEROS DESDE ARCHIVO data.csv (modo binario) ]
					if(flagArchivoBinario == 0 && flagArchivoTxt == 0)
					{
						if(controller_loadFromBinary(ARCHIVO_BINARIO,listaPasajeros) == 1)
						{
							cantidadPasajeros = ll_len(listaPasajeros);
							mostrarMensajeConEntero("SE HAN CARGADO CON EXITO A LOS PASAJEROS DESDE EL ARCHIVO BINARIO CON TOTAL DE: ", cantidadPasajeros);
							flagArchivoBinario = 1;
						}
						else
						{
							if(controller_loadFromBinary(ARCHIVO_BINARIO,listaPasajeros) == -2)
							{
								mostrarMensajeParaContinuar("[ ERROR ] -> NO EXISTE EL ARCHIVO BINARIO");
							}
							else
							{
								mostrarMensajeParaContinuar("[ ERROR ] -> NO SE HAN PODIDO CARGAR LOS PASAJEROS DESDE EL ARCHIVO BINARIO");
							}
						}
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> YA SE HA CARGADO UN ARCHIVO");
					}
					system("cls");
					break;
				case 3:	// [ ALTA DE PASAJERO ]
					if(cantidadPasajeros != 0)
					{
						if(controller_addPassenger(listaPasajeros))
						{
							mostrarMensajeParaContinuar("SE HA DADO DE ALTA A UN PASAJERO CORRECTAMENTE");
							flagModificacionRealizada++;
						}
						else
						{
							mostrarMensajeParaContinuar("[ ERROR ] -> NO SE HA PODIDO DAR DE ALTA AL PASAJERO, REINTENTE");
						}
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> NO SE CARGO NINGUNA LISTA, CARGUE UN ARCHIVO");
					}
					system("cls");
					break;
				case 4:	// [ MODIFICAR DATOS DE PASAJERO ]
					if(cantidadPasajeros != 0)
					{
						if(!controller_editPassenger(listaPasajeros))
						{
							mostrarMensajeParaContinuar("SE HA MODIFICADO A UN PASAJERO CORRECTAMENTE");
							flagModificacionRealizada++;
						}
						else
						{
							mostrarMensajeParaContinuar("[ ERROR ] -> NO SE HA PODIDO MODIFICAR AL PASAJERO, REINTENTE");
						}
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> NO HAY PASAJEROS PARA EDITAR, CARGUE UN ARCHIVO");
					}
					system("cls");
					break;
				case 5:	// [ BAJA DE PASAJERO ]
					if(cantidadPasajeros != 0)
					{
						if(!controller_removePassenger(listaPasajeros))
						{
							cantidadPasajeros = ll_len(listaPasajeros);
							flagModificacionRealizada++;
							mostrarMensajeParaContinuar("SE HA DADO DE BAJA A UN PASAJERO CORRECTAMENTE");
						}
						else
						{
							mostrarMensajeParaContinuar("[ ERROR ] -> NO SE HA PODIDO BORRAR AL PASAJERO, REINTENTE");
						}
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> NO HAY PASAJEROS PARA REMOVER, CARGUE UN ARCHIVO");
					}
					system("cls");
					break;
				case 6:	// [ LISTAR PASAJEROS ]
					if(cantidadPasajeros != 0)
					{
						controller_ListPassenger(listaPasajeros);
						mostrarMensajeParaContinuar("ESTA ES LA LISTA DE PASAJEROS CARGADOS");
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> NO HAY PASAJEROS PARA LISTAR, CARGUE UN ARCHIVO");
					}
					system("cls");
					break;
				case 7:	// [ ORDENAR PASAJEROS ]
					if(cantidadPasajeros != 0)
					{
						controller_sortPassenger(listaPasajeros);
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> NO HAY PASAJEROS PARA ORDENAR, CARGUE UN ARCHIVO");
					}
					system("cls");
					break;
				case 8:	// [ GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.csv (modo texto) ]
					if(flagArchivoBinario != 0 || flagArchivoTxt != 0)
					{
						if(flagModificacionRealizada != 0)
						{
							mostrarMensajeConEntero("MODIFICACIONES DETECTADAS: ", flagModificacionRealizada);
							if(controller_saveAsText(ARCHIVO_TEXTO, listaPasajeros) == 0)
							{
								mostrarMensajeParaContinuar("SE HA GUARDADO CON EXITO EL ARCHIVO DE TEXTO");
								flagModificacionRealizada = 0;
							}
							else
							{
								mostrarMensajeParaContinuar("[ ERROR ] -> NO SE HA GUARDADO EL ARCHIVO DE TEXTO, REINTENTE");
							}
						}
						else
						{
							mostrarMensajeParaContinuar("[ ERROR ] -> NO SE PUEDE GUARDAR SI NO SE REALIZO NINGUN CAMBIO EN EL ARCHIVO O SI YA FUE GUARDADO");
						}
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> NO SE PUEDE GUARDAR SI NO SE CARGO UN ARCHIVO PRIMERO, CARGUE UN ARCHIVO");
					}
					system("cls");
					break;
				case 9:	// [ GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.csv (modo binario) ]
					if(flagArchivoTxt != 0 || cantidadPasajeros != 0)
					{
						mostrarMensajeConEntero("MODIFICACIONES DETECTADAS: ", flagModificacionRealizada);
						if(controller_saveAsBinary(ARCHIVO_BINARIO, listaPasajeros) == 0)
						{
							mostrarMensajeParaContinuar("SE HA GUARDADO CON EXITO EL ARCHIVO DE BINARIO");
							flagModificacionRealizada = 0;
						}
						else
						{
							mostrarMensajeParaContinuar("[ ERROR ] -> NO SE HA GUARDADO EL ARCHIVO BINARIO, REINTENTE");
						}
					}
					else
					{
						mostrarMensajeParaContinuar("[ ERROR ] -> NO SE PUEDE GUARDAR SI NO SE CARGO UN ARCHIVO PRIMERO, CARGUE UN ARCHIVO");
					}
					system("cls");
					break;
				case 10:// [ SALIR ]
					if((flagArchivoTxt != 0 || cantidadPasajeros != 0) && flagModificacionRealizada != 0)
					{
						mostrarMensaje("SE HAN REALIZADO CAMBIOS A LA LISTA");
						mostrarMensajeConEntero("MODIFICACIONES DETECTADAS: ", flagModificacionRealizada);
						if(entrada_respuestaUsuario("¿REALMENTE QUIERE SALIR? [S] Si [N] No\n") == 'S')
						{
							respuesta = 'N';
						}
						else
						{
							opcionMenuPrincipal = 0;
						}
					}
					break;
			}
		}while(opcionMenuPrincipal != 10);
	}

	//	======================
	//	> FINALIZO EL PROGRAMA
	//	======================
	mensajeProgramaFinalizado ();

    return EXIT_SUCCESS;
}
