#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int antri;
} Queue;

typedef struct tElmtList *address;
typedef struct tElmtList {
    Queue info;
    address next;
} ElmtList;

typedef struct {
    address head;
    address tail;
} Teller;

void createTeller(Teller *T);
address createNode(int antri);
int isEmpty(Teller *T);
void printAntri(Teller *T);
void insertAkhir(Teller *T, int antri);
void deleteAwal(Teller *T);

#endif
