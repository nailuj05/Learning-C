#include <stdio.h>

int main()
{
    // Get Max Number to Loop from User
    int max;

    printf("Enter loop maximum: \n");

    scanf("%i", &max);

    for (int i = 0; i <= max; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (i % 3 == 0)
        {
            printf("Fizz\n");
        }
        else if (i % 5 == 0)
        {
            printf("Buzz\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }

    return 0;
}