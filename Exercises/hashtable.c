#include <stdio.h>

#define MAX 11

int dates[] = {19031980, 21121979, 9081981, 6061981, 14101980, 29081981, 11031981, 17061980};
int *hashtable[MAX];

//---//
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

    return 0;
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