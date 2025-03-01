
//Connor Sullivan
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1

void err_sys(char* str){
    perror(str);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        err_sys("Parameter Error");
    }

    //These are the files to read and write from
    char *inputFile = argv[1];
    char *outputFile = "output.txt";
    int fdInput, fdOutput;

    // Open the input file in
    fdInput = open(inputFile, O_RDONLY);
    if (fdInput == -1) {
        close(fdInput);
        err_sys("Error opening input file");
    }

    // Open the output file 
    fdOutput = open(outputFile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fdOutput == -1) {
        close(fdInput);
        close(fdOutput);
        err_sys("Error opening output file");
    }

    // Read and copy
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(fdInput, buffer, BUFFER_SIZE)) > 0) {
        if (write(fdOutput, buffer, bytesRead) != bytesRead) {
            err_sys("Error writing to output file");
            close(fdInput);
            close(fdOutput);
        }
    }

    if (bytesRead == -1) {
        close(fdInput);
        close(fdOutput);
        err_sys("Error reading from input file");
    }

    close(fdInput);
    close(fdOutput);

    return 0;

}