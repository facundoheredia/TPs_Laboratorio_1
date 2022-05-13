/*
==============================================================================================
																					1C - 2022
										TRABAJO PRACTICO N°2
									Programación I – Laboratorio I

								 Tecnicatura Superior en Programación
											  UTN-FRA
AUTORES		MARINA CARDOZO
REVISORES	LAURA CARELLI

ALUMNO		HEREDIA FACUNDO
DIVISION	1F
==============================================================================================
*/

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "inputs.h"
#include "ArrayPassenger.h"
#include "hud_menu.h"
#include "mensajes.h"

//	==========================
//	> INICIO FUNCION PRINCIPAL
//	==========================
int main(void)
{
	//	==========
	//	> SIEMPRE
	//	==========
	setbuf(stdout,NULL);

	//	===========
	//	> VARIABLES
	//	===========
	//		>> variables [ inicio ]
	int inicioPasajeros;
	//		>> variables [ presentacion ]
	char respuesta;
	//		>> variables [ menu principal ]
	int opcionMenuValida;
	int cantidadAltas;
	Passenger listaPasajeros[CANTIDAD_MAXIMA_PASAJEROS];
	EstadosDeVuelo listaEstadosDeVuelos[LONGITUD_ESTADO_VUELO] = {{0, "A TIEMPO"},{1,"ABORDANDO"},{2,"ARRIBO"},{3,"REPROGRAMADO"},{4,"CANCELADO"}};
	TiposPasajeros listaDeTipoPasajeros[LONGITUD_DE_TIPO_PASAJERO] = {{0, "ECONOMICO"},{1, "1ra CLASE"},{2, "EJECUTIVO"}};
	//		>> variables [opcion 5]
	int banderaHardcodeados;

	//	=============================
	//	> INICIALIZACION DE VARIABLES
	//	=============================
	//		>> variables opcion [1]
	cantidadAltas = 0;
	//		>> variables [opcion 5]
	banderaHardcodeados = 0;

	//	====================================
	//	> INICIO DEL PROGRAMA - PRESENTACION
	//	====================================
	respuesta = iniciarPrograma();

	if(respuesta == 'S')
	{
		inicioPasajeros = initPassengers(listaPasajeros, CANTIDAD_MAXIMA_PASAJEROS);

		if(inicioPasajeros == 0)
		{
			do
			{
				//	=============================
				//	> MENU PRINCIPAL DEL PROGRAMA
				//	=============================
				switch (opcionMenuValida = menuPricipal ())
				{
					case 1:	//	[ OPCION ALTAS DE PASAJEROS ]
						encabezadoAltas ();
						if(Passenger_Alta (listaPasajeros, CANTIDAD_MAXIMA_PASAJEROS, listaEstadosDeVuelos, LONGITUD_ESTADO_VUELO, listaDeTipoPasajeros, LONGITUD_DE_TIPO_PASAJERO) == 0)
						{
							mostrarMensaje (MENSAJE_PASAJERO_ALTA_EXITOSA);
							system("pause");
							system("cls");
							cantidadAltas++;
						}
						else
						{
							mostrarMensaje (MENSAJE_PASAJERO_ALTA_ERROR);
						}
						break;
					case 2: //	[ OPCION MODIFICACIONES DE PASAJEROS ]
						if (cantidadAltas != 0)
						{
							if(Passenger_Modificar(listaPasajeros, CANTIDAD_MAXIMA_PASAJEROS, listaEstadosDeVuelos, LONGITUD_ESTADO_VUELO, listaDeTipoPasajeros, LONGITUD_DE_TIPO_PASAJERO) == 0)
							{
								mostrarMensajeParaContinuar("SE PUDO HACER LA MODIFICACION CON EXITO"); // SE MODIFICO CON EXITO
							}
							else
							{
								mostrarMensajeParaContinuar("NO SE PUDO HACER UNA MODIFICACION"); // NO SE PUDO MODIFICAR
							}
						}
						else
						{
							mostrarMensajeParaContinuar (MENSAJE_NO_HAY_ALTAS);
						}
						break;
					case 3: //	[ OPCION BAJAS DE PASAJEROS ]
						encabezadoBajas();
						if (cantidadAltas != 0)
						{
							if(Passenger_Baja(listaPasajeros, CANTIDAD_MAXIMA_PASAJEROS, listaEstadosDeVuelos, LONGITUD_ESTADO_VUELO, listaDeTipoPasajeros, LONGITUD_DE_TIPO_PASAJERO) == 0)
							{
								printPassenger (listaPasajeros, CANTIDAD_MAXIMA_PASAJEROS, listaEstadosDeVuelos, LONGITUD_ESTADO_VUELO, listaDeTipoPasajeros, LONGITUD_DE_TIPO_PASAJERO);
								//SI CONFIRMA BAJA SE RESTAN ALTAS
								cantidadAltas--;
								mostrarMensajeParaContinuar(MENSAJE_PASAJERO_BAJA_EXITOSA);
								system("cls");
							}
						}
						else
						{
							mostrarMensajeParaContinuar(MENSAJE_NO_HAY_ALTAS);
						}
						break;
					case 4: //	[ OPCION INFORMES DE PASAJEROS ]

						if (cantidadAltas != 0)
						{
							Passenger_Listado(listaPasajeros, CANTIDAD_MAXIMA_PASAJEROS, UP, cantidadAltas, listaEstadosDeVuelos, LONGITUD_ESTADO_VUELO, listaDeTipoPasajeros, LONGITUD_DE_TIPO_PASAJERO);
						}
						else
						{
							mostrarMensajeParaContinuar(MENSAJE_NO_HAY_ALTAS);
						}
						break;
					case 5: //	[ OPCION CARGA FORZADA DE PASAJEROS ]
						if( banderaHardcodeados == 0)
						{
							ePassenger_hardcodeados(listaPasajeros, CANTIDAD_MAXIMA_PASAJEROS);
							cantidadAltas += 10;
							banderaHardcodeados = 1;
							mostrarMensajeParaContinuar("SE HAN HARDCODEADOS DATOS DE PASAJEROS");
						}
						else
						{
							mostrarMensaje("YA SE HAN HARDCODEADOS PASAJEROS");
						}
						break;
					case 6: //	SALIDA DEL PROGRAMA
						respuesta = 'S';
						break;
				}
			}while(opcionMenuValida != 6);
		}
		else
		{
			mostrarMensajeParaContinuar(MENSAJE_ERROR_INICIALIZACION_PASAJEROS);
		}

	}

	//	======================
	//	> FINALIZO EL PROGRAMA
	//	======================
	mensajeProgramaFinalizado ();

	return EXIT_SUCCESS;
}

//HOLA
