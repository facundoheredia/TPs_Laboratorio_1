# tp_laboratorio_1


===========================================================================
 
## TRABAJO PRACTICO N°1

Programación I – Laboratorio I

Tecnicatura Superior en Programacion - UTN-FRA



- **AUTORES:** MARINA CARDOZO
- **REVISORES:** LAURA CARELLI
- **ALUMNO:**	HEREDIA FACUNDO
- **DIVISION:**	1F - C1 - 2022

===========================================================================

**ENUNCIADO**
```
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
```
**MENU PRINCIPAL DEL PROGRAMA**
```
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
```
**ACLARACIONES DEL FUNCIONAMIENTO**
```
El menú se tiene que ver tal cual está descrito en la consigna. Los resultados se tienen que
mostrar con el mismo formato. Se puede realizar un submenú para ingresar los km y los
precios.
Los resultados se tienen que ver con el formato presentado en el menú.

```

===========================================================================
 
## TRABAJO PRACTICO N°2

Programación I – Laboratorio I

Tecnicatura Superior en Programacion - UTN-FRA



- **AUTORES:** MARINA CARDOZO
- **REVISORES:** LAURA CARELLI
- **ALUMNO:**	HEREDIA FACUNDO
- **DIVISION:**	1F - C1 - 2022

===========================================================================
**ENUNCIADO**
```
Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.
```
**MENU PRINCIPAL DEL PROGRAMA**
```
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
```
**ACLARACIONES DEL FUNCIONAMIENTO**
```
1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.

Para la realización de este programa, se utilizará una biblioteca llamada “ArrayPassenger” que
facilitará el manejo de la lista de pasajeros y su modificación. En la sección siguiente se
detallan las funciones que esta biblioteca debe tener.

```
