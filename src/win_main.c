#ifdef _WIN32

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <shellapi.h>
#include <stdint.h>
#include <gl/gl.h>

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

static GLfloat pixels[144 * 160 * 3] = {0}; // width * height * (R,G,B) per pixel

GLuint texid[] = { -1 };

static void Win32InitOpenGL(HWND hwnd)
{
	HDC windowDC = GetDC(hwnd);

	// We describe the buffer format we would "like" from the system
	PIXELFORMATDESCRIPTOR requestedPixelFormat = {0};
	requestedPixelFormat.nSize = sizeof(requestedPixelFormat);
	requestedPixelFormat.nVersion = 1;
	requestedPixelFormat.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
	requestedPixelFormat.cColorBits = 24;
	requestedPixelFormat.cAlphaBits = 8;
	requestedPixelFormat.iLayerType = PFD_MAIN_PLANE;

	// The system could give us anything back, we basically have to accept what we're given.
	int suggestedFormatIndex = ChoosePixelFormat(windowDC, &requestedPixelFormat);
	PIXELFORMATDESCRIPTOR suggestedFormat;
	DescribePixelFormat(windowDC, suggestedFormatIndex, sizeof(suggestedFormat), &suggestedFormat);
	SetPixelFormat(windowDC, suggestedFormatIndex, &suggestedFormat);

	// create our OpenGL context
	HGLRC openGLRC = wglCreateContext(windowDC);
	if (wglMakeCurrent(windowDC, openGLRC))
	{
		for(int i = 0; i < 144 * 160 * 3; ++i) 
		{
			pixels[i] = 0.00001f * i;
		}

		glEnable( GL_TEXTURE_2D );
    	glGenTextures( 1, texid );
    	glBindTexture( GL_TEXTURE_2D, texid[ 0 ] );
    	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 144, 160, 0, GL_RGB, GL_FLOAT, pixels );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	}
	else
	{
		// err
	}

	ReleaseDC(hwnd, windowDC);
}

static void Win32RenderBuffer(HDC ctx, RECT* windowRect, int x, int y, int width, int height)
{
	// Clear buffer
	glViewport(0, 0, width, height);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Render test
	glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0, 1, 1, 0, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glColor3f( 1, 1, 1 );
    glBindTexture( GL_TEXTURE_2D, texid[ 0 ] );
    glBegin( GL_QUADS );
    glTexCoord2f( 0, 0 );
    glVertex2f( 0, 0 );
    glTexCoord2f( 1, 0 );
    glVertex2f( 1, 0 );
    glTexCoord2f( 1, 1 );
    glVertex2f( 1, 1 );
    glTexCoord2f( 0, 1 );
    glVertex2f( 0, 1 );
    glEnd();

	// Swap back buffer
	SwapBuffers(ctx);
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

		Win32RenderBuffer(deviceCtx, &rect, x, y, width, height);
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
	// Define a window to be created
	WNDCLASS windowClass = {0};
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = WindowCallback;
	windowClass.hInstance = hInstance;
	windowClass.lpszClassName = "PyriteWindowClass";

	// Create the window
	if (RegisterClass(&windowClass))
	{
		HWND windowHandle = CreateWindowEx(
			0,
			windowClass.lpszClassName,
			"Pyrite",
			WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			144 * 3,
			160 * 3,
			0,
			0,
			hInstance,
			0);

		// Setup render context & windows message handler
		if (windowHandle)
		{
			Win32InitOpenGL(windowHandle);

			running = 1;

			while (running)
			{
				MSG msg;

				while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
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