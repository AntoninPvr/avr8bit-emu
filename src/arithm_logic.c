#include "arithm_logic.h"

void add(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Add without carry
    // Rd <- Rd + Rr
    // 1 cycle
    core->R[Rd] = core->R[Rd] + core->R[Rr];
    return 0;
    inc_pc(core);
}

void adc(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Add with carry
    // Rd <- Rd + Rr + C
    // 1 cycle
    core->R[Rd] = core->R[Rd] + core->R[Rr] + core->sreg.C;
    return 0;
    inc_pc(core);
}

void sub(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Subtract without carry
    // Rd <- Rd - Rr
    // 1 cycle
    core->R[Rd] = core->R[Rd] - core->R[Rr];
    return 0;
    inc_pc(core);
} 

void subi(int8_t Rd, int8_t K, struct CORE *core) {
    // Subtract immediate
    // Rd <- Rd - K
    // 1 cycle
    core->R[Rd] = core->R[Rd] - K;
    return 0;
    inc_pc(core);
}

void sbc(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Subtract with carry
    // Rd <- Rd - Rr - C
    // 1 cycle
    core->R[Rd] = core->R[Rd] - core->R[Rr] - core->sreg.C;
    return 0;
    inc_pc(core);
}

void sbci(int8_t Rd, int8_t K, struct CORE *core) {
    // Subtract immediate with carry
    // Rd <- Rd - K - C
    // 1 cycle
    core->R[Rd] = core->R[Rd] - K - core->sreg.C;
    return 0;
    inc_pc(core);
}

void and(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Logical AND
    // Rd <- Rd & Rr
    // 1 cycle
    core->R[Rd] = core->R[Rd] & core->R[Rr];
    return 0;
    inc_pc(core);
}

void andi(int8_t Rd, int8_t K, struct CORE *core) {
    // Logical AND with immediate
    // Rd <- Rd & K
    // 1 cycle
    core->R[Rd] = core->R[Rd] & K;
    return 0;
    inc_pc(core);
}

void or(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Logical OR
    // Rd <- Rd | Rr
    // 1 cycle
    core->R[Rd] = core->R[Rd] | core->R[Rr];
    return 0;
    inc_pc(core);
}

void ori(int8_t Rd, int8_t K, struct CORE *core) {
    // Logical OR with immediate
    // Rd <- Rd | K
    // 1 cycle
    core->R[Rd] = core->R[Rd] | K;
    return 0;
    inc_pc(core);
}

void eor(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Logical Exclusive OR
    // Rd <- Rd ^ Rr
    // 1 cycle
    core->R[Rd] = core->R[Rd] ^ core->R[Rr];
    return 0;
    inc_pc(core);
}

void com(int8_t Rd, struct CORE *core) {
    // Logical Complement
    // Rd <- $FF - Rd
    // 1 cycle
    core->R[Rd] = ~core->R[Rd];
    return 0;
    inc_pc(core);
}

void neg(int8_t Rd, struct CORE *core) {
    // Two's Complement
    // Rd <- $00 - Rd
    // 1 cycle
    core->R[Rd] = -core->R[Rd];
    return 0;
    inc_pc(core);
}

void sbr(int8_t Rd, int8_t K, struct CORE *core) {
    // Set Bit in Register
    // Rd <- Rd | K
    // 1 cycle
    core->R[Rd] = core->R[Rd] | K;
    return 0;
    inc_pc(core);
}

void cbr(int8_t Rd, int8_t K, struct CORE *core) {
    // Clear Bit in Register
    // Rd <- Rd & ($FF - K)
    // 1 cycle
    core->R[Rd] = core->R[Rd] & ~K;
    return 0;
    inc_pc(core);
}

void inc(int8_t Rd, struct CORE *core) {
    // Increment
    // Rd <- Rd + 1
    // 1 cycle
    core->R[Rd] = core->R[Rd] + 1;
    return 0;
    inc_pc(core);
}

void dec(int8_t Rd, struct CORE *core) {
    // Decrement
    // Rd <- Rd - 1
    // 1 cycle
    core->R[Rd] = core->R[Rd] - 1;
    return 0;
    inc_pc(core);
}

void tst(int8_t Rd, struct CORE *core) {
    // Test for Zero or Minus
    // Rd <- Rd & Rd
    // 1 cycle
    core->R[Rd] = core->R[Rd] & core->R[Rd];
    return 0;
    inc_pc(core);
}

void clr(int8_t Rd, struct CORE *core) {
    // Clear Register
    // Rd <- 0
    // 1 cycle
    core->R[Rd] = 0;
    return 0;
    inc_pc(core);
}

void ser(int8_t Rd, struct CORE *core) {
    // Set Register
    // Rd <- $FF
    // 1 cycle
    core->R[Rd] = 0xFF;
    return 0;
    inc_pc(core);
}

void mul(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Multiply Unsigned
    // R1:R0 <- Rd * Rr (UU)
    // 2 cycle
    uint16_t result = (uint16_t)core->R[Rd] * (uint16_t)core->R[Rr];
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    return 0;
    inc_pc(core);
}

void muls(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Multiply Signed
    // R1:R0 <- Rd * Rr (SS)
    // 2 cycle
    int16_t result = (int16_t)core->R[Rd] * (int16_t)core->R[Rr];
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    return 0;
    inc_pc(core);
}

void mulsu(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Multiply Signed with Unsigned
    // R1:R0 <- Rd * Rr (SU)
    // 2 cycle
    int16_t result = (int16_t)core->R[Rd] * (uint16_t)core->R[Rr];
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    return 0;
    inc_pc(core);
}

void fmul(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Fractional Multiply Unsigned
    // R1:R0 <- Rd * Rr (UU)
    // 2 cycle
    uint16_t result = (uint16_t)core->R[Rd] * (uint16_t)(core->R[Rr] << 1);
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    return 0;
    inc_pc(core);
}

void fmuls(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Fractional Multiply Signed
    // R1:R0 <- Rd * Rr (SS)
    // 2 cycle
    int16_t result = (int16_t)core->R[Rd] * (int16_t)(core->R[Rr] << 1);
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    return 0;
    inc_pc(core);
}

void fmulsu(int8_t Rd, int8_t Rr, struct CORE *core) {
    // Fractional Multiply Signed with Unsigned
    // R1:R0 <- Rd * Rr (SU)
    // 2 cycle
    int16_t result = (int16_t)core->R[Rd] * (uint16_t)(core->R[Rr] << 1);
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    return 0;
    inc_pc(core);
}