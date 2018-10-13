#ifdef _WIN32

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <shellapi.h>
#include <stdint.h>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

// Global for now
static int running;
static BITMAPINFO bitmapInfo;
static void *bitmapMemory;
static int bitmapWidth;
static int bitmapHeight;

static void resizeDIBSection(int width, int height)
{
	if (bitmapMemory)
	{
		VirtualFree(bitmapMemory, 0, MEM_RELEASE);
	}

	bitmapWidth = width;
	bitmapHeight = height;

	bitmapInfo.bmiHeader.biSize = sizeof(bitmapInfo.bmiHeader);
	bitmapInfo.bmiHeader.biWidth = bitmapWidth;
	bitmapInfo.bmiHeader.biHeight = -bitmapHeight;
	bitmapInfo.bmiHeader.biPlanes = 1;
	bitmapInfo.bmiHeader.biBitCount = 32;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;

	int bytesPerPixel = 4;
	int bitmapMemorySize = (bitmapWidth * bitmapHeight) * bytesPerPixel;
	bitmapMemory = VirtualAlloc(0, bitmapMemorySize, MEM_COMMIT, PAGE_READWRITE);

	int pitch = width * bytesPerPixel;
	uint8 *row = (uint8 *)bitmapMemory;
	for (int y = 0; y < bitmapHeight; ++y)
	{
		uint8 *pixel = (uint8 *)row;
		for (int x = 0; x < bitmapWidth; ++x)
		{
			*pixel = (uint8)x;
			++pixel;
			*pixel = (uint8)y;
			++pixel;
			*pixel = 0;
			++pixel;
			*pixel = 0;
			++pixel;
		}
		row += pitch;
	}
}

static void renderWindow(HDC ctx, RECT *windowRect, int x, int y, int width, int height)
{

	int windowWidth = windowRect->right - windowRect->left;
	int windowHeight = windowRect->bottom - windowRect->top;

	StretchDIBits(
		ctx,
		0, 0, bitmapWidth, bitmapHeight,
		0, 0, windowWidth, windowHeight,
		bitmapMemory,
		&bitmapInfo,
		DIB_RGB_COLORS,
		SRCCOPY);
}

LRESULT CALLBACK WindowCallback(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	LRESULT result = 1;

	switch (uMsg)
	{
	case WM_SIZE:
	{
		RECT rect;
		GetClientRect(hwnd, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		resizeDIBSection(width, height);
	}
	break;

	case WM_DESTROY:
	{
		running = 0;
		OutputDebugStringA("WM_DESTROY\n");
	}
	break;

	case WM_CLOSE:
	{
		PostQuitMessage(0);
		running = 0;
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

		RECT rect;
		GetClientRect(hwnd, &rect);

		renderWindow(deviceCtx, &rect, x, y, width, height);
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

	windowClass.style = CS_HREDRAW | CS_VREDRAW;
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
			running = 1;
			while (running)
			{
				MSG msg;

				while(PeekMessage(&msg,0, 0, 0, PM_REMOVE))
				{
					if(msg.message == WM_QUIT)
					{
						running = 0;
					}

					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			};
		}
	}
	else
	{
		// Log
	}

	return EXIT_SUCCESS;
}

#endif