#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct Vector
{
    int x;
    int y;
} Vec2;

Vec2 c_pos = {0, 0};
Vec2 moveDir = {0, 0};
Vec2 fruit;
Vec2 head = {10, 5};

int h = 10;
int w = 20;
char esc;

void draw();
void input();
Vec2 randVec(int, int);
int compareVec(Vec2, Vec2);
void addVec(Vec2 *, Vec2 *);

int main()
{
    // Init random function using current time
    time_t t;
    srand((unsigned)time(&t));

    // Vec2 test = randVec(10, 10);
    // printf("X: %i, Y: %i \n", test.x, test.y);
    // return 0;

    draw();

    while (esc != 27)
    {
        // Game Loop here
        input();
        addVec(&head, &moveDir);
        draw();

        Sleep(150);
    }

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

            if (compareVec(c_pos, head) == 1)
                printf("+");
            else if (i % (h) == 0 || j % (w) == 0)
                printf("#");
            else
                printf(" ");
        }

        printf("\n");
    }
}

void input()
{
    // moveDir.x = moveDir.y = 0;

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

int compareVec(Vec2 a, Vec2 b)
{
    if (a.x == b.x && a.y == b.y)
        return 1;
    return 0;
}

void addVec(Vec2 *a, Vec2 *b)
{
    a->x += b->x;
    a->y += b->y;
}