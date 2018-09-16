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

char readbyte(Memory* mem, char addr)
{
  return mem->data[(int)addr];
}
