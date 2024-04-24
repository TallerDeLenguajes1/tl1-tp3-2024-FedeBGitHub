#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int cantNombres;
    char buff[100];
    
    printf("Ingrese la cantidad de nombres que desea introducir: ");
    scanf("%d", &cantNombres);
    fflush(stdin);
    char ** nombres = malloc(cantNombres * sizeof(char *));

    for (int i = 0; i < cantNombres; i++)
    {
        printf("\n Ingrese un nombre: ");
        gets(buff);
        nombres[i] = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombres[i], buff);
    }


    for (int j = 0; j <cantNombres; j++)
    {
    
        printf("\n%s", nombres[j]);
        free(nombres[j]);
    }
    free(nombres);

    return 0;
}