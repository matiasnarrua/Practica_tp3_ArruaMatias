#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "matias.h"


int menu()
{
    int opcion;

    system("cls");
    printf("***---*** Menu ***---***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados.\n7. Ordenar empleados.\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir.\n");
    fflush(stdin);
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

char getConfirmacion(char mensaje[])
{
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    letter = tolower(letter);
    while(letter!='s' && letter!='n')
    {
        printf("Error. Ingrese s para si,n para No\n");
        fflush(stdin);
        scanf("%c", &letter);
    }
    return letter;
}

int getStringLetras(char string[])
{
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(string);
    for(i=0; i<tam; i++)
    {
        if(string[i] != '\0')
        {
            if ((string[i]<'a' || string[i]>'z') && (string[i]<'A'||string[i]>'Z') && string[i]!=' ')
            {
                flag= -1;
            }
            if(string[i]!=' ')
            {
                esEspacio= -1;
            }
        }
    }
    if(esEspacio == 0)
    {
        flag = -1;
    }
    return flag;
}
int getStringNumeros(char string[])
{
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(string);
    for(i=0; i<tam; i++)
    {
        if(string[i] != '\0')
        {
            if ((string[i]<'0' || string[i]>'9') && string[i]!=' ')
            {
                flag = -1;
            }

        }
    }
    if(esEspacio == -1)
    {
        flag = -1;
    }
    return flag;
}
void pedirCadena (char mensaje[], char string[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", string);
    while(getStringLetras(string)== -1)
    {
        printf("Error. Ingrese solo letras!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", string);
    }
    firstToUpper(string);
}
void pedirSoloNumeros (char mensaje[], char string[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", string);
    while(getStringNumeros(string)== -1)
    {
        printf("Error. Ingrese solo numeros!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", string);
    }
}

void firstToUpper(char string[])
{
    int tam = strlen(string);
    int i;
    strlwr(string);
    string[0] = toupper(string[0]);
    for(i=0; i<tam; i++)
    {
        if(string[i]!='\0')
        {
            if(isspace(string[i]))
            {
                string[i+1] = toupper(string[i+1]);
            }
        }
    }
}
