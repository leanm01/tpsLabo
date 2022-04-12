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

    float ingresarNumeroKM=0;
    float ingresarNumeroAerolineas=0;
    float ingresarNumeroLatam=0;


    float kilometrosHardCode=7090;

    float precioAerolineasHardcode=162965;
    float debitoAeroHardcode=120255.66;
    float creditoAeroHardcode=150666.76;
    float bitcoinAeroHardcode=33.66;
    float precioUnitarioAeroHardcode=10799.88;

    float precioLatamHardcode=159339;
    float debitoLatamHardcode=120255.66;
    float creditoLatamHardcode=150666.76;
    float bitcoinLatamHardcode=33.66;
    float precioUnitarioLatamHardcode=10799.88;



    int opcion;
	int otraOpcion;

	do
	    {
	        opcion = menu();

	        switch(opcion)
	        {

	        	case 1:

	        			ingresarNumeroKM=ingresarKilometroPrecio(ingresarNumeroKM);


	            break;

	            case 2:
	            	do
	            	{
	            		otraOpcion = otroMenu();
	            		switch(otraOpcion)
	            		{

	            			case 1:

	            				if(ingresarNumeroKM == 0)
	            				{

	            					printf("\nNo hay kilometros ingresados aun...!!\n\n");

	            				}else
	            				{
	            					ingresarNumeroAerolineas=ingresarKilometroPrecio(ingresarNumeroAerolineas);

	            					if(ingresarNumeroAerolineas==-1)
	            					{

	            						 printf("\nOperacion erronea!!\n\n");

	            					}else
	                        	    {
	                        	         printf("\nOperacion exitosa!!\n\n");
	                        	    }


	            				}

	            			break;

	            			case 2:

	            				if(ingresarNumeroKM == 0)
	            			    {

	            					  printf("\nNo hay kilometros ingresados aun...!!\n\n");

	            			    }else
	            			    {
	            					  ingresarNumeroLatam=ingresarKilometroPrecio(ingresarNumeroLatam);

	            				      if(ingresarNumeroLatam==-1)
	            					  {

	            					        printf("\nOperacion erronea!!\n\n");

	            					  }else
	            					  {
	            					        printf("\nOperacion exitosa!!\n\n");
	            					  }


	            			    }

	            			break;

	            			case 3:
	            			    printf("\nSalida con exito\n");
	            			 break;



	            		}

	            	}while(otraOpcion!=3);




	                break;
	            case 3:


	            	if(ingresarNumeroKM == 0 || ingresarNumeroAerolineas==0 || ingresarNumeroLatam==0)
	            	{

	            		printf("\nNo hay kilometros y tampoco precios ingresados aun...!!\n\n");


	            	}
	            	else
	            	{

	            		funcionDescuento(ingresarNumeroAerolineas);
	            		funcionDescuento(ingresarNumeroLatam);

	            	    funcionInteres(ingresarNumeroAerolineas);
	            	    funcionInteres(ingresarNumeroLatam);

	            	    funcionBitcoin(ingresarNumeroAerolineas);
						funcionBitcoin(ingresarNumeroLatam);

						funcionPrecioUnitario(ingresarNumeroAerolineas, ingresarNumeroKM);
						funcionPrecioUnitario(ingresarNumeroLatam, ingresarNumeroKM);

						funcionDiferenciaPrecios(ingresarNumeroLatam,ingresarNumeroAerolineas);

	            	    if(ingresarNumeroAerolineas==-1 && ingresarNumeroLatam == -1)
	            	    {

	            	    	printf("\nOperacion erronea!!\n\n");

	            	    }
	            	    else
	            	    {
	            	    	printf("\nOperacion exitosa!!\n\n");
	            	    }

	            	}



	            break;

	            case 4:


	            	if(ingresarNumeroKM == 0 || ingresarNumeroAerolineas==0 || ingresarNumeroLatam==0)
	            	{


	            		printf("\nNo hay kilometros y tampoco precios ingresados aun...!!\n\n");


	            	}else
	            	{
	            		printf("\nAerolíneas: %.2f",ingresarNumeroAerolineas);
						printf("\nPrecio con tarjeta de débito: %.2f",funcionDescuento(ingresarNumeroAerolineas));
						printf("\nPrecio con tarjeta de crédito: %.2f",funcionInteres(ingresarNumeroAerolineas));
						printf("\nPrecio pagando con bitcoin: %.2f BTC",funcionBitcoin(ingresarNumeroAerolineas));
						printf("\nPrecio unitario: %.2f \n ",funcionPrecioUnitario(ingresarNumeroAerolineas, ingresarNumeroKM));

	            		printf("\nLatam: %.2f",ingresarNumeroLatam);
	            	    printf("\nPrecio con tarjeta de débito: %.2f",funcionDescuento(ingresarNumeroLatam));
	            	    printf("\nPrecio con tarjeta de crédito: %.2f",funcionInteres(ingresarNumeroLatam));
	            	    printf("\nPrecio pagando con bitcoin: %.2f BTC",funcionBitcoin(ingresarNumeroLatam));
	            		printf("\nPrecio unitario: %.2f \n ",funcionPrecioUnitario(ingresarNumeroLatam, ingresarNumeroKM));



	            	    printf("\nLa diferencia de precio es: %.2f \n ",funcionDiferenciaPrecios(ingresarNumeroAerolineas, ingresarNumeroLatam));

	            	    if(ingresarNumeroAerolineas==-1 && ingresarNumeroLatam == -1 && ingresarNumeroKM==-1)
	            	   	{

	            	   	      printf("\nOperacion erronea!!\n\n");

	            	   	}
	            	   	else
	            	    {
	            	   	      printf("\nOperacion exitosa!!\n\n");
	            	    }

	            	}




	            break;

	            case 5:


	            	printf("\nAerolíneas: %.2f",precioAerolineasHardcode);
					printf("\nPrecio con tarjeta de débito: %.2f",funcionDescuento(debitoAeroHardcode));
					printf("\nPrecio con tarjeta de crédito: %.2f",funcionInteres(creditoAeroHardcode));
					printf("\nPrecio pagando con bitcoin: %.2f BTC",funcionBitcoin(bitcoinAeroHardcode));
					printf("\nPrecio unitario: %.2f \n ",funcionPrecioUnitario(precioUnitarioAeroHardcode, kilometrosHardCode));

	                printf("\nLatam: %.2f",precioLatamHardcode);
	                printf("\nPrecio con tarjeta de débito: %.2f",funcionDescuento(debitoLatamHardcode));
	                printf("\nPrecio con tarjeta de crédito: %.2f",funcionInteres(creditoLatamHardcode));
	                printf("\nPrecio pagando con bitcoin: %.2f BTC",funcionBitcoin(bitcoinLatamHardcode));
	                printf("\nPrecio unitario: %.2f \n ",funcionPrecioUnitario(precioUnitarioLatamHardcode, kilometrosHardCode));



		    		printf("\nLa diferencia de precio es: %.2f \n ",funcionDiferenciaPrecios(precioAerolineasHardcode, precioLatamHardcode));

	            break;

	            case 6:
	            	printf("\nGracias por usar el programa...\n");
	            break;
	        }


	    }while(opcion!=6);


	return EXIT_SUCCESS;
}
