#include "branch.h"

int rjmp(int8_t k, struct CPU *cpu) {
    // Relative jump
    // PC <- PC + k + 1
    // 2 cycles
    cpu->PC = cpu->PC + k + 1;
    return 0;
}

int ijmp(struct CPU *cpu) {
    // Indirect jump to address contained in Z
    // PC <- Z
    // 2 cycles
    cpu->PC = cpu->R[30] << 8 | cpu->R[31];
    return 0;
}
