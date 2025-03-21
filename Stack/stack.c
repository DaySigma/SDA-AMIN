#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void convertToBinary(Node *N, int n){
    while (n > 0) {
        push(N, n % 2);
        n /= 2;
    }
}