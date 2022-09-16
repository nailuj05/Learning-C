#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void readDir(char *, char *);
void fixFile(char *, char *);

int main()
{
    readDir("G:\\git\\Vaults\\Schule", "_Content");
    return 0;
}

void readDir(char *path, char *next)
{
    struct dirent *de;

    char *nextDir = calloc(100, sizeof(char));
    strcat(nextDir, path);
    strcat(nextDir, "\\");
    strcat(nextDir, next);

    DIR *dr = opendir(nextDir);

    if (dr == NULL)
    {
        int len = strlen(next);

        if (next[len - 1] == 'd' && next[len - 2] == 'm')
        {
            printf("Fixing : %s \n", next);
            fixFile(path, next);
        }
        return;
    }

    while ((de = readdir(dr)) != NULL)
    {
        if (de->d_name[0] == '.')
            continue;

        readDir(nextDir, de->d_name);
    }

    free(nextDir);
    closedir(dr);
}

void fixFile(char *path, char *file)
{
    FILE *fptr1, *fptr2;
    int bufferLength = 256;
    char lineBuffer[bufferLength];

    char *filePath = calloc(100, sizeof(char));
    char *tempFilePath = calloc(100, sizeof(char));
    strcat(filePath, path);
    strcat(filePath, "\\");

    strcat(tempFilePath, filePath);

    strcat(filePath, file);
    strcat(tempFilePath, "temp.txt");

    fptr1 = fopen(filePath, "r");
    fptr2 = fopen(tempFilePath, "w");

    int line = 0;

    while (fgets(lineBuffer, bufferLength, fptr1))
    {
        if (!(line == 0 && lineBuffer[0] == '#'))
            fprintf(fptr2, "%s", lineBuffer);

        line++;
    }

    fclose(fptr1);
    fclose(fptr2);

    remove(filePath);
    rename(tempFilePath, filePath);
}