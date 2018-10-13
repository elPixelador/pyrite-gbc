#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <shellapi.h>

#include "cpu.h"
#include "memory.h"

LRESULT CALLBACK WindowCallback(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	LRESULT result = 0;

	switch (uMsg)
	{
	case WM_SIZE:
	{
		OutputDebugStringA("WM_SZE\n");
	}
	break;

	case WM_DESTROY:
	{
		OutputDebugStringA("WM_DESTROY\n");
	}
	break;

	case WM_CLOSE:
	{
		OutputDebugStringA("WM_CLOSE\n");
	}
	break;

	case WM_ACTIVATEAPP:
	{
		OutputDebugStringA("WM_ACTIVATEAPP\n");
	}
	break;

	case WM_PAINT: 
	{
		PAINTSTRUCT paint;
		HDC deviceCtx = BeginPaint(hwnd, &paint);

		int x = paint.rcPaint.left;
		int y = paint.rcPaint.top;
		int height = paint.rcPaint.bottom - paint.rcPaint.top;
		int width = paint.rcPaint.right - paint.rcPaint.left;

		PatBlt(deviceCtx, x, y, width, height, WHITENESS);
		EndPaint(hwnd, &paint);
	}
	break;

	default:
	{
		result = DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	break;
	}

	return result;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	WNDCLASS windowClass = {0};

	windowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WindowCallback;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = "PyriteWindowClass";

	if (RegisterClass(&windowClass))
	{
		HWND windowHandle = CreateWindowEx(
			0,
			windowClass.lpszClassName,
			"Pyrite",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			0,
			0,
			hInstance,
			0);

		if (windowHandle)
		{
			LPMSG message;
			for (;;)
			{
				BOOL messageResult = GetMessage(&message, 0, 0, 0);
				if (messageResult > 0)
				{
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
				else
				{
					break;
				}
			};
		}
	}
	else
	{
	}

	// Initalize & run Pyrite emulator
	CPU *cpu = createCPU();
	Memory *memory = createMemory();
	run(cpu, memory, "./test/cpu_instrs.gb");
	unloadCPU(&cpu);
	unloadMemory(&memory);

	MessageBox(0, "One day, this will be a gameboy emulator.", "Pyrite", MB_OK | MB_ICONINFORMATION);

	return EXIT_SUCCESS;
}