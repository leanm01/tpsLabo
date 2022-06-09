#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN.h"
#include "Controller.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

	int finalizar=0;
	int valor=0;

	LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {

        switch(menu())
        {
            case 1:
            	if(valor==0)
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
            		printf("se cargaron los usuarios correctamente!!!\n");
            		valor++;
            	}else
					printf("ya se cargaron los usuarios!!!\n");
                break;

            case 2:
            	if(valor==0)
            	{
            		controller_loadFromBinary("data.bin",listaEmpleados);
            		printf("se cargaron los usuarios correctamente!!!\n");
            		valor++;
            	}else
            		printf("Ya se cargaron los usuarios!!!\n");

                break;

            case 3:
            	if(valor!=0)
            	{
            	controller_addEmployee(listaEmpleados);
            	valor++;
            	}else
            		printf("Se deben cargar los usuarios!!!\n");
                break;

            case 4:
            	if(valor!=0)
            	{
            	controller_editEmployee(listaEmpleados);
            	valor++;
            	}else
            		printf("Se deben cargar los usuarios!!!\n");
                break;

            case 5 :
            	if(valor!=0)
            	{
            	controller_removeEmployee(listaEmpleados);
            	valor++;
            	}else
            		printf("Se deben cargar los usuarios!!!\n");
            	break;

            case 6 :
            	if(valor!=0)
            	{
            	controller_ListEmployee(listaEmpleados);
            	valor++;
            	}else
            		printf("Se deben cargar los usuarios!!!\n");
            	break;

            case 7 :
            	if(valor!=0)
            	{
            	controller_sortEmployee(listaEmpleados);
            	valor++;
            	}else
            		printf("Se deben cargar los usuarios!!!\n");
            	break;

            case 8 :
            	if(valor!=0)
            	{
            	controller_saveAsText("data.csv",listaEmpleados);
            	valor++;
            	}else
            		printf("Se deben cargar los usuarios!!!\n");
            	break;

            case 9 :
            	if(valor!=0)
            	{
            	controller_saveAsBinary("data.bin",listaEmpleados);
            	valor++;
            	}else
            		printf("Se deben cargar los usuarios!!!\n");
                break;

            case 10 :
            	finalizar=1;
            	break;

        }
    }while(finalizar==0);
    return 0;
}

