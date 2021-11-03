#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "matias.h"

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
    setbuf (stdout, NULL);
    int option ;
    int id= 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

//Queda agregar las validaciones con los return de la funciones en el menu

    do{
    	option=menu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
         case 2:

            controller_loadFromBinary("data.bin", listaEmpleados);
            id = proximoId(listaEmpleados);

            printf("\n");
            system("pause");
            break;
        case 3:

            id = proximoId(listaEmpleados);
            controller_addEmployee(listaEmpleados, &id);

            printf("\n");
            system("pause");
            break;
        case 4:

             controller_editEmployee(listaEmpleados);

            printf("\n");
            system("pause");
            break;
        case 5:

           controller_removeEmployee(listaEmpleados);

            printf("\n");
            system("pause");
            break;
        case 6:

            controller_ListEmployee(listaEmpleados);

            printf("\n");
            system("pause");
            break;
        case 7:

            controller_sortEmployee(listaEmpleados);

            printf("\n");
            system("pause");
            break;
        case 8:

            controller_saveAsText("data.csv", listaEmpleados);

            printf("\n");
            system("pause");
            break;
        case 9:

            controller_saveAsBinary("data.bin", listaEmpleados);

            printf("\n");
            system("pause");
            break;
        }
    }while(option != 10);
    return 0;
}

