/// FUNCIONES DE VALIDACIONES
///
///	@author Heredia Facundo
/// @date Abril 9 del 2022

//	> BIBLIOTECAS NECESARIAS
#include <stdio.h>
#include <ctype.h>

//---------------------------------------------------------------------------------------
//	> FUNCION VALIDACION ENTERO DENTRO DE MINIMO Y MAXIMO

int validacionNumeroEnteroEntreRangos (int numero, int limiteInferior, int limiteSuperior)
{
	//	>> validacion de funcion
	while (numero < limiteInferior || numero > limiteSuperior)
	{
		printf("ERROR! Ingrese una opci%cn v%clida\n", 162, 160);
		scanf("%d", &numero);
	}
	//	>> retorno de funcion
	return numero;
}
//---------------------------------------------------------------------------------------
//	> VALIDACION DE NUMERO ENTERO POSITIVO

int validacionNumeroEnteroPositivo (char mensaje[], char mensajeError[])
{
	//	>> variables de funcion
	int numero;
	//	>> Pedido de numero de funcion
	printf("%s\n", mensaje);
	scanf("%d", &numero);
	//	>> validacion de funcion
	while (numero <= 0)
	{
		printf("%s\n", mensajeError);
		scanf("%d", &numero);
	}
	//	>> retorno de funcion
	return numero;
}
//---------------------------------------------------------------------------------------
//	> VALIDACION DE NUMERO FLOTANTE POSITIVO

float validacionNumeroFlotantePositivo (char mensaje[], char mensajeError[])
{
	//	>> variables de funcion
	float numero;
	//	>> Pedido de numero de funcion
	printf("%s\n", mensaje);
	scanf("%f", &numero);
	//	>> validacion de funcion
	while (numero <= 0)
	{
		printf("%s\n", mensajeError);
		scanf("%f", &numero);
	}
	//	>> retorno de funcion
	return numero;
}
//---------------------------------------------------------------------------------------
//	> FUNCION VALIDACION DE 2 OPCIONES CHAR

char validacionOpcionesCharDobles (char mensaje[], char mensajeError[], char mensajeOpcionUno[], char mensajeOpcionDos[], char opcionUno, char opcionDos)
{
	//	>> variables de funcion
	char respuesta;
	//	>> mensaje de funcion
	printf("%s\n", mensaje);
	printf("%s\n", mensajeOpcionUno);
	printf("%s\n", mensajeOpcionDos);
	fflush(stdin);
	scanf("%c", &respuesta);
	respuesta = toupper(respuesta);
	//	>> validacion opcion elegida
	while (respuesta != opcionUno && respuesta != opcionDos)
	{
		printf("%s\n", mensajeError);
		printf("%s\n", mensajeOpcionUno);
		printf("%s\n", mensajeOpcionDos);
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = toupper(respuesta);
	}
	//	>> retorno de funcion
	return respuesta;
}
//---------------------------------------------------------------------------------------
