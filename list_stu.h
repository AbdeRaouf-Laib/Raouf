//list_stu.h lib
#include <curses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/stat.h>

typedef struct students {
    char name[30];
    char fa_name[30];
    int age;
    long long int id;
    char adress[40];
    char email[50];
    float rate;
} students;

int Win_list(){
    clear();
    refresh();
    char name[100];
    char info[1500];
char * folderName = "Data_base";
    FILE *n = fopen("Data_base/title_data.txt", "r");;
    if (n == NULL) {
        printf("Error opening file.\n");
        return 32;
    }
FILE *file;
int i = 0;
    while (fgets(name, sizeof(name), n) != NULL) {
        printw("\nstudent nember: %d\n\n",i+1);
        for(int i = 0; i < strlen(name);i++){
            if(name[i] == '\n')
                name[i] = '\0';
        }
        file = fopen(name, "r");
        if (file == NULL) {
            printf("Error opening file2.\n");
            return 32;
        }
        int cy = 9;
        
        while(fgets(info,sizeof(info),file) != NULL){
            printw("%s",info);
            refresh(); 
        }
        i++;
        printw("\n#######################################\n");
        fclose(file);
    }
    fclose(n);
    getchar();
    return 32;
}

