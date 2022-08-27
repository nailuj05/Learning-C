#include <stdio.h>

int main()
{
    int i;
    float f;
    double d;
    char c;

    printf("%lu\n", sizeof(i));
    printf("%lu\n", sizeof(f));
    printf("%lu\n", sizeof(d));
    printf("%lu\n", sizeof(c));

    return 0;
}