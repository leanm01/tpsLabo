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
#include "UTN.h"
#include "arrayPassenger.h"



int main(void) {

	setbuf(stdout, NULL);


	 int opcion;


	 do
	    {
	        opcion = menu();
	        switch(opcion)
	        {
	            case 1:




	                break;

	            case 2:


	                break;
	            case 3:



	            break;

	            case 4:




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
