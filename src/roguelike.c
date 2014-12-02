#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 30//ordre de la matrice

typedef struct {
    int ligne;
    int column;
} t_coordonnee;

typedef struct {
    t_coordonnee l1;
    t_coordonnee c1;
    t_coordonnee l2;
    t_coordonnee c2;
} t_salle;

typedef enum {
    VIDE = ' ',
    MUR = '#'
} Case;

Case labyrinthe[TAILLE][TAILLE];

Rectangle lab_dim = {0, 0, TAILLE - 1, TAILLE - 1};

int random2(int a, int b) {
    b +=1;
    return rand() % (b - a) + a;
}

void initialiser() {
    srand(time(NULL));
}

void generer() {
    int i, j, n_salles, s;
    Rectangle * salles;
    for (i = 0 ; i < TAILLE ; i++) {
        for (j = 0 ; j < TAILLE ; j++) {
            labyrinthe[i][j] = MUR;
        }
    }
    n_salles = random2(3, lab_dim.l2 / 5);
    salles = (Rectangle *) malloc(n_salles * sizeof(Rectangle));
    if (random2(0, 1)) {
        salles[0].l1 = lab_dim.l1 + 1;
        salles[0].c1 = random2(lab_dim.c1 + 1, lab_dim.c2 / 4);
    } else {
        salles[0].l1 = random2(lab_dim.l1 + 1, lab_dim.l2 / 4);
        salles[0].c1 = lab_dim.c1 + 1;
    }
    salles[0].l2 = random2(salles[0].l1 + 4, salles[0].l1 + lab_dim.l2 / 3);
    salles[0].c2 = random2(salles[0].c1 + 4, salles[0].c1 + lab_dim.c2 / 3);
    for (s = 0 ; s <= 0 ; s++) {
        for (i = salles[0].l1 ; i < salles[0].l2 ; i++) {
            for (j = salles[0].c1 ; j < salles[0].c2 ; j++) {
                labyrinthe[i][j] = VIDE;
            }
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