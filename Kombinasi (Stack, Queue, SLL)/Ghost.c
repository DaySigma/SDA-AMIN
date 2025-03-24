#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ghost.h"

int scareSuccess(Ghost ghost, char *humanWeakness) {
    srand(time(NULL));
    int baseChance = rand() % 100; // Peluang acak (0-99)
    int successChance = 70;

    if (strstr(ghost.power, humanWeakness) != NULL) {
        successChance += 20; // Tambah 20% peluang
        printf("Kekuatan hantu '%s' (%s) sesuai dengan kelemahan manusia (%s), peluang meningkat!\n", 
               ghost.name, ghost.power, humanWeakness);
    }

    return baseChance < successChance;\
}

void createScareMessage(Ghost ghost, int success, char *message) {
    if (success) {
        sprintf(message, "Hantu %s (%s) berhasil menakuti dengan %s! Manusia pingsan ketakutan!", 
                ghost.name, ghost.type, ghost.power);
    } else {
        sprintf(message, "Hantu %s (%s) gagal menakuti dengan %s. Manusia malah tertawa!", 
                ghost.name, ghost.type, ghost.power);
    }
}