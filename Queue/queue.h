#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

void Enqueue(Teller *T, int antri);
void Dequeue(Teller *T);
int hitungAntrian(Teller *T);
void ambilAntrian(Teller *T1, Teller *T2);
extern int nomorAntrianGlobal;

#endif