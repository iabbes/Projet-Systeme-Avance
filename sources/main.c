#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "../headers/utils.h"
#include "../headers/process.h"


#define STRCMD 30 

int main(int argc, char const *argv[])
{
    int executionType = 0;
    char* inputCmd = (char*)malloc(sizeof(char) * STRCMD);
    char** cmdParsed = (char**)malloc(sizeof(char*) * MAXCMD);
    char** cmdPiped = (char**)malloc(sizeof(char*) * MAXCMD);
    bool isRunning = TRUE;

    char* rootPath = getcwd(NULL, 0);

    char* inputCmdBatch = (char*)malloc(sizeof(char) * STRCMD);
    int batchmode = false;

    //check if batch mode
    if (argc >= 2){
        batchmode = true;
    }

    //concatenate all arguments
    for (int i = 1; i < argc; i++){
        strcat(inputCmdBatch, argv[i]);
        strcat(inputCmdBatch, " ");
    }

    //if batch mode
    while(batchmode){
        
        log_history(inputCmdBatch, rootPath);
        add_history(inputCmdBatch);

        executionType = processCommand(inputCmdBatch, cmdParsed, cmdPiped);

        if(executionType == 1){
            processArguments(cmdParsed);
        }
        if (executionType == 2)
            processArgumentsPipe(cmdParsed, cmdPiped);
        return(EXIT_SUCCESS);
    }
    
    txt_init_shell();
    
    while(isRunning){
        printWorkingDirectory();
        if(waitInputUser(inputCmd, rootPath))
            continue;

        executionType = processCommand(inputCmd, cmdParsed, cmdPiped);

        if(executionType == 1){
            processArguments(cmdParsed);
        }
        if (executionType == 2)
            processArgumentsPipe(cmdParsed, cmdPiped);
    }
    

    return 0;
}
