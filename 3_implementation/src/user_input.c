#include "user_input.h"

void entergamemode() {  // Sets the terminal in a non-return mode
  tcgetattr(STDIN_FILENO,&rettonorm);
//makes sure input and stuff isn't shown
  struct termios game = rettonorm;
  
  game.c_lflag &= ~(ECHO | ICANON); //echo off. turno off output mode(canonical)
  game.c_oflag &= ~(OPOST);
  game.c_iflag &= ~(ICRNL | IXON);
  game.c_cc[VMIN] = 0;
  game.c_cc[VTIME] = 10;// amout of time to give for user to add input for read() inn tenths of sec
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &game);
}

void endgamemode() { //returns the terminal to regular
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &rettonorm);//flushes the remaining input and returns the terminal settings tonormal
  exit(0);//exits safely
}

void get_input(char* input)
{
  read(STDIN_FILENO, input, 1); //reads for 2 seconds(Sandard input into char inp, with length of 1)
}
