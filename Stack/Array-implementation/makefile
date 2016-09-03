CC = gcc
cflags = -std=c99 -lm -Wall -Werror
headers = stack.h
obj = stack.o main.o

%.o : %.c $(headers)
	$(CC) $(cflags) -c $< -o $@

stack : $(obj)
	$(CC) $(cflags) $^ -o $@

.PHONY : clean

clean : 
	rm -f *.o
