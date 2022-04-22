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

int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[])
{


return -1;
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

int printPassenger(Passenger* list, int length)
{
return 0;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
return 0;
}
