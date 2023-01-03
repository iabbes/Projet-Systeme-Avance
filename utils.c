#include "utils.h"

void complain(char *msg)
{
    perror(msg);
    exit(1);
}