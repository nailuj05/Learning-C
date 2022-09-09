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

void printMatrix(Matrix *matrix)
{
    for (int r = 0; r < matrix->size.rows; r++)
    {
        for (int c = 0; c < matrix->size.columns; c++)
        {
            printf("[%i|%f]\t", r * matrix->size.rows + c, *((matrix->content + r * matrix->size.rows) + c));
        }
        printf("\n");
    }
}

Matrix *fillRandom(Matrix *matrix)
{
    for (int r = 0; r < matrix->size.rows; r++)
    {
        for (int c = 0; c < matrix->size.columns; c++)
        {
            *((matrix->content + r * matrix->size.rows) + c) = (float)(rand() % 10000) / 10000.0f;
        }
    }
    return matrix;
}

float *createMatrix(Size s)
{
    return (float *)calloc(s.rows * s.columns, sizeof(float));
}