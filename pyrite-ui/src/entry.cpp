#include <iostream>
#include <thread>
#include <chrono>
#include "z80.h"
#include "memory.h"
#include "ppu.h"
#include "cartridge.h"
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class PyriteUI : public olc::PixelGameEngine
{
	CPU* cpu;
	PPU* ppu;
	Memory* memory;
	Cartridge* cart;

public:

	PyriteUI() {
		sAppName = "Pyrite GBC";
		this->cpu = new CPU();
		this->ppu = new PPU();
		this->memory = new Memory();
		this->cart = new Cartridge("./tetris.gb");
	}

	~PyriteUI() {
		delete this->cpu;
		delete this->memory;
		delete this->ppu;
		delete this->cart;
	}

	bool OnUserCreate() override {
		this->memory->loadCartridge(this->cart);
		this->cpu->connectMemory(this->memory);
		return true;
	}

	bool OnUserUpdate(float delta) override {

		auto start = std::chrono::steady_clock::now();

		Clear(olc::BLACK);
		
		uint16_t ticksPerFrame = CLOCK_SPEED / FRAMES_PER_SECOND;
		std::chrono::nanoseconds frameTime(16600000);
		uint16_t ticksExecuted = 0;

		// Emulate system
		while(ticksExecuted <= ticksPerFrame) {
			ticksExecuted += cpu->tick();
			ticksExecuted += ppu->tick();
		}

		// Update game screen
		for (int x = 0; x < ScreenWidth() / 2; x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));

		// Update debugging info
		auto registers = cpu->getRegisters();
		auto textX = ScreenWidth() / 2 + 1;
		DrawString(textX, (12 * 0) + 1, "PC:" + std::to_string(registers->pc));
		DrawString(textX, (12 * 1) + 1, "SP:" + std::to_string(registers->sp));
		DrawString(textX, (12 * 2) + 1, "A: " + std::to_string(registers->a));
		DrawString(textX, (12 * 3) + 1, "F: " + std::to_string(registers->f));
		DrawString(textX, (12 * 4) + 1, "B: " + std::to_string(registers->b));
		DrawString(textX, (12 * 5) + 1, "C: " + std::to_string(registers->c));
		DrawString(textX, (12 * 6) + 1, "D: " + std::to_string(registers->d));
		DrawString(textX, (12 * 7) + 1, "E: " + std::to_string(registers->e));
		DrawString(textX, (12 * 8) + 1, "H: " + std::to_string(registers->h));
		DrawString(textX, (12 * 9) + 1, "L: " + std::to_string(registers->l));

		DrawString(textX + 55, (12 * 0) + 1, "IE: " + std::to_string(cpu->getIEFlag()));
		DrawString(textX + 55, (12 * 1) + 1, "IF: " + std::to_string(cpu->getIFFlag()));
		DrawString(textX + 55, (12 * 2) + 1, "IME:" + std::to_string(cpu->getInterruptMasterEnable()));

		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		// Wait until we reach our target frame rate.
		while (elapsed < frameTime) {
			end = std::chrono::steady_clock::now();
			elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		}

		return true;
	}
};

int main(int argc, char** argv) {

	PyriteUI demo;
	if (demo.Construct(160 * 2, 144, 5, 5))
		demo.Start();

    return 0;

}