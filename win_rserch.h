#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>
typedef struct student2{
    char name[30];
    char fa_name[30];
    int age;
    long long int id;
    char adress[40];
    char email[50];
    float rate;
}student2;
int search()
{
    echo();
    curs_set(1);
    FILE *fp1;
    student2 std;
    char name2[100];
    char stname[30];
    char *basename;
    char *basename_no_ext;
    char *token;
    
    
    FILE * file1 ;
    mvprintw(1,65,"<--:SEARCH RECORD:-->\n");
    mvprintw(3,4,"Enter student's first name or family name: ");
    getstr(stname);
    fp1 = fopen("Data_base/title_data.txt", "r");
    if(fp1 == NULL){
        clear();
        refresh();
        printw("Error opening file1\n");
        refresh();
        getchar();
        return 32;
    }
    char fileename[200];
    while(fgets(fileename, sizeof(fileename), fp1) != NULL) {
        for(int i = 0 ; i < 200; i++){
            if(fileename[i] == '\n') 
                fileename[i] = '\0';
        }
        basename = strchr(fileename, '/') + 1;      
        
        if(strstr(basename, stname) != NULL) {
            FILE * fpp = fopen(fileename, "r");
            if (fpp == NULL) {
                printw("%s / %s / %s",basename,stname,fileename);
                printw("Student Doesn't exist\n");
                getch();
                refresh();
                return 32;
            }
            char buffer[200];
            printw("\nViewing student %s file: %s\n________________________________________________________\n|\n", stname, fileename);
            while(fgets(buffer, sizeof(buffer), fpp)!= NULL) {
                printw("| %s", buffer);
            }
            printw("|\n________________________________________________________\n\n");
            refresh();
        }
        else{
                printw("Student Doesn't exist\n");
                refresh();
                break;
        }
    }
    refresh();
    fclose(fp1);
    printw("Press any key to continue.");
    refresh();
    getch();
    return 32;
}