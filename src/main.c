#include "z80.h"
#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  Z80 *cpu = createCPU();
  Memory *memory = createMemory();

  if (argc < 2)
  {
    fprintf(stderr, "ERROR: No rom file specified, cannot start emulation! Quitting.");
    return EXIT_FAILURE;
  }

  run(cpu, memory, argv[1]);

  printf("Execution complete!\n");
  printf("Press Enter to Continue\n");  
  getchar();   

  unloadCPU(&cpu);
  unloadMemory(&memory);

  return EXIT_SUCCESS;
}
