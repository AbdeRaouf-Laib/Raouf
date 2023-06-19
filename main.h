//main.h lib
#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "win_add.h"
#include<locale.h>
#include "list_stu.h"
#include "win_rserch.h"
#include "win_upd.h"
#include "win_del.h"
void face_return_exit(WINDOW * big_win3,int k,int ki){
    WINDOW * return_exit = subwin(big_win3,3,19,11,2);
    WINDOW * exit = subwin(big_win3,3,19,14,2);
    if(k != 0){
        wclear(exit);
        wclear(return_exit);
    }
    else if(k == 0){
        if(ki == 0){
                wattron(return_exit,COLOR_PAIR(3));
                box(return_exit,0,0);
                mvwprintw(return_exit,1,1.5,"*.....return   ");
                wattroff(return_exit,COLOR_PAIR(3)); 
                box(exit,0,0);
                mvwprintw(exit,1,1.5,"*.....exit   ");
                wrefresh(exit);    
            }  
        else if(ki == 1){   
            box(return_exit,0,0);
            mvwprintw(return_exit,1,1.5,"*.....return");
            wattron(exit,COLOR_PAIR(3));
               box(exit,0,0);
               mvwprintw(exit,1,1.5,"*.....exit       ");
            wattroff(exit,COLOR_PAIR(3));
        }
    }
}
void face_how_use(WINDOW * big_win3 ,int k){
    WINDOW * how_use = subwin(big_win3, 4, 19, 2, 2);
    if(k != 0){
        wclear(how_use);
    }
    else{
        mvwprintw(big_win3,2,1.5,"('ENTER'):to selcte");
        mvwprintw(big_win3,4,1.5,"('SPACE'):to returne");
        mvwprintw(big_win3,6,1.5,"('ESC'):to exit");
        wrefresh(how_use);
    }
}
void face_big_win3(int k,int ki){
    WINDOW * big_win3 = newwin(15,22,3,1);
    if(k == 0){
        box(big_win3,0,0);
    }
        face_how_use(&* big_win3,k);
        face_return_exit(&* big_win3,k,ki);
        wrefresh(big_win3);
}
void face_tape(WINDOW * tape ,int * cy1, int * cx1,int k,int ki){
    tape = newwin(3,18,0,0);
    wborder(tape,'|','|','-','-','+','+','+','+');
    if(k != 0){
        face_big_win3(k,ki);
        wattron(tape,A_BOLD);
        mvwprintw(tape,1,7,"main");
        wattroff(tape,A_BOLD);
    }
    else if(k == 0){
        face_big_win3(k,ki);
        wbkgd(tape,COLOR_PAIR(1));
        wattron(tape,A_BOLD | COLOR_PAIR(2));
        mvwprintw(tape,1,7,"main");
        wattroff(tape,A_BOLD | COLOR_PAIR(2));
    }
    int cy2,cx2;
    getyx(tape, cy2, cx2);
    *cy1 = cy2;
    *cx1 = cx2;
    wrefresh(tape);
}
void face_add_etu(WINDOW * add ,WINDOW * add_etu,int  cy6, int  cx6 ,int k,int kii){
    cy6 = cy6 + 1;
    cx6 = cx6 + 2;
    add_etu = subwin(add,5, 23,cy6 ,cx6 ); 
    box(add_etu,0,0);
    if(k == 1){  
        if(kii == 0){
            wattron(add_etu,A_BOLD|COLOR_PAIR(3));
            mvwprintw(add_etu,2,6,"add student");
            wattroff(add_etu,A_BOLD|COLOR_PAIR(3));   
            wrefresh(add_etu);
        }
        else{
            wattron(add_etu,A_BOLD);
            mvwprintw(add_etu,2,6,"add student");
            wattroff(add_etu,A_BOLD);   
            wrefresh(add_etu);
        }
    }
    else{
        wattron(add_etu,A_BOLD);
        mvwprintw(add_etu,2,6,"add student");
        wattroff(add_etu,A_BOLD);   
        wrefresh(add_etu);
    }
}
void face_Student_update(WINDOW * Stu_update,WINDOW * add,int cy6,int cx6,int k,int kii){
    cy6 = cy6 + 6;
    cx6 = cx6 + 2;
    Stu_update = subwin(add,5, 23,cy6 ,cx6 );
    box(Stu_update,0,0);
    if(k == 1){
        if(kii == 1){
            wattron(Stu_update,A_BOLD|COLOR_PAIR(3));
            mvwprintw(Stu_update,2,4,"upadte a student");
            wattroff(Stu_update,A_BOLD|COLOR_PAIR(3));
            wrefresh(Stu_update);
        }
        else{
            wattron(Stu_update,A_BOLD);
            mvwprintw(Stu_update,2,4,"upadte a student");
            wattroff(Stu_update,A_BOLD);
            wrefresh(Stu_update);
        }  
    }
    else{
        wattron(Stu_update,A_BOLD);
        mvwprintw(Stu_update,2,4,"upadte a student");
        wattroff(Stu_update,A_BOLD);
        wrefresh(Stu_update);
    }
}
void face_Find_student( WINDOW * find_stu , WINDOW * add,int cy6,int cx6,int k,int kii){
    cy6 = cy6 + 11;
    cx6 = cx6 + 2;
    find_stu = subwin(add,5, 23,cy6 ,cx6 );
    box(find_stu,0,0);
    if(k == 1){
        if(kii == 2){
            wattron(find_stu,A_BOLD|COLOR_PAIR(3));
            mvwprintw(find_stu,2,5,"find a student");
            wattroff(find_stu,A_BOLD|COLOR_PAIR(3));
            wrefresh(find_stu); 
        }
        else{
            wattron(find_stu,A_BOLD);
            mvwprintw(find_stu,2,5,"find a student");
            wattroff(find_stu,A_BOLD);
            wrefresh(find_stu);
        }  
    }
    else{
        wattron(find_stu,A_BOLD);
        mvwprintw(find_stu,2,5,"find a student");
        wattroff(find_stu,A_BOLD);
        wrefresh(find_stu);
    }
}
void face_delate_student(WINDOW * delate_stu, WINDOW * add,int cy6,int cx6,int k,int kii){
    cy6 = cy6 + 16;
    cx6 = cx6 + 2;
    delate_stu = subwin(add,5, 23,cy6 ,cx6 );
    box(delate_stu,0,0);
    if(k == 1){
        if(kii == 3){
        wattron(delate_stu,A_BOLD|COLOR_PAIR(3));
        mvwprintw(delate_stu,2,3,"delate an student");
        wattroff(delate_stu,A_BOLD|COLOR_PAIR(3));
        wrefresh(delate_stu);  
        }
        else{
            wattron(delate_stu,A_BOLD);
            mvwprintw(delate_stu,2,3,"delate an student");
            wattroff(delate_stu,A_BOLD);
            wrefresh(delate_stu);       
        }  
    }
    else{
        wattron(delate_stu,A_BOLD);
        mvwprintw(delate_stu,2,3,"delate an student");
        wattroff(delate_stu,A_BOLD);
        wrefresh(delate_stu);       
    }
}
void face_big_win(WINDOW * big_win,int cy5,int cx5,int k,int kii){
    cy5 = cy5 + 4;
    cx5 = cx5 + 17;
    WINDOW * add = newwin(22, 27,cy5,cx5);
    if(k == 1){
        wbkgd(add,COLOR_PAIR(1));
    }
    box(add,0,0); 
    wrefresh(add);
    WINDOW * add_etu1;
    face_add_etu(add, &*add_etu1,cy5,cx5,k,kii);
    WINDOW * update_etu1;
    face_Student_update(&*update_etu1,&*add,cy5,cx5, k,kii);
    WINDOW * find_stu1;
    face_Find_student(&*find_stu1,&*add,cy5,cx5, k,kii); 
    WINDOW * delate_stu;
    face_delate_student(&*delate_stu,&*add,cy5,cx5,k,kii);
}
void face_rate_calculation(WINDOW * add ,WINDOW * rate_calculation,int  cy6, int  cx6 ,int k,int kiii){
    cy6 = cy6 - 4 ;
    cx6 = cx6 + 1;
    rate_calculation = subwin(add,5, 27,cy6 ,cx6 ); 
    box(rate_calculation,0,0);
    if(k == 2){
        if(kiii == 0){
            wattron(rate_calculation,A_BOLD|COLOR_PAIR(3));

            mvwprintw(rate_calculation,2,6,"rate calculation");
            wattroff(rate_calculation,A_BOLD|COLOR_PAIR(3));
            wrefresh(rate_calculation);
        }
        else{
            wattron(rate_calculation,A_BOLD);
            mvwprintw(rate_calculation,2,6,"rate calculation");
            wattroff(rate_calculation,A_BOLD);
            wrefresh(rate_calculation);
        }
    }
    else{
        wattron(rate_calculation,A_BOLD);
        mvwprintw(rate_calculation,2,6,"rate calculation");
        wattroff(rate_calculation,A_BOLD);
        wrefresh(rate_calculation);
    }
}
void face_rate_calculationG(WINDOW * rate_calculation3,WINDOW * add,int cy6,int cx6,int k,int kiii){
    cy6 = cy6 - 2 ;
    cx6 = cx6 + 1;
    rate_calculation3 = subwin(add,5, 27,cy6 ,cx6 );
    box(rate_calculation3,0,0);
    if(k == 2){
        if(kiii == 1){
            wattron(rate_calculation3,A_BOLD|COLOR_PAIR(3));
            mvwprintw(rate_calculation3,1,5,"Calculation of the ");
            mvwprintw(rate_calculation3,3,7,"general rate");
            wattroff(rate_calculation3,A_BOLD|COLOR_PAIR(3));
            wrefresh(rate_calculation3);
        }
        else{
            wattron(rate_calculation3,A_BOLD);
            mvwprintw(rate_calculation3,1,5,"Calculation of the ");
            mvwprintw(rate_calculation3,3,7,"general rate");
            wattroff(rate_calculation3,A_BOLD);
            wrefresh(rate_calculation3);
        }
    }
    else{
        wattron(rate_calculation3,A_BOLD);
        mvwprintw(rate_calculation3,1,5,"Calculation of the ");
        mvwprintw(rate_calculation3,3,7,"general rate");
        wattroff(rate_calculation3,A_BOLD);
        wrefresh(rate_calculation3);
    }
}
void face_list_students( WINDOW * list_students, WINDOW * add,int cy6,int cx6,int k,int kiii){
    cy6 = cy6 ;
    cx6 = cx6 + 1;
    list_students = subwin(add,5, 27,cy6 ,cx6 );
    box(list_students,0,0);
    if(k == 2){
        if(kiii == 2){
            wattron(list_students,A_BOLD|COLOR_PAIR(3));
            mvwprintw(list_students,2,1,"show the list of students");
            wattroff(list_students,A_BOLD|COLOR_PAIR(3));
            wrefresh(list_students);
        }
        else{
            wattron(list_students,A_BOLD);
            mvwprintw(list_students,2,1,"show the list of students");
            wattroff(list_students,A_BOLD);
            wrefresh(list_students);
        }
    }
    else{
        wattron(list_students,A_BOLD);
        mvwprintw(list_students,2,1,"show the list of students");
        wattroff(list_students,A_BOLD);
        wrefresh(list_students);
    }
}   
void face_big_win2(WINDOW * big_win,int k,int kiii){
    int cy7 = 7;
    int cx7 = 100;
    WINDOW * add1 = newwin(19, 29,cy7,cx7);
    box(add1,0,0); 
    if(k == 2){
        wbkgd(add1,COLOR_PAIR(1));
    }
    wrefresh(add1);
    WINDOW * rate_calculation1;
    face_rate_calculation(add1, &*rate_calculation1,cy7 + 5,cx7,k,kiii);
    WINDOW * rate_calculation2;
    face_rate_calculationG(&*rate_calculation2,&*add1,cy7 + 9,cx7,k,kiii);
    WINDOW * list_students1;
    face_list_students(&*list_students1,&*add1,cy7 + 13,cx7,k,kiii);
}
int print_face_main(){
    int bi = 0;
    int k = 0; 
    int ki = 0;
    int kii = 0;
    int kiii = 0;
    int bb = 0;
    do{
        if(bi == 261 ){
            k++;
        }
        if(bi == 260){
            k--;
        }
        if(k < 0){
            k = 2;
        }
        if(k == 0){
            if(bi == 258|| bi == 259 ){
                ki++;
            }
        }
        else if(k == 1){
            if(bi == 258 ){
                kii++;
            }
            else if(bi == 259){
                kii--;
            }
        }
        else{
            if(bi == 258 ){
                kiii++;  
            }
            else if( bi == 259){
                kiii--;
            }
        }
        if(ki > 1){
            ki = 0;
        }
        if(kii > 3){
            kii = 0;
        }
        else if(kii < 0){
            kii = 3;
        }
        if(kiii > 2){
            kiii = 0;
        }
        else if(kiii < 0){
            kiii = 2;
        }
        if(k > 2){
            k = 0;
        }
        refresh();
        WINDOW * tape1;
        int cy,cx;
        face_tape(&*tape1,&cy,&cx,k,ki);
        int cy4 = cy;
        int cx4 = cx;
        WINDOW * big_win1;
        face_big_win(&*big_win1,cy4,cx4,k,kii);   
        WINDOW * big_win2;
        face_big_win2(&*big_win2,k,kiii);     
        bi = getch();
        if(k == 0){
            if (ki == 0){
                if (bi == 10){
                    bi = 32;
                    break;
                }
            }
        }
        else if(k == 1){
            if(kii == 0){
                if(bi == 10){
                    bi = 0;
                    break;
                }
            }
            else if(kii == 1){
                if(bi == 10){
                    bi = 1;
                    break;
                }
            }
            else if(kii == 2){
                if(bi == 10){
                    bi = 2;
                    break;
                }
            }
            else if(kii == 3){
                if(bi == 10){
                    bi = 3;
                    break;
                }
            }
        }
        else if(k == 2){
            if(kiii == 0){
                if(bi == 10){
                    bi = 4;
                    break;
                }
            }
            else if(kiii == 1){
                if(bi == 10){
                    bi = 5;
                    break;
                }
            }
            else if(kiii == 2) 
                if(bi == 10){
                    bi = 6;
                    break;
                }
        }
    }while( bi != 10 && bi != 32 && bi != 27);
    if(bi == 0){
        clear();
        refresh();
        bb = WIN_add();
    }
    if(bi == 1){
        clear();
        refresh();
        bb = Win_upd();        
    }
    if(bi == 2){
        clear();
        refresh();
        bb = search();
    }
    if(bi == 6){
        clear();
        refresh();
        bb = Win_list();
    }
    if(bb == 32){
        noecho();
        curs_set(0);
        print_face_main();
    }
    if(bi != 0){
        clear();
        refresh();
        return bi;
    }
}