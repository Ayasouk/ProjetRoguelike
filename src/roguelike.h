/**
 * @file roguelike.h
 * Fichier définissant les types et les fonctions du Roguelike.
 * @author Hector Basset
 * @author Youssef Lamniy
 * @author Ayas Oukache
 * @date 20 novembre 2014
 */

#ifndef ROGUELIKE_H

#define ROGUELIKE_H

#include "geo.h"

/**
 * Type énuméré représentant les différents types de case possibles.
 */
typedef enum {

	/**
	 * Case vide.
	 */
    AIR = ' ',

	/**
	 * Case étant un mur.
	 */
    WALL = '#',

	/**
	 * Case contenant le joueur.
	 */
    PLAYER = 'p'
} Square;

/**
 * Type énuméré représentant les différents directions vers lesquelles le personnage peut se déplacer.
 */
typedef enum {

	/**
	 * Nord (haut).
	 */
    NORTH,

	/**
	 * Est (droite).
	 */
    EAST,

	/**
	 * Sud (bas).
	 */
    SOUTH,

	/**
	 * Ouest (gauche).
	 */
    WEST
} Direction;

/**
 * Fonction initialisant le jeu, ne doit être appellée qu'une seule fois et avant toutes les autres relatives au jeu.
 */
void init_roguelike();

/**
 * Fonction terminant le jeu, ne doit être appellée qu'une seule fois et après toutes les autres relatives au jeu.
 */
void final_roguelike();

/**
 * Fonction retournant le labyrinthe.
 * @return Le pointeur sur la matrice de case contenant le labyrinthe.
 */
Square * get_maze();

/**
 * Fonction retournant les dimensions du labyrinthe.
 * @return Le pointeur vers la dimension du labyrinthe.
 */
Dimension * get_maze_dimension();

/**
 * Fonction générant le labyrinthe.
 */
void generate_maze();

/**
 * Fonction retournant la localisation du joueur.
 * @return Le pointeur vers la localisation du joueur.
 */
Location * get_player_location();

/**
 * Déplace le joueur vers la direction donnée.
 * @param direction La direction vers laquelle le joueur doit se déplacer.
 */
void move_player(Direction direction);

#endif
