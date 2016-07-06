<<<<<<< HEAD
#include "z80.h"
#include <stdio.h>
#include <stdlib.h>

Z80* createCPU()
{
  Z80* cpu = malloc(sizeof(Z80));

  if(cpu == NULL)
    fprintf(stderr, "ERROR: Failed to allocate memory for CPU\n");

  cpu->registers.af;
  cpu->registers.bc;
  cpu->registers.de;
  cpu->registers.bc;
  cpu->registers.sp;
  cpu->registers.pc;

  cpu->memory = createMemory();

  return cpu;
}

void unloadCPU(Z80* cpu)
{
  unloadMemory(cpu->memory);
}
