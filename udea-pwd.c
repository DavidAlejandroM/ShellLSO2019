#include "stdio.h"
#include <unistd.h>

#define SIZE 200

int main(int argc, char const *argv[])
{
    char buffer[SIZE];
    char* directory;

    directory = getcwd(buffer,SIZE);
    printf("%s\n",directory);
    return 0;
}
