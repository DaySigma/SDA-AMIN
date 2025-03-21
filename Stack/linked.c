#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "stack.h"

address createNode(int biner){
    address newNode = (address)malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        newNode->info.biner = biner;
        newNode->next = NULL;
    }
}

int isEmpty(Node N){
    return (N.first == NULL);
}

void push(Node *N, int biner){
    address newNode = createNode(biner);
    if (newNode != NULL) {
        newNode->next = N->first;
        N->first = newNode;
    }
}

int pop(Node *N){
    if (!isEmpty(*N)) {
        address temp = N->first; 
        N->first = N->first->next;
        return temp->info.biner;
        free(temp);
    }
    return -1;
}

void printNode(Node N){
    address temp = N.first;
    while (temp != NULL) {
        printf("%d ", temp->info.biner);
        temp = temp->next;
    }
    printf("\n");
}