#include "ppu.h"

uint16_t PPU::tick(uint16_t elapsedTicksThisFrame)
{

	// A single frame is 154 scanlines (70224 ticks)

	// The GPU is reliant on the LCDC Status register to manage state
	//
	// Bit 6 - LYC=LY Coincidence Interrupt (1=Enable) (Read/Write)
	// Bit 5 - Mode 2 OAM Interrupt(1 = Enable) (Read / Write)
	// Bit 4 - Mode 1 V - Blank Interrupt(1 = Enable) (Read / Write)
	// Bit 3 - Mode 0 H - Blank Interrupt(1 = Enable) (Read / Write)
	// Bit 2 - Coincidence Flag(0:LYC<>LY, 1 : LYC = LY) (Read Only)
	// Bit 1 - 0 - Mode Flag(Mode 0 - 3, see below) (Read Only)
	//		   0: During H - Blank
	//         1 : During V - Blank
	//         2 : During Searching OAM
	//         3 : During Transferring Data to LCD Driver

	uint8_t lcdcRegister = this->memory->readByte(LCD_STAT_REGISTER);

	// TODO: Some magical shit here

	// Scan OAM

	// Read OAM

	// Horizontal Blank

	this->memory->writeByte(LCD_STAT_REGISTER, lcdcRegister);

	return 70224;
}