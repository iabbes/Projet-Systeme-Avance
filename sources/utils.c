#include "../headers/utils.h"
#include "../headers/history.h"

/**
 * @brief      Print an error message and exit the program
 * @param      msg   The message
 * @return     None
*/
void complain(char *msg)
{
    perror(msg);
    exit(1);
}

/**
 * @brief      Print the current working directory    
 * @param      None
 * @return     None
*/
void printWorkingDirectory(){
    // errno = 0;
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        fprintf(stdout, "%s", cwd);
    } else {
        complain("getcwd() error");
    }
}

/**
 * @brief      Wait an input of the user and store it in history
 * @param      cmd   The command
 * @return     0 if the user has entered a command, 1 otherwise
*/
int waitInputUser(char* cmd, char* path)
{
    char* buf;
    buf = readline("\n > ");
    if (strlen(buf) != 0) {
        log_history(buf, path);
        add_history(buf);
        strcpy(cmd, buf);
        return 0;
    } else {
        return 1;
    }
}