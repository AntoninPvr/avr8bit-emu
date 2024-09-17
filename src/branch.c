#include "branch.h"

void rjmp(uint8_t k, struct CORE *core) {
    // Relative jump
    // PC <- PC + k + 1
    // 2 cycles
    core->PC = core->PC + k + 1;
}

void ijmp(struct CORE *core) {
    // Indirect jump to address contained in Z
    // PC <- Z
    // 2 cycles
    core->PC = core->gp.R[30] << 8 | core->gp.R[31];
}

void jmp(uint32_t k, struct CORE *core) {
    // Absolute jump
    // PC <- k
    // 3 cycles
    core->PC = k;
}

void rcall(uint8_t k, struct CORE *core, struct SRAM *sram) {
    // Relative call
    // PC <- PC + k + 1
    // Push return address to stack
    // 3 cycles
    sram->mem[core->SP] = core->PC + 1;
    core->SP = core->SP - 2;
    core->PC = core->PC + k + 1;
}

void icall(struct CORE *core, struct SRAM *sram) {
    // Indirect call to address contained in Z
    // PC <- Z
    // Push return address to stack
    // 3 cycles
    sram->mem[core->SP] = core->PC + 1;
    core->SP = core->SP - 2;
    core->PC = core->gp.Z;
}

// void eicall(struct CORE *core, struct SRAM *sram) {

// }

void ret(struct CORE *core, struct SRAM *sram) {
    // Return from subroutine
    // Pop return address from stack
    // PC <- (SP + 1)
    // 4 cycles

    // Execute instruction
    core->SP = core->SP + 1;
    core->PC = sram->mem[core->SP] << 8 | sram->mem[core->SP + 1];

    // Update SREG
    // NONE
}

void reti(struct CORE *core, struct SRAM *sram) {
    // Return from interrupt
    // Pop return address from stack
    // PC <- (SP + 1)
    // Enable global interrupts
    // 4 cycles

    // Execute instruction
    core->SP = core->SP + 1;
    core->PC = sram->mem[core->SP] << 8 | sram->mem[core->SP + 1];

    // Update SREG
    update_sreg_I(&core->sreg, true);
}

void cpse(uint8_t d, uint8_t r, struct CORE *core) {
    // Compare, skip if equal
    // If Rd = Rr, PC <- PC + 2
    // 1 cycle

    // Execute instruction
    if (core->gp.R[d] == core->gp.R[r]) {
        core->PC = core->PC + 2;
        // LACKS IMPLEMENTATION + 3 if instruction skipped is 2word long
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void cp(uint8_t d, uint8_t r, struct CORE *core) {
    // Compare
    // Rd - Rr
    // 1 cycle

    // Execute instruction
    uint8_t result = core->gp.R[d] - core->gp.R[r];

    // Update SREG
    update_sreg_arithm(core, core->gp.R[d], core->gp.R[r], result);
}

void cpc(uint8_t d, uint8_t r, struct CORE *core) {
    // Compare with carry
    // Rd - Rr - C
    // 1 cycle

    // Execute instruction
    uint8_t result = core->gp.R[d] - core->gp.R[r] - core->sreg.C;

    // Update SREG
    update_sreg_arithm(core, core->gp.R[d], core->gp.R[r], result);
}

void cpi(uint8_t d, uint8_t K, struct CORE *core) {
    // Compare with immediate
    // Rd - K
    // 1 cycle

    // Execute instruction
    uint8_t result = core->gp.R[d] - K;

    // Update SREG
    update_sreg_arithm(core, core->gp.R[d], K, result);
}

void sbrc(uint8_t r, uint8_t b, struct CORE *core) {
    // Skip if bit in register cleared
    // If Rr(b) = 0, PC <- PC + 2
    // 1 cycle

    // Execute instruction
    if ((core->gp.R[r] & (1 << b)) == 0) {
        core->PC = core->PC + 2;
        // LACKS IMPLEMENTATION + 3 if instruction skipped is 2word long
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void sbrs(uint8_t r, uint8_t b, struct CORE *core) {
    // Skip if bit in register set
    // If Rr(b) = 1, PC <- PC + 2
    // 1 cycle

    // Execute instruction
    if ((core->gp.R[r] & (1 << b)) == 1) {
        core->PC = core->PC + 2;
        // LACKS IMPLEMENTATION + 3 if instruction skipped is 2word long
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void sbic(uint8_t A, uint8_t b, struct CORE *core, union DATA_SPACE *data_space) {
    // Skip if bit in I/O register cleared
    // Only for 0 <= A <= 31
    // If I/O(A)(b) = 0, PC <- PC + 2
    // 1 cycle

    // Execute instruction
    if ((data_space->io_reg[A] & (1 << b)) == 0) {
        core->PC = core->PC + 2;
        // LACKS IMPLEMENTATION + 3 if instruction skipped is 2word long
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void sbis(uint8_t A, uint8_t b, struct CORE *core, union DATA_SPACE *data_space) {
    // Skip if bit in I/O register set
    // Only for 0 <= A <= 31
    // If I/O(A)(b) = 1, PC <- PC + 2
    // 1 cycle

    // Execute instruction
    if ((data_space->io_reg[A] & (1 << b)) == 1) {
        core->PC = core->PC + 2;
        // LACKS IMPLEMENTATION + 3 if instruction skipped is 2word long
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brbs(uint8_t s, uint8_t k, struct CORE *core) {
    // Branch if bit in SREG set
    // If S(s) = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if ((core->sreg.sreg & (1 << s)) == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brbc(uint8_t s, uint8_t k, struct CORE *core) {
    // Branch if bit in SREG cleared
    // If S(s) = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if ((core->sreg.sreg & (1 << s)) == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void breq(uint8_t k, struct CORE *core) {
    // Branch if equal
    // If Z = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.Z == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brne(uint8_t k, struct CORE *core) {
    // Branch if not equal
    // If Z = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.Z == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brcs(uint8_t k, struct CORE *core) {
    // Branch if carry set
    // If C = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.C == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brcc(uint8_t k, struct CORE *core) {
    // Branch if carry cleared
    // If C = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.C == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brsh(uint8_t k, struct CORE *core) {
    // Branch if same or higher
    // If C = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.C == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brlo(uint8_t k, struct CORE *core) {
    // Branch if lower
    // If C = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.C == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brmi(uint8_t k, struct CORE *core) {
    // Branch if minus
    // If N = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.N == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brpl(uint8_t k, struct CORE *core) {
    // Branch if plus
    // If N = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.N == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brge(uint8_t k, struct CORE *core) {
    // Branch if greater or equal
    // If N = V, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.N == core->sreg.V) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brlt(uint8_t k, struct CORE *core) {
    // Branch if less than
    // If N != V, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.N != core->sreg.V) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brhs(uint8_t k, struct CORE *core) {
    // Branch if half carry set
    // If H = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.H == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brhc(uint8_t k, struct CORE *core) {
    // Branch if half carry cleared
    // If H = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.H == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brts(uint8_t k, struct CORE *core) {
    // Branch if T flag set
    // If T = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.T == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brtc(uint8_t k, struct CORE *core) {
    // Branch if T flag cleared
    // If T = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.T == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brvs(uint8_t k, struct CORE *core) {
    // Branch if overflow set
    // If V = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.V == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brvc(uint8_t k, struct CORE *core) {
    // Branch if overflow cleared
    // If V = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.V == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brie(uint8_t k, struct CORE *core) {
    // Branch if global interrupt enabled
    // If I = 1, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.I == 1) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}

void brid(uint8_t k, struct CORE *core) {
    // Branch if global interrupt disabled
    // If I = 0, PC <- PC + k + 1
    // 1 cycle

    // Execute instruction
    if (core->sreg.I == 0) {
        core->PC = core->PC + k + 1;
    }
    else {
        core->PC = core->PC + 1;
    }

    // Update SREG
    // NONE
}