#pragma once
#include "memory.h"
#include <cstdint>

/* Available interrupts. Cause the flow of the application to divert to certain important events such as rendering. */

constexpr uint8_t INTERRUPT_VERTICAL_BLANKING = 0x1;
constexpr uint8_t INTERRUPT_LCDC = 0x2;
constexpr uint8_t INTERRUPT_TIMER_OVERFLOW = 0x4;
constexpr uint8_t INTERRUPT_SERIAL_TRANSFER_COMPLETE = 0x8;
constexpr uint8_t INTERRUPT_P10_P13_NEGATIVE_EDGE = 0x16;

struct Registers{

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

	uint16_t sp = 0;      // Stack pointer
	uint16_t pc = 0x0100; // Program counter

};

struct Clock{
	uint16_t ticks = 0;
};

class CPU{

	Registers registers;
	Clock clock;
	Memory* memory;

	uint8_t IE = 0;   // Interrupt enable
	uint8_t IF = 0;   // Interrupt request
	bool IME = false; // Interrupt master enable

	void process_interrupts();

	// Flags can be set during operations, The
	// leftmost 4 bits are used for this purpose. The
	// rightmost 4 bits are reserved.
	enum OperationFlag : uint8_t {
		FLAG_ZERO =       0b10000000,
		FLAG_SUBTRACT =   0b01000000,
		FLAG_HALF_CARRY = 0b00100000,
		FLAG_CARRY =      0b00010000
	};

	/* Helper fuctions for dealing with flags. */

	// Takes a byte and sets the zero flag
	// if its value is 0.
	void flag_test_zero(uint16_t val);
	void flag_test_half_carry(int16_t a, int16_t b);
	void flag_test_carry(uint16_t val);
	// Sets a given flag to true state.
	void flag_set(OperationFlag flag);
	// Sets a given flag to false state.
	void flag_reset(OperationFlag flag);
	// Checks if a flag is currently set.
	bool flag_check(CPU::OperationFlag flag);

	/* Z80 Instruction set */

	void not_yet_implemented(uint8_t instr);

	void nop();       // 0x00
	void ld_bc_d16(); // 0x01
	void ld_mbc_a();  // 0x02
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

	void stop_0();    // 0x10
	void ld_de_d16(); // 0x11
	void ld_de_a();   // 0x12
	void inc_de();    // 0x13
	void inc_d();     // 0x14
	void dec_d();     // 0x15
	void ld_d_d8();   // 0x16
	void rla();       // 0x17
	void jr_r8();     // 0x18
	void add_hl_de(); // 0x19
	void ld_a_de();   // 0x1A
	void dec_de();    // 0x1B
	void inc_e();     // 0x1C
	void dec_e();     // 0x1D
	void ld_e_d8();   // 0x1E
	void rra();       // 0x1F

	void jr_nz_r8();  // 0x20
	void ld_hl_d16(); // 0x21

	void ld_hld_a();  // 0x32
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
	void di();        // 0xF3
	void ei();        // 0xFB

public:

	void tick();

	void connectMemory(Memory* memory) {
		this->memory = memory;
	}

	Registers const* const getRegisters() const {
		return &registers;
	}

	uint8_t getIEFlag() const {
		return this->IE;
	}

	uint8_t getIFFlag() const {
		return this->IF;
	}

	bool getInterruptMasterEnable() const {
		return this->IME;
	}

};