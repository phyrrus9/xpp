/*
 * Simple ncurses window test program for x++
 * ~2013 Ethan Laur
 */
#include <curses.h>
int start(int argc, char * * argv)
{
	initscr();
	noecho();
	refresh();
	WINDOW *w = newwin(7, 25, 0, 0);
	wrefresh(w);
	wprintw(w, "Hello World!\n\rPress any key to exit ");
	wrefresh(w);
	getch();
	endwin();
	return 0;
}
