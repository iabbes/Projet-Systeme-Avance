#ifndef TYPEDEF_H
#define TYPEDEF_H

typedef struct command {
    int* argc; // Number of argument in input
    char** argv; // Array containing input split by space
} Command;

#endif