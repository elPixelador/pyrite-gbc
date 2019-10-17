#pragma once

constexpr auto MEMORY_SIZE = 0xFFFF;
constexpr auto ROM_BANK_0 = 0x3FFF;

/* Starting Addresses for key locations in memory. */

constexpr auto INTERRUPT_RST =     0x0000;
constexpr auto ROM_DATA =          0x1000;
constexpr auto USER_PROG_AREA =    0x1500;
constexpr auto BANK_CHAR_DATA =    0x8000;
constexpr auto BG_DISPLAY_DATA_1 = 0x9800;
constexpr auto BG_DISPLAY_DATA_2 = 0x9C00;
constexpr auto EXTERN_EXPAC_RAM =  0xA000;
constexpr auto BANK_0 =            0xC000;
constexpr auto BANK_1_7 =          0xD000;
constexpr auto PROHIBITED =        0xE000;
constexpr auto OAM =               0xFE00;
constexpr auto WTF_IS_THIS =       0xFEA0;
constexpr auto OTHER_REGISTERS =   0xFF00;
constexpr auto WORK_STACK_RAM =    0xFF80;
constexpr auto UNUSED =            0xFFFE;

class Memory {

	unsigned char data[MEMORY_SIZE];

public:

	unsigned char readByte(unsigned short addr);
	unsigned short readWord(unsigned short addr);
	void writeByte(unsigned short addr, unsigned char byte);
	void writeWord(unsigned short addr, unsigned short byte);

};
