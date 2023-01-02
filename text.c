#include "text.h"

void txt_init_shell(){
    puts("\n\n\n\n **********************************"
    "\n\n\nBienvenue dans le shell de Victor, Ökkes et Ines !"
    "\n\n\n **********************************");
}

void txt_help(){
    puts("******* SHELL HELP *******"
    "\nVoici la liste des commandes disponibles :"
    "\n> cd"
    "\n> ls"
    "\n> exit"
    "\n> toutes les commandes disponibles dans le shell UNIX"
    "\n> pipe est pris en charge"
    "\n> les espaces sont pris en charge");
}

void txt_exit(){
    puts("\nAu revoir !\n");
}