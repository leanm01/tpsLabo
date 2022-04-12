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

	            		printf("\nLatam: %.2f",ingresarNumeroLatam);
	            	    printf("\nPrecio con tarjeta de débito: %.2f",funcionDescuento(ingresarNumeroLatam));
	            	    printf("\nPrecio con tarjeta de crédito: %.2f",funcionInteres(ingresarNumeroLatam));
	            	    printf("\nPrecio pagando con bitcoin: %.2f BTC",funcionBitcoin(ingresarNumeroLatam));
	            		printf("\nPrecio unitario: %.2f \n ",funcionPrecioUnitario(ingresarNumeroLatam, ingresarNumeroKM));

	            		printf("\nAerolíneas: %.2f",ingresarNumeroAerolineas);
	            		printf("\nPrecio con tarjeta de débito: %.2f",funcionDescuento(ingresarNumeroAerolineas));
	            		printf("\nPrecio con tarjeta de crédito: %.2f",funcionInteres(ingresarNumeroAerolineas));
	            	    printf("\nPrecio pagando con bitcoin: %.2f BTC",funcionBitcoin(ingresarNumeroAerolineas));
	            	    printf("\nPrecio unitario: %.2f \n ",funcionPrecioUnitario(ingresarNumeroAerolineas, ingresarNumeroKM));

	            	    printf("\nLa diferencia de precio es: %.2f \n ",funcionDiferenciaPrecios(ingresarNumeroLatam, ingresarNumeroAerolineas));

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

	            break;

	            case 6:
	            	printf("\nGracias por usar el programa...\n");
	            break;
	        }


	    }while(opcion!=6);


	return EXIT_SUCCESS;
}
