@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat"  x64   

set compilerflags= /Od /Zi /EHsc
set linkerflags= /link /out:emu.exe
set programFiles= src/main.c src/memory.c src/z80.c

cl.exe %compilerflags% %programFiles% %linkerflags%