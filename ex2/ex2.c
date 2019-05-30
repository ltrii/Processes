// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE* main;
    main = fopen("text.txt", "w");

    int frk = fork();

    if(frk < 0){
        fprintf(stderr, "Fork failure\n");
        exit(1);
    } else if (frk == 0) {
        printf("Child string write...\n");
        char *child = "Child write success\n";
        fwrite(child, sizeof(char), strlen(child), main);
    } else {
        printf("Parent starting write...\n");
        char *parent = "Parent write success\n";
        fwrite(parent, sizeof(char), strlen(parent), main); 
    }
    fclose(main);
    return 0;
}
