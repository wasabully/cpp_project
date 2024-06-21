CC = gcc
CPPFLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++
OBJ = s21_matrix.cc s21_matrix_oop.cc s21_matrix_help.cc s21_matrix_operators.cc
OBJ_TEST = tests/test_matrix.cc
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	ADD_LIB = -lgtest -lpthread -lm
endif

ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open -a "Google Chrome"
	ADD_LIB = -lgtest
endif

all: s21_matrix_oop.a test

s21_matrix_oop.a:
	@$(CC) $(CPPFLAGS) *.cc -c
	@ar rc s21_matrix_oop.a *.o
	@ranlib s21_matrix_oop.a
	@rm *.o

test: clean
	@$(CC) $(CPPFLAGS) $(OBJ) $(OBJ_TEST) -o test $(ADD_LIB)
	@./test

gcov: clean
	@$(CC) $(CPPFLAGS) --coverage $(OBJ) $(OBJ_TEST) -o test $(ADD_LIB)
	@./test
	@rm -rf test_matrix.gcda test_matrix.gcno
	@lcov -t "s21_matrix_test" -o fizzbuzz.info -c -d .
	@genhtml -o report fizzbuzz.info
	@$(OPEN_CMD) report/src/index.html

style:
	@clang-format -style=Google -n *.cc *.h tests/*.cc

clean:
	@-rm -rf *.o *.gcno *.gcda *.info *.gcov *.a *.dSYM  report test

