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
	display_maze(get_maze(), get_maze_dimension());
	display_message("Un test");
	update_square(PLAYER, get_player_location());
	wait_action();
	move_player(EAST);
	update_square(PLAYER, get_player_location());
	display_message("Coucou");
	wait_action();
	move_player(SOUTH);
	update_square(PLAYER, get_player_location());
	display_message("AH AH");
	wait_action();
	move_player(WEST);
	update_square(PLAYER, get_player_location());
	move_player(NORTH);
	update_square(PLAYER, get_player_location());
	move_player(WEST);
	update_square(PLAYER, get_player_location());
	final_interface();
	final_roguelike();
	return EXIT_SUCCESS;
}
