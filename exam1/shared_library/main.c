// Whay is a shared Library (Shared Object or .so)?
// A File that contains pre-written code for your program to use

//Advantages to shared library
//Disk space preservation
//Ra, Preservation
//Ease of maitmence

// gcc compiles your code to asembly code, by creating an object code
//Then gcc used the linker, the linker goes through all the libraries it knows avout and links it

//Note a library must start with lib and end with .so, ex libmy_math.so 

//To COmpile shared library do: 
// gcc -c -fPIC my_math.c
// gcc -shared -o libmy_math.so my_math.o

//To Test the library do:
// gcc -c main.c
// gcc -o main main.o libmy_math.o
// ./ main

#include <stdio.h>
#include "my_math.h"

int main(int argc, char **argv){
    int num = add(10, 20);
    printf("The sum is %d\n", num);
    return 0;
}