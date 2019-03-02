#include "stdio.h"
#include <unistd.h>
#include <sys/wait.h>
#include "parser.h"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define SIZE 200

int checkTypeFunction(char *cadena);

int main()
{
    const char *mypath[] = {"./", "/usr/bin/", "/bin/", NULL};
    char **items;
    char input[SIZE];
    int background;
    int num, i, status;
    char *path;

    while (1)
    {
        /* Wait for input */
        printf(ANSI_COLOR_GREEN "prompt> " ANSI_COLOR_RESET);
        fgets(input, SIZE, stdin);
        num = splitItems(input, &items, &background);

        if (checkTypeFunction(items[0]))
        {
            *path = (char *)malloc(1 + strlen(items[0]) + strlen(mypath[0]));
            strcpy(path, mypath[0]);
            strcat(path, items[0]);
            //printf("%s\n", path);
        }
        else
        {
            *path = (char *)malloc(1 + strlen(items[0]) + strlen(mypath[2]));
            strcpy(path, mypath[2]);
            strcat(path, items[0]);
            //printf("%s\n", path);
        }

        if (background == 0)
        {
            if(strcmp("udea-cd",items[0])){
                printf("is equal");
            }
            else if (fork() == 0)
            {
                execv(path, items); // Acá va la invocación de la orden interna
            }
            else
            {
                wait(&status);
            }
        }

        else if (background == 1)
        {
            if (fork() == 0)
            {
                execv(path, items); // Acá va la invocación de la orden externa
            }
            else
            {
                wait(&status);
            }
        }
        else
        {
            wait(&status);
        }

        liberaItems(items);
    }

    return 0;
}

/*  devuelve 0 si la primera parte del comando no concide con udea
    y 1 si coincide*/
int checkTypeFunction(char *cadena)
{
    int size = 0;
    char *udea = "udea-";
    while (*(cadena + size) != 00)
    {
        size++;
    }
    if (size > 5)
    {
        size = 5;
    }
    for (int i = 0; i < size; i++)
    {
        //printf("%c - %c\n", *(cadena + i), *(udea + i));

        if (*(cadena + i) != *(udea + i))
        {
            return 0;
        }
    }
    return 1;
}
