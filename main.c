#include "roguelike.h"

int main() {
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
}
