#pragma once
#include "memory.h"

/* Available flags. These are set by instructions.  */

constexpr uint8_t FLAG_ZERO = 0x1;
constexpr uint8_t FLAG_SUBTRACT = 0x2;
constexpr uint8_t FLAG_HALF_CARRY = 0x4;
constexpr uint8_t FLAG_CARRY = 0x8;

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

	uint8_t IE = 0; // Interrupt enable
	uint8_t IF = 0; // Interrupt request
	bool IME = false;     // Interrupt master enable

	void process_interrupts();

	void flag_test_zero(Registers* registers, uint8_t val);
	void flag_test_half_carry(Registers* registers, int16_t a, int16_t b);
	void flag_test_carry(Registers* registers, uint8_t val);
	void flag_set(Registers* registers, uint8_t flag);
	void flag_unset(Registers* registers, uint8_t flag);

	// Z80 Instruction set
	void nop();      // 0x00
	void halt();     // 0x76

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

	void ld_hl_d16(); // 0x21

	void ldh_A_a8();
	void ldh_a8_A();

public:

	void tick();

	void connectMemory(Memory* memory) {
		this->memory = memory;
	}

	Registers const* const getRegisters() const {
		return &registers;
	}

};