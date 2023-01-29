#ifndef HISTORY_H
#define HISTORY_H

/**
 * @brief Logs a command to a history file
 *
 * This function takes a filename and a command string and appends
 * the command to the file. If the file does not exist, it is
 * created.
 *
 * @param filename The name of the file to log the command to
 * @param command The command to be logged
 */
void log_command(char* filename, char* command);

#endif
