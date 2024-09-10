#include "branch.h"

void rjmp(uint8_t k, struct CORE *core) {
    // Relative jump
    // PC <- PC + k + 1
    // 2 cycles
    core->PC = core->PC + k + 1;
    return 0;
}

void ijmp(struct CORE *core) {
    // Indirect jump to address contained in Z
    // PC <- Z
    // 2 cycles
    core->PC = core->R[30] << 8 | core->R[31];
    return 0;
}

void jmp(uint32_t k, struct CORE *core) {
    // Absolute jump
    // PC <- k
    // 3 cycles
    core->PC = k;
    return 0;
}

