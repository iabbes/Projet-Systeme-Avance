#include "text.h"

void txt_init_shell(){
    puts("\n\n\n\n **********************************"
    "\n\n\nWelcome to Victor, Ökkes et Ines' Shell!"
    "\n\n\n **********************************");
}

void txt_help(){
    puts("******* SHELL HELP *******"
    "\nHere are a list of commands that can be used in our Shell :"
    "\n> cd"
    "\n> ls"
    "\n> exit"
    "\n> every other general command available in UNIX shell"
    "\n> pipe handling");
}

void txt_exit(){
    puts("\nBye !\n");
}