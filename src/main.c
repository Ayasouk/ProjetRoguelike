/**
 * @file main.c
 * Fichier de la fonction principale.
 * @author Hector Basset
 * @author Youssef Lamniy
 * @author Ayas Oukache
 * @date 20 novembre 2014
 */

#include <stdlib.h>

#include "interface.h"
#include "roguelike.h"

/**
 * Fonction principale.
 * @return Le code d'erreur.
 */
int main() {//pour l'instant, fonction main pour tester l'interface et la génération
	init_roguelike();
	init_interface();
	generate_maze();
	while (1) {
		display_maze(get_maze(), get_maze_dimension());
		switch (wait_action()) {
			case TOP:
				move_player(NORTH);
				break;
			case BOTTOM:
				move_player(SOUTH);
				break;
			case RIGHT:
				move_player(EAST);
				break;
			case LEFT:
				move_player(WEST);
				break;
			case EXIT:
				final_interface();
				final_roguelike();
				return EXIT_SUCCESS;
		}
	}
}
