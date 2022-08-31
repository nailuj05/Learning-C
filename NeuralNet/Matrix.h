#include <stdio.h>
#include <stdlib.h>

typedef struct Size
{
    int rows;
    int columns;
} size;

void printMatrix(int *matrix, size s)
{
    for (int r = 0; r < s.rows; r++)
    {
        for (int c = 0; c < s.columns; c++)
        {
            printf("[%i|%d]\t", r * s.rows + c, *((matrix + r * s.rows) + c));
        }
        printf("\n");
    }
}

int *fillRandom(int *matrix, size s)
{
    for (int r = 0; r < s.rows; r++)
    {
        for (int c = 0; c < s.columns; c++)
        {
            *((matrix + r * s.rows) + c) = rand() % 100;
        }
    }
    return matrix;
}

int *createMatrix(size s)
{
    return (int *)calloc(s.rows * s.columns, sizeof(int));
}