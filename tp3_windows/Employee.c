#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(){
	Employee* newEmp = NULL;
	newEmp = (Employee*)malloc(sizeof(Employee));

	if(newEmp != NULL){
		employee_setHorasTrabajadas(newEmp, 0);
		employee_setId(newEmp, 0);
		employee_setNombre(newEmp, " ");
		employee_setSueldo(newEmp, 0);
	}
	return newEmp;
}

Employee* employee_newParamStr(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
	Employee* newEmp = NULL;

	if(idStr!= NULL &&nombreStr!= NULL &&horasTrabajadasStr!= NULL &&sueldoStr!= NULL ){
		newEmp = employee_new();
		if(newEmp != NULL){
			if(employee_setHorasTrabajadas(newEmp, atoi(horasTrabajadasStr))==1 ||
		employee_setId(newEmp, atoi(idStr))==1 ||
		employee_setNombre(newEmp, nombreStr)==1 ||
		employee_setSueldo(newEmp, atoi(sueldoStr))==1){
				printf("Fallo algun setter\n");
				free(newEmp);
				newEmp=NULL;
			}
		}
	}
	return newEmp;
}

void employee_delete(Employee* employee)
{
    free(employee);
    employee = NULL;
}



int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }

    return retorno;
}



int mayorId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        int len;
        int flag = 0;
        int i;
        Employee* auxEmployee;

        len = ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(flag == 0 || retorno < auxEmployee->id)
            {
                retorno = auxEmployee->id;
                flag = -1;
            }
        }
    }
    return retorno;
}

int proximoId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        retorno = mayorId(pArrayListEmployee);
        retorno++;
    }
    return retorno;
}

int showOneEmployee(Employee* employee)
{
    int retorno = -1;

    if(employee != NULL)
    {
        printf("%4d %18s %20d %20d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
        retorno = 0;
    }

    return retorno;
}


	void pedirDatosEmp(char* nombre, char* horasTrabajadas, char* salario)
	{
	    pedirCadena("Ingrese el nombre del empleado: ", nombre);
	    pedirSoloNumeros("Ingrese las horas trabajadas del empleado: ", horasTrabajadas);
	    pedirSoloNumeros("Ingrese el salario del empleado: ", salario);
	}


