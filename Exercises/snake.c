#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define w 20
#define h 10

#define WALL "#"
#define SPACE " "
#define HEAD "W"
#define BODY "+"
#define FRUIT "F"

typedef struct Vector
{
    int x;
    int y;
} Vec2;

typedef struct TailPart
{
    Vec2 pos;
    struct TailPart *next;
} Tail;

Tail *tails;

Vec2 c_pos = {0, 0};
Vec2 moveDir = {0, 0};
Vec2 fruit;
Vec2 head = {10, 5};
Vec2 lastHead;

char esc;

bool gameOver;
int score;

void draw();
void logic();
Vec2 fruitPos();
void addTail();
void updateTail();
bool isTail(Vec2);
void input();
Vec2 randVec(int, int);
bool compareVec(Vec2, Vec2);
void addVec(Vec2 *, Vec2 *);

int main()
{
    // Init random function using current time
    time_t t;
    srand((unsigned)time(&t));

    fruit = fruitPos();

    draw();

    while (esc != 27 && !gameOver)
    {
        input();
        logic();
        draw();
        updateTail();

        Sleep(150);
    }

    printf("\e[1;1H\e[2J");
    printf("\n");
    printf("\tGAME OVER\n");
    printf("Score: %i", score);

    return 0;
}

void draw()
{
    printf("\e[1;1H\e[2J");
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            c_pos.y = i;
            c_pos.x = j;

            if (compareVec(c_pos, head))
                printf(HEAD);
            else if (compareVec(c_pos, fruit))
                printf(FRUIT);
            else if (isTail(c_pos))
                printf(BODY);
            else if (i % (h) == 0 || j % (w) == 0)
                printf(WALL);
            else
                printf(SPACE);
        }

        printf("\n");
    }
    printf("Score: %i\n", score);
}

void logic()
{
    // Move head
    lastHead = head;
    addVec(&head, &moveDir);

    // Check Tail Collision
    Tail *ptr = tails;

    while (ptr != NULL)
    {
        if (compareVec(ptr->pos, head))
        {
            gameOver = true;
            return;
        }

        ptr = ptr->next;
    }

    // Check Wall Collision
    if (head.y % (h) == 0 || head.x % (w) == 0)
    {
        gameOver = true;
        return;
    }

    // Check fruit collision
    if (compareVec(fruit, head))
    {
        fruit = fruitPos();
        addTail();
        score++;
    }
}

Vec2 fruitPos()
{
    Vec2 one = {1, 1};
    Vec2 rand = randVec(w - 2, h - 2);
    addVec(&rand, &one);
    return rand;
}

void addTail()
{
    Tail *newTail = (Tail *)malloc(sizeof(Tail));
    newTail->pos = lastHead;
    newTail->next = tails;
    tails = newTail;
}

void updateTail()
{
    Tail *ptr = tails;

    Vec2 prevPos = head;
    Vec2 bufferPos;

    while (ptr != NULL)
    {
        bufferPos = ptr->pos;
        ptr->pos = prevPos;
        prevPos = bufferPos;
        // printf("(%i|%i)\n", ptr->pos.x, ptr->pos.y);
        ptr = ptr->next;
    }
}

bool isTail(Vec2 pos)
{
    Tail *ptr = tails;

    while (ptr != NULL)
    {
        if (compareVec(pos, ptr->pos))
            return true;
        ptr = ptr->next;
    }
}

void input()
{
    if (kbhit())
    {
        esc = getch();
        switch (esc)
        {
        case 'w':
            moveDir.y = -1;
            moveDir.x = 0;
            break;

        case 's':
            moveDir.y = 1;
            moveDir.x = 0;
            break;

        case 'a':
            moveDir.x = -1;
            moveDir.y = 0;
            break;

        case 'd':
            moveDir.x = 1;
            moveDir.y = 0;
            break;

        default:
            break;
        }
    }
}

Vec2 randVec(int maxX, int maxY)
{
    Vec2 v = {rand() % maxX, rand() % maxY};
    return v;
}

bool compareVec(Vec2 a, Vec2 b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    return false;
}

void addVec(Vec2 *a, Vec2 *b)
{
    a->x += b->x;
    a->y += b->y;
}