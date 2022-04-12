/*
 *	validaciones.h
 *
 *  Heredia Facundo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

//	> FUNCION VALIDACION ENTERO DENTRO DE MINIMO Y MAXIMO
/// @brief Se pide un numero como parametro y se lo valida entre los limites que se pasen como parametro
///
/// @param numero			-> numero que se pasa a ser validado
/// @param limiteInferior	-> es el menor numero del rango que puede ingresar
/// @param limiteSuperior	-> es el mayor numero del rango que puede ingresar
/// @return numero			-> devuelve el numero ya validado

int validacionNumeroEnteroEntreRangos (int numero, int limiteInferior, int limiteSuperior);

//	> VALIDACION NUMERO ENTERO POSITIVO
/// @brief Pide y valida un numero entero que sea positivo
///
/// @param mensaje		-> es el mensaje que muestro al usuario la primera vez para que ingrese el numero
/// @param mensajeError	-> es el mensaje que se mostrara siempre que el valor ingresado sea erroneo
/// @return numero		-> es donde se guarda el valor ingresado por el usuario y se devuelve

int validacionNumeroEnteroPositivo (char mensaje[], char mensajeError[]);

//	> VALIDACION NUMERO FLOTANTE POSITIVO
/// @brief Pide y valida un numero flotante que sea positivo
///
/// @param mensaje		-> es el mensaje que muestro al usuario la primera vez para que ingrese el numero
/// @param mensajeError	-> es el mensaje que se mostrara siempre que el valor ingresado sea erroneo
/// @return numero		-> es donde se guarda el valor ingresado por el usuario

float validacionNumeroFlotantePositivo (char mensaje[], char mensajeError[]);

//	> FUNCION VALIDACION DE 2 OPCIONES CHAR
/// @brief Recibe mensajes a mostrar y otorga dos opciones entre las cuales elegir y la valida
///
/// @param mensaje			-> es el mensaje que muestro al usuario la primera vez para que ingrese una letra
/// @param mensajeError		-> es el mensaje que se mostrara siempre que el valor ingresado sea erroneo
/// @param mensajeOpcionUno	-> es el mensaje a mostrar para la opcion uno
/// @param mensajeOpcionDos	-> es el mensaje a mostrar para la opcion dos
/// @param opcionUno		-> es el char a ingresar para esta opcion
/// @param opcionDos		-> es el char a ingresar para esta opcion
/// @return respuesta		-> es el resultado de la opcion elegida y es devuelvo

char validacionOpcionesCharDobles (char mensaje[], char mensajeError[], char mensajeOpcionUno[], char mensajeOpcionDos[], char opcionUno, char opcionDos);

#endif /* VALIDACIONES_H_ */
