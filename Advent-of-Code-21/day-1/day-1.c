#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    int bufferLength = 255;
    char lineBuffer[bufferLength];

    fptr = fopen("day-1-input.txt", "r");

    int inputs[2000];
    int i = 0;
    while (fgets(lineBuffer, bufferLength, fptr))
    {
        inputs[i] = atoi(lineBuffer);
        i++;
    }

    fclose(fptr);

    int increased = 0;

    for (int i = 0; i < 2000 - 1; i++)
    {
        if (inputs[i] < inputs[i + 1])
        {
            increased++;
        }
    }

    printf("Simple increases; %i\n", increased);

    increased = 0;

    int sum = 0;
    int lastSum;

    for (int i = 0; i < 2000 - 3; i++)
    {
        lastSum = inputs[i] + inputs[i + 1] + inputs[i + 2];

        sum = inputs[i + 1] + inputs[i + 2] + inputs[i + 3];

        printf("%i > %i\n", sum, lastSum);

        if (sum > lastSum)
        {
            increased++;
        }
    }

    printf("Average increases; %i", increased);
}