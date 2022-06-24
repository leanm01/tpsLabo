/*
 ============================================================================
 Name        : TRABAJOpRACTICO1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "funciones.h"


int main(void) {

	setbuf(stdout, NULL);

	float Kilometros = 0;
	float NumeroAerolineas=0;
	float NumeroLatam=0;

	float debitoAero;
	float debitoLat;

	float creditoAero;
	float creditoLat;

	float bitcoinAero=0;
	float bitcoinLat=0;

	float precioKmAero;
	float precioKmLat;

	float diferenciaPrecios;

	//HARDCODEO
	float kilometrosHardCode=7090 ;
	float precioAerolineasHardcode=162965;
	float precioLatamHardcode=159339;

	float HardCodeDebitoAero;
	float HardCodeDebitoLat;

	float HardCodeCreditoAero;
	float HardCodeCreditoLat;

	float HardCodeBitcoinAero;
	float HardCodeBitcoinLat;




	int opcion;
	int otraOpcion;

	do
	    {

				printf("1) Ingrese kilómetros: (KM = %f) \n", Kilometros);
				printf("2) Ingrese precio de vuelos: (AEROLINEAS = %f, LATAM = %f) \n", NumeroAerolineas, NumeroLatam);
				printf("3) Calcular los costos: \n");
				printf("4) Informe de resultados: \n");
				printf("5) Carga forzada de datos: \n");
				printf("6) Salir. \n");
				fflush(stdout);
				scanf("%i", &opcion);

	        switch(opcion)
	        {

	        	case 1:

	        		Kilometros=ingresarKilometroPrecio(Kilometros);


	            break;

	            case 2:
	            	do
	            	{
	            		otraOpcion = otroMenu();
	            		switch(otraOpcion)
	            		{

	            			case 1:

	            				if(Kilometros == 0)
	            				{

	            					printf("\nNo hay kilometros ingresados aun...!!\n\n");

	            				}else
	            				{
	            					NumeroAerolineas=ingresarKilometroPrecio(NumeroAerolineas);

	            				}

	            			break;

	            			case 2:

	            				if(Kilometros == 0)
	            			    {

	            					  printf("\nNo hay kilometros ingresados aun...!!\n\n");

	            			    }else
	            			    {
	            			    	NumeroLatam=ingresarKilometroPrecio(NumeroLatam);

	            			    }

	            			break;

	            			case 3:
	            			    printf("\nSalida con exito\n");
	            			 break;



	            		}

	            	}while(otraOpcion!=3);




	                break;
	            case 3:


	            	if(Kilometros == 0 || NumeroAerolineas==0 || NumeroLatam==0)
	            	{

	            		printf("\nNo hay kilometros y tampoco precios ingresados aun...!!\n\n");


	            	}
	            	else
	            	{

	            		debitoAero=funcionDescuento(NumeroAerolineas);
	            		debitoLat=funcionDescuento(NumeroLatam);

	            		creditoAero=funcionInteres(NumeroAerolineas);
	            		creditoLat=funcionInteres(NumeroLatam);

	            		bitcoinAero= funcionBitcoin(NumeroAerolineas);
	            		bitcoinLat=funcionBitcoin(NumeroLatam);

						precioKmAero= funcionPrecioUnitario(NumeroAerolineas, Kilometros);

						printf("Precio por km de Aerolineas: $ %f \n", precioKmAero);

						precioKmLat= funcionPrecioUnitario(NumeroLatam, Kilometros);

						printf("Precio por km de Latam: $ %f \n", precioKmLat);



						diferenciaPrecios= funcionDiferenciaPrecios(NumeroLatam,NumeroAerolineas);

						printf("La diferencia de precios entre Aerolineas y Latam es de: $ %f \n", diferenciaPrecios);



	            	}



	            break;

	            case 4:


	            	if(Kilometros == 0 || NumeroAerolineas==0 || NumeroLatam==0)
	            	{


	            		printf("\nNo hay kilometros y tampoco precios ingresados aun...!!\n\n");


	            	}else
	            	{
	            		printf("\nKilometros: %f",Kilometros);

	            		printf("\nAerolíneas: %.2f",NumeroAerolineas);
						printf("\nPrecio con tarjeta de débito: %.2f",debitoAero);
						printf("\nPrecio con tarjeta de crédito: %.2f",creditoAero);
						printf("\nPrecio pagando con bitcoin: %.2f BTC",bitcoinAero);
						printf("\nPrecio unitario: %.2f \n ",precioKmAero);

	            		printf("\nLatam: %.2f",NumeroLatam);
	            	    printf("\nPrecio con tarjeta de débito: %.2f",debitoLat);
	            	    printf("\nPrecio con tarjeta de crédito: %.2f",creditoLat);
	            	    printf("\nPrecio pagando con bitcoin: %.2f BTC",bitcoinLat);
	            		printf("\nPrecio unitario: %.2f \n ",precioKmLat);

	            		printf("\nLa diferencia de precio es: %.2f \n ",diferenciaPrecios);


	            	}




	            break;

	            case 5:



	            	HardCodeDebitoAero = funcionDescuento(NumeroAerolineas);
	            	HardCodeDebitoLat = funcionDescuento(NumeroLatam);

	            	HardCodeCreditoAero = funcionInteres(NumeroAerolineas);
	            	HardCodeCreditoLat = funcionInteres(NumeroLatam);

	            	HardCodeBitcoinAero = funcionBitcoin (NumeroAerolineas);
	            	HardCodeBitcoinLat = funcionBitcoin(NumeroLatam);





	            	printf("\nKilometros: %.2f",kilometrosHardCode);

	            	printf("\nAerolíneas: %.2f",precioAerolineasHardcode);
					printf("\nPrecio con tarjeta de débito: %.2f",HardCodeDebitoAero);
					printf("\nPrecio con tarjeta de crédito: %.2f",HardCodeCreditoAero);
					printf("\nPrecio pagando con bitcoin: %.2f BTC",HardCodeBitcoinAero);
					printf("\nPrecio unitario: %.2f \n ",precioKmAero);

	                printf("\nLatam: %.2f",precioLatamHardcode);
	                printf("\nPrecio con tarjeta de débito: %.2f",HardCodeDebitoLat);
	                printf("\nPrecio con tarjeta de crédito: %.2f",HardCodeCreditoLat);
	                printf("\nPrecio pagando con bitcoin: %.2f BTC",HardCodeBitcoinLat);
	                printf("\nPrecio unitario: %.2f \n ",precioKmLat);



		    		printf("\nLa diferencia de precio es: %.2f \n ",diferenciaPrecios);

	            break;

	            case 6:
	            	printf("\nGracias por usar el programa...\n");
	            break;
	        }


	    }while(opcion!=6);


	return EXIT_SUCCESS;
}
