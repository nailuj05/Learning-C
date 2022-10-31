#include <stdio.h>
#include "LinkedList.h"

struct Node *list;

struct Node *invert(struct Node *);

int main()
{
    list = push(list, 20);
    list = push(list, 30);
    list = push(list, 40);

    printf("Regular:  ");
    printList(list);

    list = invert(list);
    printf("Inverted: ");
    printList(list);

    return 0;
}

struct Node *invert(struct Node *list)
{
    struct Node *prev, *curr, *next;
    curr = list;

    while (next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list = prev;
    return list;
}