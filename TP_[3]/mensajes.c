/// FUNCIONES DE MENSAJES
///
///	@author HEREDIA FACUNDO
/// @date 29 de Abril de 2022


//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include "mensajes.h"

//	================================================================================================================
//	> FUNCION PROGRAMA FINALIZADO
void mensajeProgramaFinalizado (void)
{
	system("cls");
	printf("浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
	printf("�                  Muchas Gracias, vuelva pronto                  �\n");
	printf("�                   渦� PROGRAMA FINALIZADO 朮�                   �\n");
	printf("藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
	printf("\n");
	system("pause");
}
//	================================================================================================================
//	> FUNCION MOSTRAR MENSAJE DE ALGO
void mostrarMensaje (char mensaje[])
{
	printf("%s\n", mensaje);
}
//	================================================================================================================
//	> FUNCION MOSTRAR MENSAJE DE REALIZADO, ERROR, ETC.
void mostrarMensajeParaContinuar (char mensaje[])
{
	printf("\n");
	printf("%s\n", mensaje);
	printf("\n");
	system("pause");
}
//	================================================================================================================
//	> FUNCION MOSTRAR MENSAJE CON DATO
void mostrarMensajeConEntero (char mensaje[], int datoParaMostrar)
{
	printf("\n");
	printf("%s%d\n", mensaje, datoParaMostrar);
	printf("\n");
	system("pause");
}
//	================================================================================================================
