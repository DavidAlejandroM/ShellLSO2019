#include "stdio.h"
#include <unistd.h>
#include <sys/wait.h>
#include "parser.h"


#define SIZE 200

int main()
{
    const char *mypath[] = {"./", "/usr/bin/", "/bin/", NULL};
    char input[SIZE];

    while (1)
    {
        /* Wait for input */
        printf("prompt> ");
        // fgets(input, SIZE, stdin);
        // /* Parse input */
        // while ((... = strsep(...)) != NULL)
        // {
        //     ...
        // }

        // /* If necessary locate executable using mypath array */
        // /* Launch executable */
        // if (fork() == 0)
        // {
        //     ... execv(...);
        //     ...
        // }
        // else
        // {
        //     wait(...);
        // }
    }

    return 0;
}
