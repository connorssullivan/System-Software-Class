#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char buffer[1];
    int bytes_read;

    write(1, "Enter Text", 11);

    while((bytes_read = read(0, buffer, 1)) > 0) {
        write(1, buffer, 1);
    }
    
    return 0;
}    