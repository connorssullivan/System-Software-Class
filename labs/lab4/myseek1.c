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

int main(int argsc, char *argsv[]) {
    if (argsc != 3) {
        err_sys("Usage: ./myseek1 <file1> <file2>");
    }

    // Open file to read and write to
    int fdInput1 = open(argsv[1], O_RDONLY);
    int fdInput2 = open(argsv[2], O_RDONLY);
    char* outputFile = "foo12";
    int fdOutput = open(outputFile, O_WRONLY | O_CREAT | O_TRUNC, 0760);

    //Check if file is open
    if (fdInput1 == -1 || fdInput2 == -1  || fdOutput == -1) {
        close(fdInput1);
        close(fdInput2);
        close(fdOutput);
        err_sys("open Error");
    }

    // Write the first file to the putput file
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while((bytesRead = read(fdInput1, buffer, BUFFER_SIZE)) > 0) {
        if((write(fdOutput, buffer, bytesRead))!= bytesRead){
            close(fdInput1);
            close(fdInput2);
            close(fdOutput);
            err_sys("write Error");
        }
        write(fdOutput, "\n", 1);


    }

    if (bytesRead == -1) {
        close(fdInput1);
        close(fdInput2);
        close(fdOutput);
        err_sys("Error reading from input file");
    }

    // Move over to the end of the file and append to it
    off_t offset = lseek(fdOutput, 0, SEEK_END);
    if(offset != -1) {
        while((bytesRead = read(fdInput2, buffer, BUFFER_SIZE)) > 0) {
            if((write(fdOutput, buffer, bytesRead))!= bytesRead){
                close(fdInput1);
                close(fdInput2);
                close(fdOutput);
                err_sys("write Error");
            }
        }

        if (bytesRead == -1) {
            close(fdInput1);
            close(fdInput2);
            close(fdOutput);
            err_sys("Error reading from input file");
        }
    }else{
        close(fdInput1);
        close(fdInput2);
        close(fdOutput);
        err_sys("lseek Error");
    }

    //Close Files
    close(fdInput1);
    close(fdInput2);
    close(fdOutput);

}