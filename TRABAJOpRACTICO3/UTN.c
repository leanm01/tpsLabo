/*
 * UTN.c
 *
 *  Created on: 8 jun. 2022
 *      Author: Leandro
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

int getInt(char text[])
{
    int option;
    fflush(stdin);
    printf("%s",text);
    scanf("%d",&option);

    return option;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    gets(input);
}

int menu()
{
	int opcion=0;

    printf("1) Cargar datos de forma de texto (data.csv)\n");
	printf("2) Cargar datos de forma binaria (data.bin)\n");
	printf("3) Alta empleado\n");
	printf("4) Modificar empleado\n");
	printf("5) Baja empleado\n");
	printf("6) Listar empleados\n");
	printf("7) Ordenar empleados\n");
	printf("8) Guardar los datos en forma de texto (data.csv)\n");
	printf("9) Guardar los datos de forma binaria (data.bin)\n");
	printf("10) Salir\n");
	printf("\n\ningrese la opcion: ");
	fflush(stdin);
    scanf("%d",&opcion);
    fflush(stdin);

    return opcion;
}

int utn_getChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 )
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin); // fflush // __fpurge
			resultadoScanf = scanf("%c" , &bufferChar);
			if(resultadoScanf == 1 && (bufferChar == 's' || bufferChar == 'n'))
			{
				retorno = 0;
				*pResultado = bufferChar;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
