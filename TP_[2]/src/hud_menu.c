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
	printf("บ                  ฑฒÛ TRABAJO PRACTICO N2 Ûฒฑ                    บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ                                                                 บ\n");
	printf("บ  PROGRAMA ALTAS, BAJAS, MODIFICACIONES E INFORMES DE PASAJEROS  บ\n");
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

	printf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                     ฑฒÛ MENU  PRINCIPAL Ûฒฑ                     บ\n");
	printf("ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf("บ  [1] ALTA DE PASAJERO                                           บ\n");
	printf("บ  [2] MODIFICAR PASAJERO                                         บ\n");
	printf("บ  [3] BAJA DE PASAJERO                                           บ\n");
	printf("บ  [4] INFORMES                                                   บ\n");
	printf("บ  [5] SALIR                                                      บ\n");
	printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

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
	printf("บ  [4] TIPO DE PASAJERO                                           บ\n");
	printf("บ  [5] CODIGO DE VUELO                                            บ\n");
	printf("บ  [6] SALIR                                                      บ\n");
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
	printf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ                                  EL SIGUIENTE PASAJERO SE DARA DE BAJA                                 บ\n");
	printf("ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO TABLA
void encabezadoTabla (void)
{
	printf("\n");
	printf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
	printf("บ  ID   |      NOMBRE     |    APELLIDO     |    PRECIO    | COD. VUELO | TIPO PASAJERO | EST. DE VUELO  บ\n");
	printf("ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
}
//	================================================================================================================
//	> FUNCION PIE DE PAGINA TABLA
void PieDePaginaTabla (void)
{
	printf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
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
