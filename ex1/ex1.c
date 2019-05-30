// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;

    int frk = fork();

    if(frk < 0){
        fprintf(stderr, "Fork failure.");
    } else if(frk == 0) {
        printf("child x = %d (ID: %d) \n", x, (int) getpid(), frk);
        x++;
        printf("child x changed = %d\n", x);
    } else {
        printf("parent %d of child %d | x is = %d\n", (int) getpid(), frk, x);
        x--;
        printf("parent %d of child %d | x changed is = %d\n", (int) getpid(), frk, x);
    }

    return 0;
}
