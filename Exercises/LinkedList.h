#include <stdlib.h>
#include <stdio.h>

// Struct for a Node (contains an item and a pointer to the next Node in the list)
struct Node
{
    int item;
    struct Node *next;
};

struct Node *push(struct Node *startPtr, int item)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->item = item;
    node->next = startPtr;

    startPtr = node;
    return startPtr;
}

void printList(struct Node *startPtr)
{
    struct Node *ptr = startPtr;
    int i = 0;

    while (ptr != NULL)
    {
        printf("[%d]\t", ptr->item);
        ptr = ptr->next;
        i++;
    }
    printf("[null]\n");
}