#include <stdio.h>
#include <stdlib.h>

#define MAX 11

struct Pos
{
    int index;
    int depth;
};

struct Node
{
    int data;
    struct Node *next;
};

int dates[] = {19031980, 21121979, 9081981, 6061981, 14101980, 29081981, 11031981, 17061980};
struct Node *hashtable;

//---//
struct Pos get(int);
void add(int);
int hash(int);

void push(struct Node *, int);
//---//

int main()
{
    hashtable = calloc(sizeof(struct Node *), MAX);

    for (int i = 0; i < 8; i++)
    {
        add(dates[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("[%i|%i]\n", i, hashtable[i]);
    }

    get(6061981);
    get(21121979);
    get(14101980);

    return 0;
}

struct Pos get(int element)
{
    int index = hash(element);
    int depth = 0;

    struct Pos pos = {0, 0};

    struct Node *ptr = &hashtable + sizeof(struct Node) * index;

    while (ptr != NULL)
    {
        if (ptr->data == element)
        {
            printf("%i\n", element);
            pos.depth = depth;
            pos.index = index;
            return pos;
        }
        ptr = ptr->next;
        depth++;
    }

    return pos;
}

void add(int element)
{
    int index = hash(element);

    push(&hashtable + sizeof(struct Node) * index, element);
}

int hash(int element)
{
    return element % MAX;
}

void push(struct Node *list, int element)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = element;
    node->next = list;

    list = node;
}