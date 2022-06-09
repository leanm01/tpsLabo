#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "Employee.h"
#include "Controller.h"

Employee* employee_new()
{
		Employee* new= (Employee*)malloc(sizeof(Employee));
        return new ;

}

void employee_delete(Employee* this)
{
	free(this);
}

void printEmployee(Employee* pEmpleado)
{
     int  auxId;
	 char auxNombre[128];
	 int  auxHorasTrabajadas;


	employee_getId(pEmpleado,&auxId);
	employee_getNombre(pEmpleado,auxNombre);
	employee_getHorasTrabajadas(pEmpleado,&auxHorasTrabajadas);

    printf("%4d %13s %14d\n", auxId, auxNombre, auxHorasTrabajadas);


}


int employee_setId(Employee* this,int id)
{

	int retorno=0;
	if(id>0 && this!=NULL)
		{
			this->id=id;
			retorno=1;
		}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{

	int retorno=0;
	if(id!=NULL && this!=NULL)
	 	 {
			*id=this->id;
			retorno=1;
	 	 }
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{

	int retorno=0;
    if(nombre>0 && this!=NULL)
		{
			strcpy(this->nombre,nombre);
			retorno=1;
		}
		return retorno;


}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=0;
	if(nombre!=NULL && this!=NULL)
		{
			strcpy(nombre,this->nombre);
			retorno=1;
		}
	return retorno;



}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

	int retorno=0;
	if(horasTrabajadas>0 && this!=NULL)
			{
			    this->horasTrabajadas=horasTrabajadas;
				retorno=1;
			}
	return retorno;



}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

	    int retorno=0;
		if(horasTrabajadas!=NULL && this!=NULL)
			{
				*horasTrabajadas=this->horasTrabajadas;
				retorno=1;
			}
		return retorno;



}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{

	Employee* this = employee_new();

    if(this != NULL)
    {
           if(   employee_setId(this,atoi(idStr))   != -1 &&
        		 employee_setNombre(this,nombreStr) != -1 &&
        		 employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) != -1)
                {
                      return this;
                }
    }
    return this;
}

int employee_sortID(void* employeeUno, void* employeeDos)
{
    int retorno=0;
	int auxUno;
	int auxDos;


	if(employeeUno!=NULL && employeeDos!=NULL)
	{
	employee_getId(employeeUno,&auxUno);
    employee_getId(employeeDos,&auxDos);
    return auxUno-auxDos;
    }

    return retorno;
}

int employee_sortName(void* employeeUno, void* employeeDos)
{
    int  retorno=0;
    char auxUno[128];
	char auxDos[128];

    employee_getNombre(employeeUno,auxUno);
    employee_getNombre(employeeDos,auxDos);

     if(strcmp(auxUno,auxDos)>0)
        {
        	retorno = 1;
        }
        else if(strcmp(auxUno,auxDos)==0)
         {
        	retorno = 0;
         }
         else
          {
        	 retorno = -1;
          }

        return retorno;
}
