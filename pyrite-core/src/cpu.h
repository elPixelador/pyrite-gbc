#pragma once
#include "memory.h"

/* Flag register definitions */
#define FLAG_ZERO       0x1
#define FLAG_SUBTRACT   0x2
#define FLAG_HALF_CARRY 0x4
#define FLAG_CARRY      0x8

#define INTERRUPT_VERTICAL_BLANKING         0x1
#define INTERRUPT_LCDC                      0x2
#define INTERRUPT_TIMER_OVERFLOW            0x4
#define INTERRUPT_SERIAL_TRANSFER_COMPLETE  0x8
#define INTERRUPT_P10_P13_NEGATIVE_EDGE     0x16

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

  unsigned short sp; // Stack pointer
  unsigned short pc; // Program counter

} Registers;

typedef struct Clock
{
  unsigned short cycles;
  unsigned short last_cycles;
} Clock;

typedef struct Z80
{
  Registers registers;
  Clock clock;

  unsigned char IE; // Interrupt enable
  unsigned char IF; // Interrupt request
  int IME; // Interrupt master enable

} CPU;

CPU* createCPU();
void unloadCPU(CPU** cpu);

void run(CPU* cpu, Memory* memory, const char* rom);

void process_interrupts(CPU* cpu, Memory* memory);

// Z80 Instruction set
void nop(CPU* cpu, Memory* memory);
void halt(CPU* cpu, Memory* memory);

void ret(CPU* cpu, Memory* memory);
void jp_a16(CPU* cpu, Memory* memory);

void inc_a(CPU* cpu, Memory* memory);
void dec_c(CPU* cpu, Memory* memory);

void cp_a(CPU* cpu, Memory* memory);
void cp_b(CPU* cpu, Memory* memory);
void cp_c(CPU* cpu, Memory* memory);
void cp_d(CPU* cpu, Memory* memory);
void cp_e(CPU* cpu, Memory* memory);
void cp_h(CPU* cpu, Memory* memory);
void cp_l(CPU* cpu, Memory* memory);
void cp_hl(CPU* cpu, Memory* memory);

void xor_a(CPU* cpu, Memory* memory);
void xor_b(CPU* cpu, Memory* memory);
void xor_c(CPU* cpu, Memory* memory);
void xor_d(CPU* cpu, Memory* memory);
void xor_e(CPU* cpu, Memory* memory);
void xor_h(CPU* cpu, Memory* memory);
void xor_l(CPU* cpu, Memory* memory);
void xor_hl(CPU* cpu, Memory* memory);

void ldh_A_a8(CPU* cpu, Memory* memory);
void ldh_a8_A(CPU* cpu, Memory* memory);