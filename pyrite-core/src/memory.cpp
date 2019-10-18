#include "memory.h"
#include <fstream>

void Memory::loadROM(std::string path) {
	std::ifstream ifs(path, std::ios::binary);
	if (ifs) ifs.read((char*)data, 0xFFFF);
	ifs.close();
}

uint8_t Memory::readByte(uint16_t addr) {
	return this->data[addr];
}

uint16_t Memory::readWord(uint16_t addr) {
	uint16_t a = this->data[addr];
	uint16_t b = this->data[addr+1];
	return a | (b << 8);
}

void Memory::writeByte(uint16_t addr, uint8_t byte) {
	this->data[addr] = byte;
}

void Memory::writeWord(uint16_t addr, uint16_t byte) {
	this->data[addr] = byte;
}
