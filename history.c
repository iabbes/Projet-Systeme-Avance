#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "history.h"

 
//ajouter un param chemin absolue 
void log_history(const char *cmd)
{
    FILE *fp = fopen("history.log", "a");
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