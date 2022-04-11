/*
 *	validaciones.h
 *
 *  Heredia Facundo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

//	> FUNCION VALIDACION ENTERO DENTRO DE MINIMO Y MAXIMO

int validacionNumeroEnteroEntreRangos (int numero, int limiteInferior, int limiteSuperior);

//	> VALIDACION NUMERO ENTERO POSITIVO

int validacionNumeroEnteroPositivo (char mensaje[], char mensajeError[]);

//	> VALIDACION NUMERO FLOTANTE POSITIVO

float validacionNumeroFlotantePositivo (char mensaje[], char mensajeError[]);

//	> FUNCION VALIDACION DE 2 OPCIONES CHAR

char validacionOpcionesCharDobles (char mensaje[], char mensajeError[], char mensajeOpcionUno[], char mensajeOpcionDos[], char opcionUno, char opcionDos);

#endif /* VALIDACIONES_H_ */
