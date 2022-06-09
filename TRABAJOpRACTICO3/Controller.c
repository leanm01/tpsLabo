#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	 FILE* pArchivo;

	 pArchivo=fopen(path,"r");

	 if(pArchivo!=NULL)
	 {
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
	 }
	 fclose(pArchivo);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	 FILE* pArchivo;

	 pArchivo=fopen(path,"rb");

	 if(pArchivo!=NULL)
	 {

		 parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

	 }
	 fclose(pArchivo);


    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{


	Employee* NuevoEmployee = employee_new();

		int retorno = 0;


		char auxId[100];
		char auxNombre[100];
		char auxHorasTrabajadas[100];


		int getId;
		int len;
	    int unAux;

	    len = ll_len(pArrayListEmployee);

		    if(pArrayListEmployee != NULL)
		    {
		        getId = getInt("\nIngrese id: ");
		        itoa(getId, auxId, 10);

		        for(int i=0;i<len;i++)
		        {
		        	NuevoEmployee = (Employee*) ll_get(pArrayListEmployee,i);
		        	employee_getId(NuevoEmployee,&unAux);

		            if(getId == unAux)
		            {
		                printf("este ID ya esta en uso!!\n");
		                retorno = 1;

		                break;
		            }
		        }
		        if(getId != unAux)
		        {
		            getString("Ingrese un nombre: ", auxNombre);
		            getString("Ingrese las horas: ", auxHorasTrabajadas);


		            NuevoEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas);

		            ll_add(pArrayListEmployee, NuevoEmployee);
		            printf("\nSe cargo correctamente al empleado\n");
		        }
		    }

		    return retorno;



}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	Employee* auxEmpleado = employee_new();

		 int retorno=0;

		 int  auxId;
		 char auxNombre[100];
		 int  auxHorasTrabajadas;
		 int  i;
		 int  len;
		 int  opcion = 0;
		 int  unAux;

		 len = ll_len(pArrayListEmployee);


		 if(pArrayListEmployee !=NULL)
		 {

			 controller_ListEmployee(pArrayListEmployee);

			 auxId =getInt("\nIngrese id del empleado para modificar: ");

			 for(i=0; i<len; i++)
			 {
				 auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
				 employee_getId(auxEmpleado,&unAux);
				 if(auxId == unAux)
				 {

					 do
					 {
						 opcion =getInt("\n1.Nombre-\n2.Horas trabajadas-\n3.Salir-\nIngresar una opcion: ");

						 switch(opcion)
						 {
						 	 case 1:
								getString("\nIngresar el nombre del empleado: ",auxNombre);
								employee_setNombre(auxEmpleado, auxNombre);
								break;
							case 2:
								auxHorasTrabajadas =getInt("Ingresar las horas de trabajo: ");
								employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas);
								break;

							default:
								printf("\n Ingresar la opcion correcta: \n");
								break;
						}

					}
					while(opcion != 3);
				 }
			}

		}

	   return retorno;


}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	int retorno = 0;
	int idEmpleado;
	char auxChar;

		    if(pArrayListEmployee != NULL)
		    {
		    	controller_ListEmployee(pArrayListEmployee);

		    	printf("\nIngrese el usuario que quiere eliminar: ");
		    	fflush(stdin);
		    	scanf("%d",&idEmpleado);

		    	utn_getChar("\nDesea elimnar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

		    	if(auxChar=='s')
		    	{
		    		ll_remove(pArrayListEmployee, controller_FindId(pArrayListEmployee,idEmpleado));
		    		printf("\nSe elimino el id:%d \n",idEmpleado);
		        }
		    	else
		    	{
		    		printf("\nNO se elimino el id:%d \n",idEmpleado);

		    	}

	            retorno = 0;


		    }
		    return retorno;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

	 int  len = ll_len(pArrayListEmployee);

	 Employee* pEmpleado=employee_new();

		 if(pEmpleado !=NULL && len >0 && pArrayListEmployee != NULL )
		 {
			printf("---ID---|---NOMBRE---|---HORAS TRABAJADAS\n");
			for(int i=0 ;i<len;i++)
			{

				pEmpleado=ll_get(pArrayListEmployee,i);

				printEmployee(pEmpleado);

	        }


		 }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	 int retorno=0;
	 int option;

		    if(pArrayListEmployee != NULL)
		    {
		        option = getInt("\n1. Ordenar por ID\n2. Ordenar por Nombre\n3. salir\nIngrese una opcion: ");


		        switch(option)
		        {
		            case 1:
		                ll_sort(pArrayListEmployee,employee_sortID);
		                break;
		            case 2:
		                ll_sort(pArrayListEmployee,employee_sortName);
		                break;

		            default:
		                break;
		        }
		    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

		FILE* pFile;
		Employee* auxEmpleado;


		int  auxId;
		char auxNombre[128];
		int  auxHorasTrabajadas;
		int len;
		int retorno=0;

		pFile = fopen(path,"w");
		len = ll_len(pArrayListEmployee);

		    if(pFile != NULL && pArrayListEmployee != NULL)
		    {
		        for(int i=0;i<len;i++)
		        {
		        	auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

		        	employee_getId(auxEmpleado,&auxId);
		        	employee_getNombre(auxEmpleado,auxNombre);
		        	employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);

		        }
		        printf("Se guardaron los datos en forma de:|(texto)|\n");
		        retorno=1;
		        fclose(pFile);
		    }
		    else
		    {
		        printf("ERROR\n");
		    }


    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
		FILE* pFile;
		Employee* auxEmpleado;

		int retorno=0;
	    int len;
	    int i;

	        pFile = fopen(path,"wb");
		    len = ll_len(pArrayListEmployee);


		      if(pFile!= NULL && pArrayListEmployee!= NULL)
		      	{
		    	  for(i=1;i<len;i++)
		    	  {
		    		  auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

		    		  fwrite(auxEmpleado, sizeof(Employee), 1, pFile);
		    	  }
		    	  printf("Se guardaron datos en:|binario|\n");
		    	  retorno=1;
		    	  fclose(pFile);
		      	}





		return retorno;
}
int controller_FindId(LinkedList* pArrayListEmployee,int idUser)
{
	Employee* pEmpleado = NULL;
	int len = ll_len(pArrayListEmployee);

	int auxId;

	if(pArrayListEmployee !=NULL && idUser>0)
	{

		for(int i=0;i<len;i++)
		{
			    pEmpleado = ll_get(pArrayListEmployee,i);
				employee_getId(pEmpleado, &auxId);

				if(idUser==auxId)
				{
					return i;
				}
		}
	}

	return -1;
}
