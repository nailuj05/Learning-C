#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

const size s = {3, 4};

int main()
{
    int *matrix = createMatrix(s);

    matrix = fillRandom(matrix, s);

    printMatrix(matrix, s);

    return 0;
}