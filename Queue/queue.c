#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Enqueue(Teller *T, int antri) {
    insertAkhir(T, antri);
}

void Dequeue(Teller *T) {
    deleteAwal(T);
}

int hitungAntrian (Teller *T) {
    int count = 0;
    address temp = T->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int nomorAntrianGlobal = 0;

void ambilAntrian (Teller *T1, Teller *T2) {

    int Teller1 = hitungAntrian(T1);
    int Teller2 = hitungAntrian(T2);

    nomorAntrianGlobal++;

    if (Teller1 <= Teller2) {
        Enqueue(T1, nomorAntrianGlobal);
    } else {
        Enqueue(T2, nomorAntrianGlobal);
    }
}