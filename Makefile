OBJS	= main.o utils.o text.o process.o history.o
SOURCE	= sources/main.c sources/utils.c sources/text.c sources/process.c sources/history.c
HEADER	= headers/utils.h headers/text.h headers/process.h headers/history.h
OUT	= shell-project
CC	 = gcc
FLAGS	 = -Wno-implicit-function-declaration -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -lreadline -o $(OUT) $(LFLAGS)

main.o: sources/main.c
	$(CC) $(FLAGS) sources/main.c -std=c17

utils.o: sources/utils.c
	$(CC) $(FLAGS) sources/utils.c -std=c17

text.o: sources/text.c
	$(CC) $(FLAGS) sources/text.c -std=c17

process.o: sources/process.c
	$(CC) $(FLAGS) sources/process.c -std=c17

history.o: sources/history.c
	$(CC) $(FLAGS) sources/history.c -std=c17

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)