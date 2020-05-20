#pragma once
#include "memory.h"
#include "z80.h"

constexpr uint16_t FRAMES_PER_SECOND = 60;

constexpr uint16_t LCD_STATUS_REGISTER = 0xFF41;

constexpr uint16_t LCD_STATUS_REGISTER_BIT_0 = 0x0;
constexpr uint16_t LCD_STATUS_REGISTER_BIT_1 = 0x1;
constexpr uint16_t LCD_STATUS_REGISTER_BIT_2 = 0x2;
constexpr uint16_t LCD_STATUS_REGISTER_BIT_3 = 0x4;
constexpr uint16_t LCD_STATUS_REGISTER_BIT_4 = 0x8;
constexpr uint16_t LCD_STATUS_REGISTER_BIT_5 = 0x16;
constexpr uint16_t LCD_STATUS_REGISTER_BIT_6 = 0x32;

constexpr uint16_t LCD_STATUS_MODE_0 = 0x0;
constexpr uint16_t LCD_STATUS_MODE_1 = 0x1;
constexpr uint16_t LCD_STATUS_MODE_2 = 0x2;
constexpr uint16_t LCD_STATUS_MODE_3 = 0x3;

// The pixel processing unit handles graphics related
// functionality of the gameboy.
class PPU {

	Memory* memory;
	CPU* cpu;

public: 

	uint16_t tick(uint16_t elapsedTicksThisFrame);

	void connectMemory(Memory* memory) {
		this->memory = memory;
	}

	void connectCPU(CPU* cpu) {
		this->cpu = cpu;
	}
};