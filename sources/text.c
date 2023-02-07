#include "../headers/text.h"

/**
 * @file text.c
 * @brief This file contains all the text functions used in the shell
*/

/**
 * @brief      Prints welcome message.
 * @param      None
 * @return     None
*/
void txt_init_shell(){
    puts("\n\n\n\n **********************************"
    "\n\n\nWelcome to Victor, Ökkes and Ines's Shell!"
    "\n\n\n **********************************");
}

/**
 * @brief      Prints help message with available commands in our Shell.
 * @param      None
 * @return     None
*/
void txt_help(){
    puts("******* SHELL HELP *******"
    "\nHere are a list of commands that can be used in our Shell :"
    "\n> cd"
    "\n> ls"
    "\n> exit"
    "\n> every other general command available in UNIX shell"
    "\n> pipe handling");
}

/**
 * @brief      Prints exit message.
 * @param      None
 * @return     None
*/
void txt_exit(){
    puts("\nBye !\n");
}