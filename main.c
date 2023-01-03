#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "utils.h"
#include "text.h"

#define STRCMD 30 

int main(int argc, char const *argv[])
{
    char inputCmd[STRCMD];
    bool isRunning = true;
    txt_init_shell();
    
    while(isRunning){
        printWorkingDirectory();
        if (waitInputUser(inputCmd)) {
            continue;
        }

        isRunning = FALSE;
        
    }
    

    return 0;
}
