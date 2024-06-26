CC=gcc
CFLAGS= -W -Wall -pedantic
INCLUDE= ./include/
PROGRAMS= app

all: $(PROGRAMS)



app: jeu.o main.o
	$(CC) -o $@ $^


%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE) 



clean:
	rm -f *.o *~ $(PROGRAMS)