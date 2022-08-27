#include <stdio.h>

int main()
{
    int x = 20;
    int y = 18;

    if (x > y)
    {
        printf("x is greater than y");
    }
    else if (x == y)
    {
        printf("x is equals to y");
    }
    else
    {
        printf("y is greater than x");
    }

    printf("\n");

    char a = 'A';
    char b = 'B';

    (a == b) ? printf("A and B match") : printf("A and B don't match");

    return 0;
}