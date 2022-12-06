#include <stdio.h>

int list[] = {1, 2, 4, 5, 6, 8, 9, 12, 15};

int binarysearch(int);

int main()
{
    printf("%i\n", binarysearch(13));
    return 0;
}

int binarysearch(int search)
{
    int links, rechts, mitte = 0;
    rechts = 8;

    while (links <= rechts)
    {
        mitte = links + (rechts - links) / 2;

        if (list[mitte] == search)
        {
            return mitte;
        }
        else if (list[mitte] < search)
        {
            links = mitte + 1;
        }
        else
        {
            rechts = mitte - 1;
        }
    }
    return -1;
}