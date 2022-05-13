#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "UTN.h"
#include "arrayPassenger.h"



void initAlumnosConDatos(Passenger list[])
{

	Passenger auxLista[5]={{101,"Pepe","Gonzales",18000,"ty",5},
							{102,"Rodrigo","Collins",25000,"xe",2},
							{103,"Matias","Xeller",24000,"po",7},
							{104,"Jose","Rodriguez",10000,"er",1},
							{105,"Marcos","Millan",20000,"mn",6}};



    int i;

    for (i=0; i<5; i++)
    {
    	list[i]=auxLista[i];
		list[i].isEmpty = 0; // OCUPADO.
    }
}
int initPassengers(Passenger* list, int len)
{

	int i;
	int retorno=-1;

	if(len!=0)
	{

		for(i=0;i<len;i++)
		{

			list[i].isEmpty=1;
			retorno=0;

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

		   utn_getFloat("\nIngrese el Precio: ","\nIngresa un valor correcto 0-99999: ",&list[espacioLibre].price,2,99999,2);

		   utn_getNombre("\nIngrese el Codigo de vuelo(no Numerico): ","\nIngrese un codigo correcto: ",list[espacioLibre].flycode,2,10);

		   utn_getInt("\nIngrese el tipo de pasajero: ","\nIngresa un valor correcto 0-999: ",&list[espacioLibre].typePassenger,2,999,2);


		   list[espacioLibre].id=contador+1;
		   list[espacioLibre].isEmpty=0;


		    resultado=1;



	  }




   return resultado;
}


int removePassenger(Passenger* list, int len)
{
    int aux;
    char auxChar;
    int i;
    int resultado = 0;

    printPassengers(list,len);

    utn_getInt("\nIngrese el ID  del pasajero que quiere dar de baja: ","\nIngresa un valor correcto 0-999: ",&aux,2,999,0);

    for(i=0;i<len;i++)
    {
        if(aux==list[i].id && list[i].isEmpty==0)
        {
        	printPassenger(list,i);
            utn_getChar("\nDesea elimnar este pasajero(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

            if(auxChar=='s')
            {
            	list[i].isEmpty=1;
                resultado=1;
                break;
            }
        }
    }
    return resultado;
}

int modifiyPassenger(Passenger* list, int len)
{

	 int retorno=-2;
	 int opcionMod;
	 int i;
	 int aux;
	 char auxChar;


	 printPassengers(list, len);

	 utn_getInt("\nIngrese el ID  del pasajero que quiera modificar: ","\nIngresa un valor correcto 0-999: ",&aux,2,999,0);


	 if(len > 0 && list != NULL)
	 {
	      for(i=0;i<len;i++)
	      {
	            if(aux==list[i].id && list[i].isEmpty==0)
	            {
	            	printPassenger(list,i);
	                utn_getChar("\nDesea modificar este pasajero(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

	                 if(auxChar=='s')
	                 {
	                     opcionMod=modificar();

	                     switch(opcionMod)
	                     {
	                             case 1:
	                         	     utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",list[i].name,2,51);
	                                 break;
	                             case 2:
	                         	     utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",list[i].lastName,2,51);
	                                 break;
	                             case 3:
	                            	 utn_getFloat("\nIngrese el precio: ","\nIngresa un valor correcto 0-99999: ",&list[i].price,2,99999,2);
	                                 break;
	                             case 4:
	                            	 utn_getNombre("\nIngrese el codigo: ","\nIngresa un valor correcto 0-999: ",list[i].flycode,2,10);
	                                 break;
	                             case 5:
	                            	 utn_getInt("\nIngrese el Tipo de pasajero: ","\nIngresa un valor correcto 0-99999: ",&list[i].typePassenger,2,99999,2);
	                             	 break;

	                     }
	                     retorno=1;
	                     break;
	                }
	            }
	       }

	  }

	return retorno;
}
int sortPassengers(Passenger* list, int len)
{

	Passenger auxiliarPassenger;

	int i;
	int j;
	int retorno=0;

	if(list != NULL && len >=0)
	{

		for(i=0;i < len ;i++)
		{


			for(j=0;j < len ;j++)
			{


				if(strcmp(list[i].lastName,list[j].lastName) > 0 || (strcmp(list[i].lastName,list[j].lastName) == 0 ))
				{

					auxiliarPassenger=list[i];
					list[i]=list[j];
					list[j]=auxiliarPassenger;
					retorno=1;
				}
			}

		}

	}

	return retorno;
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


	printf("\nNOMBRE:%s---APELLIDO:%s---PRECIO:%.2f---CODIGO:%s---TIPO:%d---ID:%d\n",       list[i].name,
																							list[i].lastName,
																							list[i].price,
																							list[i].flycode,
																							list[i].typePassenger,
																							list[i].id);


	return 1;




}
void totalAverage(Passenger* list, int len)
{
    int contador=0;
    int contadorPromedio=0;
    float pricePromedio=0;
    float price=0;

    for (int i=0;i<len;i++)
        {
            if (list[i].isEmpty==0)
            {
            	price = price + list[i].price;
                contador++;
            }

        }

    pricePromedio = price / contador;

      for (int i=0;i<len;i++)
        {
            if (list[i].isEmpty==0 && list[i].price >= pricePromedio)
            {
                contadorPromedio++;
            }

        }

    printf("\nEl salario promedio es:%.2f\n",pricePromedio);
    printf("\nLa cantidad de empleados que superan el salario promedio son:%d\n",contadorPromedio);


}
