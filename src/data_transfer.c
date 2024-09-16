#include "data_transfer.h"

void mov(uint8_t d, uint8_t r, struct CORE *core) {
    // Copy register r to register d
    // Rd <- Rr
    // 1 cycle

    // Execute instruction
    core->gp.R[d] = core->gp.R[r];

    // Update SREG
    // NONE

    inc_pc(core);
}

void movw(uint8_t d, uint8_t r, struct CORE *core) {
    // Copy register pair r to register pair d
    // Rd <- Rr
    // Rd+1 <- Rr+1
    // 1 cycle

    // Execute instruction
    core->gp.R[d] = core->gp.R[r];
    core->gp.R[d + 1] = core->gp.R[r + 1];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ldi(uint8_t d, uint8_t K, struct CORE *core) {
    // Load immediate 16 <= d <= 31
    // Rd <- K
    // 1 cycle

    // Execute instruction
    core->gp.R[d] = K;

    // Update SREG
    // NONE

    inc_pc(core);
}

void lds(uint8_t d, int16_t k, struct CORE *core, union DATA_SPACE *data_space) {
    // Load direct from data space
    // Rd <- k
    // 2 cycles

    // Execute instruction
    core->gp.R[d] = data_space->data[k];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_x(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using X as address
    // Rd <- (X)
    // 1 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.X];

    // Update SREG
    // NONE

    inc_pc(core);
}