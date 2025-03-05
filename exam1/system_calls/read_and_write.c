#include <unistd.h>
#include <stdlib.h>
//Read and Write to terminal Using a file descriptor

int main(int argc, char *argv[]){
    char buffer[100];
    ssize_t bytes_read;

    char message[] = "Enter A Number";
    write(1, message, sizeof(message) -1);
    bytes_read = read(0, buffer, sizeof(buffer) -1);

    if(bytes_read > 0){
        buffer[bytes_read] = '\0';
        write(1, "File Content: ", 14);
        write(1, buffer, bytes_read);
    }else{
        write(2, "Error Reading File", 18);
    }


    return 0;
}