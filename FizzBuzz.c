#include <stdio.h>

int main()
{
    // Get Max Number to Loop from User
    int max;

    printf("Enter loop maximum: \n");

    scanf("%i", &max);

    for (int i = 1; i <= max; i++)
    {
        if ((i % 15) == 0)
            printf("FizzBuzz\t");

        else if (i % 3 == 0)
            printf("Fizz\t");

        else if (i % 5 == 0)
            printf("Buzz\t");

        else
            printf("%d\t", i);
    }

    return 0;
}