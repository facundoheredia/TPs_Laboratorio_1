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
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                  ±²Ϋ TRABAJO PRACTICO N2 Ϋ²±                    Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
	printf("Ί                                                                 Ί\n");
	printf("Ί  PROGRAMA ALTAS, BAJAS, MODIFICACIONES E INFORMES DE PASAJEROS  Ί\n");
	printf("Ί                                                                 Ί\n");
	printf("Ί  DIVISION: 1F                                                   Ί\n");
	printf("Ί  ALUMNO: Heredia Facundo                                        Ί\n");
	printf("Ί                                                                 Ί\n");
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");
	printf("\n");
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                    ΏDESEA INICIAR EL PROGRAMA?                  Ί\n");
	printf("Ί                       [S] SI         [N] NO                     Ί\n");
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");
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

	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                     ±²Ϋ MENU  PRINCIPAL Ϋ²±                     Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
	printf("Ί  [1] ALTA DE PASAJERO                                           Ί\n");
	printf("Ί  [2] MODIFICAR PASAJERO                                         Ί\n");
	printf("Ί  [3] BAJA DE PASAJERO                                           Ί\n");
	printf("Ί  [4] INFORMES                                                   Ί\n");
	printf("Ί  [5] PASAJEROS HARDCODEADOS                                     Ί\n");
	printf("Ί  [6] SALIR                                                      Ί\n");
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");

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
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                     ±²Ϋ ALTA DE PASAJERO Ϋ²±                    Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
	printf("Ί  POR FAVOR LLENE LOS DATOS QUE SE VAN SOLICITANDO PARA EL ALTA  Ί\n");
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");
	printf("\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO MODIFICACION
int menuModificacion (void)
{
	int opcionMenuValidada;

	//system("cls");
	printf("\n");
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                ±²Ϋ MODIFICACION DE PASAJERO Ϋ²±                 Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
	printf("Ί  [1] NOMBRE                                                     Ί\n");
	printf("Ί  [2] APELLIDO                                                   Ί\n");
	printf("Ί  [3] PRECIO                                                     Ί\n");
	printf("Ί  [4] TIPO DE PASAJERO                                           Ί\n");
	printf("Ί  [5] CODIGO DE VUELO                                            Ί\n");
	printf("Ί  [6] SALIR                                                      Ί\n");
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");

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
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                     ±²Ϋ BAJA DE PASAJERO Ϋ²±                    Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
	printf("Ί   POR FAVOR ELIGA DE LA SIGUIENTE LISTA EL PASAJERO POR SU ID   Ί\n");
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO BAJA
void encabezadoDarDeBaja (void)
{
	printf("\n");
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                                  EL SIGUIENTE PASAJERO SE DARA DE BAJA                                 Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO TABLA
void encabezadoTabla (void)
{
	printf("\n");
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί  ID   |      NOMBRE     |    APELLIDO     |    PRECIO    | COD. VUELO | TIPO PASAJERO | EST. DE VUELO  Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
}
//	================================================================================================================
//	> FUNCION PIE DE PAGINA TABLA
void PieDePaginaTabla (void)
{
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO TABLA CODIGOS DE VUELO
void encabezadoTablaCodigosDeVuelo (void)
{
	printf("\n");
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί  COD. VUELO  Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
}
//	================================================================================================================
//	> FUNCION PIE DE PAGINA TABLA
void PieDePaginaTablaCodigosDeVuelo (void)
{
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");
}
//	================================================================================================================
//	> FUNCION LISTADO DE PASAJEROS
int menuListado (void)
{
	int opcionMenuValidada;

	system("cls");
	printf("\n");
	printf("ΙΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝ»\n");
	printf("Ί                   ±²Ϋ LISTADO DE PASAJERO Ϋ²±                   Ί\n");
	printf("ΜΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΉ\n");
	printf("Ί  [1] LISTADO DE PASAJEROS POR APELLIDO Y TIPO PASAJERO          Ί\n");
	printf("Ί  [2] TOTAL Y PROMEDIO DE PRECIOS DE LOS PASAJES,                Ί\n");
	printf("Ί      Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO             Ί\n");
	printf("Ί  [3] LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y             Ί\n");
	printf("Ί      ESTADOS DE VUELOS ACTIVOS                                  Ί\n");
	printf("Ί  [4] SALIR                                                      Ί\n");
	printf("ΘΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΝΌ\n");

	opcionMenuValidada = entrada_obtenerEnteroEntreRango ("INGRESE UNA OPCION: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", M_OPCION_MINIMA, ML_OPCION_MAXIMA);
	system("cls");
	return opcionMenuValidada;
}
//	================================================================================================================
