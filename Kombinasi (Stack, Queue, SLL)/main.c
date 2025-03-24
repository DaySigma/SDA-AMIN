// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Ghost.h"
#include "LinkedList.c"
#include "Queue.c"
#include "Stack.c"
#include "Ghost.c"

int main() {
    List ghostList;
    Queue ghostQueue;
    Stack successStack;
    int choice;
    char name[50], type[50], power[50], weakness[50];
    char humanWeakness[50];

    // Inisialisasi semua struktur data
    initSLL(&ghostList);
    initQueue(&ghostQueue);
    initStack(&successStack);

    // Tambahkan beberapa hantu awal
    Ghost oni = {"Oni", "Hantu Jepang", "Teriakan mengerikan", "Cahaya terang"};
    Ghost pocong = {"Pocong", "Hantu Lokal", "Melompat di gelap", "Doa"};
    insertGhost(&ghostList, oni);
    insertGhost(&ghostList, pocong);

    // Minta pengguna memasukkan kelemahan manusia
    printf("Masukkan kelemahan manusia (misalnya: gelap, suara keras, dingin): ");
    fgets(humanWeakness, 50, stdin);
    humanWeakness[strcspn(humanWeakness, "\n")] = 0;
    printf("Kelemahan manusia telah ditetapkan: %s\n", humanWeakness);

    while (1) {
        printf("\n=== Simulator Dunia Hantu ===\n");
        printf("1. Kelola Database Hantu (SLL)\n");
        printf("2. Kelola Antrian Hantu (Queue)\n");
        printf("3. Kelola Riwayat Keberhasilan (Stack)\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 4) {
            printf("Keluar dari program.\n");
            break;
        }

        switch (choice) {
        case 1: // SLL: Database Hantu
            printf("\n=== Kelola Database Hantu ===\n");
            printf("1. Tambah Hantu\n2. Edit Hantu\n3. Hapus Hantu\n4. Tampilkan Hantu\nPilih: ");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                printf("Masukkan nama hantu: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Masukkan jenis hantu: ");
                fgets(type, 50, stdin);
                type[strcspn(type, "\n")] = 0;
                printf("Masukkan kekuatan khusus: ");
                fgets(power, 50, stdin);
                power[strcspn(power, "\n")] = 0;
                printf("Masukkan kelemahan: ");
                fgets(weakness, 50, stdin);
                weakness[strcspn(weakness, "\n")] = 0;
                Ghost newGhost;
                strcpy(newGhost.name, name);
                strcpy(newGhost.type, type);
                strcpy(newGhost.power, power);
                strcpy(newGhost.weakness, weakness);
                insertGhost(&ghostList, newGhost);
            } else if (choice == 2) {
                printf("Masukkan nama hantu yang akan diedit: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                editGhost(&ghostList, name);
            } else if (choice == 3) {
                printf("Masukkan nama hantu yang akan dihapus: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                deleteGhost(&ghostList, name);
            } else if (choice == 4) {
                displayGhosts(&ghostList);
            }
            break;

        case 2: // Queue: Antrian Hantu
            printf("\n=== Kelola Antrian Hantu ===\n");
            printf("1. Tambah Hantu ke Antrian\n2. Hantu Menakuti\n3. Tampilkan Antrian\nPilih: ");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                printf("Masukkan nama hantu: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                address ghostNode = findGhost(&ghostList, name);
                if (ghostNode != NULL) {
                    enqueueGhost(&ghostQueue, ghostNode->ghost);
                } else {
                    printf("Hantu '%s' tidak ada di database!\n", name);
                }
            } else if (choice == 2) {
                Ghost ghost = dequeueGhost(&ghostQueue);
                if (strlen(ghost.name) > 0) {
                    int success = scareSuccess(ghost, humanWeakness);
                    char message[100];
                    createScareMessage(ghost, success, message);
                    printf("%s\n", message);
                    if (success) {
                        pushSuccess(&successStack, ghost);
                    } else {
                        enqueueGhost(&ghostQueue, ghost);
                    }
                }
            } else if (choice == 3) {
                displayQueue(&ghostQueue);
            }
            break;

        case 3: // Stack: Riwayat Keberhasilan
            printf("\n=== Kelola Riwayat Keberhasilan ===\n");
            printf("1. Undo Keberhasilan\n2. Tampilkan Riwayat\nPilih: ");
            scanf("%d", &choice);
            getchar();
            if (choice == 1) {
                Ghost ghost = popSuccess(&successStack);
                if (strlen(ghost.name) > 0) {
                    enqueueGhost(&ghostQueue, ghost);
                    printf("Hantu '%s' dikembalikan ke antrian.\n", ghost.name);
                }
            } else if (choice == 2) {
                displaySuccess(&successStack);
            }
            break;

        default:
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}