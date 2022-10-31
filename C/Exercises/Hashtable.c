#include <stdio.h>

#define MAX 11

int dates[] = {19031980, 21121979, 9081981, 6061981, 14101980, 29081981, 11031981, 17061980};
int *hashtable[MAX];

//---//
int get(int);
void add(int);
int hash(int);
//---//

int main()
{
    for (int i = 0; i < 8; i++)
    {
        add(dates[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("[%i|%i]\n", i, hashtable[i]);
    }

    printf("Found %i\n", get(6061981));
    printf("Found %i\n", get(21121979));
    printf("Found %i\n", get(14101980));

    return 0;
}

int get(int element)
{
    int index = hash(element);
    int ops = 0;

    while (hashtable[index] != element)
    {
        index++;
        ops++;

        if (index >= MAX)
            index = 0;
    }
    printf("Operations: %i\n", ops);

    return index;
}

void add(int element)
{
    int index = hash(element);

    while (hashtable[index] != 0)
    {
        index++;

        if (index >= MAX)
            index = 0;
    }
    hashtable[index] = element;
}

int hash(int element)
{
    return element % MAX;
}