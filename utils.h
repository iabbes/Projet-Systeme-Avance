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

void complain (char* msg);
void printWorkingDirectory();
int waitInputUser(char* cmd);

#endif