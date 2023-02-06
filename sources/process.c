#include "../headers/process.h"

/**
 * @brief find pipe in command
 * @param cmd command
 * @param cmdPiped command piped
 * @return 0 if no pipe, 1 otherwise
 */
int findPipe(char *cmd, char **cmdPiped)
{
    int i = 0;
    while (i <= 3)
    {
        cmdPiped[i] = strsep(&cmd, "|");
        if (cmdPiped[i] == NULL)
        {
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
void findSpace(char *cmd, char **cmdParsed)
{
    int i = 0;
    while (i < MAXCMD)
    {
        cmdParsed[i] = strsep(&cmd, " ");
        if (cmdParsed[i] == NULL)
        {
            break;
        }
        if (strlen(cmdParsed[i]) == 0)
        {
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
int processCommand(char *cmd, char **cmdParsed, char **cmdPiped)
{
    int piped = 0;
    char *pipedCmd[2];
    piped = findPipe(cmd, pipedCmd);
    if (!piped)
    {
        findSpace(cmd, cmdParsed);
    }
    else
    {
        findSpace(pipedCmd[0], cmdParsed);
        findSpace(pipedCmd[1], cmdPiped);
    }

    return (cmdManager(cmdParsed)) ? 0 : piped + 1;
}

/**
 * @brief function which handle our commands
 * @param cmdParsed command parsed
 * @return 0 if we don't have a command, 1 otherwise
 */
int cmdManager(char **cmdParsed)
{
    int nbCmd = 3;
    int value = 0;
    char *listCmd[nbCmd];
    listCmd[0] = "cd";
    listCmd[1] = "exit";
    listCmd[2] = "help";

    int i = 0;
    while (i < nbCmd)
    {
        if (strcmp(cmdParsed[0], listCmd[i]) == 0)
        {
            value = i + 1;
            break;
        }
        i++;
    }

    switch (value)
    {
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
void processArguments(char **parsed)
{
    // Forking a child
    pid_t pid = fork();

    if (pid == -1)
    {
        return;
    }
    else if (pid == 0)
    {
        if (execvp(parsed[0], parsed) < 0)
        {
            printf("\n Error command : %s \n", parsed[0]);
        }
        exit(1);
    }
    else
    {
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
void processArgumentsPipe(char **parsed, char **parsedpipe)
{
    int statutExec1, statutExec2;
    int pipeProc[2];
    pid_t pid;

    if (pipe(pipeProc) < 0) // create pipe and check for error
    {
        perror("\nError : pipe");
        exit(1);
    }

    if ((pid = fork()) == -1) // create child process and check for error
    {
        perror("\nError : fork");
        exit(1);
    }
    else if (pid == 0) // Child
    {
        close(pipeProc[0]);   // close the output of the pipe
        dup2(pipeProc[1], 1); // redirect the output of the pipe to the input of the pipe
        if (execvp(parsed[0], parsed) < 0)
        {
            printf("\n Error command : %s \n", parsed[0]);
        }

        close(pipeProc[1]);
        exit(1);
    }

    if ((pid = fork()) == -1) // create child process and check for error
    {
        perror("\nError : fork");
        exit(1);
    }
    else if (pid == 0) // Child
    {
        close(pipeProc[1]);   // close the input of the pipe
        dup2(pipeProc[0], 0); // redirect the input of the pipe to the output of the pipe
        if (execvp(parsedpipe[0], parsedpipe) < 0)
        {
            printf("\nError command : %s \n", parsed[0]);
        }
        exit(1);
    }

    // Close the pipe
    close(pipeProc[1]);
    close(pipeProc[0]);

    // Wait for the child processes to finish
    wait(&statutExec1);
    wait(&statutExec2);
}

/**
 * @brief function which handle our commands
 * @param cmdParsed command parsed
 * @return 0 if we don't have a command, 1 otherwise
 */
char *strsep(char **stringp, const char *delim)
{
    char *rv = *stringp;
    if (rv)
    {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0;
    }
    return rv;
}