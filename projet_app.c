#include <bits/types/FILE.h>
#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "interface.h"
#include "main.h"

typedef struct module{
    char name_mod[40];
    int coefficient;
    float note;
}mod;
int main()
{
    dub:
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    keypad(stdscr, TRUE);
    refresh();
    int bo;
    bo = print_face();
    if(bo == 27 ){
        endwin();
        return 0;
    }
    clear();
    int bi;
    bi = print_face_main();
    if(bi == 32){
        goto dub;
    }
    clear();
    endwin();
return 0;
}