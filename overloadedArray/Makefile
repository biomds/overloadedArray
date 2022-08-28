OBJS = main.o Array.o
CC = gcc

main:$(OBJS)
	$(CC) $^ -o overloadedArray

%.o:%.c
	$(CC) $^ -o $@

clean:
	$(RM) *.o  -r
