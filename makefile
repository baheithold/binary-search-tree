OBJS = integer.o bst.o test-bst.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all: test-bst

test-bst:	$(OBJS)
		gcc $(LOPTS) $(OBJS) -o test-bst

integer.o:	integer.c integer.h
		gcc $(OOPTS) integer.c

bst.o:	bst.c bst.h
		gcc $(OOPTS) bst.c

test-bst.o:	test-bst.c bst.h
		gcc $(OOPTS) test-bst.c

test:	test-bst
		./test-bst

valgrind: test-bst
		valgrind test-bst

clean:
		rm -f vgcore.* $(OBJS) test-bst
