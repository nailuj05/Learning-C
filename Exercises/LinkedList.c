#include <stdlib.h>
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

struct Node *getNode(int index)
{
    struct Node *ptr = start;
    int counter = 0;

    while (counter != index)
    {
        if (ptr->next == NULL)
        {
            if (index > 0) // Negativ Index for last element
            {
                printf("Index out of bounds\n");
            }
            break;
        }

        ptr = ptr->next;
        counter++;
    }

    return ptr;
}

void printList()
{
    struct Node *ptr = start;
    int i = 0;

    while (ptr != NULL)
    {
        printf("[%i|%d]\n", i, ptr->item);
        ptr = ptr->next;
        i++;
    }
    printf("[null]\n");
}

int main()
{
    append(10);
    append(24);
    append(42);
    printList();

    printf("%d\n", getNode(4)->item);

    return 0;
}