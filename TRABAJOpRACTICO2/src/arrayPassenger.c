/*
 * arrayPassenger.c
 *
 *  Created on: 19 abr. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "arrayPassenger.h"

int initPassengers(Passenger* list, int len)
{

	int i;
	int retorno=-1;

	if(len!=0)
	{

		for(i=0;i<len;i++)
		{

			list[i].isEmpty=1;
			return 0;

		}


	}



    return retorno;
}

int addPassenger(Passenger* list, int len, int contador)
{

	  int resultado=0;
	  int espacioLibre=-1;
	  int i;


	  if(len > 0)
	  {

		  for(i=0;i<len;i++)
		  {

			  if(list[i].isEmpty==1)
			  {


				  espacioLibre=i;
				  break;


			  }




		  }



	  }

	  if(espacioLibre>=0)
	  {


		   utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",list[espacioLibre].name,2,51);

		   utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",list[espacioLibre].lastName,2,51);

		   utn_getFloat("\nIngrese el Precio: ","\nIngresa un valor correcto 0-99999: ",&list[espacioLibre].price,2,99999,0);

		   utn_getNombre("\nIngrese el Codigo de vuelo(no Numerico): ","\nIngrese un codigo correcto: ",list[espacioLibre].flycode,10,2);//getNombre lo uso por el char

		   utn_getInt("\nIngrese el tipo de pasajero: ","\nIngresa un valor correcto 0-999: ",&list[espacioLibre].typePassenger,2,999,0);


		   list[espacioLibre].id=contador+1;
		   list[espacioLibre].isEmpty=0;


		    resultado=1;



	  }




   return resultado;
}

int findPassengerById(Passenger* list, int len,int id)
{
return 0;
}

int removePassenger(Passenger* list, int len, int id)
{
return -1;
}

int sortPassengers(Passenger* list, int len, int order)
{
return 0;
}

int printPassengers(Passenger* list, int length)
{

	int i;
	int resultado=-1;

	if(list != NULL && length >=0)
	{

		for(i=0;i<length;i++)
		{

			if(list[i].isEmpty==0)
			{

				printPassenger(list, i);


			}


		}

		resultado=1;

	}



return resultado;
}
int printPassenger(Passenger* list, int i)
{


	printf("\nNOMBRE:%s---APELLIDO:%s---PRECIO:%f---CODIGO:%d---TIPO:%d---ID:%d\n",         list[i].name,
																							list[i].lastName,
																							list[i].price,
																							list[i].flycode,
																							list[i].typePassenger,
																							list[i].id);


	return 1;




}


int sortPassengersByCode(Passenger* list, int len, int order)
{
return 0;
}
