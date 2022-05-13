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

//	==============
//	> DEFINICIONES
//	==============
#define MENSAJE_NO_HAY_ALTAS "NO SE PUEDE INGRESAR A ESTA OPCION SIN DAR DE ALTA A UN PASAJERO"
#define MENSAJE_ERROR_INICIALIZACION_PASAJEROS "NO SE PUDO INICIALIZAR LA LISTA DE PASAJEROS"
#define MENSAJE_PASAJERO_ALTA_EXITOSA "EL PASAJERO FUE VALIDADO CON EXITO"
#define MENSAJE_PASAJERO_ALTA_ERROR "HUBO UN ERROR EN EL ALTA DEL PASAJERO, REINTENTE NUEVAMENTE DAR EL ALTA"
#define MENSAJE_PASAJERO_BAJA_EXITOSA "EL PASAJERO FUE DADO DE BAJA CON EXITO"
#define MENSAJE_PASAJERO_BAJA_CANCELADA "SE HA CANCELADO LA BAJA DEL PASAJERO, VOLVIENDO AL MENU"

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
