#pragma once
#include "memory.h"
#include <stdint.h>

/* Available interrupts. Cause the flow of the application to divert to certain important events such as rendering. */

constexpr uint8_t INTERRUPT_VERTICAL_BLANKING = 0x1;
constexpr uint8_t INTERRUPT_LCDC = 0x2;
constexpr uint8_t INTERRUPT_TIMER_OVERFLOW = 0x4;
constexpr uint8_t INTERRUPT_SERIAL_TRANSFER_COMPLETE = 0x8;
constexpr uint8_t INTERRUPT_P10_P13_NEGATIVE_EDGE = 0x16;

struct Registers
{
	union {
		struct {
			uint8_t a;
			uint8_t f;
		};
		uint16_t af = 0;
	};

	union {
		struct {
			uint8_t b;
			uint8_t c;
		};
		uint16_t bc = 0;
	};

	union {
		struct {
			uint8_t d;
			uint8_t e;
		};
		uint16_t de = 0;
	};

	union {
		struct {
			uint8_t h;
			uint8_t l;
		};
		uint16_t hl = 0;
	};

	uint16_t sp = 0; // Stack pointer
	uint16_t pc = 0; // Program counter

};

struct Clock
{
	uint16_t cycles = 0;
};

class Z80
{

	Registers registers;
	Clock clock;
	Memory* memory;

	uint8_t IE = 0;   // Interrupt enable
	uint8_t IF = 0;   // Interrupt request
	bool IME = false; // Interrupt master enable

	void process_interrupts();

	// Flags can be set during operations, The
	// leftmost 4 bits are used for this purpose. The
	// rightmost 4 bits are always 0.
	enum Flag : uint8_t {
		FLAG_ZERO =       0b10000000,
		FLAG_SUBTRACT =   0b01000000,
		FLAG_HALF_CARRY = 0b00100000,
		FLAG_CARRY =      0b00010000
	};

	/* Helper fuctions for dealing with flags. */

	void flag_test_zero(uint8_t val);
	void flag_test_half_carry(int16_t a, int16_t b);
	void flag_test_carry(uint8_t val);
	void flag_set(Flag flag);
	void flag_unset(Flag flag);

	/* Z80 Instruction set */

	void nop();       // 0x00
	void ld_bc_d16(); // 0x01
	void ld_bc_a();   // 0x02
	void inc_bc();    // 0x03
	void inc_b();     // 0x04
	void dec_b();     // 0x05
	void ld_b_d8();   // 0x06
	void rlca();      // 0x07
	void ld_a16_sp(); // 0x08
	void add_hl_bc(); // 0x09
	void ld_a_bc();   // 0x0A
	void dec_bc();    // 0x0B
	void inc_c();     // 0x0C
	void dec_c();     // 0x0D
	void ld_c_d8();   // 0x0E
	void rrca();      // 0x0F

	void ld_hl_d16(); // 0x21

	void inc_a();     // 0x3C

	void halt();      // 0x76

	void xor_a();     // 0xAF
	void xor_b();     // 0xA8
	void xor_c();     // 0xA9
	void xor_d();     // 0xAA
	void xor_e();     // 0xAB
	void xor_h();	  // 0xAC
	void xor_l();	  // 0xAD
	void xor_hl();	  // 0xAE

	void cp_a();      // 0xBF
	void cp_b();      // 0xB8
	void cp_c();      // 0xB9
	void cp_d();      // 0xBA
	void cp_e();      // 0xBB
	void cp_h();      // 0xBC
	void cp_l();      // 0xBD
	void cp_hl();     // 0xBE

	void jp_a16();    // 0xC3
	void ret();		  // 0xC9

	void ldh_a8_A();  // 0xE0

	void ldh_A_a8();  // 0xF0

public:

	void tick();

	void connectMemory(Memory* memory) {
		this->memory = memory;
	}

	Registers const* const getRegisters() const {
		return &registers;
	}

};