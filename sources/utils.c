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
void printWorkingDirectory()
{
    // errno = 0;
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        fprintf(stdout, "%s", cwd);
    }
    else
    {
        complain("getcwd() error");
    }
}

/**
 * @brief      Wait an input of the user and store it in history
 * @param      cmd   The command
 * @return     0 if the user has entered a command, 1 otherwise
 */
int waitInputUser(char *cmd)
{
    char *buf;
    buf = readline("\n > ");
    if (strlen(buf) != 0)
    {
        log_history(buf);
        add_history(buf);
        strcpy(cmd, buf);
        return 0;
    }
    else
    {
        return 1;
    }
}

struct alias aliases[MAX_ALIASES];
int num_aliases = 0;

void add_alias(char *command, char *alias)
{
    strcpy(aliases[num_aliases].command, command);
    strcpy(aliases[num_aliases].alias, alias);
    num_aliases++;
}

char *get_alias(char *command)
{

    for (int i = 0; i < num_aliases; i++)
    {

        if (strcmp(aliases[i].command, command) == 0)
        {
            return aliases[i].alias;
        }
    }
    return NULL;
}

void printAliases()
{
    int i;
    for (i = 0; i < num_aliases; i++)
    {
        printf("%s -> %s \n", aliases[i].alias, aliases[i].command);
    }
    printf("---------------\n");
}

// wait input of alias then command and store the alias
void manage_alias()
{
    char aliasInput[MAXCMD];
    char commandInput[MAXCMD];
    printf("Enter alias: ");
    scanf("%s", aliasInput);
    // if aliasInput is empty, return
    if (strlen(aliasInput) == 0)
    {
        printf("Alias cannot be empty");
        return;
    }

    getchar(); // clear buffer
    
    printf("Enter command: ");
    scanf("%[^\n]", commandInput);
    if (strlen(commandInput) == 0)
    {
        printf("Command cannot be empty");
        return;
    }
    add_alias(aliasInput, commandInput);
    printf("Alias added successfully! \n List of aliases: \n");
    printAliases();
}