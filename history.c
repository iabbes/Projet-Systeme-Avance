#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "history.h"

void log_command(char* filename, char* command) {
  FILE* file = fopen(filename, "a");
  if (file == NULL) {
    perror("Error opening history file");
    return;
  }

  // Append the command to the file
  fprintf(file, "%s\n", command);
  fclose(file);
}
