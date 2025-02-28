//Connor Sullivan
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void err_sys(char* str){
    perror(str);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    // Check for arguments
    if (argc != 2){
        err_sys("Usage: ./a.out <filename>");
    }

    // Open input and output File's
    int fdInput = open(argv[1], O_RDONLY);
    char* reversedFileName = "fooReversed";
    int fdOutput = open(reversedFileName, O_WRONLY | O_CREAT | O_TRUNC, 0760);

    //Check if files open correctly
    if(fdInput == -1 || fdOutput == -1) {
        close(fdInput);
        close(fdOutput);
        err_sys("Error opening file");
    }

    //Create Variables to read charecters
    ssize_t bytesRead;
    char buffer;

    // Find the file size
    off_t fileSize = 0;
    while((bytesRead = read(fdInput, &buffer, 1)) > 0){
        fileSize+=1;
    }


    // Read byte by byte the file starting with the size
    for (off_t i=fileSize - 1; i > -1; i--) {
        bytesRead = pread(fdInput, &buffer, 1, i);
        if (bytesRead == -1) {
            close(fdInput);
            close(fdOutput);
            err_sys("Error reading file");
        }

        if(write(fdOutput, &buffer, 1) == -1) {
            close(fdInput);
            close(fdOutput);
        }
    
    }

    close(fdInput);
    close(fdOutput);


    return 0;
}