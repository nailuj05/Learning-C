#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    int bufferLength = 255;
    char lineBuffer[bufferLength];

    fptr = fopen("day-2-input.txt", "r");

    char iDirection[1000];
    int iValues[1000];

    int i = 0;
    while (fgets(lineBuffer, bufferLength, fptr))
    {
        iDirection[i] = lineBuffer[0];

        char *c = &lineBuffer[0];
        while (*c)
        {
            if (*c++ == ' ')
            {
                iValues[i] = atoi(c);
                break;
            }
        }

        i++;
    }

    fclose(fptr);

    //----------------------//

    int depth = 0;
    int position = 0;

    for (int i = 0; i < 1000; i++)
    {
        switch (iDirection[i])
        {
        case 'f':
            position += iValues[i];
            break;

        case 'd':
            depth += iValues[i];
            break;

        case 'u':
            depth -= iValues[i];
            break;

        default:
            break;
        }
    }

    printf("2-1: %i\n", depth * position);

    //----------------------//

    depth = 0;
    position = 0;
    int aim = 0;

    for (int i = 0; i < 1000; i++)
    {
        switch (iDirection[i])
        {
            // Forward
        case 'f':
            position += iValues[i];
            depth += aim * iValues[i];
            break;

            // Down
        case 'd':
            aim += iValues[i];
            break;

            // Up
        case 'u':
            aim -= iValues[i];
            break;

        default:
            break;
        }
    }

    printf("2-2: %i\n", depth * position);

    return 0;
}