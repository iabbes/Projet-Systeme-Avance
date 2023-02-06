#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/history.h"

 
void log_history(const char *cmd, char *path)
{
    char path_copy[strlen(path) + 1];
    strcpy(path_copy, path);

    FILE *fp = fopen(strcat(path_copy,"/history.log"), "a");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    fprintf(fp, "%s: %s\n", timestamp, cmd);

    fclose(fp);
}