#include "memory.h"

Z80* createCPU()
{
  Z80* cpu = malloc(sizeof(Z80));

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
