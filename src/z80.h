#pragma once

typedef struct Registers
{
  union{
    struct{
        unsigned char a;
        unsigned char f;
    };
    unsigned short af;
  };

  union{
    struct{
        unsigned char b;
        unsigned char c;
    };
    unsigned short bc;
  };

  union{
    struct{
        unsigned char d;
        unsigned char e;
    };
    unsigned short de;
  };

  union{
    struct{
        unsigned char h;
        unsigned char l;
    };
    unsigned short bc;
  };

  unsigned short sp;
  unsigned short pc;

} Registers;

typedef struct Z80
{
  Registers registers;
  Memory* memory;
} Z80;

Z80* createCPU();
void unloadCPU(Z80* cpu);

// Gameboy Instruction Set
void (*instruction)(int argc, char[] args);
