#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

static char* rom;

Memory* createMemory()
{
  Memory* mem = malloc(sizeof(Memory));

  if(mem == NULL) {
    fprintf(stderr," ERROR: Failed to allocate memory!\n");
  }

  return mem;
}

void unloadMemory(Memory** mem)
{
  if(*mem)
    free(*mem);

  *mem = NULL;
}

char* loadROM(const char* fileName)
{
  char ch;
  char* curIndex;
  int fileSize;

  /* If an existing rom is loaded we need to make sure to clean it out first. */
  if(rom)
    free(rom);

  FILE* fp = fopen(fileName,"rb");

  /* Obtain file size */
  fseek(fp, 0L, SEEK_END);
  fileSize = ftell(fp);

  /* Set file pointer back to start of rom. */
  rewind(fp);

  if(!fp)
    fprintf(stderr," ERROR: Failed to open %s\n", fileName);

  /* Allocate space for ROM and read into heap. */
  rom = malloc(fileSize);

  curIndex = rom;
  while((ch = getc(fp)) != EOF)
  {
    *curIndex = ch;
    curIndex++;
  }

  fclose(fp);

  if(fp)
    fprintf(stderr," ERROR: Failed to close %s\n", fileName);

  return rom;
}

unsigned char readByte(Memory* mem, unsigned short addr) {
  return mem->data[addr];
}

unsigned short readWord(Memory* mem, unsigned short addr) {
  // Have I mixed up order of a and b?
  unsigned short a = mem->data[addr];
  unsigned short b = mem->data[addr+1];
  return (a << 8) | b;
}

void writeByte(Memory* mem, unsigned short addr, unsigned char byte) {
  mem->data[addr] = byte;
}

void writeWord(Memory* mem, unsigned short addr, unsigned short byte) {
  mem->data[addr] = byte;
}
