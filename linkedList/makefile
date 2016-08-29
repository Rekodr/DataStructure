CC = gcc
CFLAGS = -std=c99 -Wall -Werror 
Headers = list.h
Obj = linkedList.o main.o

%.o : %.c $(Headers)
	echo "creating obj files"
	$(CC) $(CFLAGS) -c $< -o $@ 

linkedList : $(Obj)
	echo "generating the build"
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean

clean :
	rm -f $(Obj)
