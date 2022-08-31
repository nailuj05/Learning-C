#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

const Size s = {3, 4};

int main()
{
    Matrix m = {createMatrix(s), s};

    matrix = fillRandom(matrix, s);

    printMatrix(matrix, s);

    return 0;
}