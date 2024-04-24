#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char buff[100];
    char ** nombres = malloc(5 * sizeof(char *));;

    for (int i = 0; i < 5; i++)
    {
        printf("\n Ingrese un nombre: ");
        gets(buff);
        nombres[i] = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombres[i], buff);
    }


    for (int j = 0; j < 5; j++)
    {
    
        printf("\n%s", nombres[j]);
        free(nombres[j]);
    }
    free(nombres);

    return 0;
}