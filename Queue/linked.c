#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"


void createTeller(Teller *T) {
    T->head = NULL;
    T->tail = NULL;
}

address createNode (int antri){
    address newNode = (address) malloc(sizeof(ElmtList));
    if (newNode != NULL) {
        newNode->info.antri = antri;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAkhir(Teller *T, int antri) {
    address newNode = createNode(antri);
    if (newNode != NULL) {
        if (isEmpty(T)) {
            T->head = newNode;
            T->tail = newNode;
        } else {
            T->tail->next = newNode;
            T->tail = newNode;
        }
    }
}

void deleteAwal(Teller *T) {
    if (!isEmpty(T)) {
        address temp = T->head;
        if (T->head == T->tail) {
            T->head = NULL;
            T->tail = NULL;
        } else {
            T->head = T->head->next;
        }
        free(temp);
    }
}

int isEmpty(Teller *T) {
    return T->head == NULL;
}

void printAntri(Teller *T) {
    address temp = T->head;
    while (temp != NULL) {
        printf("%d ", temp->info.antri);
        temp = temp->next;
    }
    printf("\n");
}