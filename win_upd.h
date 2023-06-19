#include <bits/types/FILE.h>
#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student3 {
  char name[30];
  char fa_name[30];
  int age;
  long long int id;
  char adress[40];
  char email[50];
  float rate;
} student3;

int Win_upd() {
  echo();
  curs_set(1);
  student3 std;
  FILE *titlef;
  FILE *infofile;
  int count = 0;
  int car;
  char name[120];
  char faname[120];
  char spnamef[245];
  char *tnamefile;
  char namefile[1500];
  char gnamefile[3200];
  char *ifgnamefile;
  char nnamefile[255];
  char snnamefile[320];
  char Folder_data[] = "Data_base";
  char *basename;
  char *info;
  char *ninfo;
  mvprintw(1, 65, "<--:UPDATE RECORD:-->\n");
  mvprintw(4, 4, "Enter student`(s) Name: ");
  getstr(name);
  mvprintw(4, 4, "Enter student`(s) Family Name: ");
  getstr(faname);
  sprintf(spnamef, "%s %s.txt", name, faname);
  titlef = fopen("Data_base/title_data.txt", "r");
  if (titlef == NULL) {
    printw("Error open title_data file");
    refresh();
    getch();
    clear();
    return 32;
  }

  while (fgets(namefile, sizeof(namefile), titlef) != NULL) {
    for (int i = 0; i < sizeof(namefile); i++) {
      if (namefile[i] == '\n')
        namefile[i] = '\0';
    }
    basename = strchr(namefile, '/') + 1;
    printw("\n\nname file :%s\nbasename: %s\n\n", namefile, basename);
    if (strcmp(basename, spnamef) == 0) {
      printw(
          "\nViewing student %s %sfile: "
          "%s\n________________________________________________________\n|\n",
          name, faname, spnamef);
      printw("Enter the new info: \n"
             "_______________________________________________________\n\n");
      printw("Name: ");
      getstr(std.name);
      printw("family Name:");
      getstr(std.fa_name);
      printw("Age: ");
      scanw("%d", &std.age);
      printw("ID: ");
      scanw("%lld", &std.id);
      printw("Adress: ");
      getstr(std.adress);
      printw("Email: ");
      getstr(std.email);
      printw("|\n________________________________________________________\n\n");
      refresh();
      infofile = fopen(namefile, "w");
      if (infofile == NULL) {
        printw("Error open file %s", namefile);
        refresh();
        getch();
        clear();
        return 32;
      }
      fprintf(infofile,
              "name: %s  \nfamily_name: %s \nage: %d   \nID: %lld   "
              "\nadress:%s \nEmail: %s \n",
              std.name, std.fa_name, std.age, std.id, std.adress, std.email);
      sprintf(nnamefile, "%s %s.txt", std.name, std.fa_name);
      snprintf(snnamefile, 320, "%s/%s", Folder_data, nnamefile);
      rename(nnamefile, snnamefile);
      break;
    }
  }
  printw("\nb5le: %d\n", count);
  refresh();

  printw("\n%s\n", namefile);
  refresh();
  printw("\n%s\n", snnamefile);
  refresh();

  fclose(titlef);
  fclose(infofile);
  titlef = fopen("Data_base/title_data.txt", "r");
  printw("\nb5le: %d\n", count);
  refresh();
  if (titlef == NULL) {
    printw("Error open title_data file");
    refresh();
    getch();
    clear();
    return 32;
  }

  printw("\nb5le1: %d\n", count);
  refresh();
  while (!feof(titlef)) {
    printw("\nb5le: %d\n", count);
    refresh();
    while ((car = fgetc(titlef)) != EOF) {
      count++;
    }
    printw("\nb5le2: %d\n", count);
    refresh();
    printw("\nb5le: %d\n", count);
    while (fgets(gnamefile, count, titlef) != NULL) {
      for (int i = 0; i < count; i++) {
        if (gnamefile[i] == '\0') {
          gnamefile[i] = '\n';
        }
      }
      ifgnamefile = gnamefile;
    }
  }
  fclose(titlef);
  titlef = fopen("Data_base/title_data.txt", "w");
  if (titlef == NULL) {
    printw("Error open title_data file");
    refresh();
    getch();
    clear();
    return 32;
  }
  fprintf(titlef, "%s\n%s", gnamefile, snnamefile);
  fclose(titlef);
  getch();
  return 32;
}