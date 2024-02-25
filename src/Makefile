BUILD_PATH=../bin/
CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -std=c11
EXTRAFLAGS=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector 

all: check rebuild

build: clean

rebuild: clean_all bst_create_test bst_insert_test  bst_traverse_test stack_test list_test clean

bst_create_test: bst_create_test.c bst.c
	$(CC) $(CFLAGS) bst_create_test.c bst.c -o  $(BUILD_PATH)bst_create_test
	$(CC) $(CFLAGS) $(EXTRAFLAGS) bst_create_test.c bst.c -o  $(BUILD_PATH)bst_create_test_extra

bst_insert_test: bst_insert_test.c bst.c
	$(CC) $(CFLAGS) bst_insert_test.c bst.c -o  $(BUILD_PATH)bst_insert_test
	$(CC) $(CFLAGS) $(EXTRAFLAGS) bst_insert_test.c bst.c -o  $(BUILD_PATH)bst_insert_test_extra

bst_traverse_test: bst_traverse_test.c bst.c
	$(CC) $(CFLAGS) bst_traverse_test.c bst.c -o  $(BUILD_PATH)bst_traverse_test
	$(CC) $(CFLAGS) $(EXTRAFLAGS) bst_traverse_test.c bst.c -o  $(BUILD_PATH)bst_traverse_test_extra

list_test: list_test.c list.c
	$(CC) $(CFLAGS) list_test.c list.c -o  $(BUILD_PATH)list_test
	$(CC) $(CFLAGS) $(EXTRAFLAGS) list_test.c list.c -o  $(BUILD_PATH)list_test_extra

stack_test: stack_test.c stack.c
	$(CC) $(CFLAGS) stack_test.c stack.c -o  $(BUILD_PATH)stack_test
	$(CC) $(CFLAGS) $(EXTRAFLAGS) stack_test.c stack.c -o  $(BUILD_PATH)stack_test_extra

clean_all:
	rm -rf *.o *.a *.so $(BUILD_PATH)Quest* $(BUILD_PATH)*.so
	
clean:
	rm -rf *.o *.a

check:
	clang-format -n *.c
	clang-format -n *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

run:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes $(BUILD_PATH)bst_create_test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes $(BUILD_PATH)bst_insert_test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes $(BUILD_PATH)bst_traverse_test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes $(BUILD_PATH)list_test
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes $(BUILD_PATH)stack_test

run_no_valgrind:
	$(BUILD_PATH)bst_create_test
	$(BUILD_PATH)bst_insert_test
	$(BUILD_PATH)bst_traverse_test
	$(BUILD_PATH)list_test
	$(BUILD_PATH)stack_test


