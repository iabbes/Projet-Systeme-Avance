#include "process.h"

/**
 * @brief find pipe in command
 * @param cmd command
 * @param cmdPiped command piped
 * @return 0 if no pipe, 1 otherwise
*/
int findPipe(char* cmd, char** cmdPiped){
    int i = 0;
    while(i <= 3){
        cmdPiped[i] = strsep(&cmd, "|");
        if(cmdPiped[i] == NULL){
            break;
        }
        i++;
    }
    return (cmdPiped[1] == NULL) ? 0 : 1;
}

/**
 * @brief find space in command
 * @param cmd command
 * @param cmdParsed command parsed
 * @return None
*/
void findSpace(char* cmd, char** cmdParsed){
    int i = 0;
    while(i < MAXCMD){
        cmdParsed[i] = strsep(&cmd, " ");
        if(cmdParsed[i] == NULL){
            break;
        }
        if(strlen(cmdParsed[i]) == 0){
            i--;
        }
        i++;
    }
}

/**
 * @brief process command
 * @param cmd command
 * @param cmdParsed command parsed
 * @param cmdPiped command piped
 * @return 0 if no pipe, 1 otherwise
*/
int processCommand(char* cmd, char** cmdParsed, char** cmdPiped){
    int piped = 0;
    char* pipedCmd[2];
    piped = findPipe(cmd, pipedCmd);
    if(!piped){
        findSpace(cmd, cmdParsed);
    }else{
        findSpace(pipedCmd[0], cmdParsed);
        findSpace(pipedCmd[1], cmdPiped);
    }

    return (cmdManager(cmdParsed))? 0 : piped + 1;
}

/**
 * @brief function which handle our commands
 * @param cmdParsed command parsed
 * @return 0 if we don't have a command, 1 otherwise
*/
int cmdManager(char** cmdParsed)
{
    int nbCmd = 3;
    int value = 0;
    char* listCmd[nbCmd];
    listCmd[0] = "cd";
    listCmd[1] = "exit";
    listCmd[2] = "help";


    int i = 0;
    while(i < nbCmd){
        if(strcmp(cmdParsed[0], listCmd[i]) == 0){
            value = i + 1;
            break;
        }
        i++;
    }

    switch(value){
        case 1:
            chdir(cmdParsed[1]);
            return 1;
        case 2:
            txt_exit();
            exit(0);
        case 3:
            txt_help();
            return 1;
        default:
            break;
    }
    return 0;
}
