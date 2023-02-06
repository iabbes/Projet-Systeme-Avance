#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <curses.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "text.h"
#include "process.h"
#include "history.h"

#define MAXCMD 30
#define MAX_ALIASES 100
#define MAX_COMMAND_LENGTH 100
#define MAX_ALIAS_LENGTH 50

struct alias {
  char command[MAX_COMMAND_LENGTH];
  char alias[MAX_ALIAS_LENGTH];
};


void complain (char* msg);
void printWorkingDirectory();
int waitInputUser(char* cmd);
void add_alias(char* command, char* alias);
char* get_alias(char* command);
void manage_alias();
#endif