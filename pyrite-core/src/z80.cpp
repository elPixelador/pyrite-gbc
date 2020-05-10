#include "z80.h"
#include <iostream>

void CPU::not_yet_implemented(uint8_t instr) {
	std::cerr << "Error: Instruction not yet implemented: 0x" << std::hex << static_cast<int>(instr) << std::endl;
	this->registers.pc--;
}

void CPU::tick() {

	if (this->registers.pc == 0x2817) {
		std::cout << "Loading gpu data" << std::endl;
	}

	uint8_t instr = this->memory->readByte(this->registers.pc++);

	switch (instr)
	{
	case 0x00: nop();                      break;
	case 0x01: ld_bc_d16();                break;
	case 0x02: ld_mbc_a();                 break;
	case 0x03: inc_bc();                   break;
	case 0x04: inc_b();                    break;
	case 0x05: dec_b();                    break;
	case 0x06: ld_b_d8();                  break;
	case 0x07: rlca();                     break;
	case 0x08: ld_a16_sp();                break;
	case 0x09: add_hl_bc();                break;
	case 0x0A: ld_a_bc();                  break;
	case 0x0B: dec_bc();                   break;
	case 0x0C: inc_c();                    break;
	case 0x0D: dec_c();                    break;
	case 0x0E: ld_c_d8();                  break;
	case 0x0F: rrca();                     break;
	case 0x10: stop_0();                   break;
	case 0x11: ld_de_d16();                break;
	case 0x12: ld_de_a();                  break;
	case 0x13: inc_de();                   break;
	case 0x14: inc_d();                    break;
	case 0x15: dec_d();                    break;
	case 0x16: ld_d_d8();                  break;
	case 0x17: rla();                      break;
	case 0x18: jr_r8();                    break;
	case 0x19: add_hl_de();                break;
	case 0x1A: ld_a_de();                  break;
	case 0x1B: dec_de();                   break;
	case 0x1C: inc_e();                    break;
	case 0x1D: dec_e();                    break;
	case 0x1E: ld_e_d8();                  break;
	case 0x1F: rra();                      break;
	case 0x20: jr_nz_r8();                 break;
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
	case 0x32: ld_hld_a();                 break;
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
	case 0xF3: di();                       break;
	case 0xF4:                             break;
	case 0xF5: not_yet_implemented(instr); break;
	case 0xF6: not_yet_implemented(instr); break;
	case 0xF7: not_yet_implemented(instr); break;
	case 0xF8: not_yet_implemented(instr); break;
	case 0xF9: not_yet_implemented(instr); break;
	case 0xFA: not_yet_implemented(instr); break;
	case 0xFB: ei();                       break;
	case 0xFC:                             break;
	case 0xFD:                             break;
	case 0xFE: not_yet_implemented(instr); break;
	case 0xFF: not_yet_implemented(instr); break;
	default: std::cout << "Error: 0x" << instr << " not found in opcode switch" << std::endl;
	}

	process_interrupts();

}

void CPU::nop() {
	this->clock.ticks += 4;
	return;
}

void CPU::ld_bc_d16() {
	this->registers.bc = this->memory->readWord(this->registers.pc);
	this->registers.pc += 2;
	this->clock.ticks += 12;
}

void CPU::ld_mbc_a() {
	this->memory->writeByte(this->registers.bc, this->registers.a);
	this->clock.ticks += 8;
}

void CPU::inc_bc() {
	this->registers.bc++;
	this->clock.ticks += 8;
}

void CPU::inc_b() {
	this->registers.b++;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.b);
	flag_reset(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.b, 1);
}

void CPU::dec_b() {
	this->registers.b--;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.b);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.b, 1);
}

void CPU::ld_b_d8() {
	this->registers.b = this->memory->readByte(this->registers.pc++);
	this->clock.ticks += 8;
}

void CPU::rlca() {
	uint8_t tmpA = this->registers.a;
	this->registers.a <<= 1;
	this->registers.f = 0;
	if (tmpA & 0x80) {
		this->registers.a |= 0x01;
		flag_set(FLAG_CARRY);
	}
	this->clock.ticks += 4;
}

void CPU::ld_a16_sp() {
	uint16_t addr = this->memory->readWord(this->registers.pc);
	this->registers.pc += 2;
	this->memory->writeWord(addr, this->registers.pc);
	this->clock.ticks += 20;
}

void CPU::add_hl_bc() {
	this->registers.hl += this->registers.bc;
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.hl, 1);
	flag_test_carry(this->registers.hl);
	this->clock.ticks += 8;
}

void CPU::ld_a_bc() {
	this->registers.a = this->memory->readByte(this->registers.bc);
	this->clock.ticks += 8;
}

void CPU::dec_bc() {
	this->registers.bc--;
	this->clock.ticks += 8;
}

void CPU::inc_c() {
	this->registers.c++;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.c);
	flag_reset(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.c, 1);
}

void CPU::dec_c() {
	this->registers.c--;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.c);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.c, 1);
}

void CPU::ld_c_d8() {
	uint8_t data = this->memory->readByte(this->registers.pc++);
	this->registers.c = data;
	this->clock.ticks += 8;
}

void CPU::rrca() {
	this->registers.a >>= 1;
	flag_reset(FLAG_ZERO);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_test_carry(this->registers.a);
	this->clock.ticks += 4;
}

void CPU::stop_0() {
	// TODO
	this->clock.ticks += 4;
}

void CPU::ld_de_d16() {
	this->registers.de = this->memory->readWord(this->registers.pc);
	this->registers.pc += 2;
	this->clock.ticks += 12;
}

void CPU::ld_de_a() {
	this->memory->writeByte(this->registers.de, this->registers.a);
	this->clock.ticks += 8;
}

void CPU::inc_de() {
	this->registers.de++;
	this->clock.ticks += 8;
}

void CPU::inc_d() {
	this->registers.d++;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.d);
	flag_reset(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.d, 1);
}

void CPU::dec_d() {
	this->registers.d--;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.d);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.d, 1);
}

void CPU::ld_d_d8() {
	this->registers.d = this->memory->readByte(this->registers.pc++);
	this->clock.ticks += 8;
}

void CPU::rla() {
	this->registers.a <<= 1;
	flag_reset(FLAG_ZERO);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_test_carry(this->registers.a);
	this->clock.ticks += 4;
}

void CPU::jr_r8() {
	this->registers.pc += (int8_t)this->memory->readByte(this->registers.pc);
	this->clock.ticks += 12;
}

void CPU::add_hl_de() {
	this->registers.hl += this->registers.de;
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.hl, 1);
	flag_test_carry(this->registers.hl);
	this->clock.ticks += 8;
}

void CPU::ld_a_de() {
	this->registers.a = this->memory->readByte(this->registers.de);
	this->clock.ticks += 8;
}

void CPU::dec_de() {
	this->registers.de--;
	this->clock.ticks += 8;
}

void CPU::inc_e() {
	this->registers.e++;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.e);
	flag_reset(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.e, 1);
}

void CPU::dec_e() {
	this->registers.e--;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.e);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.e, 1);
}

void CPU::ld_e_d8() {
	uint8_t data = this->memory->readByte(this->registers.pc++);
	this->registers.e = data;
	this->clock.ticks += 8;
}

void CPU::rra() {
	this->registers.a >>= 1;
	flag_reset(FLAG_ZERO);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_test_carry(this->registers.a);
	this->clock.ticks += 4;
}

void CPU::jr_nz_r8() {
	if (this->flag_check(OperationFlag::FLAG_ZERO)) {
		int8_t data = (int8_t)memory->readByte(this->registers.pc);
		this->registers.pc += data;
		this->clock.ticks += 12;
	} else {
		this->clock.ticks += 8;
	}
}

void CPU::ld_hl_d16() {
	uint16_t data = memory->readWord(this->registers.pc);
	this->registers.pc += 2;
	this->registers.hl = data;
	this->clock.ticks += 12;
}

void CPU::ld_hld_a() {
	this->memory->writeByte(this->registers.hl, this->registers.a);
	this->registers.hl--;
	this->clock.ticks += 8;
}

void CPU::inc_a() {
	this->registers.a++;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_test_half_carry(this->registers.a, 1);
}











// Mess of unordered opcode funcs

void CPU::halt() {
	// TODO
	this->clock.ticks += 4;
}

void CPU::ret() {
	memory->readWord(this->registers.sp);
	this->registers.sp += 2;
	this->clock.ticks += 16;
}

void CPU::jp_a16() {
	// Read 2 bytes into 16 bits each to avoid truncation
	uint16_t data = memory->readWord(this->registers.pc);
	this->registers.pc = data;
	this->clock.ticks += 16;
}

void CPU::cp_a() {
	uint8_t a = this->registers.a;
	uint8_t result = a - a;
	this->clock.ticks += 4;
	flag_test_zero(result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, a);
	flag_test_carry(result);
}

void CPU::cp_b() {
	uint8_t a = this->registers.a;
	uint8_t b = this->registers.b;
	char result = a - b;
	this->clock.ticks += 4;
	flag_test_zero( result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, b);
	flag_test_carry(result);
}

void CPU::cp_c()
{
	uint8_t a = this->registers.a;
	uint8_t c = this->registers.c;
	char result = a - c;
	this->clock.ticks += 4;
	flag_test_zero(result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, c);
	flag_test_carry(result);
}

void CPU::cp_d() {
	uint8_t a = this->registers.a;
	uint8_t d = this->registers.d;
	char result = a - d;
	this->clock.ticks += 4;
	flag_test_zero(result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, d);
	flag_test_carry(result);
}

void CPU::cp_e() {
	uint8_t a = this->registers.a;
	uint8_t e = this->registers.e;
	char result = a - e;
	this->clock.ticks += 4;
	flag_test_zero(result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, e);
	flag_test_carry(result);
}

void CPU::cp_h() {
	uint8_t a = this->registers.a;
	uint8_t h = this->registers.h;
	char result = a - h;
	this->clock.ticks += 4;
	flag_test_zero(result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, h);
	flag_test_carry(result);
}

void CPU::cp_l() {
	uint8_t a = this->registers.a;
	uint8_t l = this->registers.l;
	char result = a - l;
	this->clock.ticks += 4;
	flag_test_zero(result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, l);
	flag_test_carry(result);
}

void CPU::cp_hl() {
	uint8_t a = this->registers.a;
	uint16_t hl = this->registers.hl;
	char result = a - hl;
	this->clock.ticks += 8;
	flag_test_zero(result);
	flag_set(FLAG_SUBTRACT);
	flag_test_half_carry(a, hl);
	flag_test_carry(result);
}

void CPU::xor_a() {
	this->registers.a ^= this->registers.a;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::xor_b() {
	this->registers.a ^= this->registers.b;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::xor_c() {
	this->registers.a ^= this->registers.c;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::xor_d() {
	this->registers.a ^= this->registers.d;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::xor_e() {
	this->registers.a ^= this->registers.e;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::xor_h() {
	this->registers.a ^= this->registers.h;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::xor_l() {
	this->registers.a ^= this->registers.l;
	this->clock.ticks += 4;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::xor_hl() {
	this->registers.a ^= this->registers.hl;
	this->clock.ticks += 8;
	flag_test_zero(this->registers.a);
	flag_reset(FLAG_SUBTRACT);
	flag_reset(FLAG_HALF_CARRY);
	flag_reset(FLAG_CARRY);
}

void CPU::ldh_a8_A() {
	uint8_t n = memory->readByte(this->registers.pc++);
	memory->writeByte(0xFF00 + n, this->registers.a);
	this->clock.ticks += 12;
}

void CPU::ldh_A_a8() {
	uint8_t n = memory->readByte(this->registers.pc++);
	this->registers.a = memory->readByte(0xFF00 + n);
	this->clock.ticks += 12;
}

void CPU::di() {
	this->IME = false;
	this->clock.ticks += 4;
}

void CPU::ei() {
	this->IME = true;
	this->clock.ticks += 4;
}

void CPU::process_interrupts() {

	if (!this->IME) {
		return;
	}

	// Vertical blank (Priority 1)
	if (this->IE & INTERRUPT_VERTICAL_BLANKING) {
		this->IF |= INTERRUPT_VERTICAL_BLANKING;
		this->IME = false;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0040;
		return;
	}

	// LCDC status interrupt (Priority 2)
	if (this->IE & INTERRUPT_LCDC) {
		this->IF |= INTERRUPT_LCDC;
		this->IME = false;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0048;
		return;
	}

	// Timer overflow (Priority 3)
	if (this->IE & INTERRUPT_TIMER_OVERFLOW) {
		this->IF |= INTERRUPT_TIMER_OVERFLOW;
		this->IME = false;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0050;
		return;
	}

	// Serial transfer completion (Priority 4)
	if (this->IE & INTERRUPT_SERIAL_TRANSFER_COMPLETE) {
		this->IF |= INTERRUPT_SERIAL_TRANSFER_COMPLETE;
		this->IME = false;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0058;
		return;
	}

	// P10-P13 input signal goes low (Priority 5)
	if (this->IE & INTERRUPT_P10_P13_NEGATIVE_EDGE) {
		this->IF |= INTERRUPT_P10_P13_NEGATIVE_EDGE;
		this->IME = false;
		memory->writeWord(this->registers.sp, memory->readWord(this->registers.pc));
		this->registers.sp += 2;
		this->registers.pc = 0x0060;
		return;
	}
}

//
// Flag operations
//

void CPU::flag_test_zero(uint16_t val) {
	if (val == 0x00)
		this->registers.f |= FLAG_ZERO;
}

void CPU::flag_test_half_carry(int16_t a, int16_t b) {
	if ((((a & 0xf) + (b & 0xf)) & 0x10) == 0x10)
		this->registers.f |= FLAG_HALF_CARRY;
}

void CPU::flag_test_carry(uint16_t val) {
	if (val < 0)
		this->registers.f |= FLAG_CARRY;
}

void CPU::flag_set(CPU::OperationFlag flag) {
	this->registers.f |= flag;
}

void CPU::flag_reset(CPU::OperationFlag flag) {
	this->registers.f &= ~flag;
}

bool CPU::flag_check(CPU::OperationFlag flag) {
	return (this->registers.f & flag) != 0x0;
}