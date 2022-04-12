/// FUNCIONES DE CALCULOS
///
///	@author Heredia Facundo
/// @date Abril 9 del 2022

//	> BIBLIOTECAS NECESARIAS
#include <stdio.h>

//---------------------------------------------------------------------------------------
//	> FUNCION DE CALCULO DE DESCUENTO O INTERES

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
