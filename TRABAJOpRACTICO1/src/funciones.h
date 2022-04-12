/*
 * funciones.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Leandro
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * \brief permite el ingreso de un numero
 * \param float de un dato ingresado
 * \
 * \return retorna el dato ingresado
 *
 */
float ingresarKilometroPrecio(float dato);

/**
 * \brief 	permite hacer un descuento
 * \param   float de un dato

 * \return retorna el descuento realizado
 *
 */
float funcionDescuento(float dato);

/**
 * \brief 	realiza un interes
 * \param   float de un dato

 * \return  retorna el interes realizado
 *
 */
float funcionInteres(float dato);

/**
 * \brief divide el dato ingreasado con el valor del bitcoin
 * \param float de un dato

 * \return retorna la division
 *
 */
float funcionBitcoin(float dato);

/**
 * \brief divide el dato y los kilometros ingresados
 * \param float de un dato y del kilometro ingresado

 * \return retorna la cuenta realizada
 *
 */
float funcionPrecioUnitario(float dato, float kilometro);

/**
 * \brief resta los precios latam y aerolineas
 * \param float de los precios latam y aerolineas

 * \return retorna la diferencia de los precios
 *
 */
float funcionDiferenciaPrecios(float datoLatam, float datoAerolineas);


#endif /* FUNCIONES_H_ */
