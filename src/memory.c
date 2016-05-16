#include "Memory.h"
#include <stdio.h>

Memory* createMemory()
{
  Memory* mem = calloc(sizeof(char) * MEMORY_SIZE);

  if(mem == NULL)
  {
    fprintf(stderr," ERROR: Failed to allocate memory!\n");
  }

  return mem;
}

void unloadMemory(Memory** mem)
{
  if(*mem != NULL)
    free(*mem);

  *mem = NULL;
}

void loadROM(Memory* mem, const char* fileName)
{
  char ch;
  char* curIndex;

  FILE* fp = fopen(fileName,"r");

  if(fp == NULL)
  {
    fprintf(stderr," ERROR: Failed to open %s\n", fileName);
  }

  curIndex = &mem[ROM_DATA];
  while((ch = getc(fp)) != EOF)
  {
    *curIndex = ch;
    curIndex++;
  }

  fclose(fp);
}

void unloadROM(Memory* mem)
{

}
