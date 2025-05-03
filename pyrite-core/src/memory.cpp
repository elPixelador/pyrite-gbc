#include "memory.h"
#include <iostream>

void Memory::loadCartridge(Cartridge* cartridge) {
	cartridge->loadROM0(this->data);
}

uint8_t Memory::readByte(uint16_t addr) {
	return this->data[addr];
}

uint16_t Memory::readWord(uint16_t addr) {
	uint8_t hi = this->data[addr];
	uint8_t lo = this->data[addr+1];
	return hi | (lo << 8);
}

void Memory::writeByte(uint16_t addr, uint8_t byte) {
	this->data[addr] = byte;
}

void Memory::writeWord(uint16_t addr, uint16_t word) {
	uint8_t hi = word & 0xff;
	uint8_t lo = (word >> 8);
	this->data[addr] = hi;   
	this->data[addr+1] = lo;
}
