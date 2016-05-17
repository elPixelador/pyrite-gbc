
#define MEMORY_SIZE 0xFFFF

/* Starting Addresses for key locations in memory. */
#define INTERRUPT_RST       0x000
#define ROM_DATA            0x100
#define USER_PROG_AREA      0x150
#define BANK_CHAR_DATA      0x8000
#define BG_DISPLAY_DATA_1   0x9800
#define BG_DISPLAY_DATA_2   0x9C00
#define EXTERN_EXPAC_RAM    0xA000
#define BANK_0              0xC000
#define BANK_1_7            0xD000
#define PROHIBITED          0xE000
#define OAM                 0xFE00
#define WTF_IS_THIS         0xFEA0 /*TODO: Figure out wtf this address space is used for. */
#define OTHER_REGISTERS     0xFF00
#define WORK_STACK_RAM      0xFF80
#define UNUSED              0xFFFE


typedef struct Memory
{
  char memory[MEMORY_SIZE];

} Memory;

Memory* createMemory();
void unloadMemory(Memory* mem);

void loadROM(Memory* mem, const char* fileName);
void unloadROM(Memory* mem);
