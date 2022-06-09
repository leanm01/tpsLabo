#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{


	int retorno=0;
	int len;

		if(pFile!=NULL)
		{
			char id[128];
			char nombre[128];
			char horasTrabajadas[128];
			char sueldo[128];

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			do
			{
				len = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n ",id,nombre,horasTrabajadas,sueldo);
				if (len==4)
				{
					  Employee* pEmpleado=employee_new();
					  if(pEmpleado!=NULL)
					  {

						  pEmpleado=employee_newParametros(id,nombre,horasTrabajadas);

						  ll_add(pArrayListEmployee,pEmpleado);
					  }
				}
			}
			while(!feof(pFile));

			retorno=1;

		}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	 int retorno=0;

		 if(pFile!=NULL)
		 {

			 Employee* pEmpleado;
		     while(!feof(pFile))
		     {

		    	 pEmpleado=employee_new();

		         if(fread(pEmpleado, sizeof(Employee),1,pFile)==1)
		         {
		               ll_add(pArrayListEmployee,pEmpleado);
		         }
		     }

		        retorno=1;
		 }

    return retorno;
}
