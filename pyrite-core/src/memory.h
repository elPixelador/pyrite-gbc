#pragma once
#include <string>

/* Important regions in memory. */

struct MemoryRegion {
	uint16_t start;
	uint16_t end;
};

constexpr MemoryRegion ROM0 =         { 0x0000, 0x3FFF }; // Non-switchable ROM
constexpr MemoryRegion ROMX =         { 0x4000, 0x7FFF }; // Switchable ROM bank
constexpr MemoryRegion VRAM =         { 0x8000, 0x9FFF }; // Video RAM, Switchable
constexpr MemoryRegion SRAM =         { 0xA000, 0xBFFF }; // External RAM
constexpr MemoryRegion WRAM0 =        { 0xC000, 0xCFFF }; // Work RAM
constexpr MemoryRegion WRAMX =        { 0xD000, 0xDFFF }; // Work RAM, Switchable
constexpr MemoryRegion ECHO =         { 0xE000, 0xFDFF }; // 
constexpr MemoryRegion OAM =          { 0xFE00, 0xFE9F }; // Sprite information table
constexpr MemoryRegion UNUSED =       { 0xFEA0, 0xFEFF }; // 
constexpr MemoryRegion IO_REGISTERS = { 0xFF00, 0xFF7F }; // Input / Output registers
constexpr MemoryRegion HRAM =         { 0xFF80, 0xFFFE }; // Internal CPU RAM
constexpr MemoryRegion IE_REGISTERS = { 0xFFFF, 0xFFFF }; // Interupt enable flags

class Memory {

	uint8_t data[0xFFFF];

public:

	void loadROM(std::string path);

	uint8_t readByte(uint16_t addr);
	uint16_t readWord(uint16_t addr);
	void writeByte(uint16_t addr, uint8_t byte);
	void writeWord(uint16_t addr, uint16_t byte);

};
