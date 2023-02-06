OBJS	= main.o utils.o text.o process.o history.o
SOURCE	= main.c utils.c text.c process.c history.c
HEADER	= utils.h text.h process.h history.h
OUT	= shell-project
CC	 = gcc
FLAGS	 = -Wno-implicit-function-declaration -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -lreadline -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c -std=c17

utils.o: utils.c
	$(CC) $(FLAGS) utils.c -std=c17

text.o: text.c
	$(CC) $(FLAGS) text.c -std=c17

process.o: process.c
	$(CC) $(FLAGS) process.c -std=c17

history.o: history.c
	$(CC) $(FLAGS) history.c -std=c17

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)