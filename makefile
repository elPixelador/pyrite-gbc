CC=gcc
CFLAGS=-I.
DEPS = main.c z80.h memory.h
OBJ = z80.o memory.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)