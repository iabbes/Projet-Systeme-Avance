#include "utils.h"

void complain(char *msg)
{
    perror(msg);
    exit(1);
}

void printWorkingDirectory(){
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        fprintf(stdout, "%s", cwd);
    } else {
        complain("getcwd() error");
    }
}

int waitInputUser(char* cmd)
{
    char* buf;
    buf = readline("\n>>> ");
    if (strlen(buf) != 0) {
        add_history(buf);
        strcpy(cmd, buf);
        return 0;
    } else {
        return 1;
    }
}