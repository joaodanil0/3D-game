
#include <defs.h>
#include <iostream>

int main(){

    initscr();
    raw();
    noecho();

    printw("Hello World Ncurses!");
    getch();

    endwin();
    return 0;
}