#pragma once
#include "memory.h"

/* F Register flag defines */
#define FLAG_CARRY      0x10
#define FLAG_HALF_CARRY 0x20
#define FLAG_OP         0x40
#define FLAG_ZERO       0x80

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
  Memory* memory;
} Z80;

Z80* createCPU();
void unloadCPU(Z80* cpu);

void run(Z80* cpu, const char* rom);

/* Gameboy Instruction Set */
void (*instruction)(Z80* cpu);
