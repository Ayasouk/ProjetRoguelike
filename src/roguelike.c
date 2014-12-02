/**
 * @file roguelike.c
 * Fichier implémentant les types et les fonctions du Roguelike.
 * @author Hector Basset
 * @author Youssef Lamniy
 * @author Ayas Oukache
 * @date 20 novembre 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "geo.h"
#include "roguelike.h"

/**
 * Le pointeur vers la matrice de case contenant le labyrinthe.
 */
Square * maze;

/**
 * Les dimensions du labyrinthe.
 */
Dimension maze_dimension;

Location player_location;

void init_roguelike() {
    srand(time(NULL));
    maze = NULL;
    maze_dimension.horizontal = maze_dimension.vertical = -1;
    player_location.row = player_location.column = -1;
}

void final_roguelike() {
	free(maze);//libération de l'espace mémoire alloué au labyrinthe, inutile de vérifier si NULL car free(NULL) n'a tout simplement aucun effet
}

Square * get_maze() {
	return maze;
}

Dimension * get_maze_dimension() {
	return &maze_dimension;
}

void generate_maze() {
	int i;
	free(maze);//libération de l'espace mémoire alloué au labyrinthe, inutile de vérifier si NULL car free(NULL) n'a tout simplement aucun effet
	maze = (Square *) malloc(20 * 20 * sizeof(Square));//allocation de la mémoire nécessaire pour stocker le labyrinthe
	maze_dimension.horizontal = maze_dimension.vertical = 20;//sélection des dimensions du labyrinthe, pour l'instant constante à 20
	for (i = 0 ; i < maze_dimension.horizontal * maze_dimension.vertical ; i++) {//remplissage du labyrinthe par des murs
		maze[i] = WALL;
	}
	//choix du nombre de pièces...
	//choix de leur taille et de leur placement...
	//génération des couloirs
	player_location.row = player_location.column = 2;//placement du joueur, pour l'instant arbitrairement à 2:2
}

Location * get_player_location() {
	return &player_location;
}

void move_player(Direction direction) {
	switch (direction) {
		case NORTH:
			player_location.row--;
			break;
		case EAST:
			player_location.column++;
			break;
		case SOUTH:
			player_location.row++;
			break;
		case WEST:
			player_location.column--;
			break;
	}
}

/*Rectangle lab_dim = {0, 0, TAILLE - 1, TAILLE - 1};

int random2(int a, int b) {
    b +=1;
    return rand() % (b - a) + a;
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
}*/
