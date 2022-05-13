/// FUNCIONES DE ENTRADAS
///
///	@author HEREDIA FACUNDO
/// @date 29 de Abril de 2022

#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

/// @brief SOLICITA UN NUMERO Y LO VALIDA
///
/// @param entrada* int Se carga el numero ingresado.
/// @param mensaje[] char Es el mensaje a ser mostrado.
/// @param mensajeError[] char Es el mensaje a ser mostrado en caso de error.
/// @param limiteInferior int Limite inferior a validar.
/// @param limiteSuperior int Limite superior a validar.
/// @return int Si obtuvo el numero devuelve [0] si no [-1].
int entrada_obtenerEntero(int* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/// @brief SOLICITA UN NUMERO EN CADENA Y LO VALIDA SI ES UN NUMERO
///
/// @param mensaje[] char Es el mensaje a ser mostrado.
/// @param mensajeErrorValidacion[] char Es el mensaje a ser mostrado en caso de de ser un numero.
/// @param mensajeErrorRango[] char Es el mensaje a ser mostrado en caso de de esta fuera del rango de limites.
/// @param limiteInferior int Limite inferior a validar.
/// @param limiteSuperior int Limite superior a validar.
/// @return numeroEsNumeroValido int Numero validado en cadena
int entrada_obtenerEnteroEntreRango (char mensaje[], char mensajeErrorValidacion[], char mensajeErrorRango[], int limiteMinimo, int limiteMaximo);

/// @brief SOLICITA UN NUMERO FLOTANTE Y LO VALIDA
///
/// @param entrada* float Se carga el numero flotante ingresado.
/// @param mensaje[] char Es el mensaje a ser mostrado.
/// @param mensajeError[] char Es el mensaje a ser mostrado en caso de error.
/// @param limiteInferior float Limite inferior a validar.
/// @param limiteSuperior float Limite superior a validar.
/// @return int Si obtuvo el numero devuelve [0] si no [-1].
int entrada_obtenerFlotante(float* input, char message[], char eMessage[], float lowLimit, float hiLimit);

/// @brief VERIFICA SI EL NUMERO ES ENTERO O FLOTANTE SI TIENE O NO DECIMALES.
///
/// @param numero float Numero con o sin decimales a evaluar.
/// @return int Si devuelve [0] no puede reconocer el tipo.
///      	    Si devuelve [1] el numero es de tipo entero.
///      	    Si devuelve [2] el numero es de tipo flotante.
int entrada_obtenerTipoNumero(float numero);

/// @brief VALIDA SI ES UN CARACTER.
///
/// @param entrada char* Se carga el caracter ingresado.
/// @param mensaje[] char Es el mensaje a ser mostrado.
/// @param mensajeError[] char Es el mensaje a ser mostrado en caso de error.
/// @param limiteInferior char Limite inferior a validar.
/// @param limiteSuperior char Limite superior a validar.
/// @return int Si obtuvo el caracter devuelve [0] si no [-1].
int entrada_obtenerCaracter(char* entrada, char mensaje[], char mensajeError[], char limiteInferior, char limiteSuperior);

/// @brief VERIFICA SI ES UNA CADENA
///
/// @param mensaje[] char* El puntero a char que solicita el ingreso de una cadena
/// @param mensajeError[] char* El puntero a char que informa de un error
/// @param pCadena char* El puntero a char donde se guardar la cadena
/// @param longitud int El limite de la cadena
/// @return (-1) Error (0) OK
int entrada_obtenerCadena(char *pCadena, char mensaje[], char mensajeError[], int longitudLimite);

/// @brief FUNCION PREGUNTA AL USUARIO POR SI O NO
///
/// @param message[] char Pregunta al usuario.
/// @return int Si la respuesta es [S] o [Y] devuelve [1], Si responde [N] devuelve [0].
char entrada_respuestaUsuario(char message[]);

/// @brief EVALUA SI UNA CADENA INGRESADA ES UN NUMERO ENTERO
///
/// @param cadenaRecibida[] char Direccion de la cadena a evaluar.
/// @return int Si es un numero decimal retorna [1] si no [0].
int entrada_esNumero(char stringValue[]);

/// @brief VALIDA SI EL NUMERO INGRESADO ES UN NUMERO ENTERO
///
/// @param cadenaRecibida[] char
/// @param auxiliar[] char
/// @return int Si es un numero decimal retorna [1] si no [0].
int validarSiEsNumeroEntero (char cadenaRecibida[], char auxiliar[]);

/// @brief VALIDA SI UNA CADENA INGRESADA ES UN NUMERO FLOTANTE.
///
/// @param cadenaRecibida[] char Direccion de la cadena a evaluar.
/// @return int Si es un numero flotante retorna [1] si no [0].
int entrada_esFlotante(char cadenaRecibida[]);

/// @brief VALIDA SI SON SOLO LETRAS
///
/// @param pCadena char* El puntero a char que se recorre para corroborar si es alfabetico
/// @return (-1) Error (0) todo OK
int entrada_esLetras(char *pCadena);

/// @brief FUNCION PARA REMOVER EL SALTO DE LINEA DE LA CADENA
///
/// @param pCadena char* El puntero a char del cual sacar el salto de linea
/// @param longitud int El size limite de la cadena
/// @return (-1) Error (0)  OK
int myGets(char *pCadena, int longitud);

/// @brief FUNCION IMPRIME SEGUN TIPO DE NUMERO (ENTERO O FLOTANTE).
///
/// @param mensaje[] char Mensaje a imprimir antes del numero.
/// @param numero float Numero con o sin decimales a imprimir.
/// @return No retorna valores.
void entrada_imprimirTipoNumero(char mensaje[], float numero);


/// @brief FUNCION OBTIENE UNA CADENA ALFANUMERICA
///
/// @param requestMessage Es el mensaje a ser mostrado para solicitar el dato
/// @param requestMessage Es el mensaje a ser mostrado en caso de error
/// @param input Array donde se cargar· el texto ingresado
/// @return -
void entrada_obtenerCadenaAlfaNumerica(char mensaje[],char mensajeError[], char entrada[]);

/// @brief FUNCION SECUNDARIA A OBTENER CADENA ALFANUMERICA
///
/// @param mensaje Es el mensaje a ser mostrado
/// @param input Array donde se cargara el texto ingresado
/// @return 1 si el texto contiene solo letras y numeros
int obtenerCadenaAlfaNumerica(char mensaje[],char entrada[]);


/// @brief FUNCION SECUNDARIA A OBTENER CADENA
///
/// @param mensaje Es el mensaje a ser mostrado
/// @param input Array donde se cargar· el texto ingresado
/// @return void
void obtenerCadena(char mensaje[],char entrada[]);


/// @brief FUNCION SECUNDARIA VERIFICA SI LA CADENA TIENE LETRAS Y NUMEROS
///
/// @param str Array con la cadena a ser analizada
/// @return 1 si contiene solo espacio o letras y n˙meros, y 0 si no lo es

int esAlfaNumerico(char str[]);

#endif // INPUTS_H_INCLUDED
