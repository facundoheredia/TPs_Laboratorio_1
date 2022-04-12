/// FUNCIONES DE CALCULOS
///
///	@author Heredia Facundo
/// @date Abril 9 del 2022

#ifndef CALCULOS_H_
#define CALCULOS_H_

//	> FUNCION DE CALCULO DE DESCUENTO O INTERES
/// @brief Calcula un descuento o Interes (segun el parametro auxiliar pasado) con el precio pasado.
///
/// @param precio 		-> es el precio para calcular
/// @param porcentaje	-> es el valor que se usara para sacar el porcentaje
/// @param auxiliar		-> es la variable con la que le digo a la funcion si debe hacer un descuento (1) o interes
/// @return precioFinal	-> es el valor final con descuento o interes

float calculoDescuentoOInteres (float precio, int porcentaje, int auxiliar);

//	> FUNCION DIFERENCIA DE DOS NUMEROS FLOTANTES
/// @brief Calcula haciendo una resta del numero mayor con el menor, comprobando cual de los dos es mayor antes de hacer la resta.
///
/// @param numeroUno	-> es el primer numero para calcular la diferencia
/// @param numeroDos	-> es el segundo numero para calcular la diferencia
/// @return diferencia	-> es el resultado de la diferencia entre los dos numeros

float calculoDiferenciaDosNumerosFlotantes (float numeroUno, float numeroDos);

//	> FUNCION DE CAMBIO DE MONEDA
/// @brief Hace al cambio de moneda segun que parametro se pase, si el tipo de cambio o el valor de la moneda con respeco a la otra
///
/// @param monedaUno						-> es el valor de la moneda actual que yo quiero cambiar 	(ARG A BTC)
/// @param tipoDeCambioMonedaDos			-> es el valor de la moneda dos respecto de la moneda uno	(BTC $1 = ARG $4606954.55 -> tipo de cambio)
/// @param valorMonedaUnoEnMonedaDos		-> es el valor de la moneda actual respecto a la moneda dos (ARG $4606954.55 = BTC $1 -> ARG por ARG)
/// @return monedaUnoConvertidaEnMonedaDos	-> devuelve el valor de la monedaUno cambiado a la mnnedaDos

float calculoCambioDeMoneda (float monedaUno, float tipoDeCambioMonedaDos, float valorMonedaUnoEnMonedaDos);

//	> FUNCION DE PRECIOS UNITARIOS
/// @brief Divide el precio total pasado por la cantidad de unidades pasadas
///
/// @param dividendo	-> es el precio total
/// @param divisor		-> es la cantidad de unidades
/// @return resultado	> es el valor de cada unidad

float calculoPrecioUnitario (float dividendo, int divisor);

#endif /* CALCULOS_H_ */
