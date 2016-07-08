SOURCES=main.c memory.c z80.c
HEADERS=memory.h z80.h
BIN=../bin
PROGRAM=../bin/pyrite
FLAGS=-Wall
OBJS=memory.o z80.o

all: $(OBJS)
	@echo "Linking..."
	gcc $(FLAGS) -o $(PROGRAM) $(OBJS)

%.0: %.c
	@echo "Compiling..."
	gcc $(FLAGS) -c -o $@ $^

clean:
	@echo "Cleaning..."
	rm *.o $(PROGRAM)

archive:
	@echo "Creating source archive..."
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile
