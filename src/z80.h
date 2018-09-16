#pragma once
#include "memory.h"

/* Flag register definitions */
#define FLAG_ZERO       0x1
#define FLAG_SUBTRACT   0x2
#define FLAG_HALF_CARRY 0x4
#define FLAG_CARRY      0x8

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
    unsigned short hl;
  };

  unsigned short sp;
  unsigned short pc;

} Registers;

typedef struct Clock
{
  char m, t;
  char last_m, last_t;
} Clock;

typedef struct Z80
{
  Registers registers;
  Clock clock;
} Z80;

Z80* createCPU();
void unloadCPU(Z80** cpu);

void run(Z80* cpu, Memory* memory, const char* rom);

// Z80 Instruction set
void nop(Z80* cpu, Memory* memory);

void inc_a(Z80* cpu, Memory* memory);
