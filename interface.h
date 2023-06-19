//مكتبة interface.h
#include <curses.h>
#include <ncurses.h>
#include "logo_title.h"
#include<locale.h>

void ver_sup(WINDOW * ver_sp){  
        ver_sp = newwin(4,40,35,120);
        mvwprintw(ver_sp,1,1,"version: 1.00.000.102.H_kakashi R&H");
        mvwprintw(ver_sp,2, 1,"Sponsor: 3moke Uchiha_MADARA");
        wrefresh(ver_sp);
}
int Face_About(){
    int ba;
    WINDOW * ABOUT = newwin(3,40,17,60);
        wrefresh(ABOUT);
        wprintw(ABOUT,"NOT FOUND!!!press 'enter' for return...");
        wrefresh(ABOUT);
        ba = getch();
        if(ba == 10){
            clear();
            refresh();
            return ba = 0;
        }
        else{
            clear();
            refresh();
            Face_About();
        }
}
void face_about(int k,WINDOW * about){
    about = newwin(3,11,1,155);
    if( k == 1){
        wbkgd(about, COLOR_PAIR(1));
    }
    box(about,0,0);
    wattron(about,A_BOLD);
    mvwprintw(about,1,1,"ABOUT (!)");
    wattroff(about,A_BOLD);
    wrefresh(about);
}
void face_hello(int *y1,int *x1,WINDOW * hello){
    int y,x; 
    hello = newwin(4,12,3,8);
    wattron(hello,A_BOLD);
    wprintw(hello,"WELCOME; to,");
    wattroff(hello,A_BOLD);
    wrefresh(hello);
    getmaxyx(hello,y,x);
    *y1 = y;
    *x1 = x;
}
void face_title(int y1,int x1,int *z1,int *r1,WINDOW * title){
    title = newwin(200, 200, y1 + 4 , x1 + 3 );
    wattron(title,A_BOLD);
    titlefe(&*title);
    int z,r;
    getyx(title, z, r);
    *z1 = z;
    *r1 = r;
}
void face_list(int z1,int r1,WINDOW * list){
    list = newwin(4, 45,z1 + 15, r1 );
    wprintw(list,("!!!....press ('F1') how to use ;\n"));
    wprintw(list,("!!!....press ('ENTER') to continue ;\n"));
    wprintw(list,("!!!....press ('ESC') to exit ;\n"));
    wrefresh(list);
}
int face_F1(){
    int ba;
    WINDOW * F1 = newwin(3,40,17,60);
        wrefresh(F1);
        wprintw(F1,"NOT FOUND!!!press 'ENTER' for return...");
        wrefresh(F1);
        ba = getch();
        if(ba == 10){
            clear();
            refresh();
            return ba = 0;
        }
        else{
            clear();
            refresh();
            face_F1();
        }
}
int print_face(){
    dub:
    int bo ;
    int k = 0;
    int b ;
    bo = 258;
    k = 0;
    do{
        WINDOW * title1;
        WINDOW * about1;
        WINDOW * hello1;
        WINDOW * list1;
        WINDOW * ver_sp1;
        int x1;
        int y1;
        int z1,r1;
        face_about(k,&*about1); 
        face_hello(&y1,&x1,&*hello1);
        face_title(y1,x1,&z1,&r1,&*title1);
        face_list(z1,r1,&*list1);
        ver_sup(&*ver_sp1);
        delwin(title1);
        delwin(about1);
        delwin(hello1);
        delwin(list1);
        delwin(ver_sp1);
            bo = getch();
            if(bo == 258 || bo == 259)
                k++;
            if(k == 1){
                if(bo == 10){
                    clear();
                    refresh();
                    bo = Face_About();
                    break;
                }
            }  
            if(k > 1)
                k = 0;
    }while( bo  != 10 &&  bo != 27 && bo !=265);
    if(bo == 265){
    clear();
    refresh();
    bo = face_F1();
    }
    if(bo == 0){
        goto dub;
    }

    if(bo == 27){
        return bo;
    }
}