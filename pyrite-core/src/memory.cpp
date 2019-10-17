#include "memory.h"

unsigned char Memory::readByte(unsigned short addr) {
  return this->data[addr];
}

unsigned short Memory::readWord(unsigned short addr) {
  unsigned short a = this->data[addr];
  unsigned short b = this->data[addr+1];
  return a | (b << 8);
}

void Memory::writeByte(unsigned short addr, unsigned char byte) {
  this->data[addr] = byte;
}

void Memory::writeWord(unsigned short addr, unsigned short byte) {
	this->data[addr] = byte;
}
