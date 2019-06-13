CC:=g++
SRCS:=mathlib.c

all: *.o
	ar rvs lib.a $^
mathlib.o: $(SRCS)
	@$(CC) -c $(SRCS)
%.o: %.c %.h
	@$(CC) -c $<
clean:
	rm -f *.o *.a
