#pragma once
#include "memory.h"

/* Flag register definitions */
constexpr auto FLAG_ZERO = 0x1;
constexpr auto FLAG_SUBTRACT = 0x2;
constexpr auto FLAG_HALF_CARRY = 0x4;
constexpr auto FLAG_CARRY = 0x8;

constexpr auto INTERRUPT_VERTICAL_BLANKING = 0x1;
constexpr auto INTERRUPT_LCDC = 0x2;
constexpr auto INTERRUPT_TIMER_OVERFLOW = 0x4;
constexpr auto INTERRUPT_SERIAL_TRANSFER_COMPLETE = 0x8;
constexpr auto INTERRUPT_P10_P13_NEGATIVE_EDGE = 0x16;

struct Registers
{
	union {
		struct {
			unsigned char a;
			unsigned char f;
		};
		unsigned short af = 0;
	};

	union {
		struct {
			unsigned char b;
			unsigned char c;
		};
		unsigned short bc = 0;
	};

	union {
		struct {
			unsigned char d;
			unsigned char e;
		};
		unsigned short de = 0;
	};

	union {
		struct {
			unsigned char h;
			unsigned char l;
		};
		unsigned short hl = 0;
	};

	unsigned short sp = 0; // Stack pointer
	unsigned short pc = 0; // Program counter

};

struct Clock
{
	unsigned short cycles = 0;
	unsigned short last_cycles = 0;
};

class Z80
{

	Registers registers;
	Clock clock;
	Memory memory;

	unsigned char IE = 0; // Interrupt enable
	unsigned char IF = 0; // Interrupt request
	int IME = 0;          // Interrupt master enable

	void tick();
	void process_interrupts();

	void flag_test_zero(Registers* registers, unsigned char val);
	void flag_test_half_carry(Registers* registers, char a, char b);
	void flag_test_carry(Registers* registers, unsigned char val);
	void flag_set(Registers* registers, unsigned char flag);
	void flag_unset(Registers* registers, unsigned char flag);

	// Z80 Instruction set
	void nop();
	void halt();

	void ret();
	void jp_a16();

	void inc_a();
	void dec_c();
	void cp_a();
	void cp_b();
	void cp_c();
	void cp_d();
	void cp_e();
	void cp_h();
	void cp_l();
	void cp_hl();

	void xor_a();
	void xor_b();
	void xor_c();
	void xor_d();
	void xor_e();
	void xor_h();
	void xor_l();
	void xor_hl();

	void ldh_A_a8();
	void ldh_a8_A();

};