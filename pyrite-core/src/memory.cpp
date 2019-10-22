#include "memory.h"
#include <fstream>
#include <iostream>

void Memory::loadROM(std::string path) {
	std::ifstream ifs(path, std::ios::binary);
	if (ifs)
		ifs.read((char*)data, 0xFFFF);
	else
		std::cerr << "Failed to open ROM: " << path << std::endl;
	ifs.close();
}

uint8_t Memory::readByte(uint16_t addr) {
	return this->data[addr];
}

uint16_t Memory::readWord(uint16_t addr) {
	return this->data[addr] | (this->data[addr + 1] << 8);
}

void Memory::writeByte(uint16_t addr, uint8_t byte) {
	this->data[addr] = byte;
}

void Memory::writeWord(uint16_t addr, uint16_t word) {
	this->data[addr] = word & 0xff;
	this->data[addr+1] = (word >> 8);
}
