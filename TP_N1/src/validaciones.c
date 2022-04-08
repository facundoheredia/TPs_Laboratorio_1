/*
 *	validaciones.c
 *
 *	Heredia Facundo
 */

//	> BIBLIOTECAS NECESARIAS
#include <stdio.h>
#include <ctype.h>

//---------------------------------------------------------------------------------------
//	> FUNCION VALIDACION ENTERO DENTRO DE MINIMO Y MAXIMO

// El usuario ingresa un numero y este es evaluado y validado entre un rango de numeros,
// y es devuelvo si es correcto, si no, sigue pidiendo un numero valido dentro del rango

// numero			-> es el numero ingresado por el usuario
// limiteInferior	-> es el menor numero del rango que puede ingresar
// limiteSuperior	-> es el mayor numero del rango que puede ingresar

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

// El usuario ingresa un numero y este es evaluado y validado si es positivo
// y es devuelvo si es correcto, si no, sigue pidiendo un numero positivo

// numero			-> es donde se guarda el valor ingresado por el usuario
// mensaje			-> es el mensaje que muestro al usuario la primera vez para que ingrese el numero
// mensajeError		-> es el mensaje que se mostrara siempre que el valor ingresado sea erroneo

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

// El usuario ingresa un numero y este es evaluado y validado si es positivo
// y es devuelvo si es correcto, si no, sigue pidiendo un numero positivo

// numero			-> es donde se guarda el valor ingresado por el usuario
// mensaje			-> es el mensaje que muestro al usuario la primera vez para que ingrese el numero
// mensajeError		-> es el mensaje que se mostrara siempre que el valor ingresado sea erroneo

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

// El usuario ingresa una opcion con una letra y este es evaluado y validado si esta en esas opciones
// y es devuelvo si es correcto, si no, sigue pidiendo una opcion valida

// mensaje			-> es el mensaje que muestro al usuario la primera vez para que ingrese una letra
// mensajeError		-> es el mensaje que se mostrara siempre que el valor ingresado sea erroneo
// mensajeOpcioUno	-> es el mensaje a mostrar para la opcion uno
// mensajeOpcionDos	-> es el mensaje a mostrar para la opcion dos
// opcionUno		-> es el char a ingresar para esta opcion
// opcionDos		-> es el char a ingresar para esta opcion
// respuesta		-> es el resultado de la opcion elegida y es devuelvo

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
//	> FUNCION PARA MOSTRAR MENSAJE QUE EVITA SEGUIR ADELANTE
void mensajeDatosForzadosIngresados (int flag)
{
	if(flag == 1)
	{
		printf("\n");
		printf("ATENCION! USTED YA HABIA INGRESADO DATOS AUTOMATICOS [5]\n");
		printf("\n");
		printf("Vuelva al menu principal y borrelos para ingresar datos manualmente\n");
		printf("\n");
	}

}
//---------------------------------------------------------------------------------------







