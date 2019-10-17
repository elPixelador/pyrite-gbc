#include <iostream>;
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class PyriteUI : public olc::PixelGameEngine
{
public:
	PyriteUI()
	{
		sAppName = "Pyrite GBC";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Update game screen
		for (int x = 0; x < ScreenWidth() / 2; x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));

		// Update debugging info

		auto textX = ScreenWidth() / 2 + 1;

		DrawString(textX, 12 * 0, "Registers: ");
		DrawString(textX, 12 * 1, "PC: ");
		DrawString(textX, 12 * 2, "SP: ");
		DrawString(textX, 12 * 3, "A: ");
		DrawString(textX, 12 * 4, "F: ");
		DrawString(textX, 12 * 5, "B: ");
		DrawString(textX, 12 * 6, "C: ");
		DrawString(textX, 12 * 7, "D: ");
		DrawString(textX, 12 * 8, "E: ");
		DrawString(textX, 12 * 9, "H: ");
		DrawString(textX, 12 * 10, "L: ");

		return true;
	}
};

int main(int argc, char** argv)
{
	PyriteUI demo;
	if (demo.Construct(160 * 2, 144, 5, 5))
		demo.Start();

    return 0;
}