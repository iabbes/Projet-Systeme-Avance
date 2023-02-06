#include "../headers/typedef.h"
#include "../headers/utils.h"

//init struct command 
Command* init_command(){
    Command* cmd = (Command*)malloc(sizeof(Command));
    cmd->argc = (int*)malloc(sizeof(int));
    cmd->argv = (char**)malloc(sizeof(char*) * MAXCMD);
    return cmd;
}

//set struct command
/*void set_command(Command* cmd, char* inputCmd){
    int i = 0;
    while (i < MAXCMD)
    {
        cmd->argv[i] = strsep(&inputCmd, " ");
        if (cmd->argv[i] == NULL)
        {
            break;
        }
        if (strlen(cmd->argv[i]) == 0)
        {
            i--;
        }
        i++;
    }
    cmd->argc = &i;
} */

//free struct command
void free_command(Command* cmd){
    free(cmd->argc);
    free(cmd->argv);
    free(cmd);
}
