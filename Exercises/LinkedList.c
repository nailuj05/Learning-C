#include <stdio.h>

// Struct for a Node (contains an item and a pointer to the next Node in the list)
struct Node
{
    int item;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *current = NULL;

void append(int item)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->item = item;
    node->next = start;

    start = node;
}

void printList()
{
    struct Node *ptr = start;

    while (ptr != NULL)
    {
        printf("[%d]\n", ptr->item);
        ptr = ptr->next;
    }
    printf("[null]\n");
}

int main()
{
    append(10);
    append(24);
    append(42);
    printList();

    return 0;
}