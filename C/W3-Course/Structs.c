#include <stdio.h>

// Create structure called myStructure
struct myStructure
{
    int num;
    char letter;
};

struct stringStruct
{
    char string[32];
};

int main()
{
    // Create struct var (s1, s2) of myStructure
    struct myStructure s1;
    struct myStructure s2 = {24, 'B'}; // Direct Assignment

    // Access members
    s1.num = 42;
    s1.letter = 'A';

    // Output values
    printf("Number: %d\n", s1.num);
    printf("Letter: %c\n", s1.letter);

    printf("Number: %d\n", s2.num);
    printf("Letter: %c\n", s2.letter);

    // Strings in structs
    struct stringStruct s;

    strcpy(s.string, "Test Text");

    printf("The String is: %s\n", s.string);

    // Copying
    s2 = s1;

    return 0;
}