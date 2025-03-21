#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "linked.h"
#include "linked.c"
#include "queue.c"


int main(){

    int n;
    Teller T1, T2;

    createTeller(&T1);
    createTeller(&T2);

    while (1) {
        printf("SELAMAT DATANG DI BANK ABC\n");
        printf("==========================\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &n);
        
        switch (n) {
            case 1:
                ambilAntrian(&T1, &T2);
                printf("Nomor antrian: %d\n", nomorAntrianGlobal);
                break;
            case 2:
                Dequeue(&T1);
                Dequeue(&T2);
                printf("Antrian telah diproses\n");
                break;
            case 3:
                printf("Antrian Teller 1: \n");
                printAntri(&T1);
                printf("Antrian Teller 2: \n");
                printAntri(&T2);
                break;
            default:
                printf("Pilihan tidak tersedia\n");
                break;
        }
    }
    return 0;
}
