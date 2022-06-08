/// FUNCIONES MENUS
/// @author HEREDIA, FACUNDO GASTON
///
/// @date 29 de Abril de 2022

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "hud_menu.h"

//	================================================================================================================
//	> FUNCION ENCABEZADO PRESENTACION
char iniciarPrograma (void)
{
	char opcionValidada;

	system("cls");
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                  ฑฒÛ TRABAJO PRACTICO N3 Ûฒฑ                    บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ                                                                 บ\n");
	printf("บ                       PROGRAMA LINKEDLIST                       บ\n");
	printf("บ      ALTAS, BAJAS, MODIFICACIONES E INFORMES DE PASAJEROS       บ\n");
	printf("บ                                                                 บ\n");
	printf("บ  DIVISION: 1F                                                   บ\n");
	printf("บ  ALUMNO: Heredia Facundo                                        บ\n");
	printf("บ                                                                 บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
	printf("\n");
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                    ฟDESEA INICIAR EL PROGRAMA?                  บ\n");
	printf("บ                       [S] SI         [N] NO                     บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
	printf("\n");

	opcionValidada = entrada_respuestaUsuario ("INGRESE UNA OPCION\n");

	system("cls");

	return opcionValidada;
}
//	================================================================================================================
//	> FUNCION MENU PRINCIPAL
int menuPricipal (void)
{
	int opcionMenuValidada;

	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                             ฑฒÛ MENU  PRINCIPAL Ûฒฑ                             บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ  [01] CARGAR LOS DATOS DE LOS PASAJEROS DESDE ARCHIVO data.csv (modo texto)     บ\n");
	printf("บ  [02] CARGAR LOS DATOS DE LOS PASAJEROS DESDE ARCHIVO data.bin (modo binario)   บ\n");
	printf("บ  [03] ALTA DE PASAJERO                                                          บ\n");
	printf("บ  [04] MODIFICAR DATOS DE PASAJERO                                               บ\n");
	printf("บ  [05] BAJA DE PASAJERO                                                          บ\n");
	printf("บ  [06] LISTAR PASAJEROS                                                          บ\n");
	printf("บ  [07] ORDENAR PASAJEROS                                                         บ\n");
	printf("บ  [08] GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.csv (modo texto)    บ\n");
	printf("บ  [09] GUARDAR LOS DATOS DE LOS PASAJEROS EN EL ARCHIVO data.bin (modo binario)  บ\n");
	printf("บ  [10] SALIR                                                                     บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

	opcionMenuValidada = entrada_obtenerEnteroEntreRango ("INGRESE UNA OPCION: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", M_OPCION_MINIMA, MP_OPCION_MAXIMA);
	system("cls");
	return opcionMenuValidada;
}
//	================================================================================================================
//	> FUNCION ENCABEZADO ALTA
void encabezadoAltas (void)
{
	system("cls");
	printf("\n");
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                     ฑฒÛ ALTA DE PASAJERO Ûฒฑ                    บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ  POR FAVOR LLENE LOS DATOS QUE SE VAN SOLICITANDO PARA EL ALTA  บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
	printf("\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO MODIFICACION
int menuModificacion (void)
{
	int opcionMenuValidada;

	//system("cls");
	printf("\n");
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                ฑฒÛ MODIFICACION DE PASAJERO Ûฒฑ                 บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ  [1] NOMBRE                                                     บ\n");
	printf("บ  [2] APELLIDO                                                   บ\n");
	printf("บ  [3] PRECIO                                                     บ\n");
	printf("บ  [4] CODIGO DE VUELO                                            บ\n");
	printf("บ  [5] TIPO DE PASAJERO                                           บ\n");
	printf("บ  [6] VOLVER AL MENU PRINCIPAL                                   บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

	opcionMenuValidada = entrada_obtenerEnteroEntreRango ("INGRESE UNA OPCION: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", M_OPCION_MINIMA, MM_OPCION_MAXIMA);
	system("cls");
	return opcionMenuValidada;
}
//	================================================================================================================
//	> FUNCION ENCABEZADO BAJA
void encabezadoBajas (void)
{
	system("cls");
	printf("\n");
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                     ฑฒÛ BAJA DE PASAJERO Ûฒฑ                    บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ   POR FAVOR ELIGA DE LA SIGUIENTE LISTA EL PASAJERO POR SU ID   บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO BAJA
void encabezadoDarDeBaja (void)
{
	printf("\n");
	printf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                                      EL SIGUIENTE PASAJERO SE DARA DE BAJA                                     บ\n");
	printf("ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO TABLA
void encabezadoTabla (void)
{
	printf("\n");
	printf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ  ID   |      NOMBRE     |    APELLIDO     |    PRECIO    | COD. VUELO |     TIPO PASAJERO     | EST. DE VUELO  บ\n");
	printf("ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
}
//	================================================================================================================
//	> FUNCION PIE DE PAGINA TABLA
void PieDePaginaTabla (void)
{
	printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO TABLA TIPO PASAJERO
void encabezadoTablaTipoPasajero (void)
{
	printf("\n");
	printf("ษออออออออออออออออออออออป\n");
	printf("บ     TIPO PASAJERO    บ\n");
	printf("ฬออออออออออออออออออออออน\n");
}
//	================================================================================================================
//	> FUNCION PIE DE TIPO PASAJERO
void PieDePaginaTablaTipoPasajero (void)
{
	printf("ศออออออออออออออออออออออผ\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO TABLA CODIGOS DE VUELO
void encabezadoTablaCodigosDeVuelo (void)
{
	printf("\n");
	printf("ษอออออออออออออออป\n");
	printf("บ  COD. VUELO   บ\n");
	printf("ฬอออออออออออออออน\n");
}
//	================================================================================================================
//	> FUNCION PIE DE PAGINA TABLA
void PieDePaginaTablaCodigosDeVuelo (void)
{
	printf("ศอออออออออออออออผ\n");
}
//	================================================================================================================
//	> FUNCION LISTADO DE PASAJEROS
int menuListado (void)
{
	int opcionMenuValidada;

	system("cls");
	printf("\n");
	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                   ฑฒÛ LISTADO DE PASAJERO Ûฒฑ                   บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ  [1] LISTADO DE PASAJEROS POR APELLIDO Y TIPO PASAJERO          บ\n");
	printf("บ  [2] TOTAL Y PROMEDIO DE PRECIOS DE LOS PASAJES,                บ\n");
	printf("บ      Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO             บ\n");
	printf("บ  [3] LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y             บ\n");
	printf("บ      ESTADOS DE VUELOS ACTIVOS                                  บ\n");
	printf("บ  [4] SALIR                                                      บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

	opcionMenuValidada = entrada_obtenerEnteroEntreRango ("INGRESE UNA OPCION: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", M_OPCION_MINIMA, ML_OPCION_MAXIMA);
	system("cls");
	return opcionMenuValidada;
}
//	================================================================================================================
//	> FUNCION ORDENAR PASAJEROS
int menuOrdenar (void)
{
	int opcionMenuValidada;

	system("cls");
	printf("\n");
	printf("ษอออออออออออออออออออออออออออออออออออออป\n");
	printf("บ  ฑฒÛ ORDENAMIENTO DE PASAJEROS Ûฒฑ  บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออน\n");
	printf("บ  [1] POR ID                         บ\n");
	printf("บ  [2] POR NOMBRE                     บ\n");
	printf("บ  [3] POR APELLIDO                   บ\n");
	printf("บ  [4] POR PRECIO                     บ\n");
	printf("บ  [5] POR CODIGO DE VUELO            บ\n");
	printf("บ  [6] POR TIPO DE PASAJERO           บ\n");
	printf("บ  [7] POR ESTADO DE VUELO            บ\n");
	printf("บ  [8] SALIR                          บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออผ\n");

	opcionMenuValidada = entrada_obtenerEnteroEntreRango ("INGRESE UNA OPCION: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", M_OPCION_MINIMA, MO_OPCION_MAXIMA);
	system("cls");
	return opcionMenuValidada;
}
