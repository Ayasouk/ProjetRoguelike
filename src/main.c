/**
 * @file main.c
 * Fichier de la fonction principale.
 * @author Hector Basset
 * @author Youssef Lamniy
 * @author Ayas Oukache
 * @date 27 novembre 2014
 */

#include <stdlib.h>

#include "interface.h"

int main() {
	init_interface();
	wait_action();
	final_interface();
	return EXIT_SUCCESS;
}
