//win_add.h lib
#include <curses.h>
#include<ncurses.h>
#include<stdlib.h>
#include <stdio.h>
#include<locale.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
typedef struct student{
    char name[30];
    char fa_name[30];
    int age;
    long long int id;
    char adress[40];
    char email[50];
    float rate;
}student;
void face_return_exit1(WINDOW * big_win31,int k,int ki){
    WINDOW * return_exit = subwin(big_win31,3,19,11,2);
    WINDOW * exit = subwin(big_win31,3,19,14,2);
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
void face_how_use1(WINDOW * big_win31 ,int k){
    WINDOW * how_use = subwin(big_win31, 4, 19, 2, 2);
    if(k != 0){
        wclear(how_use);
    }
    else{
        mvwprintw(big_win31,2,1.5,"('ENTER'):to selcte");
        mvwprintw(big_win31,4,1.5,"('SPACE'):to returne");
        mvwprintw(big_win31,6,1.5,"('ESC'):to exit");
        wrefresh(how_use);
    }
}
void face_big_win31(int k,int ki){
    WINDOW * big_win31 = newwin(15,22,3,1);
    if(k == 0){
        box(big_win31,0,0);
    }
        face_how_use1(&* big_win31,k);
        face_return_exit1(&* big_win31,k,ki);
        wrefresh(big_win31);
}
void face_tape1(WINDOW * tape ,int * cy1, int * cx1,int k,int ki){
    tape = newwin(3,18,0,0);
    wborder(tape,'|','|','-','-','+','+','+','+');
    if(k != 0){
        face_big_win31(k,ki);
        wattron(tape,A_BOLD);
        mvwprintw(tape,1,7,"main");
        wattroff(tape,A_BOLD);
    }
    else if(k == 0){
        face_big_win31(k,ki);
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
int face_close(WINDOW * Close,WINDOW *no,WINDOW *yes);
int face_save(student stu);
int scan_stu(WINDOW* wname,WINDOW * wfa_name,WINDOW * wage,WINDOW * wid, WINDOW * wadress,WINDOW * wemail,WINDOW * wmoyenne,WINDOW * close,WINDOW * save,int cy,int cx){
        student stu;
        int br;
        int ks = 0;
        int re = 0;
        mvprintw(cy + 1.5,cx + 2 , "Name*");
        mvprintw(cy + 5.5,cx + 2 , "Family name*");
        mvprintw(cy + 9.5,cx + 2 , "Age*");
        mvprintw(cy + 13.5,cx + 2 , "ID*");
        mvprintw(cy + 1.5,cx + 40 , "Adress*");
        mvprintw(cy + 5.5,cx + 40 , "Email*");
        mvprintw(cy + 9.5,cx + 40 , "Rate");
        refresh();
        echo();
        curs_set(1);
        int i = 0;
        do{
                wclear(wname);
                box(wname,0,0);
                wrefresh(wname);        
                wattron(wname, COLOR_PAIR(3));
                mvwgetstr(wname,1,1,stu.name);
                wattroff(wname, COLOR_PAIR(3));
                while (stu.name[i] != '\0') {
                        if (!isalpha(stu.name[i]) && !isspace(stu.name[i])) {
                                attron( COLOR_PAIR(5)|A_BLINK);
                                mvprintw(cy + 17.5,cx ,"(!) Enter only letters of the alphabet or spaces");
                                attroff( COLOR_PAIR(5)|A_BLINK);
                                refresh();  
                                break;
                        }
                        i++;
                }            
        }while(stu.name[i] != '\0'||strcmp(stu.name , "\0") == 0 ); 
        mvprintw(cy + 17.5,cx ,"                                                  ");
        refresh();
        i = 0;
        do{
                wclear(wfa_name);
                box(wfa_name,0,0);
                wrefresh(wfa_name);
                wattron(wfa_name, COLOR_PAIR(3));
                mvwgetstr(wfa_name,1,1,stu.fa_name);
                wattroff(wfa_name, COLOR_PAIR(3));
                while (stu.fa_name[i] != '\0') {
                        if (!isalpha(stu.fa_name[i]) && !isspace(stu.fa_name[i])) {
                                attron( COLOR_PAIR(5)|A_BLINK);
                                mvprintw(cy + 17.5,cx ,"(!) Enter only letters of the alphabet or spaces");
                                attroff( COLOR_PAIR(5)|A_BLINK);
                                refresh();  
                                break;
                        }
                        i++;
                }            
        }while(stu.fa_name[i] != '\0' || strcmp(stu.fa_name , "\0") == 0 );
        mvprintw(cy + 17.5,cx ,"                                                  ");
        refresh();
        i = 0;
        do{
                wclear(wage);
                box(wage,0,0);
                wrefresh(wage);
                wattron(wage, COLOR_PAIR(3));
                mvwscanw(wage,1,1,"%d",&stu.age);
                wattroff(wage, COLOR_PAIR(3));
                i++;
                if(i > 0){
                        attron( COLOR_PAIR(5)|A_BLINK);
                        mvprintw(cy + 13.5,cx + 6,"(!) enter the age between 4-50");
                        attroff( COLOR_PAIR(5)|A_BLINK);
                        refresh();
                }
        }while(stu.age < 4 || stu.age > 50);
        mvprintw(cy + 13.5,cx + 6,"                                ");
        refresh();
        i = 0;
        do{
                wclear(wid);
                box(wid, 0, 0);
                wrefresh(wid);
                wattron(wid, COLOR_PAIR(3));
                mvwscanw(wid, 1, 1, " %lld ",&stu.id );
                wattroff(wid, COLOR_PAIR(3));
                i++;
                if (i > 0) {
                        attron(COLOR_PAIR(5) | A_BLINK);
                        mvprintw(cy + 17.5, cx + 6, "(!) enter the correct ID");
                        attroff(COLOR_PAIR(5) | A_BLINK);
                        refresh();
                }
        }while (stu.id < 222200000000 || stu.id > 222300000000);
        mvprintw(cy + 17.5,cx + 6,"                                ");
        refresh();
        i = 0;
        do{
                wclear(wadress);
                box(wadress,0,0);
                wrefresh(wadress);
                wattron(wadress, COLOR_PAIR(3));
                mvwgetstr(wadress,1,1,stu.adress);
                wattroff(wadress, COLOR_PAIR(3));
                while (stu.adress[i] != '\0') {
                if (strlen(stu.adress) < 1) {
                        attron( COLOR_PAIR(5)|A_BLINK);
                        mvprintw(cy + 13.5,cx + 40 ,"(!) Address can't be empty");
                        attroff( COLOR_PAIR(5)|A_BLINK);
                        refresh();  
                        break;
                }
                        i++;
                }            
        }while(stu.adress[i] != '\0'||strcmp(stu.adress , "\0") == 0);
        mvprintw(cy + 13.5,cx + 40,"                                                  ");
        refresh();
        i = 0;
        int dot = 0,att = 0;
        dub:
        dot = 0,att = 0;
        wclear(wemail);
        box(wemail,0,0);
        wrefresh(wemail);
        wattron(wemail, COLOR_PAIR(3));
        mvwgetstr(wemail,1,1,stu.email);
        wattroff(wemail, COLOR_PAIR(3));
        for(i = 0;stu.email[i] != '\0';i++) {
                if ( stu.email[i] == '@') {
                        att++;
                }
                else if (stu.email[i] == '.') {
                        dot++;
                }
        }
        if(att == 1 && dot >= 1){
                mvprintw(cy + 13.5,cx + 40 ,"                                                  ");
                refresh();
        }
        else{
                attron( COLOR_PAIR(5)|A_BLINK);
                mvprintw(cy + 13.5,cx + 40 ,"(!) Invalid Email");
                attroff( COLOR_PAIR(5)|A_BLINK);
                refresh();
                goto dub;           
        }
        i = 0;
        do{
                wclear(wmoyenne);
                box(wmoyenne,0,0);
                wrefresh(wmoyenne);
                mvprintw(cy + 9.5 ,cx + 45,"!!!..Not mandatory");
                refresh();
                wattron(wmoyenne, COLOR_PAIR(3));
                mvwscanw(wmoyenne,1,1,"%f",&stu.rate);
                wattroff(wmoyenne, COLOR_PAIR(3));
                if(i > 0){
                        attron( COLOR_PAIR(5)|A_BLINK);
                        mvprintw(cy + 13.5,cx + 40,"(!) enter the rate between 0-20");
                        attroff( COLOR_PAIR(5)|A_BLINK);
                        refresh();
                }
                if(stu.rate == KEY_ENTER){
                        break;
                }
        }while(stu.rate < 0 || stu.rate > 20 );
        mvprintw(cy + 13.5,cx + 40 ,"                                                  ");
        refresh();
        i = 0;
        noecho();
        curs_set(0);
        do{
                if(br == 258){
                        ks++;
                }
                if(ks > 2){
                        ks = 1;
                }
                if (ks == 1){
                        wattron(close,COLOR_PAIR(3));
                        box(close,0,0);
                        mvwprintw(close, 1, 3,"close");
                        wrefresh(close);
                        wattroff(close,COLOR_PAIR(3));
                        box(save,0,0);
                        mvwprintw(save, 1, 4, "save");
                        wrefresh(save);
                        if(br == 10){
                                WINDOW * Close = newwin(9,100,16,36);
                                WINDOW * no = subwin(Close,3,8,21,110);
                                WINDOW * yes = subwin(Close,3,9,21,120);
                                re = face_close(&*Close,&*no,&*yes);
                        }
                        if(re == 50){
                               
                        }
                        if(re == 32){
                                clear();
                                refresh();
                                break;
                        }
                }
                if(ks == 2){
                        box(close,0,0);
                        mvwprintw(close, 1, 3,"close");
                        wrefresh(close);
                        wattron(save,COLOR_PAIR(3));
                        box(save,0,0);
                        mvwprintw(save, 1, 4, "save");
                        wrefresh(save);
                        wattroff(save,COLOR_PAIR(3));
                        if(br == 10){
                                re = face_save(stu);
                        }
                        if(re == 32){
                                break;
                        }
                }
                br = getch();
        }while(true);
        return re;
}
int Open_add();
int WIN_add();
int face_close(WINDOW * Close,WINDOW *no,WINDOW *yes){
        int bx;
        int ka = 0;
        do{
                if(bx == 261 || bx == 260){
                        ka++;
                }
                if(ka > 1){
                        ka = 0;
                }
                if(ka == 0){
                        if(bx == 10){
 
                        }
                }
                if(ka == 1){
                        if(bx == 10){
                                bx = 32;
                                break;  
                        }
                }
                box(Close,0,0);
                wattron(Close,A_BOLD|A_UNDERLINE|COLOR_PAIR(3) );
                mvwprintw(Close,1,2,"Warning!!!");
                wattroff(Close,A_BOLD|A_UNDERLINE|COLOR_PAIR(3) );
                wattron(Close, A_BOLD);
                mvwprintw(Close, 3, 5,"Are you sure all entered data will be erased");
                wattroff(Close,A_BOLD);
                if(ka == 0){
                        wattron(no,COLOR_PAIR(3));
                        box(no,0,0);
                        mvwprintw(no,1,3,"no");
                        wattroff(no,COLOR_PAIR(3));
                        box(yes,0,0);
                        mvwprintw(yes,1,3,"yes");
                        wrefresh(yes);       
                        wrefresh(no);
                        wrefresh(Close);
                }
                if(ka == 1){
                        box(no,0,0);
                        mvwprintw(no,1,3,"no");
                        wattron(yes,COLOR_PAIR(3));
                        box(yes,0,0);
                        mvwprintw(yes,1,3,"yes");
                        wattroff(yes,COLOR_PAIR(3));          
                        wrefresh(no);
                        wrefresh(yes);
                        wrefresh(Close);  
                }
                bx = getch();
        }while(true);

        return bx;
}
int face_save(student stu){
        WINDOW * Save = newwin(9,100,16,36);
        WINDOW * no1 = subwin(Save,3,8,21,110);
        WINDOW * yes1 = subwin(Save,3,9,21,120); 
        FILE *fp;
        FILE *title;
        int bc;
        int kaa = 0;
        char x[100];
        char s[30];
        char flo[150];
        char flo1[200];
        char * folderName = "Data_base";
        mkdir(folderName,0777);
        snprintf(flo1,sizeof(flo1),"%s/title_data.txt",folderName);
        do{
                if(bc == 261 || bc == 260){
                        kaa++;
                }
                if(kaa > 1){
                        kaa = 0;
                }
                if(kaa == 0){
                        if(bc == 10){
                                sprintf(x, "%s %s.txt",stu.name,stu.fa_name);
                                snprintf(flo,sizeof(flo),"%s/%s",folderName,x);
                                fp = fopen(flo, "a");
                                if(fp == NULL){
                                        printf("Error opening file\n");
                                        exit(1);
                                }
                                fprintf(fp,"name: %s  \nfamily_name: %s \nage: %d   \nID: %lld   \nadress:%s \nEmail: %s  \nRate: %.2f \n",stu.name,stu.fa_name,stu.age,stu.id,stu.adress,stu.email,stu.rate);
                                fclose(fp);
                                title = fopen(flo1,"a");
                                fprintf(title, "%s\n",flo);
                                fclose(title);
                                bc = 32;
                                clear();
                                refresh();
                                break;
                        }
                }/*
                if(kaa == 1){
                        if(bc == 10){
                                curs_set(1);
                                echo();
                                WINDOW *gestr = subwin(Save,3,35,21,45);
                                box(gestr,0,0);
                                mvwgetstr(gestr,1,2,s);
                                sprintf(x, "%s.txt",s);
                                snprintf(flo,sizeof(flo),"%s/%s",folderName,x);
                                noecho();
                                curs_set(0);
                                fp = fopen(flo, "a");
                                if(fp == NULL){
                                        printf("Error opening file\n");
                                        exit(1);
                                }
                                fprintf(fp,"name: %s  \nfamily_name: %s \nage: %d   \nID: %lld   \nadress:%s \nEmail: %s  \nRate: %f \n",stu.name,stu.fa_name,stu.age,stu.id,stu.adress,stu.email,stu.rate);
                                fclose(fp);
                                title = fopen(flo1,"a");
                                fprintf(title, "%s\n",flo);
                                fclose(title);
                                bc = 32;
                                clear();
                                refresh();
                                break;
                        }
                }*/
                box(Save,0,0);
                wattron(Save, A_BOLD|COLOR_PAIR(3)|A_UNDERLINE);
                mvwprintw(Save,1,2,"Notice");
                wattroff(Save, A_BOLD|COLOR_PAIR(3)|A_UNDERLINE);
                wattron(Save, A_BOLD);
                mvwprintw(Save, 3, 5, "Do you want to enter the file name manually?");
                if(kaa == 0){
                        wattron(no1,COLOR_PAIR(3));
                        box(no1,0,0);
                        mvwprintw(no1,1,3,"no");
                        wattroff(no1,COLOR_PAIR(3));
                        box(yes1,0,0);
                        mvwprintw(yes1,1,3,"yes");
                        wrefresh(yes1);       
                        wrefresh(no1);
                        wrefresh(Save);
                }
                if(kaa == 1){
                        box(no1,0,0);
                        mvwprintw(no1,1,3,"no");
                        wattron(yes1,COLOR_PAIR(3));
                        box(yes1,0,0);
                        mvwprintw(yes1,1,3,"yes");
                        wattroff(yes1,COLOR_PAIR(3));          
                        wrefresh(no1);
                        wrefresh(yes1);
                        wrefresh(Save);  
                }
                bc = getch();
        }while(true);
        return bc;
}
int Open_add(){
        WINDOW *open_add;
        int y = 30;
        int x = 130;
        int cy = 4;
        int cx = 18;
        int br;
        int kk = 0;
        int ks = 0;
        int ret;
        open_add = newwin(y,x,cy,cx);
        box(open_add,0,0);
        wrefresh(open_add);
        cy = cy + 2;
        cx = cx + 4;
        WINDOW * wname = subwin(open_add, 3,35, cy + 2,cx + 2);
        WINDOW * wfa_name = subwin(open_add, 3,35, cy + 2 + 4,cx + 2);
        WINDOW * wage = subwin(open_add, 3,35, cy + 2 + 8,cx + 2);
        WINDOW * wid = subwin(open_add, 3,35, cy + 2 + 12,cx + 2 );
        WINDOW * wadress = subwin(open_add, 3,35, cy + 2 ,cx + 2 + 38);
        WINDOW * wemail = subwin(open_add, 3,35, cy + 2 + 4,cx + 2 + 38);
        WINDOW * wmoyenne = subwin(open_add, 3,35, cy + 2 + 8,cx + 2 + 38);
        WINDOW * close = subwin(open_add,3,12,cy + 23,cx + 93);
        WINDOW * save = subwin(open_add,3,12,cy + 23,cx + 107);
        do{     
                refresh();
                wattron(open_add,A_BOLD|COLOR_PAIR(3)|A_UNDERLINE);
                mvwprintw(open_add, 1.5, 2, "Add student:");
                wattroff(open_add,A_BOLD|COLOR_PAIR(3)|A_UNDERLINE);
                wrefresh(open_add);
                wrefresh(open_add);
                box(wname,0,0);
                wrefresh(wname);
                box(wfa_name,0,0);
                wrefresh(wfa_name);
                box(wage,0,0);
                wrefresh(wage);
                box(wid,0,0);
                wrefresh(wid);
                box(wadress,0,0);
                wrefresh(wadress);
                box(wemail,0,0);
                wrefresh(wemail);
                box(wmoyenne,0,0);
                wrefresh(wmoyenne);
                mvwprintw(open_add,1,20,"press 'ENTER' to select!!!");
                wrefresh(open_add);
                box(close,0,0);
                mvwprintw(close, 1, 3,"close");
                wrefresh(close);
                box(save,0,0);
                mvwprintw(save, 1, 4, "save");
                wrefresh(save);
                ret = scan_stu(&*wname,&*wfa_name,&*wage,&*wid,
                &*wadress,&*wemail,&*wmoyenne,
                &*close,&*save,cy,cx);
                if(ret == 32){
                        break;
                }
                if(ret == 50){
                        break;
                }
                br = getch();
        }while(true); 
        if(ret == 50){

        }
        return ret ;
}
int WIN_add(){
        dub:
        WINDOW *Win_Add;
        int be;
        int k = 0;
        int ki = 0;
        Win_Add = newwin( 5, 160, 19, 4);
        WINDOW * Add = subwin(Win_Add,3,7,20,141);
        int i = 0;
        int ret;
        do{
                if(be == 261 || be == 260){
                        k++;
                }
                if(k > 1){
                        k = 0;
                }
                if(k == 0){
                        if(be == 258 || be == 259){
                                ki++;
                        }
                }
                if(ki > 1){
                        ki = 0;
                }

                WINDOW * tape1;
                int cy,cx;
                face_tape1(&*tape1,&cy,&cx,k,ki);
                if(k == 0){
                        box(Win_Add ,0,0);
                        wbkgd(Win_Add, COLOR_PAIR(4));
                        wbkgd(Add, COLOR_PAIR(4));
                        wattron(Win_Add,A_BOLD);
                        mvwprintw(Win_Add,2,4,"Add student:");
                        wattroff(Win_Add,A_BOLD);
                        box(Add,0,0);
                        mvwprintw(Add,1,2,"(+)");
                        wrefresh(Win_Add);
                }
                else if(k == 1){
                        wbkgd(Win_Add, COLOR_PAIR(1));
                        wbkgd(Add, COLOR_PAIR(1));
                        wattron(Add, COLOR_PAIR(2)|A_BOLD);
                        mvwprintw(Add,1,2,"(+)");
                        wattroff(Add, COLOR_PAIR(2)|A_BOLD);
                        wrefresh(Add); 
                        wrefresh(Win_Add);
                }
                be = getch();
                if(k == 1){
                        if(be == 10){
                                if(be == 10){
                                        refresh();
                                        ret = Open_add();
                                        if(ret == 32){
                                                clear();
                                                refresh();
                                                goto dub;
                                        }   
                                }
                        }
                }
                if(k == 0){
                        if(ki == 0){
                                if(be == 10){
                                        be = 32;
                                        break;
                                }
                        }
                } 
        }while(be != 10 && be != 27 && be != 32);
        clear();
        return be;
}