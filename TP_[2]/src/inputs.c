/// FUNCIONES DE ENTRADAS
///
///	@author HEREDIA FACUNDO
/// @date 29 de Abril de 2022

//	========================
//	> BIBLIOTECAS NECESARIAS
//	========================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

//	========
//	> DEFINE
//	========


//	==================================
//	> FUNCIONES DE ENTRADA PRINCIPALES
//	==================================
//	FUNCION PRINCIPAL DE ENTRADA DE NUMERO ENTERO ENTRE RANGO (CON PUNTERO UTN)
int entrada_obtenerEntero(int* entrada, char mensaje[], char mensajeError[], int limiteInferior, int limiteSuperior)
{
    int retorno;
    int contador;
    int numeroValido;
    int numeroEntero;
    char cadenaNumerica[64];

    retorno = -1;
    contador = 0;
    numeroValido = -1;

    if(limiteSuperior >= limiteInferior && entrada != NULL && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
        	contador++;

            if(contador == 1)
            {
                printf("%s", mensaje);
            }
            else
            {
                if(contador > 1)
                {
                    printf("%s", mensajeError);
                }
            }

            scanf("%s", cadenaNumerica);

            numeroValido = entrada_esNumero(cadenaNumerica);
            if(numeroValido)
            {
            	numeroEntero = atoi(cadenaNumerica);
            }
        } while(!numeroValido || (numeroValido && (numeroEntero < limiteInferior || numeroEntero > limiteSuperior)));

        if(numeroEntero >= limiteInferior && numeroEntero <= limiteSuperior)
        {
            *entrada = numeroEntero;
            retorno = 0;
        }
    }

    return retorno;
}

//	FUNCION PRINCIPAL OBTENER NUMERO ENTERO ENTRE RANGO (SIN PUNTERO)
int entrada_obtenerEnteroEntreRango (char mensaje[], char mensajeErrorValidacion[], char mensajeErrorRango[], int limiteMinimo, int limiteMaximo)
{
	char cadenaNumero[10];
	char auxiliar[4096];
	int numeroEsNumeroValido;
	int respuestaValidacion;

	auxiliar[0] = '\0';

	printf("%s\n", mensaje);

	do
	{
		if (respuestaValidacion == 0)
		{
			printf("%s\n", mensajeErrorValidacion);
		}

		if(atoi(auxiliar))
		{
			printf("%s\n", mensajeErrorRango);
		}

		fflush(stdin);
		scanf("%s", cadenaNumero);

		respuestaValidacion = validarSiEsNumeroEntero (cadenaNumero, auxiliar);

		numeroEsNumeroValido = atoi(auxiliar);

	} while (respuestaValidacion == 0 || (numeroEsNumeroValido < limiteMinimo || numeroEsNumeroValido > limiteMaximo));


	return numeroEsNumeroValido;
}

//	FUNCION PRINCIPAL DE ENTRADA DE NUMERO FLOTANTE ENTRE RANGO (CON PUNTERO UTN))
int entrada_obtenerFlotante(float* entrada, char mensaje[], char mensajeError[], float limiteInferior, float limiteSuperior)
{
    int retorno;
    int contador;
    int numeroValido = -1;
    float numeroFlotante;
    char cadenaNumerica[64];

    retorno = -1;
    contador = 0;
    numeroValido = -1;


    if(limiteSuperior >= limiteInferior && entrada != NULL && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
        	contador++;

            if(contador == 1)
            {
                printf("%s", mensaje);
            }
            else
            {
                printf("%s", mensajeError);
            }

            scanf("%s", cadenaNumerica);

            numeroValido = entrada_esFlotante(cadenaNumerica);
            if(numeroValido)
            {
                numeroFlotante = atof(cadenaNumerica);
            }
        } while(!numeroValido || (numeroValido && (numeroFlotante < limiteInferior || numeroFlotante > limiteSuperior)));

        if(numeroFlotante >= limiteInferior && numeroFlotante <= limiteSuperior)
        {
            *entrada = numeroFlotante;
            retorno = 0;
        }
    }

    return retorno;
}

//	FUNCION PRINCIPAL OBTENER TIPO DE NUMERO ENTERO O FLOTANTE
int entrada_obtenerTipoNumero(float numero)
{
    int retorno;
    float numeroEntero;

    numeroEntero = (int)numero;

    if (numero - numeroEntero != 0.0f)
    {
        retorno = 2;
    }
    else
    {
        if (numero == numeroEntero || (float)numero == 0)
        {
            retorno = 1;
        }
        else
        {
        	retorno = 0;
        }
    }

    return retorno;
}

//	FUNCION PRINCIPAL VALIDAR SI ES UN CARACTER
int entrada_obtenerCaracter(char* entrada, char mensaje[], char mensajeError[], char limiteInferior, char limiteSuperior)
{
    int retorno = -1;
    int contador = 0;
    char caracterValidar;

    retorno = -1;
    contador = 0;

    if(entrada != NULL && mensaje != NULL && mensajeError != NULL && (int)limiteSuperior >= (int)limiteInferior && isalpha(limiteInferior) && isalpha(limiteSuperior))
    {
        do
        {
            contador++;

            if(contador == 1)
            {
                printf("%s", mensaje);
            }
            else
            {
                if(contador > 1)
                {
                    printf("%s", mensajeError);
                }
            }

            fflush(stdin);
            scanf("%c", &caracterValidar);
        } while((int)caracterValidar < (int)limiteInferior || (int)caracterValidar > (int)limiteSuperior);

        if((int)caracterValidar >= (int)limiteInferior && (int)caracterValidar <= (int)limiteSuperior)
        {
            *entrada = caracterValidar;
            retorno = 0;
        }
    }

    return retorno;
}

//	FUNCION PRINCIPAL OBTENER CADENA
int entrada_obtenerCadena(char *pCadena, char mensaje[], char mensajeError[], int longitudLimite)
{
    int retorno = -1;
    int i;

    retorno = -1;

    if (mensaje != NULL && mensajeError != NULL && pCadena != NULL && longitudLimite > 0)
    {
        do
        {
            printf("%s", mensaje);
            if (!(myGets(pCadena, longitudLimite)) && entrada_esLetras(pCadena))
            {
                for(i = 0; i < longitudLimite; i++)
                {
                    pCadena[i] = toupper(pCadena[i]);
                }
                retorno = 0;
            }
            else
            {
            	printf("%s\n", mensajeError);
            }
        } while (retorno != 0);
    }
    return retorno;
}

//	FUNCION PRINCIPAL OBTENER RESPUESTA
char entrada_respuestaUsuario(char mensaje[])
{
    char respuesta;

    if(mensaje != NULL)
    {
    	do
    	{
    		 printf("%s", mensaje);
    		 fflush(stdin);
    		 scanf("%c", &respuesta);

    		 respuesta = toupper(respuesta);

    	}while(respuesta != 'S' && respuesta != 'N');

    }

    return respuesta;
}

//	==================================
//	> FUNCIONES DE ENTRADA SECUNDARIAS
//	==================================
//	FUNCION SECUNDARIA VALIDAR SI ES UN NUMERO (DEPENDIENTE DE "entrada_obtenerEntero")
int entrada_esNumero(char cadenaRecibida[])
{
    int retorno;
    int indice;
    char caracterAuxiliar;

    retorno = 0;
    indice = 0;
    
    while(cadenaRecibida[indice] != (int)'\0')
    {
        caracterAuxiliar = cadenaRecibida[indice];

        if(indice == 0 && (caracterAuxiliar == '-' || caracterAuxiliar == '+'))
        {
        	indice = 1;
            continue;
        }

        if((int)caracterAuxiliar >= (int)'0' && (int)caracterAuxiliar <= (int)'9')
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
            break;
        }
        indice++;
    }

    return retorno;
}

//	FUNCION SECUNDARIA VALIDAR SI ES UN NUMERO ENTERO (DEPENDIENTE DE "entrada_obtenerEnteroEntreRango")
int validarSiEsNumeroEntero (char cadenaRecibida[], char auxiliar[])
{
	int i;
	int longitudCadenaRecibida;
	int retorno;
	int caracteresNumericos;

	i = 0;
	retorno = 1;
	longitudCadenaRecibida = strlen (cadenaRecibida);
	caracteresNumericos = 0;

	//Salto los espacios en blanco
	while (isspace(cadenaRecibida[i]))
	{
		i++;
	}
	//Si llego al final devuelvo error
	if (longitudCadenaRecibida == i)
	{
		retorno = 0;
	}
	//Guardo el signo negativo si lo tiene
	if(cadenaRecibida[i] == '-')
	{
		auxiliar[caracteresNumericos] = '-';
		caracteresNumericos++;
		i++;
		//Reviso si hay numeros despues del signo
		if(!isdigit(cadenaRecibida[i]) || isalpha(cadenaRecibida[i]))
		{
			retorno = 0;
		}
	}
	//Avanzo hasta el final de la cadena o si llego a un espacio en blanco
	while (i < longitudCadenaRecibida && !isspace(cadenaRecibida[i]))
	{
		//Si no hay un digito da error
		if (!isdigit(cadenaRecibida[i]))
		{
			retorno = 0;
		}

		auxiliar[caracteresNumericos] = cadenaRecibida[i];

		caracteresNumericos++;
		i++;
	}

	auxiliar[caracteresNumericos] = '\0';

	while (isspace(cadenaRecibida[i]))
	{
		i++;
	}

	if(cadenaRecibida[i] != '\0')
	{
		retorno = 0;
	}

	return retorno;
}

//	FUNCION SECUNDARIA VALIDAR SI ES UN NUMERO FLOTANTE (DEPENDIENTE DE "entrada_obtenerFlotante")
int entrada_esFlotante(char cadenaRecibida[])
{
    int retorno;
    int i;
    int contadorPuntos;

    retorno = 0;
    contadorPuntos = 0;

    while(cadenaRecibida[i] != (int)'\0')
    {
        if(i == 0 && ((int)cadenaRecibida[0] == (int)'-' || (int)cadenaRecibida[0] == (int)'+'))
        {
            i = 1;
            continue;
        }

        if(cadenaRecibida[i] == '.')
        {
            contadorPuntos++;
        }
        else
        {
            if((int)cadenaRecibida[i] >= (int)'0' && (int)cadenaRecibida[i] <= (int)'9' && contadorPuntos <= 1)
            {
                retorno = 1;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
        i++;
    }

    return retorno;
}

//	FUNCION SECUNDARIA VALIDAR SI SON LETRAS (DEPENDIENTE DE "entrada_obtenerCadena")
int entrada_esLetras(char *pCadena)
{
    int retorno;

    retorno = 1;

    if(pCadena !=NULL)
    {
        for(int x = 0; pCadena[x] !='\0'; x++)
        {
            if((pCadena[x] < 'A' || pCadena[x] > 'z') && (pCadena[x] > 'Z' || pCadena[x] < 'a') && pCadena[x] != ' ')
            {
            	retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

//	FUNCION SECUNDARIA REMOVER SALTO DE LINIEA
int myGets(char *pCadena, int longitud)
{
    int retorno;
    char cadenaAuxiliar[4096];

    retorno = -1;

    fflush(stdin);

    if (pCadena != NULL && longitud > 0 && fgets(cadenaAuxiliar, sizeof(cadenaAuxiliar), stdin) != NULL)
    {
        if (cadenaAuxiliar[0] == '\n' || cadenaAuxiliar[0] == ' ')
        {
            printf("ERROR!, SOLO INGRESO UN ENTER O UN ESPACIO EN EL PRIMER CARACTER\n");
        }
        else
        {
        	cadenaAuxiliar[strnlen(cadenaAuxiliar, sizeof(cadenaAuxiliar)) - 1] = '\0';
            if (strnlen(cadenaAuxiliar, sizeof(cadenaAuxiliar)) <= longitud)
            {
                strncpy(pCadena, cadenaAuxiliar, longitud);
                retorno = 0;
            }
        }
    }
    return retorno;
}

//	FUNCION SECUNDARIA IMPRIMIR NUMERO SEGUN TIPO (DEPENDIENTE DE "entrada_obtenerTipoNumero")
void entrada_imprimirTipoNumero(char mensaje[], float numero)
{
    switch (entrada_obtenerTipoNumero(numero))
    {
        case 1:
            printf("%s %.0lf\n", mensaje, numero);
            break;
        case 2:
            printf("%s %.3lf\n", mensaje, numero);
            break;
    }
}

//	FUNCION PRINCIPAL OBTENER CADENA ALFANUMERICA
void entrada_obtenerCadenaAlfaNumerica(char mensaje[],char mensajeError[], char entrada[])
{
    while(1)
    {
        if (!obtenerCadenaAlfaNumerica(mensaje,entrada))
        {
            printf ("%s\n",mensajeError);
            continue;
        }
        //cleanStdin();
        break;
    }
}

//	FUNCION SECUNDARIA OBTENER CADENA ALFANUMERICA
int obtenerCadenaAlfaNumerica(char mensaje[],char entrada[])
{
    char aux[256];
    obtenerCadena(mensaje,aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(entrada,aux);
        return 1;
    }
    return 0;
}

//	FUNCION SECUNDARIA OBTENER CADENA
void obtenerCadena(char mensaje[],char entrada[])
{
    printf("%s",mensaje);
    scanf ("%s", entrada);
}

//	FUNCION SECUNDARIA ES ALFANUMERICA
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
