/*
 ============================================================================
 Name        : TRABAJOpRACTICO2.c
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
#include "arrayPassenger.h"
#define TAM 5


int main(void) {

	setbuf(stdout, NULL);




	 Passenger listado[TAM];
	 initPassengers(listado, TAM);

	 int contadorId=0;
	 int opcion;
	 int estadoAlta;
	 int estadoBaja;
	 int hayPasajero=0;


	 do
	    {
	        opcion = menu();
	        switch(opcion)
	        {
	            case 1:

	            	estadoAlta = addPassenger(listado, TAM, contadorId);

	            	if(estadoAlta==-1)
	            	{

	            		printf("\nAlta pasajero erronea!!\n\n");

	            	}else
	            	{

	            		printf("\nAlta pasajero exitosa!!\n\n");
	            		contadorId++;
	            		hayPasajero=1;

	            	}


	                break;

	            case 2:

	            	if(hayPasajero==0)
	            	{

	            		printf("\nNo hay pasajeros que mostrar!!\n\n");

	            	}else
	            	{

	            		estadoBaja=printPassengers(listado, TAM);

	            		 if (estadoBaja==-1)
	            		 {
							printf("\nOperacion erronea!!\n\n");

						 }
				         else
						 {
							printf("\nOperacion exitosa!!\n\n");
			             }


	            	}


	                break;
	            case 3:
	            	if(hayPasajero==0)
	                {

	            		 printf("\nNo hay pasajeros que modificar!!\n\n");

	                }else
	                {

	                	estadoBaja=modifiyPassenger(listado, TAM);

	            		if(estadoBaja==-1)
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
	            	if(hayPasajero==0)
	            	{

	            		  printf("\nNo hay pasajeros que eliminar!!\n\n");

	                }else
	                {

	            		  estadoBaja=removePassenger(listado, TAM);

	            		  if(estadoBaja==-1)
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


	                switch (informes())
	                {

	                      case 1:






	                             break;

	                      case 2:





	                             break;
	                       case 3:

	                    	   printf("\nSalir\n");
	                    	   break;

	              }

	            break;

	            case 6:
	            	printf("\nGracias por usar el programa...\n");
	            break;
	        }


	    }while(opcion!=6);


	return EXIT_SUCCESS;
}
