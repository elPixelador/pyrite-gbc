
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat"  x64

IF EXIST bin (rmdir bin /s /q)
IF EXIST obj (rmdir obj /s /q)
mkdir bin
mkdir obj

set src= test/unit_test.c src/emulator.c src/memory.c src/cpu.c

cl /Od /EHsc /Fo:obj\ %src% /link /out:bin\pyrite_tests.exe