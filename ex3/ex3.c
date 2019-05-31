// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    
    int frk = fork();

    if(frk < 0){
        fprintf(stderr, "Fork Failure! :O\n");
        exit(1);
    } else if(frk == 0){
        printf("Hello!\n");
    } else {
        int wait = waitpid(frk, NULL, 0);
        printf("Goodbye!\n");
    }

    return 0;
}
