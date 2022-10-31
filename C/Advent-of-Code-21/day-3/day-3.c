#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sums[12];
int gamma_rate[12];
int epsilon_rate[12];

int bin2int(int[12]);

int main()
{
    FILE *fptr;
    int bufferLength = 255;
    char lineBuffer[bufferLength];

    fptr = fopen("day-3-input.txt", "r");

    while (fgets(lineBuffer, bufferLength, fptr))
    {
        for (int i = 0; i < 12; i++)
        {
            sums[i] += lineBuffer[i] - '0';
        }
    }

    fclose(fptr);

    for (int i = 0; i < 12; i++)
    {
        gamma_rate[i] = (int)(sums[i] > 500);
        epsilon_rate[i] = (int)(sums[i] < 500);
    }

    int result = bin2int(gamma_rate) * bin2int(epsilon_rate);

    printf("%i\n", result);

    return 0;
}

int bin2int(int bin[12])
{
    int result = 0;

    for (int i = 0; i < 12; i++)
    {
        result += bin[i] * pow(2, 11 - i);
    }

    return result;
}