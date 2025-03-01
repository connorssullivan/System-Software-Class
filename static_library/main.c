#include <stdio.h>
#include "basic_math_library.h"


int main() {
    int sum = add(5, 3);
    int product = multiply(4, 2);

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}