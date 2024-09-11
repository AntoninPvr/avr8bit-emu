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
    core->PC = core->gp.R[30] << 8 | core->gp.R[31];
    return 0;
}

void jmp(uint32_t k, struct CORE *core) {
    // Absolute jump
    // PC <- k
    // 3 cycles
    core->PC = k;
    return 0;
}

void rcall(uint8_t k, struct CORE *core, struct SRAM *sram) {
    // Relative call
    // PC <- PC + k + 1
    // Push return address to stack
    // 3 cycles
    sram->mem[core->SP] = core->PC + 1;
    core->SP - 2;
    core->PC = core->PC + k + 1;
    return 0;
}