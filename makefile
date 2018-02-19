OBJS = integer.o real.o string.o bst.o queue.o sll.o
OOPTS = -Wall -Wextra -std=c99 -g -c
LOPTS = -Wall -Wextra -std=c99 -g

all:	bst-0-0 bst-0-1 bst-0-2 bst-0-3 bst-0-4 bst-0-5 bst-0-6 bst-0-7 \
		bst-0-8 bst-0-9

bst-0-0:	$(OBJS) bst-0-0.o
		gcc $(LOPTS) $(OBJS) bst-0-0.o -o bst-0-0

bst-0-1:	$(OBJS) bst-0-1.o
		gcc $(LOPTS) $(OBJS) bst-0-1.o -o bst-0-1

bst-0-2:	$(OBJS) bst-0-2.o
		gcc $(LOPTS) $(OBJS) bst-0-2.o -o bst-0-2

bst-0-3:	$(OBJS) bst-0-3.o
		gcc $(LOPTS) $(OBJS) bst-0-3.o -o bst-0-3

bst-0-4:	$(OBJS) bst-0-4.o
		gcc $(LOPTS) $(OBJS) bst-0-4.o -o bst-0-4

bst-0-5:	$(OBJS) bst-0-5.o
		gcc $(LOPTS) $(OBJS) bst-0-5.o -o bst-0-5

bst-0-6:	$(OBJS) bst-0-6.o
		gcc $(LOPTS) $(OBJS) bst-0-6.o -o bst-0-6

bst-0-7:	$(OBJS) bst-0-7.o
		gcc $(LOPTS) $(OBJS) bst-0-7.o -o bst-0-7

bst-0-8:	$(OBJS) bst-0-8.o
		gcc $(LOPTS) $(OBJS) bst-0-8.o -o bst-0-8

bst-0-9:	$(OBJS) bst-0-9.o
		gcc $(LOPTS) $(OBJS) bst-0-9.o -o bst-0-9

integer.o:	integer.c integer.h
		gcc $(OOPTS) integer.c

real.o:	real.c real.h
		gcc $(OOPTS) real.c

string.o:	string.c string.h
		gcc $(OOPTS) string.c

queue.o:	queue.c queue.h sll.h
		gcc $(OOPTS) queue.c

sll.o:	sll.c sll.h
		gcc $(OOPTS) sll.c

bst.o:	bst.c bst.h queue.h
		gcc $(OOPTS) bst.c

bst-0-0.o:	./Testing/bst-0-0.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-0.c

bst-0-1.o:	./Testing/bst-0-1.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-1.c

bst-0-2.o:	./Testing/bst-0-2.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-2.c

bst-0-3.o:	./Testing/bst-0-3.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-3.c

bst-0-4.o:	./Testing/bst-0-4.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-4.c

bst-0-5.o:	./Testing/bst-0-5.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-5.c

bst-0-6.o:	./Testing/bst-0-6.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-6.c

bst-0-7.o:	./Testing/bst-0-7.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-7.c

bst-0-8.o:	./Testing/bst-0-8.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-8.c

bst-0-9.o:	./Testing/bst-0-9.c bst.h queue.h integer.h real.h string.h
		gcc $(OOPTS) ./Testing/bst-0-9.c

test:	bst-0-0	bst-0-1 bst-0-2 bst-0-3 bst-0-4 bst-0-5 bst-0-6 bst-0-7 \
		bst-0-8 bst-0-9
		@echo Testing bst-0-0...
		@./bst-0-0 >> ./Testing/myresults/bst-0-0.txt
		@echo Testing bst-0-1...
		@./bst-0-1 >> ./Testing/myresults/bst-0-1.txt
		@echo Testing bst-0-2...
		@./bst-0-2 >> ./Testing/myresults/bst-0-2.txt
		@echo Testing bst-0-3...
		@./bst-0-3 >> ./Testing/myresults/bst-0-3.txt
		@echo Testing bst-0-4...
	#	@./bst-0-4 >> ./Testing/myresults/bst-0-4.txt
		@echo Testing bst-0-5...
		@./bst-0-5 >> ./Testing/myresults/bst-0-5.txt
		@echo Testing bst-0-6...
	#	@./bst-0-6 >> ./Testing/myresults/bst-0-6.txt
		@echo Testing bst-0-7...
	#	@./bst-0-7 >> ./Testing/myresults/bst-0-7.txt
		@echo Testing bst-0-8...
	#	@./bst-0-8 >> ./Testing/myresults/bst-0-8.txt
		@echo Testing bst-0-9...
	#	@./bst-0-9 >> ./Testing/myresults/bst-0-9.txt

valgrind: bst-0-0
		valgrind ./bst-0-0

clean:
		rm -f vgcore.* $(OBJS) bst-0-0 bst-0-1 bst-0-2 bst-0-3 bst-0-4 bst-0-5 \
		bst-0-6 bst-0-7 bst-0-8 bst-0-9
