#include "cpu.h"
#include "memory.h"

int main(int argc, char** argv)
{
    CPU* cpu = createCPU();
	Memory* memory = createMemory();
	run(cpu, memory, "../test/cpu_instrs.gb");
	unloadCPU(&cpu);
	unloadMemory(&memory);
    return 0;
}