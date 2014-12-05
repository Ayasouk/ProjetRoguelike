/**
 * @file ansi.h
 * Fichier définissant les fonctions générant des séquences ANSI permettant d'interagir avec le terminal et de modifier la mise en forme du texte.
 * @author Hector Basset
 * @date 1 décembre 2014
 */

#ifndef ANSI_H

#define ANSI_H

#include "boolean.h"

/**
 * Type énuméré définissant les différentes couleurs directement sélectionnables en ANSI.
 */
typedef enum {

	/**
	 * Noir.
	 */
	ANSI_BLACK = 30,

	/**
	 * Rouge.
	 */
	ANSI_RED,

	/**
	 * Vert.
	 */
	ANSI_GREEN,

	/**
	 * Orange/Marron.
	 */
	ANSI_BROWN,

	/**
	 * Bleu.
	 */
	ANSI_BLUE,

	/**
	 * Magenta.
	 */
	ANSI_MAGENTA,

	/**
	 * Cyan.
	 */
	ANSI_CYAN,

	/**
	 * Gris clair.
	 */
	ANSI_LIGHT_GREY,

	/**
	 * Gris.
	 */
	ANSI_GREY = 90,

	/**
	 * Rouge clair.
	 */
	ANSI_LIGHT_RED,

	/**
	 * Vert clair.
	 */
	ANSI_LIGHT_GREEN,

	/**
	 * Jaune.
	 */
	ANSI_YELLOW,

	/**
	 * Bleu clair.
	 */
	ANSI_LIGHT_BLUE,

	/**
	 * Rose.
	 */
	ANSI_PINK,

	/**
	 * Cyan clair.
	 */
	ANSI_LIGHT_CYAN,

	/**
	 * Blanc.
	 */
	ANSI_WHITE,

	/**
	 * Couleur par défaut, varie selon les terminaux.
	 */
	ANSI_DEFAULT_COLOR = 39
} ANSIColor;

/**
 * Type énuméré définissant les différentes valeurs possibles de police de caractère dans le terminal.
 */
typedef enum {

	/**
	 * Police par défaut du terminal.
	 */
	ANSI_DEFAULT_FONT = 10,

	/**
	 * Police alternative 1.
	 */
	ANSI_ALTERNATE_FONT_1,

	/**
	 * Police alternative 2.
	 */
	ANSI_ALTERNATE_FONT_2,

	/**
	 * Police alternative 3.
	 */
	ANSI_ALTERNATE_FONT_3,

	/**
	 * Police alternative 4.
	 */
	ANSI_ALTERNATE_FONT_4,

	/**
	 * Police alternative 5.
	 */
	ANSI_ALTERNATE_FONT_5,

	/**
	 * Police alternative 6.
	 */
	ANSI_ALTERNATE_FONT_6,

	/**
	 * Police alternative 7.
	 */
	ANSI_ALTERNATE_FONT_7,

	/**
	 * Police alternative 8.
	 */
	ANSI_ALTERNATE_FONT_8,

	/**
	 * Police alternative 9.
	 */
	ANSI_ALTERNATE_FONT_9
} ANSIFont;

void ansi_up(unsigned int n);

void ansi_down(unsigned int n);

void ansi_right(unsigned int n);

void ansi_left(unsigned int n);

void ansi_next_line(unsigned int n);

void ansi_previous_line(unsigned int n);

void ansi_set_column(unsigned int a);

void ansi_set_position(unsigned int a, unsigned int b);

void ansi_clear_screen();

void ansi_clear_screen_before();

void ansi_clear_screen_after();

void ansi_clear_line();

void ansi_clear_line_before();

void ansi_clear_line_after();

void ansi_scroll_up(unsigned int n);

void ansi_scroll_down(unsigned int n);

void ansi_save_position();

void ansi_restore_position();

void ansi_hide_cursor();

void ansi_show_cursor();

void ansi_set_color(ANSIColor color);

void ansi_set_bg_color(ANSIColor color);

void ansi_set_color_index(unsigned char color);

void ansi_set_bg_color_index(unsigned char color);

void ansi_set_color_rgb(unsigned char red, unsigned char green, unsigned char blue);

void ansi_set_bg_color_rgb(unsigned char red, unsigned char green, unsigned char blue);

void ansi_set_font(ANSIFont font);

void ansi_normal();

void ansi_bold(boolean bold);

void ansi_underlined(boolean underlined);

void ansi_overlined(boolean overlined);

void ansi_italic(boolean italic);

void ansi_framed(boolean framed);

#endif
