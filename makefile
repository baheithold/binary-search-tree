OBJS = integer.o bst.o queue.o sll.o test-bst.o
OOPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g

all: test-bst

test-bst:	$(OBJS)
		gcc $(LOPTS) $(OBJS) -o test-bst

integer.o:	integer.c integer.h
		gcc $(OOPTS) integer.c

queue.o:	queue.c queue.h sll.h
		gcc $(OOPTS) queue.c

sll.o:	sll.c sll.h
		gcc $(OOPTS) sll.c

bst.o:	bst.c bst.h queue.h
		gcc $(OOPTS) bst.c

test-bst.o:	test-bst.c bst.h queue.h
		gcc $(OOPTS) test-bst.c

test:	test-bst
		@./test-bst

valgrind: test-bst
		valgrind ./test-bst

clean:
		rm -f vgcore.* $(OBJS) test-bst
