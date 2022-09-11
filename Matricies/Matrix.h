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
    int rows;
    int columns;
} Matrix;

void printMatrix(Matrix *matrix)
{
    for (int r = 0; r < matrix->rows; r++)
    {
        for (int c = 0; c < matrix->columns; c++)
        {
            printf("[%i|%f]\t", r * matrix->rows + c, *(matrix->content + r * matrix->rows + c));
        }
        printf("\n");
    }
}

Matrix *fillRandom(Matrix *matrix)
{
    for (int r = 0; r < matrix->rows; r++)
    {
        for (int c = 0; c < matrix->columns; c++)
        {
            *((matrix->content + r * matrix->rows) + c) = (float)(rand() % 10000) / 10000.0f;
        }
    }
    return matrix;
}

Matrix *createMatrix(Size s)
{
    Matrix *m = malloc(sizeof(Matrix));
    m->content = (float *)calloc(s.rows * s.columns, sizeof(float));
    m->rows = s.rows;
    m->columns = s.columns;

    return m;
}

int position(Size s, int row, int column)
{
    return row * s.rows + column;
}

void freeMatrix(Matrix *m)
{
    free(m->content);
    m = NULL;
}