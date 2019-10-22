#include <iostream>
#include "z80.h"
#include "memory.h"
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class PyriteUI : public olc::PixelGameEngine
{
	Z80* cpu;
	Memory* memory;

public:

	PyriteUI() {
		sAppName = "Pyrite GBC";
		this->cpu = new Z80();
		this->memory = new Memory();
	}

	~PyriteUI() {
		delete this->cpu;
		delete this->memory;
	}

	bool OnUserCreate() override {
		this->cpu->connectMemory(this->memory);
		this->memory->loadROM("./tetris.gb");
		return true;
	}

	bool OnUserUpdate(float delta) override {

		Clear(olc::BLACK);

		cpu->tick();

		// Update game screen
		for (int x = 0; x < ScreenWidth() / 2; x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));

		// Update debugging info
		auto registers = cpu->getRegisters();
		auto textX = ScreenWidth() / 2 + 1;
		DrawString(textX, 12 * 0, "PC:" + std::to_string(registers->pc));
		DrawString(textX, 12 * 1, "SP:" + std::to_string(registers->sp));
		DrawString(textX, 12 * 2, "A: " + std::to_string(registers->a));
		DrawString(textX, 12 * 3, "F: " + std::to_string(registers->f));
		DrawString(textX, 12 * 4, "B: " + std::to_string(registers->b));
		DrawString(textX, 12 * 5, "C: " + std::to_string(registers->c));
		DrawString(textX, 12 * 6, "D: " + std::to_string(registers->d));
		DrawString(textX, 12 * 7, "E: " + std::to_string(registers->e));
		DrawString(textX, 12 * 8, "H: " + std::to_string(registers->h));
		DrawString(textX, 12 * 9, "L: " + std::to_string(registers->l));

		return true;
	}
};

int main(int argc, char** argv) {

	PyriteUI demo;
	if (demo.Construct(160 * 2, 144, 5, 5))
		demo.Start();

    return 0;

}