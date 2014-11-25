CC = gcc
OPTS = -Wall

roguelike.exe: main.o roguelike.o
	$(CC) $(OPTS) main.o roguelike.o -o roguelike.exe

main.o: main.c
	$(CC) $(OPTS) -c main.c

roguelike.o: roguelike.c
	$(CC) $(OPTS) -c roguelike.c