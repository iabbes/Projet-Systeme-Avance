#ifndef PROCESS_H
#define PROCESS_H
#include "utils.h"
#include <sys/types.h>

int findPipe(char* cmd, char** cmdPiped);
void findSpace(char* cmd, char** cmdParsed);
int processCommand(char* cmd, char** cmdParsed, char** cmdPiped);
int cmdManager(char** cmdParsed);
void processArguments(char** parsed);
void processArgumentsPipe(char** parsed, char** parsedpipe);
char *strsep(char **stringp, const char *delim);

#endif