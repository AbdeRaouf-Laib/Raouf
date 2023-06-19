#include <curses.h>
#include<ncurses.h>

int main(){

initscr();
keypad(stdscr,TRUE);
int ch = getch();
    printw("%d ",ch);

getch();

}