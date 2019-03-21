#include "minunit.h"
#include "cpu.h"
#include "memory.h"

static CPU* cpu;
static Memory* memory;

void test_setup(void) {
	cpu = createCPU();
	memory = createMemory();
}

void test_teardown(void) {
	unloadCPU(&cpu);
	unloadMemory(&memory);
}

MU_TEST(test_check) {
	mu_check(5 == 7);
}

MU_TEST_SUITE(instruction_test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_check);
}

int main()
{ 
    MU_RUN_SUITE(test_suite);
	MU_REPORT();
    return 0;
} 