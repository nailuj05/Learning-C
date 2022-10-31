#include <stdio.h>

int main()
{
    int num;

    printf("Type a number: \n");

    scanf("%d", &num);

    printf("Your number is: %d \n", num);

    char name[30];

    printf("Enter your name: \n");

    scanf("%s", name);

    printf("Hello %s.", name);

    return 0;
}