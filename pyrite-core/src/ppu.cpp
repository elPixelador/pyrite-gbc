#include "ppu.h"

uint16_t PPU::tick(uint16_t elapsedTicks)
{
    this->ppuClockCycles += elapsedTicks;

    uint8_t lcdcRegister = this->memory->readByte(LCD_CONTROL_REGISTER); // LCDC at 0xFF40
    if (!(lcdcRegister & 0x80))
    {
        // LCD is off, reset state and exit
        this->currentScanline = 0;
        this->ppuClockCycles = 0;
        this->memory->writeByte(LCD_STATUS_REGISTER, (this->memory->readByte(LCD_STATUS_REGISTER) & 0xFC) | 0x00); // Mode 0
        this->memory->writeByte(LY_REGISTER, 0);                                                                   // LY at 0xFF44
        return elapsedTicks;
    }

    uint8_t statusRegister = this->memory->readByte(LCD_STATUS_REGISTER);
    uint8_t currentMode = statusRegister & 0x03; // Get current mode (bits 0-1)

    // --- Mode 2: OAM Scan (80 cycles per scanline) ---
    if (this->currentScanline < 144)
    {
        if (this->ppuClockCycles < 80)
        {
            if (currentMode != 2)
            {
                this->memory->writeByte(LCD_STATUS_REGISTER, (statusRegister & 0xFC) | 0x02); // Set Mode 2
                // Request OAM interrupt if enabled
                if (statusRegister & 0x20)
                {
                    requestInterrupt(InterruptType::LcdStat);
                }
            }
        }
        // --- Mode 3: LCD Driver Transfer (172 cycles per scanline) ---
        else if (this->ppuClockCycles < (80 + 172))
        {
            if (currentMode != 3)
            {
                this->memory->writeByte(LCD_STATUS_REGISTER, (statusRegister & 0xFC) | 0x03); // Set Mode 3
                // Here you would read tile data and sprite data to prepare for rendering
            }
        }
        // --- Mode 0: H-Blank (204 cycles per scanline) ---
        else if (this->ppuClockCycles < (80 + 172 + 204))
        {
            if (currentMode != 0)
            {
                this->memory->writeByte(LCD_STATUS_REGISTER, (statusRegister & 0xFC) | 0x00); // Set Mode 0
                // Request H-Blank interrupt if enabled
                if (statusRegister & 0x08)
                {
                    requestInterrupt(InterruptType::LcdStat);
                }
                // Increment LY (current scanline) at the end of H-Blank
                this->currentScanline++;
                this->ppuClockCycles -= (80 + 172 + 204); // Reset for the next scanline

                this->memory->writeByte(LY_REGISTER, this->currentScanline);

                // Check LYC=LY coincidence
                uint8_t lyc = this->memory->readByte(LY_COMPARE_REGISTER); // LYC at 0xFF45
                if (this->currentScanline == lyc)
                {
                    this->memory->writeByte(LCD_STATUS_REGISTER, statusRegister | 0x04); // Set Coincidence Flag
                    // Request LYC=LY interrupt if enabled
                    if (statusRegister & 0x40)
                    {
                        requestInterrupt(InterruptType::LcdStat);
                    }
                }
                else
                {
                    this->memory->writeByte(LCD_STATUS_REGISTER, statusRegister & ~0x04); // Clear Coincidence Flag
                }
            }
        }
    }
    // --- Mode 1: V-Blank (4560 cycles per V-Blank line, 10 V-Blank lines) ---
    else if (this->currentScanline < 154)
    {
        if (currentMode != 1)
        {
            this->memory->writeByte(LCD_STATUS_REGISTER, (statusRegister & 0xFC) | 0x01); // Set Mode 1 (V-Blank)
            // Request V-Blank interrupt (always enabled)
            requestInterrupt(InterruptType::VBlank);
        }
        this->ppuClockCycles -= (80 + 172 + 204); // Effectively reset for the next V-Blank line
        this->currentScanline++;
        this->memory->writeByte(LY_REGISTER, this->currentScanline);
    }
    // --- Reset frame ---
    else
    {
        this->currentScanline = 0;
        this->ppuClockCycles = 0;
        this->memory->writeByte(LY_REGISTER, 0);
    }

    return elapsedTicks; // PPU tick doesn't directly return a cycle count for the CPU
}

void PPU::requestInterrupt(InterruptType type)
{
    uint8_t interruptFlag = this->memory->readByte(INTERRUPT_FLAG_REGISTER); // IF at 0xFF0F
    interruptFlag |= (1 << static_cast<uint8_t>(type));
    this->memory->writeByte(INTERRUPT_FLAG_REGISTER, interruptFlag);
}