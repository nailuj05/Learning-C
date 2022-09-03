#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

const Size s = {3, 4};

int main()
{
    Matrix m = {createMatrix(s), s};

    m.content = fillRandom(m.content, s);

    printMatrix(m.content, s);

    return 0;
}