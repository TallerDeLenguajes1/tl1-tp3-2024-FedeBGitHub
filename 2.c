#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILA 5
#define COLUMNA 12
int cargarMatriz(int matriz[FILA][COLUMNA]);
void mostrarMatriz(int matriz[FILA][COLUMNA]);
void promedioPorAnio(int matriz[FILA][COLUMNA]);
void valoresMaximoMinimo(int matriz[FILA][COLUMNA]);

int main()
{
    int matriz[FILA][COLUMNA];
    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    promedioPorAnio(matriz);
    valoresMaximoMinimo(matriz);

    return 0;
}

int cargarMatriz(int matriz[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;
        }
    }
}

void mostrarMatriz(int matriz[FILA][COLUMNA])
{
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }
}

void promedioPorAnio(int matriz[FILA][COLUMNA])
{
    int promedio = 0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            promedio += matriz[i][j];
        }
        printf("\nEl promedio del anio %d: %d", i + 1, promedio / 12);
        promedio = 0;
    }
}

void valoresMaximoMinimo(int matriz[FILA][COLUMNA])
{
    int max = 0, min = 60000, anioMax, mesMax, anioMin, mesMin;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUMNA; j++)
        {
            if (max < matriz[i][j])
            {
                max = matriz[i][j];
                anioMax = i + 1;
                mesMax = j + 1;
            }

            if (min > matriz[i][j])
            {
                min = matriz[i][j];
                anioMin = i + 1;
                mesMin = j + 1;
            }
        }
    }
    printf("\nEl Valor maximo es %d (anio: %d, mes: %d ) ", max, anioMax, mesMax);
    printf("\nEl Valor minimo es %d (anio: %d, mes: %d ) ", min, anioMin, mesMin);
}