#include "stdio.h"
#include <unistd.h>
#include <sys/wait.h>


#define SIZE 200

int main() {
    char input[SIZE];
    char buffer[SIZE];
    char* directory;
    char currentUser[SIZE];
    int status;
    char* args[2];

    args[0] = "/bin/ls";
    args[1] = NULL;
    
    directory = getcwd(buffer,SIZE);
    cuserid(currentUser);
    
    
    while(1) {
        printf("%s:%s#", currentUser, directory);
        fgets(input,SIZE,stdin);
        printf("%s",input);

        if( fork() == 0 ){
            execv(args[0], args);
        }
        else {
            wait(&status);
        }
    }
    return 0;
}