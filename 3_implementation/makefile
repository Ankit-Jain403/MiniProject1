PROJ_NAME = snake_game
TEST_PROJ_NAME = Test_$(PROJ_NAME)

SRC =src/backend.c \
src/frontend.c \


COV_SRC = my-test-main.ts

TEST_SRC = Test/my-test-main.ts \
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
	gcc -I $(INC_H) $(SRC) Test/my-test-main.ts -o $(call FixPath,$(PROJ_NAME).$(EXEC))
	
run: all
	./$(PROJ_NAME).$(EXEC)
test:
	gcc Test/my-test-main.ts -I -c unity/unity.c -o Test/$(TEST_NAME).$(EXEC)
	./Test/$(TEST_NAME).$(EXEC)

coverage:
	cp Test/my-test-main.ts .
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I -c unity/unity.c Test/my-test-main.ts $(SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath, ./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.gcn
	$(RM) my-test-main.ts


cppcheck:
	cppcheck --enable=all $(SRC) my-test-main.ts
debug:
	gcc -I $(INC_H) $(SRC) Test/my-test-main.ts -g -o $(PROJ_NAME).$(EXEC)
	gdb $(PROJ_NAME).$(EXEC)

valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)


clean:
	rm test snake backend.o frontend.o my-test-main.o *~
	$(RM) *.gcn
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov

	
