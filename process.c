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

/**
 * @brief function which handle our commands
 * @param parsed command parsed
 * @return 0 if we don't have a command, 1 otherwise
*/
void processArguments(char** parsed)
{
    // Forking a child
    pid_t pid = fork(); 
  
    if (pid == -1) {
        return;
    } 
    else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCommande n'a pas pu être executée..");
        }
        exit(0);
    } 
    else {
        // Attente de la fin du fils
        wait(NULL); 
        return;
    }
}

/**
 * @brief function which handle our commands
 * @param parsed command parsed
 * @param parsedpipe command parsed pipe
 * @return 0 if we don't have a command, 1 otherwise
*/
void processArgumentsPipe(char** parsed, char** parsedpipe)
{
    int pipefd[2]; 
    pid_t p1, p2;
  
    if (pipe(pipefd) < 0) {
        printf("\nPipe n'a pas pu être créé");
        return;
    }
    p1 = fork();
    if (p1 < 0) {
        printf("\nLe fork n'a pas pu être créé");
        return;
    }
  
    if (p1 == 0) {
        // Execution de premier fils
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
  
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nLa première commande n'a pas pu être executée..");
            exit(0);
        }
    } else {
        // Execution du père
        p2 = fork();
  
        if (p2 < 0) {
            printf("\nLe fork n'a pas pu être créé");
            return;
        }
  
        // Execution du deuxième fils
        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execvp(parsedpipe[0], parsedpipe) < 0) {
                printf("\nLa deuxième commande n'a pas pu être executée..");
                exit(0);
            }
        } else {
            // Execeution du père, attente de la fin des fils
            wait(NULL);
            wait(NULL);
        }
    }
}

/**
 * @brief function which handle our commands
 * @param cmdParsed command parsed
 * @return 0 if we don't have a command, 1 otherwise
*/
char *strsep(char **stringp, const char *delim)
{
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}