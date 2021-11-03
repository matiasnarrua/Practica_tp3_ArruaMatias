#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "matias.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
FILE *auxF;
int retorno =1;
auxF = fopen(path, "r");
if(auxF == NULL){
	printf("Error al abrir el archivo");

}
else{
	parser_EmployeeFromText(auxF, pArrayListEmployee);
	retorno=0;
}
fclose(auxF);
    return retorno;
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
	int retorno = 1;

FILE* pFile = NULL;

pFile = fopen(path,"rb");

if(pFile!= NULL && pArrayListEmployee!= NULL)
{
        retorno= parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }
    else
    {
        retorno= 2;
    }

fclose(pFile);
return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int retorno = 1;
    char nombre[60];
    char sueldo[60];
    char horasTrabajadas[60];
    char idEmp[60];
    int poxId;
    char check;
    char continuar;

    if(pArrayListEmployee!= NULL)
    {
        do
        {
            Employee* newEmp;

            sprintf(idEmp, "%d", *id);
            pedirDatosEmp(nombre, horasTrabajadas, sueldo);
            newEmp= employee_newParamStr(idEmp, nombre, horasTrabajadas, sueldo);

            printf("Los datos ingresados son:\n");
            printf("%5s %15s %22s %22s\n","ID:","Nombre:","Horas trabajadas:","Sueldo:");
            showOneEmployee(newEmp);
            printf("\n");

            check = getConfirmacion("Desea cargar al empleado? S/N: ");
            if(check== 's')
            {
                retorno= ll_add(pArrayListEmployee, newEmp);
            }
            else if(check== 'n')
            {
                retorno= 2;
            }
            printf("\n");

            poxId= *id;
            poxId++;
            *id= poxId;

            continuar = getConfirmacion("Desea ingresar otro empleado? S/N: ");
            printf("\n");
        }
        while(continuar== 's');
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
{int retorno =-1;




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
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)	{
	    int retorno = -1;
	    int i;
	    int len;


	    if(pArrayListEmployee != NULL)
	    {
	        retorno = 0;

	            len = ll_len(pArrayListEmployee);
	            Employee* auxEmpleado;
	            printf("%4s%22s%32s%32s\n","Id","Nombre","Horas Trabajadas","Sueldo");
	            for(i=0; i<len; i++)
	            {
	                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
	                showOneEmployee(auxEmpleado);
	                if(i!=0 && i%200==0)
	                {
	                    system("pause");
	                }
	            }
	        }
	        else
	        {
	            retorno = 1;
	        }

	    return retorno;
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
    return 1;
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
    return 1;
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
    return 1;
}

