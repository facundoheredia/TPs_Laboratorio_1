/// FUNCIONES ESPECIFICAS DEL TP N°1
///
///	@author Heredia Facundo
/// @date Abril 9 del 2022

#ifndef FUNCIONESTPUNO_H_
#define FUNCIONESTPUNO_H_

//	> FUNCION DE FORZAR CARGA
/// @brief Hardcodea los datos del punto 5 para ser calculados por las distintas funciones y ser mostrados
///
/// @param kilometros		-> Se estandarizan 7090 Km para ser mostrados
/// @param precioAerolineas	-> Se estandarizan $ 162965.00 como valor del vuelo y calcular en base a ellos
/// @param precioLatam		-> Se estandarizan $ 159339.00 como valor del vuelo y calcular en base a ellos

void cargaForzada (void);

//	> FUNCION PARA MOSTRAR MENSAJE QUE EVITA SEGUIR ADELANTE
/// @brief Funcion que emite mensaje si la bandera es verdadera para evitar que el usuario siga adelante y vuelva atras
///
/// @param flag	-> si la vandera pasada como parametro es 1 muestra el mensaje, si no, deja al usuario continuar

void mensajeDatosForzadosIngresados (int flag);

#endif /* FUNCIONESTPUNO_H_ */
