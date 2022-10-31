#include <stdio.h>

int main()
{
    // Memory Adress
    int age = 42;

    printf("%d\n", age);  // Outputs value of "age"
    printf("%p\n", &age); // Outputs memory adress of "age"

    // Pointer Variables
    int *agePointer = &age; // Holds the value of the memory adress (&age)

    printf("%p\n", &age);       // Outputs memory adress of "age"
    printf("%p\n", agePointer); // Outputs memory adress of "agePointer"

    // Dereference
    int num = 24;           // Var declaration
    int *numPointer = &num; // Pointer declaration

    printf("%p\n", numPointer);  // Reference: Output the adress (=> &age)
    printf("%d\n", *numPointer); // Dereference: Output the value at adress (=> age)

    return 0;
}