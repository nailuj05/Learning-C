#include <stdio.h>

// Declaration
void test();
void sayName(char[]);
int add(int, int);

// Main method (entry point)
int main()
{
    test();
    sayName("Max");
    printf("%i", add(3, 7));
    return 0;
}

// Definition
void test()
{
    printf("Hello there\n");
}

void sayName(char name[])
{
    printf("Hi %s\n", name);
}

int add(int a, int b)
{
    return a + b;
}