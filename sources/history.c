#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/history.h"

/** 
 * @file history.c
 * @brief This file contains all the functions used to log the history
 */


/**
 * @brief writes the command to the history file
 * @param cmd the command to write
 * @param path the path to the directory where is the history file
 * @return void
 */ 
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