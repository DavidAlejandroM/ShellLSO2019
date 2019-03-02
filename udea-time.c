
#include <stdlib.h>
#include <stdio.h>

#define SIZE 200

int main(int argc, char const *argv[])
{
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    printf("%s", c_time_string);
    return 0;
}