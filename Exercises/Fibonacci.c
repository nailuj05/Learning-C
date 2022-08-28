#include <stdio.h>

int fib(int);

int main()
{
    printf("%d", fib(20));
    return 0;
}

int fib(int i)
{
    if (i < 0)
    {
        printf("Incorrect Input");
        return 0;
    }
    else if (i == 0)
    {
        return 0;
    }
    else if (i == 1 || i == 2)
    {
        return 1;
    }

    return fib(i - 1) + fib(i - 2);
}