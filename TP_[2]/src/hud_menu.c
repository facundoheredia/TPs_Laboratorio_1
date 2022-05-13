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
	printf("�����������������������������������������������������������������ͻ\n");
	printf("�                  ��� TRABAJO PRACTICO N2 ۲�                    �\n");
	printf("�����������������������������������������������������������������͹\n");
	printf("�                                                                 �\n");
	printf("�  PROGRAMA ALTAS, BAJAS, MODIFICACIONES E INFORMES DE PASAJEROS  �\n");
	printf("�                                                                 �\n");
	printf("�  DIVISION: 1F                                                   �\n");
	printf("�  ALUMNO: Heredia Facundo                                        �\n");
	printf("�                                                                 �\n");
	printf("�����������������������������������������������������������������ͼ\n");
	printf("\n");
	printf("�����������������������������������������������������������������ͻ\n");
	printf("�                    �DESEA INICIAR EL PROGRAMA?                  �\n");
	printf("�                       [S] SI         [N] NO                     �\n");
	printf("�����������������������������������������������������������������ͼ\n");
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

	printf("�����������������������������������������������������������������ͻ\n");
	printf("�                     ��� MENU  PRINCIPAL ۲�                     �\n");
	printf("�����������������������������������������������������������������͹\n");
	printf("�  [1] ALTA DE PASAJERO                                           �\n");
	printf("�  [2] MODIFICAR PASAJERO                                         �\n");
	printf("�  [3] BAJA DE PASAJERO                                           �\n");
	printf("�  [4] INFORMES                                                   �\n");
	printf("�  [5] SALIR                                                      �\n");
	printf("�����������������������������������������������������������������ͼ\n");

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
	printf("�����������������������������������������������������������������ͻ\n");
	printf("�                     ��� ALTA DE PASAJERO ۲�                    �\n");
	printf("�����������������������������������������������������������������͹\n");
	printf("�  POR FAVOR LLENE LOS DATOS QUE SE VAN SOLICITANDO PARA EL ALTA  �\n");
	printf("�����������������������������������������������������������������ͼ\n");
	printf("\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO MODIFICACION
int menuModificacion (void)
{
	int opcionMenuValidada;

	//system("cls");
	printf("\n");
	printf("�����������������������������������������������������������������ͻ\n");
	printf("�                ��� MODIFICACION DE PASAJERO ۲�                 �\n");
	printf("�����������������������������������������������������������������͹\n");
	printf("�  [1] NOMBRE                                                     �\n");
	printf("�  [2] APELLIDO                                                   �\n");
	printf("�  [3] PRECIO                                                     �\n");
	printf("�  [4] TIPO DE PASAJERO                                           �\n");
	printf("�  [5] CODIGO DE VUELO                                            �\n");
	printf("�  [6] SALIR                                                      �\n");
	printf("�����������������������������������������������������������������ͼ\n");

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
	printf("�����������������������������������������������������������������ͻ\n");
	printf("�                     ��� BAJA DE PASAJERO ۲�                    �\n");
	printf("�����������������������������������������������������������������͹\n");
	printf("�   POR FAVOR ELIGA DE LA SIGUIENTE LISTA EL PASAJERO POR SU ID   �\n");
	printf("�����������������������������������������������������������������ͼ\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO BAJA
void encabezadoDarDeBaja (void)
{
	printf("\n");
	printf("��������������������������������������������������������������������������������������������������������ͻ\n");
	printf("�                                  EL SIGUIENTE PASAJERO SE DARA DE BAJA                                 �\n");
	printf("��������������������������������������������������������������������������������������������������������͹\n");
}
//	================================================================================================================
//	> FUNCION ENCABEZADO TABLA
void encabezadoTabla (void)
{
	printf("\n");
	printf("��������������������������������������������������������������������������������������������������������ͻ\n");
	printf("�  ID   |      NOMBRE     |    APELLIDO     |    PRECIO    | COD. VUELO | TIPO PASAJERO | EST. DE VUELO  �\n");
	printf("��������������������������������������������������������������������������������������������������������͹\n");
}
//	================================================================================================================
//	> FUNCION PIE DE PAGINA TABLA
void PieDePaginaTabla (void)
{
	printf("��������������������������������������������������������������������������������������������������������ͼ\n");
}
//	================================================================================================================
//	> FUNCION LISTADO DE PASAJEROS
int menuListado (void)
{
	int opcionMenuValidada;

	system("cls");
	printf("\n");
	printf("�����������������������������������������������������������������ͻ\n");
	printf("�                   ��� LISTADO DE PASAJERO ۲�                   �\n");
	printf("�����������������������������������������������������������������͹\n");
	printf("�  [1] LISTADO DE PASAJEROS POR APELLIDO Y TIPO PASAJERO          �\n");
	printf("�  [2] TOTAL Y PROMEDIO DE PRECIOS DE LOS PASAJES,                �\n");
	printf("�      Y CUANTOS PASAJEROS SUPERAN EL PRECIO PROMEDIO             �\n");
	printf("�  [3] LISTADO DE LOS PASAJEROS POR CODIGO DE VUELO Y             �\n");
	printf("�      ESTADOS DE VUELOS ACTIVOS                                  �\n");
	printf("�  [4] SALIR                                                      �\n");
	printf("�����������������������������������������������������������������ͼ\n");

	opcionMenuValidada = entrada_obtenerEnteroEntreRango ("INGRESE UNA OPCION: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", "UPS! NO ES UN DATO VALIDO, REINTENTE: ", M_OPCION_MINIMA, ML_OPCION_MAXIMA);
	system("cls");
	return opcionMenuValidada;
}
//	================================================================================================================
