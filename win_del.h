#include <bits/types/FILE.h>
#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Win_del() {
  echo();
  curs_set(1);
  FILE *titlef;
  char names[120];
  char fanames[120];
  char spnamef[245];
  char namefile[1500];
  char gnamefile[3200];
  char Folder_data[] = "Data_base";
  char *basename;
  mvprintw(1, 65, "<--:DELETE RECORD:-->\n");
  mvprintw(4, 4, "Enter student`(s) Name: ");
  getstr(names);
  mvprintw(4, 4, "Enter student`(s) Family Name: ");
  getstr(fanames);
  sprintf(spnamef, "%s %s.txt", names, fanames);
  titlef = fopen("Data_base/title_data.txt", "r");
  if (titlef == NULL) {
    printw("Error open title_data file");
    refresh();
    getch();
    clear();
    exit(1);
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
          names, fanames, spnamef);
          remove(spnamef);
        }
    }
}