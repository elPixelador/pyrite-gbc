#include "cartridge.h"
#include <fstream>
#include <iostream>

Cartridge::Cartridge(std::string path) : data()
{
	std::ifstream ifs(path, std::ios::binary);
	if (ifs)
		ifs.read((char *)data, 0x8000);
	else
		std::cerr << "Failed to open ROM: " << path << std::endl;
	ifs.close();
}

void Cartridge::loadROM0(uint8_t *memory)
{
	memcpy(memory, this->data, 0x3FFF);
}