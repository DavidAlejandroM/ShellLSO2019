#include "stdio.h"
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "parser.h"
#include <stdlib.h>
#include <time.h>

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
    int num, status;
    char *path;

    while (1)
    {
        /* Wait for input */
        printf(ANSI_COLOR_GREEN "prompt> " ANSI_COLOR_RESET);
        fgets(input, SIZE, stdin);
        num = splitItems(input, &items, &background);

        *path = (char *)malloc(1 + strlen(items[0]) + strlen(mypath[2]));
        strcpy(path, mypath[2]);
        strcat(path, items[0]);

        if (strcmp(items[0], "udea-cd") == 0)
        {
            chdir(items[1]);
        }
        else if (strcmp(items[0], "udea-exit") == 0)
        {
            exit(0);
        }
        else if (strcmp(items[0], "udea-clr") == 0)
        {
            const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
            write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
        }
        else if (strcmp(items[0], "udea-echo") == 0)
        {
            for (int i = 1; i < num; i++)
            {
                printf("%s ", items[i]);
            }
            printf("\n");
        }
        else if (strcmp(items[0], "udea-time") == 0)
        {
            time_t current_time;
            char *c_time_string;

            current_time = time(NULL);

            /* Convert to local time format. */
            c_time_string = ctime(&current_time);

            printf("%s", c_time_string);
        }
        else if (strcmp(items[0], "udea-pwd") == 0)
        {
            char buffer[SIZE];
            char *directory;

            directory = getcwd(buffer, SIZE);
            printf("%s\n", directory);
        }
        else if (fork() == 0)
        {
            execv(path, items); // Acá va la invocación de la orden interna
        }

        if (checkTypeFunction(items[0]) == 0)
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
