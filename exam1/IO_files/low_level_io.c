#include <stdio.h> //Standard Input Otput
#include <unistd.h> //Unix Standard
#include <stdlib.h> //Standard Library

#define BUFFERSIZE 1024

void err_sys(char* str){
    perror(str);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){ 
    if(argc)
}



/*
Connor Sullivan
low_level_io.c.c - A Simple File Copy Utility Using Low-Level I/O

Description:
This program mimics the functionality of the Unix `cp` command but uses 
low-level system calls (`read` and `write`) to manually copy data from 
one file to another.

How It Works:
- Uses a buffer of 1024 bytes to efficiently read and write data.
- Reads from **stdin** (file descriptor 0) and writes to **stdout** (file descriptor 1).
- Works with input/output redirection in the shell.

How to Run:
    ./ow_level_io.c < input_file > output_file

Example:
    ./ow_level_io.c < demo.c > out.txt
    - Redirects `demo.c` to stdin (fd 0) and writes to `out.txt` (fd 1).
