#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

const Size s1 = {2, 4};
const Size s2 = {4, 4};

Matrix *testMatrix(Size);

int main()
{
    Matrix *m1 = testMatrix(s1);
    Matrix *m2 = testMatrix(s2);

    printMatrix(m1);
    printf("\n");
    printMatrix(m2);

    return 0;
}

Matrix *testMatrix(Size s)
{
    Matrix *m = createMatrix(s);
    int i = 0;

    for (int r = 0; r < s.rows; r++)
    {
        for (int c = 0; c < s.columns; c++)
        {
            m->content[position(s, r, c)] = i;
            i++;
        }
    }
    return m;
}