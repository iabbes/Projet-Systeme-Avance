#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "text.h"

int main(int argc, char const *argv[])
{
    txt_init_shell();
    txt_help();
    txt_exit();
    return 0;
}
