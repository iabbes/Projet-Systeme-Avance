#ifndef PROCESS_H
#define PROCESS_H
#include "utils.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int findPipe(char* cmd, char** cmdPiped);
void findSpace(char* cmd, char** cmdParsed);
int findEpsilone(char* cmd, char** cmdPiped);
int findRedirection(char* cmd, char** cmdPiped);
int processCommand(char* cmd, char** cmdParsed, char** cmdPiped);
int cmdManager(char** cmdParsed);
void processArguments(char** parsed);
void processArgumentsPipe(char** parsed, char** parsedpipe);
void processArgumentsBackground(char **parsed);
void processArgumentsRedirection(char **parsedCmd, char **parsedFile);
char *strsep(char **stringp, const char *delim);

#endif