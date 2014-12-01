/**
 * @file interface.h
 * Fichier définissant l'interface avec l'utilisateur.
 * @author Hector Basset
 * @date 1 décembre 2014
 */

#ifndef INTERFACE_H

#define INTERFACE_H

/**
 * Type énuméré définissant les différentes actions voulues par l'utilisateur.
 */
typedef enum {

	/**
	 * Aller vers le haut.
	 */
	TOP,

	/**
	 * Aller vers le bas.
	 */
	BOTTOM,

	/**
	 * Aller à droite.
	 */
	RIGHT,

	/**
	 * Aller à gauche.
	 */
	LEFT,

	/**
	 * Quitter/Sortir.
	 */
	EXIT,

	/**
	 * Frapper.
	 */
	HIT
} Action;

/**
 * Initialise l'interface.
 */
void init_interface();

/**
 * Termine l'interface.
 */
void final_interface();

/**
 * Affiche un message à l'utilisateur.
 * @param message Le message à afficher à l'utilisateur.
 */
void display_message(char message[]);

/**
 * Affiche un message à l'utilisateur.
 * @return Le type d'action souhaitée par l'utilisateur.
 */
Action wait_action();

/**
 * Met à jour l'interface.
 */
void update();

#endif
