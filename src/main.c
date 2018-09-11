#include "z80.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
  Z80* cpu = createCPU();
  run(cpu, "./rom/cpu_instrs.gb");

  return EXIT_SUCCESS;
}
