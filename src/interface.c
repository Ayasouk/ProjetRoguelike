/**
 * @file interface.c
 * Fichier implémentant l'interface avec l'utilisateur.
 * Cette implémentation utilise le terminal.
 * Elle le met en mode non canonique et désactive l'affichage de la saisie afin d'une meilleure interaction avec l'utilisateur.
 * Elle utilise les séquences ANSI pour les couleurs, la mise en forme tu texte et le déplacement du curseur.
 * @author Hector Basset
 * @date 1 décembre 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include "ansi.h"
#include "boolean.h"
#include "geo.h"
#include "interface.h"
#include "roguelike.h"

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

/**
 * Marge entre la fenre et le bord du terminal.
 */
#define WINDOW_MARGIN 6

/**
 * Marge entre la fenêtre et le labyrinthe.
 */
#define WINDOW_TOP_MARGIN 2

/**
 * Nombre de lignes qui composent la fenêtre quand le message est vide.
 */
#define NB_LINES_ON_EMPTY_MSG 5

/**
 * Hauteur actuelle du labyrinthe.
 */
int maze_height = 0;

/**
 * Hauteur actuelle de la fenêtre.
 */
int window_height = 0;

/**
 * Fonction interne permettant d'afficher une case en fonction de son type.
 * @param square Le type de case à afficher.
 */
void print_square(Square square) {
	switch (square) {
		case AIR:
			ansi_set_bg_color(ANSI_BLACK);
			putchar(' ');
			ansi_set_bg_color(ANSI_DEFAULT_COLOR);
			break;
		case WALL:
			ansi_set_bg_color(ANSI_LIGHT_GREY);
			putchar(' ');
			ansi_set_bg_color(ANSI_DEFAULT_COLOR);
			break;
		case PLAYER:
			ansi_set_bg_color(ANSI_BLACK);
			ansi_set_color(ANSI_GREEN);
			ansi_bold(true);
			fputs("☻", stdout);
			ansi_bold(false);
			ansi_set_color(ANSI_DEFAULT_COLOR);
			ansi_set_bg_color(ANSI_DEFAULT_COLOR);
			break;
	}
}

/**
 * Retourne la largeur du terminal en nombre de caractère.
 * @return La largeur du terminal en nombre de caractère.
 */
short get_terminal_width() {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return size.ws_col;
}

/**
 * Affiche le haut de la fenêtre.
 */
void print_window_top() {
	const int width = get_terminal_width() - 2 * WINDOW_MARGIN;
	int i;
	ansi_set_column(WINDOW_MARGIN + 1);
	ansi_set_color(ANSI_LIGHT_BLUE);
	fputs("╔", stdout);
	for (i = 0 ; i < width - 2 ; i++) {
		fputs("═", stdout);
	}
	fputs("╗", stdout);
}

/**
 * Affiche une ligne de fenêtre vide.
 */
void print_window_line() {
	const int width = get_terminal_width() - 2 * WINDOW_MARGIN;
	ansi_clear_line();
	ansi_set_column(WINDOW_MARGIN + 1);
	ansi_set_color(ANSI_LIGHT_BLUE);
	fputs("║", stdout);
	ansi_set_column(WINDOW_MARGIN + width);
	fputs("║", stdout);
}

/**
 * Affiche le bas de la fenêtre.
 */
void print_window_bottom() {
	const int width = get_terminal_width() - 2 * WINDOW_MARGIN;
	int i;
	ansi_set_column(WINDOW_MARGIN + 1);
	ansi_set_color(ANSI_LIGHT_BLUE);
	fputs("╠", stdout);
	for (i = 0 ; i < width - 2 ; i++) {
		fputs("═", stdout);
	}
	fputs("╣", stdout);
	putchar('\n');
	print_window_line();
	ansi_set_column(WINDOW_MARGIN + 4);
	ansi_set_color(ANSI_LIGHT_GREY);
	fputs("Oui : ", stdout);
	ansi_set_color(ANSI_LIGHT_GREEN);
	putchar('O');
	ansi_set_color(ANSI_LIGHT_BLUE);
	ansi_set_column(WINDOW_MARGIN + width - 9);
	ansi_set_color(ANSI_LIGHT_GREY);
	fputs("Non : ", stdout);
	ansi_set_color(ANSI_LIGHT_RED);
	putchar('N');
	ansi_set_color(ANSI_LIGHT_BLUE);
	putchar('\n');
	print_window_line();
	ansi_set_column(WINDOW_MARGIN + 4);
	ansi_set_color(ANSI_LIGHT_GREY);
	fputs("Frapper : ", stdout);
	ansi_set_color(ANSI_GREY);
	fputs("ESPACE", stdout);
	ansi_set_color(ANSI_LIGHT_BLUE);
	ansi_set_column(WINDOW_MARGIN + width - 17);
	ansi_set_color(ANSI_LIGHT_GREY);
	fputs("Quitter : ", stdout);
	ansi_set_color(ANSI_RED);
	fputs("ECHAP", stdout);
	ansi_set_color(ANSI_LIGHT_BLUE);
	putchar('\n');
	ansi_set_column(WINDOW_MARGIN + 1);
	fputs("╚", stdout);
	for (i = 0 ; i < width - 2 ; i++) {
		fputs("═", stdout);
	}
	fputs("╝", stdout);
}

void init_interface() {
	tcgetattr(STDIN_FILENO, &before);//sauvegarde des attributs du terminal avant le jeu
	actual = before;//copie de ces attributs
#ifdef __APPLE__
#ifdef TARGET_OS_MAC
	actual.c_cc[VMIN] = 1;//nombre minimum de caractères pour la lecture à 1
#endif
#else
	actual.c_cc[VMIN] = 0;//nombre minimum de caractères pour la lecture à 0
#endif
	actual.c_cc[VTIME] = 0;//temps d'attente lors de la lecture à 0
	actual.c_lflag &= ~ECHO;//désactivation de l'affichage de la saisie
	actual.c_lflag &= ~ICANON;//passage en mode non canonique
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &actual);//appliquation des attributs au terminal
	ansi_set_color(ANSI_DEFAULT_COLOR);
	ansi_set_bg_color(ANSI_DEFAULT_COLOR);
	ansi_set_font(ANSI_DEFAULT_FONT);
	ansi_hide_cursor(true);
	ansi_clear_screen();
}

void final_interface() {
	ansi_down(window_height + WINDOW_TOP_MARGIN + maze_height);
	putchar('\n');
	ansi_set_color(ANSI_DEFAULT_COLOR);
	ansi_set_bg_color(ANSI_DEFAULT_COLOR);
	ansi_hide_cursor(false);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &before);//réappliquation des atributs d'avant le jeu
	putchar('\n');
}

void display_maze(Square * maze, Dimension * dimension) {
	const int width = get_terminal_width();
	int i, j;
	ansi_clear_screen_after();
	for (i = 0 ; i < dimension->vertical ; i++) {
		ansi_set_column((width - dimension->horizontal) / 2);
		for (j = 0 ; j < dimension->horizontal ; j++) {
			print_square(maze[i * dimension->vertical + j]);
		}
		putchar('\n');
	}
	maze_height = dimension->vertical;
	ansi_previous_line(maze_height);
	clear_message();//on affiche un message vide
}

void display_message(char message[]) {
	const int width = get_terminal_width() - 2 * WINDOW_MARGIN, length = strlen(message);
	int i, lines = -1;
	ansi_down(maze_height);
	for (i = 0 ; i < WINDOW_TOP_MARGIN ; i++) {
		putchar('\n');
	}
	print_window_top();
	for (i = 0 ; i < length ; i++) {
		if (i % (width - 4) == 0) {
			putchar('\n');
			print_window_line();
			lines++;
			ansi_set_color(ANSI_LIGHT_GREY);
			ansi_set_column(WINDOW_MARGIN + 3);
		}
		putchar(message[i]);
	}
	putchar('\n');
	print_window_bottom();
	ansi_clear_screen_after();
	window_height = NB_LINES_ON_EMPTY_MSG + lines;
	ansi_previous_line(window_height + WINDOW_TOP_MARGIN + maze_height);
}

void clear_message() {
	int i;
	ansi_down(maze_height);
	for (i = 0 ; i < WINDOW_TOP_MARGIN ; i++) {
		putchar('\n');
	}
	print_window_top();
	putchar('\n');
	print_window_line();
	putchar('\n');
	print_window_bottom();
	ansi_clear_screen_after();
	window_height = NB_LINES_ON_EMPTY_MSG;
	ansi_previous_line(window_height + WINDOW_TOP_MARGIN + maze_height);
}

Action wait_action() {
	while (1) {
		switch (getchar()) {
			case 27://code retourné par cetraines touche comme ECHAP ou les touches flêchées
				usleep(1);
				if (getchar() == 91) {//la pression d'une touche flêche provoque la saisie de trois caractères (27 91 6x), les instructions suivantes permettent de voir si il s'agit donc d'une touche flêchée ou d'une autre touche spéciale 
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
			case 'o':
			case 'O':
				return ACCEPT;
			case 'n':
			case 'N':
				return DENY;
		}
	}
}

void wait_ready() {
	fflush(stdout);
}
