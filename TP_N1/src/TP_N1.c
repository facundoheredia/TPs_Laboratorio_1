/*
==============================================================================================
																					1C - 2022
										TRABAJO PRACTICO N°1
									Programación I – Laboratorio I

								 Tecnicatura Superior en Programación
											  UTN-FRA
AUTORES		MARINA CARDOZO
REVISORES	LAURA CARELLI

ALUMNO		HEREDIA FACUNDO
DIVISION	1F
==============================================================================================
ENUNCIADO
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

ACLARACIONES DEL FUNCIONAMIENTO
El menú se tiene que ver tal cual está descrito en la consigna. Los resultados se tienen que
mostrar con el mismo formato. Se puede realizar un submenú para ingresar los km y los
precios.
Los resultados se tienen que ver con el formato presentado en el menú.
==============================================================================================
*/

//	> BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validaciones.h"
#include "calculos.h"

//----------------------------
//	> INICIO FUNCION PRINCIPAL
//----------------------------
int main(void)
{
	//	> SIEMPRE
	setbuf(stdout,NULL);

	//	> VARAIBLES
	//		>> variables inicio programa
	char respuesta;
	//		>> variables menu principal
	int opcionElegida;
	//		>> variables opcion [1]
	int kilometros;
	int flagKilometrosValidados;
	//		>> variables opcion [2]
	char empresaDeVuelo;
	float precioAerolineas;
	float precioLatam;
	int flagprecioIngresadoAerolineas;
	int flagprecioIngresadoLatam;
	//		>> variables opcion [3]
	float diferenciaDePrecio;
	float precioUnitarioLatam;
	float precioUnitarioAerolineas;
	float precioTarjetaDebitoAerolineas;
	float precioTarjetaDebitoLatam;
	float precioTarjetaCreditoAerolineas;
	float precioTarjetaCreditoLatam;
	float precioEnBtcAerolineas;
	float precioEnBtcLatam;
	char recalcularCostos;
	int flagCostosCalculados;
	//		>> variables opcion [4]
	int flagResultadosMostrados;
	//		>> variables opcion [5]
	int flagCargaForzada;
	//		>> variables opcion circunstancial [7]
	int flagOpcionSieteHabilitada;

	//	> INICIALIZACION DE VARIABLES <>
	//		>> variables opcion [1]
	flagKilometrosValidados = 0;
	//		>> variables opcion [2]
	flagprecioIngresadoAerolineas = 0;
	flagprecioIngresadoLatam = 0;
	//		>> variables opcion [2]
	flagCostosCalculados = 0;
	//		>> variables opcion [4]
	flagResultadosMostrados = 0;
	//		>> variables opcion [5]
	flagCargaForzada = 0;
	//		>> variables opcion circunstancial [7]
	flagOpcionSieteHabilitada = 0;
	//--------------------------------------
	//	> INICIO DEL PROGRAMA - PRESENTACION
	//--------------------------------------
	//		>> Mensaje de inicio
	printf("__________________________________________\n");
	printf("\n");
	printf(" 	  [TRABAJO PRACTICO N%c1]\n", 167);
	printf("\n");
	printf("Alumno: Heredia Facundo\n");
	printf("Divisi%cn: 1 F\n", 162);
	printf("__________________________________________\n");
	printf("\n");
	//		>> Validacion de inicio
	respuesta = validacionOpcionesCharDobles ("BIENVENIDO AL PROGRAMA DE COSTOS DE VUELOS\n", "ERROR! Ingrese una opcion valida", "[I] Iniciar programa", "[S] Salir del programa", 'I', 'S');
	system("cls");
	//-------------------------------
	//	> MENU PRINCIPAL DEL PROGRAMA
	//-------------------------------
	while (respuesta == 'I')
	{
		printf("\n");
		printf("__________________________________________\n");
		printf("\n");
		printf("	     [MEN%c PRINCIPAL]\n", 233);
		printf("__________________________________________\n");
		printf("\n");

		//	>> Opcion 1
		if (flagKilometrosValidados == 1 || flagCostosCalculados == 2)
		{
			if(flagKilometrosValidados == 1)
			{
				printf("[1] KIL%cMETROS DE VUELO INGRESADOS %d KM.\n", 224, kilometros);
				printf("\t> Ingrese [1] para modificarlo\n");
			}
			if(flagCostosCalculados == 2)
			{
				printf("[1] KIL%cMETROS CARGADOS AUTOMATICAMENTE 7090 KM.\n", 224);
			}
		}
		else
		{
			printf("[1] INGRESAR KIL%cMETROS\n", 224);
		}
		printf("\n");
		//	>> Opcion 2
		if (flagprecioIngresadoAerolineas == 1 || flagprecioIngresadoLatam == 1 || flagCostosCalculados == 2)
		{
			if(flagprecioIngresadoAerolineas == 1 && flagprecioIngresadoLatam == 1)
			{
				printf("[2] PRECIO DE VUELOS INGRESADOS SON:\n");
				printf("\t> El precio por Aerolineas es de $ %.2f\n", precioAerolineas);
				printf("\t> El precio por Latam es de $ %.2f\n", precioLatam);
			}
			else
			{
				if(flagprecioIngresadoAerolineas == 1 && flagprecioIngresadoLatam == 0)
				{
					printf("[2] EL PRECIO DEL VUELO CARGADO\n");
					printf("\t> El precio por Aerolineas es de $ %.2f\n", precioAerolineas);
					printf("\t> Falta precio por Latam\n");
				}
				if(flagprecioIngresadoAerolineas == 0 && flagprecioIngresadoLatam == 1)
				{
					printf("[2] PRECIO DEL VUELO CARGADO\n");
					printf("\t> El precio por Latam es de $ %.2f\n", precioLatam);
					printf("\t> Falta precio por Aerolineas\n");
				}
				if(flagCostosCalculados == 2)
				{
					printf("[2] PRECIOS VUELO CARGADOS AUTOMATICAMENTE\n");
					printf("\t> El precio por Aerolineas es de $ 162965\n");
					printf("\t> El precio por Latam es de $ 159339\n");
				}
			}

			printf("\t> Ingrese [2] para modificarlo\n");
		}
		else
		{
			printf("[2] INGRESAR PRECIO DE VUELOS\n");
		}
		printf("\n");
		//	>> Opcion 3
		if(flagCostosCalculados == 1)
		{
			printf("[3] LOS COSTOS YA FUERON CALCULADOS\n");
		}
		else
		{
			printf("[3] CALCULAR TODOS LOS COSTOS\n");
			if (flagCostosCalculados == 2)
			{
				printf("\t> Los costos ya se calcularon con una carga forzada\n");
			}
		}
		printf("\n");
		//	>> Opcion 4
		printf("[4] INFORMAR RESULTADOS\n");
		if (flagResultadosMostrados == 1)
		{
			printf("\t> Volver a mostrar los resultados\n");
		}
		if (flagCostosCalculados == 2)
		{
			printf("\t> Los resultados ya se mostraron con una carga forzada\n");
		}
		printf("\n");
		//	>> Opcion 5
		printf("[5] CARGA FORZADA DE DATOS\n");
		if (flagCostosCalculados == 2)
				{
					printf("\t> Volver a mostrar\n");
				}
		printf("\n");
		//	>> Opcion 6
		printf("[6] SALIR\n");
		printf("__________________________________________\n");
		printf("\n");
		//	>> Opcion 7 (circunstancial)
		if(flagCargaForzada == 1 || flagKilometrosValidados == 1 || flagprecioIngresadoAerolineas == 1 || flagprecioIngresadoLatam == 1)
		{
			printf("[7] BORRAR LOS DATOS INGRESADOS\n");
			printf("__________________________________________\n");
			printf("\n");
			flagOpcionSieteHabilitada = 1;
		}
		//	>> Eleccion de opcion
		printf("Ingrese una opci%cn\n", 162);
		scanf("%d", &opcionElegida);

		//		>> Validacion de opcion elegida

		if(flagOpcionSieteHabilitada == 0)
		{
			opcionElegida = validacionNumeroEnteroEntreRangos (opcionElegida, 1, 6);
		}
		else
		{
			opcionElegida = validacionNumeroEnteroEntreRangos (opcionElegida, 1, 7);
		}
		system("cls");
		//-------------
		//	> SUB MENUS
		//-------------
		switch (opcionElegida)
		{
		//	>> Sub menu Opcion 1
		case 1:
			printf("\n");
			printf("__________________________________________\n");
			printf("\n");
			printf("MP -> [1] INGRESAR KIL%cMETROS\n",224);
			printf("__________________________________________\n");
			printf("\n");

			//		>> Validacion de kilometros
			if(flagCargaForzada == 1)
			{
				mensajeDatosForzadosIngresados (flagCargaForzada);
				system ("pause");
			}
			else
			{
			kilometros = validacionNumeroEnteroPositivo ("Ingrese los kilometros del vuelo", "ERROR! Ingrese un numero mayor a 0");
			flagKilometrosValidados = 1;
			}
			system("cls");
			break;
		//	>> Sub menu Opcion 2
		case 2:
			printf("\n");
			printf("__________________________________________\n");
			printf("\n");
			printf("MP -> [2] INGRESAR PRECIO DE VUELOS\n");
			printf("__________________________________________\n");
			printf("\n");

			//	>> Validacion de opcion elegida
			if(flagCargaForzada == 1)
			{
				mensajeDatosForzadosIngresados (flagCargaForzada);
				system ("pause");
				system("cls");
			}
			else
			{
				empresaDeVuelo = validacionOpcionesCharDobles ("Ingrese de que empresa es el vuelo:", "ERROR! Ingrese una opcion valida", "[Y] AEROLINEAS", "[Z] LATAM", 'Y', 'Z');
				printf("\n");
				system("cls");

				//	>>> Ingreso de empresa de vuelo
				switch (empresaDeVuelo)
				{
					case 'Y':
						printf("\n");
						printf("__________________________________________\n");
						printf("\n");
						printf("MP -> [2] -> [Y] AEROLINEAS\n");
						printf("__________________________________________\n");
						printf("\n");
						precioAerolineas = validacionNumeroFlotantePositivo ("Ingrese el valor del vuelo de AEROLINEAS:", "ERROR! El valor no puede ser menor a $0:");
						flagprecioIngresadoAerolineas = 1;
						system("cls");
						break;
					case 'Z':
						printf("\n");
						printf("__________________________________________\n");
						printf("\n");
						printf("MP -> [2] -> [Z] LATAM\n");
						printf("__________________________________________\n");
						printf("\n");
						precioLatam = validacionNumeroFlotantePositivo ("Ingrese el valor del vuelo de LATAM:", "ERROR! El valor no puede ser menor a $0:");
						flagprecioIngresadoLatam = 1;
						system("cls");
						break;
					case 'S':
						break;
				}
			}
			break;
		//	>> Sub menu Opcion 3
		case 3:
			printf("\n");
			printf("__________________________________________\n");
			printf("\n");
			printf("MP -> [3] CALCULO DE COSTOS\n");
			printf("__________________________________________\n");
			printf("\n");

			if(flagCargaForzada == 1)
			{
				mensajeDatosForzadosIngresados (flagCargaForzada);
			}
			else
			{
				if (flagKilometrosValidados == 1 && flagprecioIngresadoAerolineas == 1 && flagprecioIngresadoLatam == 1)
				{
					precioTarjetaDebitoAerolineas = calculoDescuentoOInteres (precioAerolineas, 10, 0);
					precioTarjetaDebitoLatam = calculoDescuentoOInteres (precioLatam, 10, 0);
					precioTarjetaCreditoAerolineas = calculoDescuentoOInteres (precioAerolineas, 25, 1);
					precioTarjetaCreditoLatam = calculoDescuentoOInteres (precioLatam, 25, 1);
					precioEnBtcAerolineas = calculoCambioDeMoneda (precioAerolineas, 4606954.55, 0);
					precioEnBtcLatam = calculoCambioDeMoneda (precioLatam, 4606954.55, 0);
					precioUnitarioAerolineas = calculoPrecioUnitario (precioAerolineas, kilometros);
					precioUnitarioLatam = calculoPrecioUnitario (precioLatam, kilometros);
					diferenciaDePrecio = calculoDiferenciaDosNumerosFlotantes (precioAerolineas, precioLatam);

					printf("Los valores ingresados se cargaron con exito.\n");
					printf("Vuelva al menu principal y vealos en la opcion [4]\n");

					flagCostosCalculados = 1;
				}
				else
				{
					printf("ATENCION! NO SE PUEDE CALCULAR LOS COSTOS\n");
					printf("Vuelva al menu principal y carguelos manualmente.\n");
					printf("[1] y [2] o [5] del menu principal.\n");
				}
			}

			printf("\n");
			system ("pause");
			system("cls");
			break;
		//	>> Sub menu Opcion 4
		case 4:
			printf("\n");
			printf("__________________________________________\n");
			printf("\n");
			printf("MP -> [4] INFORME DE RESULTADOS\n");
			printf("__________________________________________\n");
			printf("\n");
			if(flagCargaForzada == 1)
			{
				mensajeDatosForzadosIngresados (flagCargaForzada);
			}
			else
			{
				if(flagKilometrosValidados == 1 && flagprecioIngresadoAerolineas == 1 && flagprecioIngresadoLatam == 1 && flagCostosCalculados == 1)	//VER POR QUE A VECES TIRA LAS DIRECCIONES DE MEMORIA
				{
					printf("KMs Ingresados: %d Km\n", kilometros);
					printf("\n");
					printf("Precio Aerolineas: $ %.2f\n", precioAerolineas);
					printf("a) Precio con tarjeta de débito: $ %.2f\n", precioTarjetaDebitoAerolineas);
					printf("b) Precio con tarjeta de crédito: $ %.2f\n", precioTarjetaCreditoAerolineas);
					printf("c) Precio pagando con bitcoin: %.8f BTC \n", precioEnBtcAerolineas);
					printf("d) Precio unitario: $ %.2f\n", precioUnitarioAerolineas);
					printf("\n");
					printf("Precio Latam: $ %.2f\n", precioLatam);
					printf("a) Precio con tarjeta de débito: $ %.2f\n", precioTarjetaDebitoLatam);
					printf("b) Precio con tarjeta de crédito: $ %.2f\n", precioTarjetaCreditoLatam);
					printf("c) Precio pagando con bitcoin: %.8f BTC \n", precioEnBtcLatam);
					printf("d) Precio unitario: $ %.2f \n", precioUnitarioLatam);
					printf("\n");
					printf("La diferencia de precio es: $ %.2f \n", diferenciaDePrecio);
					printf("__________________________________________\n");
					printf("\n");
					flagResultadosMostrados = 1;
				}
				else
				{
					printf("ATENCION!\n");
					printf("NO SE CALCULARON LOS DATOS PARA REALIZAR EL INFORME\n");
					printf("\n");
					printf("Vuelva al menu principal y carguelos en la opcion [3]\n");
					printf("\n");
				}
			}
			system ("pause");
			system("cls");
			break;
		case 5:
			printf("\n");
			printf("__________________________________________\n");
			printf("\n");
			printf("MP -> [5] CARGA FORZADA DE DATOS\n");
			printf("__________________________________________\n");
			printf("\n");
			if(flagprecioIngresadoAerolineas == 1 || flagprecioIngresadoLatam == 1 || flagKilometrosValidados == 1)
			{
				printf("ATENCION!\n");
				printf("YA SE CARGARON DATOS MANUALMENTE\n");
				printf("\n");
				printf("Vuelva al menu principal y borrelos de ser necesario\n");
				printf("\n");
			}
			else
			{
				cargaForzada ();
				flagCargaForzada = 1;
				flagCostosCalculados = 2;
			}
			system ("pause");
			system("cls");
			break;
		case 6:
			respuesta = 'S';
			break;

		case 7:
				if(flagOpcionSieteHabilitada == 1)
				{
					recalcularCostos = validacionOpcionesCharDobles ("Si quiere borrar los datos ingrese", "ERROR! Ingrese una opcion valida", "[I] Borrar datos automaticos", "[S] Salir", 'I', 'S');
					if (recalcularCostos == 'I')
					{
						flagCargaForzada = 0;
						flagCostosCalculados = 0;
						flagKilometrosValidados = 0;
						flagprecioIngresadoAerolineas = 0;
						flagprecioIngresadoLatam = 0;
						flagResultadosMostrados = 0;
						flagOpcionSieteHabilitada = 0;
					}
				}
				if(flagOpcionSieteHabilitada == 0)
				{
					opcionElegida = validacionNumeroEnteroEntreRangos (opcionElegida, 1, 7);
				}
				system("cls");
			break;
		}
	}
	//---------------------------
	//	> MENSAJE DE FINALIZACION
	//---------------------------
	if(respuesta == 'S')
	{
		printf("\n");
		printf(" __________________________________________\n");
		printf("\n");
		printf(" 	Muchas Gracias, vuelva pronto\n");
		printf("\n");
		printf(" 	  < PROGRAMA FINALIZADO >\n");
		printf(" __________________________________________\n");
		printf("\n");
		system ("pause");
	}
	//------------------------
	//	> FINALIZO EL PROGRAMA
	//------------------------
	return EXIT_SUCCESS;
}






