
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat"  x64

IF EXIST bin (rmdir bin /s /q)
IF EXIST obj (rmdir obj /s /q)
mkdir bin
mkdir obj

set src=src/win_main.c src/emulator.c src/memory.c src/cpu.c
set libs=user32.lib Gdi32.lib opengl32.lib

cl /Od /EHsc /Fo:obj\ %src% %libs% /link /out:bin\pyrite.exe /Subsystem:WINDOWS