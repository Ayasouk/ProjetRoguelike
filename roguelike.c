#include <stdio.h>
#include <stdlib.h>

#define TAILLE 30//ordre de la matrice

typedef struct {
    int ligne;
    int column;
} Coordonnee;

typedef enum {
    VIDE = ' ',
    MUR = '#'
} Case;

Case labyrinthe[TAILLE][TAILLE];

void initialiser() {
}

void generer() {
    int i, j;
    for (i = 0 ; i < TAILLE ; i++) {
        for (j = 0 ; j < TAILLE ; j++) {
            labyrinthe[i][j] = MUR;
        }
    }
}

void afficher() {
    int i, j;
    for (i = 0 ; i < TAILLE ; i++) {
        for (j = 0 ; j < TAILLE ; j++) {
            printf("%c", labyrinthe[i][j]);
        }
        printf("\n");
    }
}

void deplacement() {

}

int gagne() {
    return 0;
}