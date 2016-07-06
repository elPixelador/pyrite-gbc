#include "z80.h"
#include <stdio.h>
#include <stdlib.h>

Z80* createCPU()
{
  Z80* cpu = malloc(sizeof(Z80));

  if(cpu == NULL)
    fprintf(stderr, "ERROR: Failed to allocate memory for CPU\n");

  cpu->memory = createMemory();

  return cpu;
}

void freeCPU(Z80* cpu)
{
  if(cpu == NULL)
    return;

  free(cpu->memory);
  free(cpu);

  return;
}

// TODO: Move elsewhere
int main(int argc, char** argv)
{
  Z80* cpu = createCPU();

  printf("pyrite-gbc\n");



  return EXIT_SUCCESS;
}
