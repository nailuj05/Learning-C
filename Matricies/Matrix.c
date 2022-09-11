#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

const Size s = {3, 4};

int main()
{
    Matrix m = *createMatrix(s);

    m = *fillRandom(&m);

    printMatrix(&m);

    return 0;
}