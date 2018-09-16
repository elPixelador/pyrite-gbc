#include "z80.h"
#include "memory.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  Z80* cpu = createCPU();
  Memory* memory = createMemory();

  run(cpu, memory, "./rom/cpu_instrs.gb");

  unloadCPU(&cpu);
  unloadMemory(&memory);

  return EXIT_SUCCESS;
}
