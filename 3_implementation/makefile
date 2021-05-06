snake : 3_implementation/src/game_loop.c 3_implementation/src/helper_functions.c 3_implementation/src/main.c 3_implementation/src/menu.c 3_implementation/src/high_scores.c
	gcc -std=gnu11 -Wall -Iheaders 3_implementation/src/game_loop.c 3_implementation/src/helper_functions.c 3_implementation/src/main.c 3_implementation/src/menu.c 3_implementation/src/high_scores.c -o snake -lncurses -lsqlite3

snaketest : 3_implementation/src/game_loop.c 3_implementation/src/helper_functions.c 3_implementation/src/main.c 3_implementation/src/menu.c 3_implementation/src/high_scores.c
	gcc -std=gnu11 -ggdb -Wall -Iheaders 3_implementation/src/game_loop.c 3_implementation/src/helper_functions.c 3_implementation/src/main.c 3_implementation/src/menu.c 3_implementation/src/high_scores.c -o snaketest -lncurses -lsqlite3

gdb : snaketest
	gdb snaketest

clean : 
	rm snake
