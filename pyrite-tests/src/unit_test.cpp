#include "minunit.h"
#include "z80.h"
#include "memory.h"

static Z80* cpu;
static Memory* memory;

void test_setup() {
	cpu = new Z80();
	memory = new Memory();
}

void test_teardown() {
	delete cpu;
	delete memory;
}

MU_TEST(test_inc_a) {
	/*
    int preA = cpu->registers.a;
    int preCyc = cpu->clock.cycles;
    inc_a(cpu, memory);
    int postA = cpu->registers.a;
    int postCyc = cpu->clock.cycles;
	mu_assert_int_eq(preA + 1, postA);
    mu_assert_int_eq(preCyc + 4, postCyc);
	*/
}

MU_TEST_SUITE(instruction_test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_inc_a);
}

int main()
{
    MU_RUN_SUITE(instruction_test_suite);
	MU_REPORT();

    printf("Press Enter to Continue\n");  
    getchar();

    return 0;
}