#include "z80.h"
#include <iostream>

void not_yet_implemented(uint8_t instr) {
	std::cerr << "Error: Instruction not yet implemented: 0x" << std::hex << static_cast<int>(instr) << std::endl;
}

void Z80::tick() {

	uint8_t instr = this->memory->readByte(this->registers.pc++);

	switch (instr)
	{
	case 0x00: nop();                      break;
	case 0x01: not_yet_implemented(instr); break;
	case 0x02: not_yet_implemented(instr); break;
	case 0x03: not_yet_implemented(instr); break;
	case 0x04: not_yet_implemented(instr); break;
	case 0x05: not_yet_implemented(instr); break;
	case 0x06: not_yet_implemented(instr); break;
	case 0x07: not_yet_implemented(instr); break;
	case 0x08: not_yet_implemented(instr); break;
	case 0x09: not_yet_implemented(instr); break;
	case 0x0A: not_yet_implemented(instr); break;
	case 0x0B: not_yet_implemented(instr); break;
	case 0x0C: not_yet_implemented(instr); break;
	case 0x0D: dec_c();                    break;
	case 0x0E: not_yet_implemented(instr); break;
	case 0x0F: not_yet_implemented(instr); break;
	case 0x10: not_yet_implemented(instr); break;
	case 0x11: not_yet_implemented(instr); break;
	case 0x12: not_yet_implemented(instr); break;
	case 0x13: not_yet_implemented(instr); break;
	case 0x14: not_yet_implemented(instr); break;
	case 0x15: not_yet_implemented(instr); break;
	case 0x16: not_yet_implemented(instr); break;
	case 0x17: not_yet_implemented(instr); break;
	case 0x18: not_yet_implemented(instr); break;
	case 0x19: not_yet_implemented(instr); break;
	case 0x1A: not_yet_implemented(instr); break;
	case 0x1B: not_yet_implemented(instr); break;
	case 0x1C: not_yet_implemented(instr); break;
	case 0x1D: not_yet_implemented(instr); break;
	case 0x1E: not_yet_implemented(instr); break;
	case 0x1F: not_yet_implemented(instr); break;
	case 0x20: not_yet_implemented(instr); break;
	case 0x21: ld_hl_d16();                break;
	case 0x22: not_yet_implemented(instr); break;
	case 0x23: not_yet_implemented(instr); break;
	case 0x24: not_yet_implemented(instr); break;
	case 0x25: not_yet_implemented(instr); break;
	case 0x26: not_yet_implemented(instr); break;
	case 0x27: not_yet_implemented(instr); break;
	case 0x28: not_yet_implemented(instr); break;
	case 0x29: not_yet_implemented(instr); break;
	case 0x2A: not_yet_implemented(instr); break;
	case 0x2B: not_yet_implemented(instr); break;
	case 0x2C: not_yet_implemented(instr); break;
	case 0x2D: not_yet_implemented(instr); break;
	case 0x2E: not_yet_implemented(instr); break;
	case 0x2F: not_yet_implemented(instr); break;
	case 0x30: not_yet_implemented(instr); break;
	case 0x31: not_yet_implemented(instr); break;
	case 0x32: not_yet_implemented(instr); break;
	case 0x33: not_yet_implemented(instr); break;
	case 0x34: not_yet_implemented(instr); break;
	case 0x35: not_yet_implemented(instr); break;
	case 0x36: not_yet_implemented(instr); break;
	case 0x37: not_yet_implemented(instr); break;
	case 0x38: not_yet_implemented(instr); break;
	case 0x39: not_yet_implemented(instr); break;
	case 0x3A: not_yet_implemented(instr); break;
	case 0x3B: not_yet_implemented(instr); break;
	case 0x3C: inc_a();                    break;
	case 0x3D: not_yet_implemented(instr); break;
	case 0x3E: not_yet_implemented(instr); break;
	case 0x3F: not_yet_implemented(instr); break;
	case 0x40: not_yet_implemented(instr); break;
	case 0x41: not_yet_implemented(instr); break;
	case 0x42: not_yet_implemented(instr); break;
	case 0x43: not_yet_implemented(instr); break;
	case 0x44: not_yet_implemented(instr); break;
	case 0x45: not_yet_implemented(instr); break;
	case 0x46: not_yet_implemented(instr); break;
	case 0x47: not_yet_implemented(instr); break;
	case 0x48: not_yet_implemented(instr); break;
	case 0x49: not_yet_implemented(instr); break;
	case 0x4A: not_yet_implemented(instr); break;
	case 0x4B: not_yet_implemented(instr); break;
	case 0x4C: not_yet_implemented(instr); break;
	case 0x4D: not_yet_implemented(instr); break;
	case 0x4E: not_yet_implemented(instr); break;
	case 0x4F: not_yet_implemented(instr); break;
	case 0x50: not_yet_implemented(instr); break;
	case 0x51: not_yet_implemented(instr); break;
	case 0x52: not_yet_implemented(instr); break;
	case 0x53: not_yet_implemented(instr); break;
	case 0x54: not_yet_implemented(instr); break;
	case 0x55: not_yet_implemented(instr); break;
	case 0x56: not_yet_implemented(instr); break;
	case 0x57: not_yet_implemented(instr); break;
	case 0x58: not_yet_implemented(instr); break;
	case 0x59: not_yet_implemented(instr); break;
	case 0x5A: not_yet_implemented(instr); break;
	case 0x5B: not_yet_implemented(instr); break;
	case 0x5C: not_yet_implemented(instr); break;
	case 0x5D: not_yet_implemented(instr); break;
	case 0x5E: not_yet_implemented(instr); break;
	case 0x5F: not_yet_implemented(instr); break;
	case 0x60: not_yet_implemented(instr); break;
	case 0x61: not_yet_implemented(instr); break;
	case 0x62: not_yet_implemented(instr); break;
	case 0x63: not_yet_implemented(instr); break;
	case 0x64: not_yet_implemented(instr); break;
	case 0x65: not_yet_implemented(instr); break;
	case 0x66: not_yet_implemented(instr); break;
	case 0x67: not_yet_implemented(instr); break;
	case 0x68: not_yet_implemented(instr); break;
	case 0x69: not_yet_implemented(instr); break;
	case 0x6A: not_yet_implemented(instr); break;
	case 0x6B: not_yet_implemented(instr); break;
	case 0x6C: not_yet_implemented(instr); break;
	case 0x6D: not_yet_implemented(instr); break;
	case 0x6E: not_yet_implemented(instr); break;
	case 0x6F: not_yet_implemented(instr); break;
	case 0x70: not_yet_implemented(instr); break;
	case 0x71: not_yet_implemented(instr); break;
	case 0x72: not_yet_implemented(instr); break;
	case 0x73: not_yet_implemented(instr); break;
	case 0x74: not_yet_implemented(instr); break;
	case 0x75: not_yet_implemented(instr); break;
	case 0x76: halt();                     break;
	case 0x77: not_yet_implemented(instr); break;
	case 0x78: not_yet_implemented(instr); break;
	case 0x79: not_yet_implemented(instr); break;
	case 0x7A: not_yet_implemented(instr); break;
	case 0x7B: not_yet_implemented(instr); break;
	case 0x7C: not_yet_implemented(instr); break;
	case 0x7D: not_yet_implemented(instr); break;
	case 0x7E: not_yet_implemented(instr); break;
	case 0x7F: not_yet_implemented(instr); break;
	case 0x80: not_yet_implemented(instr); break;
	case 0x81: not_yet_implemented(instr); break;
	case 0x82: not_yet_implemented(instr); break;
	case 0x83: not_yet_implemented(instr); break;
	case 0x84: not_yet_implemented(instr); break;
	case 0x85: not_yet_implemented(instr); break;
	case 0x86: not_yet_implemented(instr); break;
	case 0x87: not_yet_implemented(instr); break;
	case 0x88: not_yet_implemented(instr); break;
	case 0x89: not_yet_implemented(instr); break;
	case 0x8A: not_yet_implemented(instr); break;
	case 0x8B: not_yet_implemented(instr); break;
	case 0x8C: not_yet_implemented(instr); break;
	case 0x8D: not_yet_implemented(instr); break;
	case 0x8E: not_yet_implemented(instr); break;
	case 0x8F: not_yet_implemented(instr); break;
	case 0x90: not_yet_implemented(instr); break;
	case 0x91: not_yet_implemented(instr); break;
	case 0x92: not_yet_implemented(instr); break;
	case 0x93: not_yet_implemented(instr); break;
	case 0x94: not_yet_implemented(instr); break;
	case 0x95: not_yet_implemented(instr); break;
	case 0x96: not_yet_implemented(instr); break;
	case 0x97: not_yet_implemented(instr); break;
	case 0x98: not_yet_implemented(instr); break;
	case 0x99: not_yet_implemented(instr); break;
	case 0x9A: not_yet_implemented(instr); break;
	case 0x9B: not_yet_implemented(instr); break;
	case 0x9C: not_yet_implemented(instr); break;
	case 0x9D: not_yet_implemented(instr); break;
	case 0x9E: not_yet_implemented(instr); break;
	case 0x9F: not_yet_implemented(instr); break;
	case 0xA0: not_yet_implemented(instr); break;
	case 0xA1: not_yet_implemented(instr); break;
	case 0xA2: not_yet_implemented(instr); break;
	case 0xA3: not_yet_implemented(instr); break;
	case 0xA4: not_yet_implemented(instr); break;
	case 0xA5: not_yet_implemented(instr); break;
	case 0xA6: not_yet_implemented(instr); break;
	case 0xA7: not_yet_implemented(instr); break;
	case 0xA8: xor_b();                    break;
	case 0xA9: xor_c();                    break;
	case 0xAA: xor_d();                    break;
	case 0xAB: xor_e();                    break;
	case 0xAC: xor_h();                    break;
	case 0xAD: xor_l();                    break;
	case 0xAE: xor_hl();                   break;
	case 0xAF: xor_a();                    break;
	case 0xB0: not_yet_implemented(instr); break;
	case 0xB1: not_yet_implemented(instr); break;
	case 0xB2: not_yet_implemented(instr); break;
	case 0xB3: not_yet_implemented(instr); break;
	case 0xB4: not_yet_implemented(instr); break;
	case 0xB5: not_yet_implemented(instr); break;
	case 0xB6: not_yet_implemented(instr); break;
	case 0xB7: not_yet_implemented(instr); break;
	case 0xB8: cp_b();                     break;
	case 0xB9: cp_c();                     break;
	case 0xBA: cp_d();                     break;
	case 0xBB: cp_e();                     break;
	case 0xBC: cp_h();                     break;
	case 0xBD: cp_l();                     break;
	case 0xBE: cp_hl();                    break;
	case 0xBF: cp_a();                     break;
	case 0xC0: not_yet_implemented(instr); break;
	case 0xC1: not_yet_implemented(instr); break;
	case 0xC2: not_yet_implemented(instr); break;
	case 0xC3: jp_a16();                   break;
	case 0xC4: not_yet_implemented(instr); break;
	case 0xC5: not_yet_implemented(instr); break;
	case 0xC6: not_yet_implemented(instr); break;
	case 0xC7: not_yet_implemented(instr); break;
	case 0xC8: not_yet_implemented(instr); break;
	case 0XC9: ret();                      break;
	case 0xCA: not_yet_implemented(instr); break;
	case 0xCB: not_yet_implemented(instr); break;
	case 0xCC: not_yet_implemented(instr); break;
	case 0xCD: not_yet_implemented(instr); break;
	case 0xCE: not_yet_implemented(instr); break;
	case 0xCF: not_yet_implemented(instr); break;
	case 0xD0: not_yet_implemented(instr); break;
	case 0xD1: not_yet_implemented(instr); break;
	case 0xD2: not_yet_implemented(instr); break;
	case 0xD3:                             break;
	case 0xD4: not_yet_implemented(instr); break;
	case 0xD5: not_yet_implemented(instr); break;
	case 0xD6: not_yet_implemented(instr); break;
	case 0xD7: not_yet_implemented(instr); break;
	case 0xD8: not_yet_implemented(instr); break;
	case 0xD9: not_yet_implemented(instr); break;
	case 0xDA: not_yet_implemented(instr); break;
	case 0xDB:                             break;
	case 0xDC: not_yet_implemented(instr); break;
	case 0xDD:                             break;
	case 0xDE: not_yet_implemented(instr); break;
	case 0xDF: not_yet_implemented(instr); break;
	case 0xE0: ldh_a8_A();                 break;
	case 0xE1: not_yet_implemented(instr); break;
	case 0xE2: not_yet_implemented(instr); break;
	case 0xE3:                             break;
	case 0xE4:                             break;
	case 0xE5: not_yet_implemented(instr); break;
	case 0xE6: not_yet_implemented(instr); break;
	case 0xE7: not_yet_implemented(instr); break;
	case 0xE8: not_yet_implemented(instr); break;
	case 0xE9: not_yet_implemented(instr); break;
	case 0xEA: not_yet_implemented(instr); break;
	case 0xEB:                             break;
	case 0xEC:                             break;
	case 0xED:                             break;
	case 0xEE: not_yet_implemented(instr); break;
	case 0xEF: not_yet_implemented(instr); break;
	case 0xF0: ldh_A_a8();                 break;
	case 0xF1: not_yet_implemented(instr); break;
	case 0xF2: not_yet_implemented(instr); break;
	case 0xF3: not_yet_implemented(instr); break;
	case 0xF4:                             break;
	case 0xF5: not_yet_implemented(instr); break;
	case 0xF6: not_yet_implemented(instr); break;
	case 0xF7: not_yet_implemented(instr); break;
	case 0xF8: not_yet_implemented(instr); break;
	case 0xF9: not_yet_implemented(instr); break;
	case 0xFA: not_yet_implemented(instr); break;
	case 0xFB: not_yet_implemented(instr); break;
	case 0xFC:                             break;
	case 0xFD:                             break;
	case 0xFE: not_yet_implemented(instr); break;
	case 0xFF: not_yet_implemented(instr); break;
	default: std::cout << "Error: 0x" << instr << " not found in opcode switch" << std::endl;
	}

	process_interrupts();

}

void Z80::process_interrupts() {

	if (!this->IME) {
		return;
	}

	// Vertical blank
	if (this->IE & INTERRUPT_VERTICAL_BLANKING) {
		this->IF |= INTERRUPT_VERTICAL_BLANKING;
		this->IME = 0;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0040;
		return;
	}

	// LCDC status interrupt
	if (this->IE & INTERRUPT_LCDC) {
		this->IF |= INTERRUPT_LCDC;
		this->IME = 0;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0048;
		return;
	}

	// Timer overflow
	if (this->IE & INTERRUPT_TIMER_OVERFLOW) {
		this->IF |= INTERRUPT_TIMER_OVERFLOW;
		this->IME = 0;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0050;
		return;
	}

	// Serial transfer completion
	if (this->IE & INTERRUPT_SERIAL_TRANSFER_COMPLETE) {
		this->IF |= INTERRUPT_SERIAL_TRANSFER_COMPLETE;
		this->IME = 0;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0058;
		return;
	}

	// P10-P13 input signal goes low
	if (this->IE & INTERRUPT_P10_P13_NEGATIVE_EDGE) {
		this->IF |= INTERRUPT_P10_P13_NEGATIVE_EDGE;
		this->IME = 0;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0060;
		return;
	}
}

//
// Flag operations
//

void Z80::flag_test_zero(Registers* registers, uint8_t val) {
	if (val == 0x00) 
		registers->f |= FLAG_ZERO;
}

void Z80::flag_test_half_carry(Registers* registers, int16_t a, int16_t b) {
	if ((((a & 0xf) + (b & 0xf)) & 0x10) == 0x10) 
		registers->f |= FLAG_HALF_CARRY;
}

void Z80::flag_test_carry(Registers* registers, uint8_t val) {
	if (val < 0) 
		registers->f |= FLAG_CARRY;
}

void Z80::flag_set(Registers* registers, uint8_t flag) {
	registers->f |= flag;
}

void Z80::flag_unset(Registers* registers, uint8_t flag) {
	registers->f &= ~flag;
}

//
// Misc Instructions
//

void Z80::nop() {
	this->clock.cycles += 4;
	return;
}

void Z80::halt() {
	// TODO
	this->clock.cycles += 4;
	return;
}

//
// Jumps & Calls
//

void Z80::ret() {
	memory->readWord(this->registers.sp);
	this->registers.sp += 2;
	this->clock.cycles += 16;
}

void Z80::jp_a16() {
	// Read 2 bytes into 16 bits each to avoid truncation
	uint16_t a = memory->readWord(this->registers.pc++);
	uint16_t b = memory->readWord(this->registers.pc++);
	this->registers.pc = (b << 8) | a;
	this->clock.cycles += 16;
}

//
// Increment Instructions
//

void Z80::inc_a() {
	this->registers.a++;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, this->registers.a, 1);
}

void Z80::dec_c() {
	this->registers.c--;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, this->registers.a, 1);
}

//
// 8bit arithmetic/logical instructions
//

void Z80::cp_a() {
	uint8_t a = this->registers.a;
	uint8_t result = a - a;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, a);
	flag_test_carry(&this->registers, result);
}

void Z80::cp_b() {
	uint8_t a = this->registers.a;
	uint8_t b = this->registers.b;
	char result = a - b;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, b);
	flag_test_carry(&this->registers, result);
}

void Z80::cp_c()
{
	uint8_t a = this->registers.a;
	uint8_t c = this->registers.c;
	char result = a - c;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, c);
	flag_test_carry(&this->registers, result);
}

void Z80::cp_d() {
	uint8_t a = this->registers.a;
	uint8_t d = this->registers.d;
	char result = a - d;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, d);
	flag_test_carry(&this->registers, result);
}

void Z80::cp_e() {
	uint8_t a = this->registers.a;
	uint8_t e = this->registers.e;
	char result = a - e;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, e);
	flag_test_carry(&this->registers, result);
}

void Z80::cp_h() {
	uint8_t a = this->registers.a;
	uint8_t h = this->registers.h;
	char result = a - h;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, h);
	flag_test_carry(&this->registers, result);
}

void Z80::cp_l() {
	uint8_t a = this->registers.a;
	uint8_t l = this->registers.l;
	char result = a - l;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, l);
	flag_test_carry(&this->registers, result);
}

void Z80::cp_hl() {
	uint8_t a = this->registers.a;
	uint16_t hl = this->registers.hl;
	char result = a - hl;
	this->clock.cycles += 8;
	flag_test_zero(&this->registers, result);
	flag_set(&this->registers, FLAG_SUBTRACT);
	flag_test_half_carry(&this->registers, a, hl);
	flag_test_carry(&this->registers, result);
}

void Z80::xor_a() {
	this->registers.a ^= this->registers.a;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::xor_b() {
	this->registers.a ^= this->registers.b;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::xor_c() {
	this->registers.a ^= this->registers.c;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::xor_d() {
	this->registers.a ^= this->registers.d;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::xor_e() {
	this->registers.a ^= this->registers.e;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::xor_h() {
	this->registers.a ^= this->registers.h;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::xor_l() {
	this->registers.a ^= this->registers.l;
	this->clock.cycles += 4;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::xor_hl() {
	this->registers.a ^= this->registers.hl;
	this->clock.cycles += 8;
	flag_test_zero(&this->registers, this->registers.a);
	flag_unset(&this->registers, FLAG_SUBTRACT);
	flag_unset(&this->registers, FLAG_HALF_CARRY);
	flag_unset(&this->registers, FLAG_CARRY);
}

void Z80::ldh_A_a8() {
	uint8_t n = memory->readByte(this->registers.pc++);
	this->registers.a = memory->readByte(0xFF00 + n);
	this->clock.cycles += 12;
}

void Z80::ldh_a8_A() {
	uint8_t n = memory->readByte(this->registers.pc++);
	memory->writeByte(0xFF00 + n, this->registers.a);
	this->clock.cycles += 12;
}

//
// 16bit load/store/move instructions
//

void Z80::ld_hl_d16() {
	// TODO
	uint8_t n = memory->readByte(this->registers.pc++);
}