/// FUNCIONES ESPECIFICAS DEL TP N�1
///
///	@author Heredia Facundo
/// @date Abril 9 del 2022

//	> BIBLIOTECAS NECESARIAS
#include <stdio.h>
#include "calculos.h"

//---------------------------------------------------------------------------------------
//	> FUNCION DE FORZAR CARGA
/// @brief Hardcodea los datos del punto 5 para ser calculados por las distintas funciones y ser mostrados
///
/// @param kilometros		-> Se estandarizan 7090 Km para ser mostrados
/// @param precioAerolineas	-> Se estandarizan $ 162965.00 como valor del vuelo y calcular en base a ellos
/// @param precioLatam		-> Se estandarizan $ 159339.00 como valor del vuelo y calcular en base a ellos

void cargaForzada (void)
 {
	//	>> variables de funcion
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	double valorMonedaBtc;

	//	>> inicializacion de variables de funcion
	kilometros = 7090;
	precioAerolineas = 162965;
	precioLatam = 159339;
	valorMonedaBtc = 4606954.55;

	//	>> calculos de funcion
	printf("KMs Ingresados: %.2f Km\n", kilometros);
	printf("\n");
	printf("Precio Aerolineas: $ %.2f\n", precioAerolineas);
	printf("a) Precio con tarjeta de d�bito: $ %.2f\n", calculoDescuentoOInteres (precioAerolineas, 10, 0));
	printf("b) Precio con tarjeta de cr�dito: $ %.2f\n", calculoDescuentoOInteres (precioAerolineas, 25, 1));
	printf("c) Precio pagando con bitcoin: %.8f BTC \n", calculoCambioDeMoneda (precioAerolineas, valorMonedaBtc, 0));
	printf("d) Precio unitario: $ %.2f\n", calculoPrecioUnitario (precioAerolineas, kilometros));
	printf("\n");
	printf("Precio Latam: $ %.2f\n", precioLatam);
	printf("a) Precio con tarjeta de d�bito: $ %.2f\n", calculoDescuentoOInteres (precioLatam, 10, 0));
	printf("b) Precio con tarjeta de cr�dito: $ %.2f\n", calculoDescuentoOInteres (precioLatam, 25, 1));
	printf("c) Precio pagando con bitcoin: %.8f BTC \n", calculoCambioDeMoneda (precioLatam, valorMonedaBtc, 0));
	printf("d) Precio unitario: $ %.2f \n", calculoPrecioUnitario (precioLatam, kilometros));
	printf("\n");
	printf("La diferencia de precio es: $ %.2f \n", calculoDiferenciaDosNumerosFlotantes (precioAerolineas, precioLatam));
	printf("__________________________________________\n");
	printf("\n");
 }
//---------------------------------------------------------------------------------------
//	> FUNCION PARA MOSTRAR MENSAJE QUE EVITA SEGUIR ADELANTE
/// @brief Funcion que emite mensaje si la bandera es verdadera para evitar que el usuario siga adelante y vuelva atras
///
/// @param flag	-> si la vandera pasada como parametro es 1 muestra el mensaje, si no, deja al usuario continuar

void mensajeDatosForzadosIngresados (int flag)
{
	if(flag == 1)
	{
		printf("\n");
		printf("ATENCION! USTED YA HABIA INGRESADO DATOS AUTOMATICOS [5]\n");
		printf("\n");
		printf("Vuelva al menu principal y borrelos para ingresar datos manualmente\n");
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------
