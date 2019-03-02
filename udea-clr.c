#include "stdio.h"
#include <unistd.h>

#define SIZE 200

int main(int argc, char const *argv[])
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
    return 0;
}