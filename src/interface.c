/**
 * @file interface.c
 * Fichier implémentant l'interface avec l'utilisateur.
 * Cette implémentation utilise le terminal.
 * Elle le met en mode non canonique et désactive l'affichage de la saisie afin d'une meilleure interaction avec l'utilisateur.
 * Elle utilise les séquences AINSI pour les couleurs et le déplacement du curseur.
 * @author Hector Basset
 * @date 1 décembre 2014
 */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "interface.h"

/**
 * Type renommant termios pour plus de clarté
 */
typedef struct termios TerminalAttribut;

/**
 * Variable servant à stocker les attributs du terminal avant le jeu.
 */
TerminalAttribut before;

/**
 * Variable servant à stocker les attributs du terminal pendant le jeu.
 */
TerminalAttribut actual;

void init_interface() {
	tcgetattr(STDIN_FILENO, &before);//sauvegarde des attributs du terminal avant le jeu
	actual = before;//copie de ces attributs
	actual.c_cc[VMIN] = 0;//nombre minimum de caractères pour la lecture à 0
	actual.c_cc[VTIME] = 0;//temps d'attente lors de la lecture à 0
	actual.c_lflag &= ~ECHO;//désactivation de l'affichage des caractères tapés
	actual.c_lflag &= ~ICANON;//passage en mode non canonique
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &actual);//appliquation des attributs au terminal
}

void final_interface() {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &before);//réappliquation des atributs d'avant le jeu
}

void display_message(char message[]) {
	puts(message);
}

Action wait_action() {
	while (1) {
		switch (getchar()) {
			case 27:
				usleep(1);
				if (getchar() == 91) {
					switch (getchar()) {
						case 65:
							return TOP;
						case 66:
							return BOTTOM;
						case 67:
							return RIGHT;
						case 68:
							return LEFT;
					}
				} else {
					return EXIT;
				}
			case ' ':
				return HIT;
		}
	}
}

void update() {
	fflush(stdout);
}
