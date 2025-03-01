#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
Connor Sullivan
How To Run:
./mycp1 < demo.c > out.txt
Direct to an input file, then Redirect to a output file
< demo.c tells the shell to attach demo.c to stdin (fd 0) of mycp1
> out.txt tells the shell to attach out.txt to stdout (fd 1) of mycp1
*/


//This holds chunks of data to read from input File. 1 kilobyte (1025 bytes) is common practice bc/ it strikes
//A balance between Efficiancy and memory usage. A buffer is esentially temporary memory that holds data being
//Transfered between 2 places like input and output. Essentially it acts as a middleman between reading and 
//Weiting, improving efficianccy by processing data a little chunk at a time. The buffer does not need to be freed
//bc/ it is declared as a stack variable which is automatically released when the function exits. 
#define BUFFER_SIZE 1024

void err_sys(char* str){
    perror(str);
    exit(EXIT_FAILURE);
}

int main() {
    char buffer[BUFFER_SIZE]; // Temporary memory for processing
    ssize_t bytesRead; //Size_t is a special type of data specifically designed to return a sys call

    //This is reading until the end of the file, but if we write and the write does not equal bytes read, then we return an error
    while((bytesRead = read(0, buffer, BUFFER_SIZE)) > 0){
        // There is a few different cases when this error could execute,
            // If disk apace is full
            // If someonte uses the pipe (|) instead of a redirect (>) it will only read the first five lines
        if(write(1, buffer, bytesRead) != bytesRead){ 
            err_sys("Write error");
        }
    }

    if (bytesRead == -1){
        err_sys("Write error");
    }else {
        fprintf(stderr, "File copied successfully\n"); // Output to terminal because it is unbuffered
        exit(EXIT_SUCCESS);
    }
}




