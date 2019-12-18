CFLAGS = -c -O2 -Wall -fPIC

all: automute

automute: plugin.o
	gcc -o automute.so -shared plugin.o

plugin.o: ./src/plugin.c
	gcc -Iinclude src/plugin.c $(CFLAGS)

clean:
	rm -rf *.o automute.so
