/// FUNCIONES MENUS
/// @author HEREDIA, FACUNDO GASTON
///
/// @date 29 de Abril de 2022

#ifndef HUD_MENU_H_
#define HUD_MENU_H_

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>

//	==============
//	> DEFINICIONES
//	==============
#define M_OPCION_MINIMA 1
#define MP_OPCION_MAXIMA 6
#define MM_OPCION_MAXIMA 6
#define ML_OPCION_MAXIMA 4

//	> FUNCION ENCABEZADO MENU
/// @brief FUNCION QUE MUESTRA LA PRESENTACION DEL INICIO DEL PROGRAMA
///
/// @return opcionValidada char [S] ingresa al programa [N] sale del programa
char iniciarPrograma (void);

//	> FUNCION MENU PRINCIPAL
/// @brief FUNCION QUE MUESTRA LAS OPCIONES DEL MENU PRINCIPAL
///
/// @return opcionMenuValidada int Devuelve la opcion elegida
int menuPricipal (void);

//	> FUNCION ENCABEZADO ALTA
/// @brief FUNCION QUE MUESTRA UN ENCABEZADO DENTRO DEL MENU DE ALTAS
void encabezadoAltas (void);

//	> FUNCION ENCABEZADO MODIFICACION
/// @brief FUNCION QUE MUESTRA EL MENU DE MOFICACIONES
///
/// @return opcionMenuValidada int Devuelve la opcion elegida
int menuModificacion (void);

//	> FUNCION ENCABEZADO BAJA
/// @brief FUNCION QUE MUESTRA UN ENCABEZADO DENTRO DEL MENU DE BAJAS
void encabezadoBajas (void);

//	> FUNCION ENCABEZADO BAJA
/// @brief FUNCION QUE MUESTRA UN ENCABEZADO DENTRO DEL MENU DE BAJAS DEL PASAJERO A DAR DE BAJA
void encabezadoDarDeBaja (void);

//	> FUNCION ENCABEZADO TABLA
/// @brief FUNCION QUE MUESTRA UN ENCABEZADO DE TABLA CUANDO SE MUESTRA EL LISTADO DE PASAJEROS
void encabezadoTabla (void);

//	> FUNCION PIE DE PAGINA TABLA
/// @brief FUNCION QUE MUESTRA UN FINAL DE TABLA CUANDO SE MUESTRA EL LISTADO DE PASAJEROS
void PieDePaginaTabla (void);

//	> FUNCION LISTADO DE PASAJEROS
/// @brief FUNCION QUE MUESTRA UN MENU CON LAS OPCIONES A LISTAR
///
/// @return opcionMenuValidada int Devuelve la opcion elegida
int menuListado (void);

#endif /* HUD_MENU_H_ */
