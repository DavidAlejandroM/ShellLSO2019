#include "stdio.h"
#include <unistd.h>

#define SIZE 200

int main(int argc, char const *argv[])
{
    if(argc > 1)
    {
        chdir(argv[1]);
    }
    else
    {
        printf("no specific path\n");
    }
    
    return 0;
}
