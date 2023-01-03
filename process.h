#ifndef PROCESS_H
#define PROCESS_H
#include "utils.h"

int findPipe(char* cmd, char** cmdPiped);
void findSpace(char* cmd, char** cmdParsed);
int processCommand(char* cmd, char** cmdParsed, char** cmdPiped);
int cmdManager(char** cmdParsed);

#endif