#include "z80.h"
#include <stdio.h>
#include <stdlib.h>

void not_yet_implemented(unsigned char instr) {
  printf("Error: 0x%X not found in opcode switch \n", instr & 0xff);
}

Z80* createCPU() {
  Z80* cpu = malloc(sizeof(Z80));

  if(!cpu)
    fprintf(stderr, "ERROR: Failed to allocate memory for CPU\n");

  cpu->registers.af = 0;
  cpu->registers.bc = 0;
  cpu->registers.de = 0;
  cpu->registers.hl = 0;
  cpu->registers.bc = 0;
  cpu->registers.sp = 0;
  cpu->registers.pc = 0;

  return cpu;
}

void unloadCPU(Z80** cpu) {
  if(*cpu)
    free(*cpu);

  *cpu = NULL;
}

void run(Z80* cpu, Memory* memory, const char* file) 
{
  // Load a rom
  char* romPtr = loadROM(file);

  // Copy the first 0x3FFF data from the cartridge
  // and load it into our memory for execution.
  memcpy(memory->data, romPtr, ROM_BANK_0+1);

  while(cpu->registers.pc < ROM_BANK_0) // Short term, avoid overflow by only executing loaded data
  {
    unsigned char instr = memory->data[cpu->registers.pc++];

    printf("Instruction value = 0x%X, Program Counter = %d\n", instr & 0xff , cpu->registers.pc - 1 );

    // To better understand which instructions I'm yet to implement. I've
    // coded the entire instruction set into the switch with a not yet implemented
    // error func as opposed to using default.
    switch(instr) 
    {
      case 0x00: nop(cpu, memory);           break;
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
      case 0x0D: not_yet_implemented(instr); break;
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
      case 0x21: not_yet_implemented(instr); break;
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
      case 0x3C: inc_a(cpu, memory);         break;
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
      case 0x76: not_yet_implemented(instr); break;
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
      case 0xA8: not_yet_implemented(instr); break;
      case 0xA9: not_yet_implemented(instr); break;
      case 0xAA: not_yet_implemented(instr); break;
      case 0xAB: not_yet_implemented(instr); break;
      case 0xAC: not_yet_implemented(instr); break;
      case 0xAD: not_yet_implemented(instr); break;
      case 0xAE: not_yet_implemented(instr); break;
      case 0xAF: not_yet_implemented(instr); break;
      case 0xB0: not_yet_implemented(instr); break;
      case 0xB1: not_yet_implemented(instr); break;
      case 0xB2: not_yet_implemented(instr); break;
      case 0xB3: not_yet_implemented(instr); break;
      case 0xB4: not_yet_implemented(instr); break;
      case 0xB5: not_yet_implemented(instr); break;
      case 0xB6: not_yet_implemented(instr); break;
      case 0xB7: not_yet_implemented(instr); break;
      case 0xB8: not_yet_implemented(instr); break;
      case 0xB9: not_yet_implemented(instr); break;
      case 0xBA: not_yet_implemented(instr); break;
      case 0xBB: not_yet_implemented(instr); break;
      case 0xBC: not_yet_implemented(instr); break;
      case 0xBD: not_yet_implemented(instr); break;
      case 0xBE: not_yet_implemented(instr); break;
      case 0xBF: not_yet_implemented(instr); break;
      case 0xC0: not_yet_implemented(instr); break;
      case 0xC1: not_yet_implemented(instr); break;
      case 0xC2: not_yet_implemented(instr); break;
      case 0xC3: not_yet_implemented(instr); break;
      case 0xC4: not_yet_implemented(instr); break;
      case 0xC5: not_yet_implemented(instr); break;
      case 0xC6: not_yet_implemented(instr); break;
      case 0xC7: not_yet_implemented(instr); break;
      case 0xC8: not_yet_implemented(instr); break;
      case 0XC9: ret(cpu, memory);           break;
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
      case 0xE0: not_yet_implemented(instr); break;
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
      case 0xF0: not_yet_implemented(instr); break;
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
      default: printf("Error: Unexpected instruction 0x%X \n", instr & 0xff);
    }
  }
  return;
}

void inline flag_test_zero(Registers* registers, unsigned char val) {
  if(val == 0x00) registers->f |= FLAG_ZERO;
}

void inline flag_test_half_carry(Registers* registers, char a, char b) {
  if((((a & 0xf) + (b & 0xf)) & 0x10) == 0x10) registers->f |= FLAG_HALF_CARRY;
}

void inline flag_test_carry(Registers* registers, unsigned char val) {
  if(val < 0) registers->f |= FLAG_CARRY;
}

void inline flag_set(Registers* registers, unsigned char flag) {
  registers->f |= flag;
}

void inline flag_unset(Registers* registers, unsigned char flag) {
  registers->f &= ~flag;
}

//
// Misc Instructions
//

void nop(Z80* cpu, Memory* memory) {
  return;
}

//
// Jumps & Calls
//

void ret(Z80* cpu, Memory* memory) {
  // TODO
}

//
// Increment Instructions
//

// Increment the value of register A
void inc_a(Z80* cpu, Memory* memory) {
  cpu->registers.a += 1;
  flag_test_zero(&cpu->registers, cpu->registers.a);
  flag_unset(&cpu->registers, FLAG_SUBTRACT);
  flag_test_half_carry(&cpu->registers, cpu->registers.a, 1);
}