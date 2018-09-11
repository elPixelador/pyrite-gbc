#include "z80.h"
#include <stdio.h>
#include <stdlib.h>

Z80* createCPU()
{
  Z80* cpu = malloc(sizeof(Z80));

  if(!cpu)
    fprintf(stderr, "ERROR: Failed to allocate memory for CPU\n");

  cpu->registers.af = 0;
  cpu->registers.bc = 0;
  cpu->registers.de = 0;
  cpu->registers.bc = 0;
  cpu->registers.sp = 0;
  cpu->registers.pc = 0;

  cpu->memory = createMemory();

  return cpu;
}

void unloadCPU(Z80* cpu)
{
  unloadMemory(&cpu->memory);
}

void run(Z80* cpu, const char* rom) 
{
  loadROM(rom);
}
