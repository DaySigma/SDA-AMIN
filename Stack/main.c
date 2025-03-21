#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "linked.c"

int main(){

    Node N = {NULL};

    int n;
    printf("Masukkan angka: ");
    fflush(stdout);
    scanf("%d", &n);

    convertToBinary(&N, n);
    printNode(N);

    int stack_popped = pop(&N);
    printf("Pop : %d\n", stack_popped);

    printf("Setelah pop: ");
    printNode(N);

}