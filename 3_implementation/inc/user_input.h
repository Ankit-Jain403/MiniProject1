#include <unistd.h>
#include <termios.h>

#ifndef USER_INPUT_H
#define USER_INPUT_H

struct termios rettonorm;

#endif

void exit(int status);
void entergamemode();
void endgamemode();
void get_input(char* input);
