#include <stdio.h>
#include <stdlib.h>

typedef struct size
{
    int rows;
    int columns;
} Size;

typedef struct matrix
{
    float *content;
    Size size;
} Matrix;

void printMatrix(float *matrix, Size s)
{
    for (int r = 0; r < s.rows; r++)
    {
        for (int c = 0; c < s.columns; c++)
        {
            printf("[%i|%f]\t", r * s.rows + c, *((matrix + r * s.rows) + c));
        }
        printf("\n");
    }
}

float *fillRandom(float *matrix, Size s)
{
    for (int r = 0; r < s.rows; r++)
    {
        for (int c = 0; c < s.columns; c++)
        {
            *((matrix + r * s.rows) + c) = (float)(rand() % 10000) / 10000.0f;
        }
    }
    return matrix;
}

float *createMatrix(Size s)
{
    return (float *)calloc(s.rows * s.columns, sizeof(float));
}