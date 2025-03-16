#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int value);
void InsertAtFirst(Node** top, int value);
void InsertAtLast(Node** top, int value);
void InsertBetween(Node* top, int target, int value);
void InsertByValue(Node** top, int value);
void DeleteAtFirst(Node** top);
void DeleteAtLast(Node** top);
void DeleteByValue(Node** top, int value);
void DeleteBetween(Node** top, int target);
void DeleteAll(Node** top);
void PrintList(Node* top);

#endif
