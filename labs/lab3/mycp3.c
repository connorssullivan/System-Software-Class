//Connor Sullivan

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUFFER_SIZE 32

void err_sys(char* str){
    perror(str);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    // Check for argument length
    if (argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    // Read the input file
    int fdInput = open(argv[1], O_RDONLY);
    if (fdInput == -1){
        printf("Error opening file\n");
        close(fdInput);
        exit(1);
    }

    // Get the output file
    char *output_file = "outputFile2.txt";
    int fdOutput = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0770);
    if (fdOutput == -1){
        printf("Error opening file\n");
        close(fdInput);
        close(fdOutput);
        exit(1);
    }

    // Write the output file
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(fdInput, buffer, BUFFER_SIZE)) > 0){
        if(write(fdOutput, buffer, bytesRead)!=bytesRead){
            err_sys("Error writing to output file");
            close(fdInput);
            close(fdOutput);
            exit(1);
        }
    }

    if (bytesRead == -1){
        printf("Error reading file\n");
        close(fdInput);
        close(fdOutput);
        exit(1);
    }





    printf("Success \n");
    close(fdInput);
    close(fdOutput);






    return 0;
}
