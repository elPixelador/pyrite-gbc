@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat"  x64   
cl /Od /Zi /EHsc src/main.c src/memory.c src/cpu.c user32.lib Shell32.lib Gdi32.lib /link /Subsystem:WINDOWS