/*
 *	calculos.c
 *
 *	Heredia Facundo
 */

//	> BIBLIOTECAS NECESARIAS
#include <stdio.h>

//---------------------------------------------------------------------------------------
//	> FUNCION DE CALCULO DE DESCUENTO O INTERES

// Se pide el precio total, el porcentaje que se le descuenta o suma,
// y un auxiliar que dira si es un descuento o interes para calcular
// y retorna el precio final con el descuento o interes incorporado

// precio		-> es el precio para calcular
// porcentaje	-> es el valor que se usara para sacar el porcentaje
// auxiliar		-> es la variable con la que le digo a la funcion si debe hacer un descuento (1) o interes
// precioFinal	-> es el valor final con descuento o interes

float calculoDescuentoOInteres (float precio, int porcentaje, int auxiliar)
{
	//	>> variables de funcion
	float precioFinal;
	float precioPorcentaje;
	//	>> calculo de funcion
	precioPorcentaje = precio * porcentaje / 100;
	//	>> verificacion datos ingresados y calculo de la funcion
	if (auxiliar == 1)
	{
		precioFinal = precio + precioPorcentaje;
	}
	else
	{
		precioFinal = precio - precioPorcentaje;
	}
	//	>> retorno de funcion
	return precioFinal;
}
//---------------------------------------------------------------------------------------
//	> FUNCION DIFERENCIA DE DOS NUMEROS FLOTANTES

// Se necesitan dos numeros flotantes, y se devuelve la diferencia resultante de los dos
// se comprueba cual de los dos numeros es mayor para que el resultado sea positivo
// y asi tener un resultado positivo siempre para saber la diferencia entre los dos numeros

// numeroUno	-> es el primer numero para calcular la diferencia
// numeroDos	-> es el segundo numero para calcular la diferencia
// diferencia	-> es el resultado de la diferencia entre los dos numeros

float calculoDiferenciaDosNumerosFlotantes (float numeroUno, float numeroDos)
{
	//	>> validacion de funcion
	float diferencia;
	//	>> verificacion datos ingresados
	if (numeroUno > numeroDos)
	{
		diferencia = numeroUno - numeroDos;
	}
	else
	{
		diferencia = numeroDos - numeroUno;
	}
	//	>> retorno de funcion
	return diferencia;
}
//---------------------------------------------------------------------------------------
//	> FUNCION DE CAMBIO DE MONEDA

// Se necesitan el valor de la moneda que se quiere cambiar, el valor del tipo de cambio a la otra moneda
// o el valor de la misma moneda equibalente a una unidad de la moneda a cambiar
// Si tipo de cambio tiene un valor se calcula por el tipo de cambio, si no llenar el otro valor para
// calcular el valor final

// monedaUno					-> es el valor de la moneda actual que yo quiero cambiar 	(ARG A BTC)
// tipoDeCambioMonedaDos		-> es el valor de la moneda dos respecto de la moneda uno	(BTC $1 = ARG $4606954.55 -> tipo de cambio)
// valorMonedaUnoEnMonedaDos	-> es el valor de la moneda actual respecto a la moneda dos (ARG $4606954.55 = BTC $1 -> ARG por ARG)

float calculoCambioDeMoneda (float monedaUno, float tipoDeCambioMonedaDos, float valorMonedaUnoEnMonedaDos)
{
	//	>> validacion de funcion
	float monedaUnoConvertidaEnMonedaDos;
	//	>> verificacion datos ingresados
	if(tipoDeCambioMonedaDos != 0)
	{
		monedaUnoConvertidaEnMonedaDos = monedaUno / tipoDeCambioMonedaDos;
	}
	else
	{
		monedaUnoConvertidaEnMonedaDos = monedaUno * valorMonedaUnoEnMonedaDos;
	}
	//	>> retorno de funcion
	return monedaUnoConvertidaEnMonedaDos;
}
//---------------------------------------------------------------------------------------
//	> FUNCION DE PRECIOS UNITARIOS

// Se necesitan el valor total, y la cantidad de unidades
// Devuelve el precio de cada unidad

// dividendo	-> es el precio total
// divisor		-> es la cantidad de unidades
// resultado	-> es el valor de cada unidad

float calculoPrecioUnitario (float dividendo, int divisor)
{
	//	>> validacion de funcion
	float resultado;
	//	>> calculo de funcion
	resultado = dividendo / divisor;
	//	>> retorno de funcion
	return resultado;
}
//---------------------------------------------------------------------------------------
//	> FUNCION DE FORZAR CARGA
void cargaForzada (void)
 {
	//	>> variables de funcion
	int kilometros;
	float precioAerolineas;
	float precioLatam;
	//	>> inicializacion de variables de funcion
	kilometros = 7090;
	precioAerolineas = 162965;
	precioLatam = 159339;
	//	>> calculos de funcion
	printf("KMs Ingresados: %d Km\n", kilometros);
	printf("\n");
	printf("Precio Aerolineas: $ %.2f\n", precioAerolineas);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", calculoDescuentoOInteres (precioAerolineas, 10, 0));
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", calculoDescuentoOInteres (precioAerolineas, 25, 1));
	printf("c) Precio pagando con bitcoin: %.8f BTC \n", calculoCambioDeMoneda (precioAerolineas, 4606954.55, 0));
	printf("d) Precio unitario: $ %.2f\n", calculoPrecioUnitario (precioAerolineas, kilometros));
	printf("\n");
	printf("Precio Latam: $ %.2f\n", precioLatam);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", calculoDescuentoOInteres (precioLatam, 10, 0));
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", calculoDescuentoOInteres (precioLatam, 25, 1));
	printf("c) Precio pagando con bitcoin: %.8f BTC \n", calculoCambioDeMoneda (precioLatam, 4606954.55, 0));
	printf("d) Precio unitario: $ %.2f \n", calculoPrecioUnitario (precioLatam, kilometros));
	printf("\n");
	printf("La diferencia de precio es: $ %.2f \n", calculoDiferenciaDosNumerosFlotantes (precioAerolineas, precioLatam));
	printf("__________________________________________\n");
	printf("\n");
 }
//---------------------------------------------------------------------------------------
