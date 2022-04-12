/*
 * funciones.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Leandro
 */

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

float ingresarKilometroPrecio(float dato)
{
    printf("\nPor favor, ingresar un numero: ");
    fflush(stdin);
    scanf("%f",&dato);


    return dato;

}

float funcionDescuento(float dato)
{

	float sacarPorcentaje;

	sacarPorcentaje = dato *10/100;

    return sacarPorcentaje;
}

float funcionInteres(float dato)
{


	float sacarInteres;

	sacarInteres = (dato * 25/100) + dato;

	return sacarInteres;

}

float funcionBitcoin(float dato)
{

	float datoBitcoin;

	datoBitcoin = dato/4606954.55;

    return datoBitcoin;



}

float funcionPrecioUnitario(float dato, float kilometro)
{

	float precioUnitario;

	precioUnitario = dato/kilometro;

	return precioUnitario;
}

float funcionDiferenciaPrecios(float datoLatam, float datoAerolineas)
{

	float diferenciaPrecios;

	diferenciaPrecios = datoLatam - datoAerolineas;

	return diferenciaPrecios;
}

