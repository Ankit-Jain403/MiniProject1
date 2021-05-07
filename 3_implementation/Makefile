PROJ_NAME = snake_game
TEST_PROJ_NAME = Test_$(PROJ_NAME)

SRC =src/game_loop.c \
src/helper_functions.c \
src/high_scores.c \
src/menu.c 


COV_SRC = my-test-main.c

TEST_SRC = Test/my-test-main.c \
unity/unity.c 
INC_H = inc
INC_T = unity

ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
.PHONY: run clean my-test-main doc all

all:
	gcc -I $(INC_H) $(SRC) Test/my-test-main.c -o $(call FixPath,$(PROJ_NAME).$(EXEC))
	
run: all
	./$(PROJ_NAME).$(EXEC)
test:
	gcc Test/my-test-main.c -I -c unity/unity.c -o Test/$(TEST_NAME).$(EXEC)
	./Test/$(TEST_NAME).$(EXEC)

coverage:
	cp Test/my-test-main.c .
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I -c unity/unity.c Test/my-test-main.c $(SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath, ./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.gcn
	$(RM) my-test-main.c


cppcheck:
	cppcheck --enable=all $(SRC) my-test-main.c
debug:
	gcc -I $(INC_H) $(SRC) Test/my-test-main.c -g -o $(PROJ_NAME).$(EXEC)
	gdb $(PROJ_NAME).$(EXEC)

valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)


clean:
	rm test snake game_loop.o helper_functions.o high_scores.o menu.o my-test-main.o *~
	$(RM) *.gcn
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov

	
