// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    printf("parent begin\n");
    int frk = fork();

    if (frk < 0) {
        fprintf(stderr, "fork failure\n");
        exit(1);
    } else if (frk == 0) {
        printf("child\n");

        execlp("ls", "ls", "-l", (char *) NULL);

    } else {
        int wait = waitpid(frk, NULL, 0);
    }

    return 0;
}
