#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int biner;
} Stack;

typedef struct tElmtList *address;
typedef struct tElmtList {
    Stack info;
    address next;
} ElmtList;

typedef struct {
    address first;
} Node;

address createNode(int biner);
int isEmpty(Node N);
void push(Node *N, int biner);
int pop(Node *N);
void printNode(Node N);

#endif