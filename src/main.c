#include <stdlib.h>
#include "roguelike.h"

int main() {
    initialiser();
    generer();
    afficher();
    return EXIT_SUCCESS;
}

/*int main() {
	initialiser();
	while (1) {
        generer();
		while (1) {
			afficher();
			deplacement();
			if (gagne()) {
				break;
			}
		}
	}
    return EXIT_SUCESS;
}*/