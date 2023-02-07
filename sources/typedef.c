#include "../headers/typedef.h"
#include "../headers/utils.h"

/** 
 * @file typedef.c
 * @brief This file contains all the functions used to free and malloc data
 */


/**
 * @brief malloc struct command
 * @param None
 * @return Command* 
 */
Command* init_command(){
    Command* cmd = (Command*)malloc(sizeof(Command));
    cmd->argc = (int*)malloc(sizeof(int));
    cmd->argv = (char**)malloc(sizeof(char*) * MAXCMD);
    return cmd;
}


/**
 * @brief free struct command
 * @param cmd Command*
 * @return None
 */
void free_command(Command* cmd){
    free(cmd->argc);
    free(cmd->argv);
    free(cmd);
}
