#include "emulator.h"
#include "cpu.h"
#include "memory.h"

void runEmulator() {
	CPU *cpu = createCPU();
	Memory *memory = createMemory();
	run(cpu, memory, "./test/cpu_instrs.gb"); // TODO: accept rom filepath
	unloadCPU(&cpu);
	unloadMemory(&memory);
}