SRC=$(wildcard functions/*.c)
TEST_SRC=$(wildcard tests/*test.c) unit_tests.c

OBJ=$(patsubst functions/%.c,%.o,$(SRC))
TEST_OBJ=$(patsubst tests/%.c,%.o,$(TEST_SRC))
GCOV_TEST_OBJ=$(patsubst %, gcov_%, $(OBJ))

CFLAGS=-Wall -Werror -Wextra -std=c11
OS = $(shell uname -s)
ifeq ($(OS), Darwin)
TEST_FLAGS=-lcheck
OPEN=open
else ifeq ($(shell hostnamectl | grep -o 'Ubuntu'), Ubuntu)
TEST_FLAGS=-lpthread -lcheck   -lm -lsubunit -Wno-missing-braces -Wno-shift-overflow 
OPEN=open
else
TEST_FLAGS=-lpthread -lm -lcheck -Wno-missing-braces -Wno-shift-overflow
OPEN=xdg-open
endif
GCOV_FLAGS=-ftest-coverage --coverage
CC=gcc

all: s21_matrix.a

s21_matrix.a: clang-format $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

test: s21_matrix.a $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ)  s21_matrix.a -o ./unit_tests $(TEST_FLAGS)
	./unit_tests

gcov_report: s21_matrix.a $(GCOV_TEST_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(GCOV_TEST_OBJ) $(TEST_OBJ) -o ./gcov_unit_tests $(TEST_FLAGS)
	./gcov_unit_tests
	lcov -t "s21_matrix_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN) report/index.html

%.o: functions/%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: tests/%.c
	$(CC) -c $(CFLAGS) $< -o $@ $(TEST_FLAGS)

gcov_%.o: ./functions/%.c
	$(CC) -c $(CFLAGS) $(GCOV_FLAGS) $< -o ./$@ $(TEST_FLAGS)

clang-format:
	clang-format -i ./functions/*.c *.h ./tests/*.c ./tests/*.h

clean:
	rm -rf report/
	rm -rf *.o *.a *.gcno *.gcda unit_tests gcov_unit_tests *.info

commit:
	git fetch
	git pull
	git add ..
	git commit -m "update"
