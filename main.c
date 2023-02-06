#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "utils.h"
#include "process.h"

#define STRCMD 30

int main(int argc, char const *argv[])
{
    int executionType = 0;
    char *inputCmd = (char *)malloc(sizeof(char) * STRCMD);
    char **cmdParsed = (char **)malloc(sizeof(char *) * MAXCMD);
    char **cmdPiped = (char **)malloc(sizeof(char *) * MAXCMD);
    char *alias = (char *)malloc(sizeof(char) * MAXCMD);
    char completeCmd[STRCMD];
    bool isRunning = TRUE;
    txt_init_shell();

    add_alias("ll", "ls -al");
    add_alias("hi", "echo \"hello project\"");

    while (isRunning)
    {
        printWorkingDirectory();
        if (waitInputUser(inputCmd))
            continue;

        // store inputCmd to completeCmd
        strcpy(completeCmd, inputCmd);

        executionType = processCommand(inputCmd, cmdParsed, cmdPiped);
        alias = get_alias(inputCmd);



        if (alias != NULL)
        {
            system(alias);
        }
        else if(strcmp(cmdParsed[0], "alias") == 0 && argc == 1)
        {
            manage_alias();
        }
        else if (executionType == 1)
        {
            processArguments(cmdParsed);
        } else if (executionType == 2)
            processArgumentsPipe(cmdParsed, cmdPiped);

        // isRunning = FALSE;
    }

    return 0;
}
