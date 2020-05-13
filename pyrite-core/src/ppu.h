#pragma once
#include "memory.h"
#include "z80.h"

constexpr uint16_t FRAMES_PER_SECOND = 60;

constexpr uint16_t LCD_STATUS_REGISTER = 0xFF41;


// The pixel processing unit handles graphics related
// functionality of the gameboy.
class PPU {

	Memory* memory;
	CPU* cpu;

	uint8_t frameTicks = 0;
	uint8_t scanlineTicks = 0;

public: 

	uint16_t tick();

	void connectMemory(Memory* memory) {
		this->memory = memory;
	}

	void connectCPU(CPU* cpu) {
		this->cpu = cpu;
	}
};