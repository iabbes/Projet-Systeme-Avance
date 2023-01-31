#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "utils.h"
#include "process.h"


#define STRCMD 30 
#define HISTORY_FILE "history.log"

int main(int argc, char const *argv[])
{
    int executionType = 0;
    char* inputCmd = (char*)malloc(sizeof(char) * STRCMD);
    char** cmdParsed = (char**)malloc(sizeof(char*) * MAXCMD);
    char** cmdPiped = (char**)malloc(sizeof(char*) * MAXCMD);
    bool isRunning = TRUE;
    txt_init_shell();
    
    while(isRunning){
        printWorkingDirectory();
        if(waitInputUser(inputCmd))
            continue;

        executionType = processCommand(inputCmd, cmdParsed, cmdPiped);

        if(executionType == 1){
            processArguments(cmdParsed);
        }
        if (executionType == 2)
            processArgumentsPipe(cmdParsed, cmdPiped);

        //isRunning = FALSE;

        // Log command to history file
        //log_command(HISTORY_FILE, inputCmd);
        log_history(inputCmd);
    }
    

    return 0;
}
