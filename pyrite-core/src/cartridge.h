#pragma once
#include <string>

class Cartridge {
	uint8_t data[0x8000];
public:
	Cartridge(std::string path);
	void loadROM0(uint8_t* memory);
};