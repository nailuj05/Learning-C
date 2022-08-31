#include <stdio.h>
#include <stdlib.h>

const int size = 3;

int *fillRandom(int *, int);

void printArray(int *, int);
void printMatrix(int *, int);

int main()
{
    int *matrix = calloc(size * size, sizeof(int));

    matrix = fillRandom(matrix, size);

    printMatrix(matrix, size);

    return 0;
}

void printMatrix(int *matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("[%i|%d]\n", i * size + j, *((matrix + i * size) + j));
        }
    }
}

int *fillRandom(int *matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *((matrix + i * size) + j) = rand() % 100;
        }
    }

    return matrix;
}