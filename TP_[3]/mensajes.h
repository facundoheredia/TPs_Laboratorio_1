/// FUNCIONES DE MENSAJES
///
///	@author HEREDIA FACUNDO
/// @date 29 de Abril de 2022

#ifndef MENSAJES_MENSAJES_H_
#define MENSAJES_MENSAJES_H_

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include <stdio.h>
#include <stdlib.h>

//	===========
//	> FUNCIONES
//	===========
//	> FUNCION PROGRAMA FINALIZADO
/// @brief FUNCION QUE MUESTRA UN MENSAJE DE PROGRAMA FINALIZADO
void mensajeProgramaFinalizado (void);

//	> FUNCION MOSTRAR MENSAJE DE ALGO REALIZADO, ERROR, ETC.
/// @brief FUNCION QUE MUESTRA UN MENSAJE AL USUARIO
///
/// @param mensaje char Mensaje a mostrar al usuario
void mostrarMensaje (char mensaje[]);

//	> FUNCION MOSTRAR MENSAJE DE REALIZADO, ERROR, ETC.
/// @brief FUNCION QUE MUESTRA UN MENSAJE AL USUARIO Y PIDE PRECIONAR UNA TECLA PARA CONTINUAR
///
/// @param mensaje char Mensaje a ser mostrardo
void mostrarMensajeParaContinuar (char mensaje[]);

//	> FUNCION MOSTRAR MENSAJE CON DATO
/// @brief FUNCION QUE MUESTRA UN MENSAJE CON UN DATO DE TIPO ENTERO
///
/// @param mensaje char Mensaje a ser mostrado al usuario
/// @param datoParaMostrar int Dato a ser mostrado junto al mensaje
void mostrarMensajeConEntero (char mensaje[], int datoParaMostrar);

#endif /* MENSAJES_MENSAJES_H_ */
