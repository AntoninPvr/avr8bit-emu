#include "arithm_logic.h"

void add(uint8_t d, uint8_t r, struct CORE *core) {
    // Add without cary
    // r <- r + r
    // 1 cycle
    core->R[d] = core->R[d] + core->R[r];
    inc_pc(core);
}

void adc(uint8_t d, uint8_t r, struct CORE *core) {
    // Add with cary
    // r <- r + r + C
    // 1 cycle
    core->R[d] = core->R[d] + core->R[r] + core->sreg.C;
    inc_pc(core);
}

void sub(uint8_t d, uint8_t r, struct CORE *core) {
    // Subtract without cary
    // r <- r - r
    // 1 cycle
    core->R[d] = core->R[d] - core->R[r];
    inc_pc(core);
} 

void subi(uint8_t d, uint8_t K, struct CORE *core) {
    // Subtract immediate
    // r <- r - K
    // 1 cycle
    core->R[d] = core->R[d] - K;
    inc_pc(core);
}

void sbc(uint8_t d, uint8_t r, struct CORE *core) {
    // Subtract with cary
    // r <- r - r - C
    // 1 cycle
    core->R[d] = core->R[d] - core->R[r] - core->sreg.C;
    inc_pc(core);
}

void sbci(uint8_t d, uint8_t K, struct CORE *core) {
    // Subtract immediate with cary
    // r <- r - K - C
    // 1 cycle
    core->R[d] = core->R[d] - K - core->sreg.C;
    inc_pc(core);
}

void and(uint8_t d, uint8_t r, struct CORE *core) {
    // Logical AND
    // r <- r & r
    // 1 cycle
    core->R[d] = core->R[d] & core->R[r];
    inc_pc(core);
}

void andi(uint8_t d, uint8_t K, struct CORE *core) {
    // Logical AND with immediate
    // r <- r & K
    // 1 cycle
    core->R[d] = core->R[d] & K;
    inc_pc(core);
}

void or(uint8_t d, uint8_t r, struct CORE *core) {
    // Logical OR
    // r <- r | r
    // 1 cycle
    core->R[d] = core->R[d] | core->R[r];
    inc_pc(core);
}

void ori(uint8_t d, uint8_t K, struct CORE *core) {
    // Logical OR with immediate
    // r <- r | K
    // 1 cycle
    core->R[d] = core->R[d] | K;
    inc_pc(core);
}

void eor(uint8_t d, uint8_t r, struct CORE *core) {
    // Logical Exclusive OR
    // r <- r ^ r
    // 1 cycle
    core->R[d] = core->R[d] ^ core->R[r];
    inc_pc(core);
}

void com(uint8_t d, struct CORE *core) {
    // Logical Complement
    // r <- $FF - r
    // 1 cycle
    core->R[d] = ~core->R[d];
    inc_pc(core);
}

void neg(uint8_t d, struct CORE *core) {
    // Two's Complement
    // r <- $00 - r
    // 1 cycle
    core->R[d] = -core->R[d];
    inc_pc(core);
}

void sbr(uint8_t d, uint8_t K, struct CORE *core) {
    // Set Bit in Register
    // r <- r | K
    // 1 cycle
    core->R[d] = core->R[d] | K;
    inc_pc(core);
}

void cbr(uint8_t d, uint8_t K, struct CORE *core) {
    // Clear Bit in Register
    // r <- r & ($FF - K)
    // 1 cycle
    core->R[d] = core->R[d] & ~K;
    inc_pc(core);
}

void inc(uint8_t d, struct CORE *core) {
    // Increment
    // r <- r + 1
    // 1 cycle
    core->R[d] = core->R[d] + 1;
    inc_pc(core);
}

void dec(uint8_t d, struct CORE *core) {
    // Decrement
    // r <- r - 1
    // 1 cycle
    core->R[d] = core->R[d] - 1;
    inc_pc(core);
}

void tst(uint8_t d, struct CORE *core) {
    // Test for Zero or Minus
    // r <- r & r
    // 1 cycle
    core->R[d] = core->R[d] & core->R[d];
    inc_pc(core);
}

void clr(uint8_t d, struct CORE *core) {
    // Clear Register
    // r <- 0
    // 1 cycle
    core->R[d] = 0;
    inc_pc(core);
}

void ser(uint8_t d, struct CORE *core) {
    // Set Register
    // r <- $FF
    // 1 cycle
    core->R[d] = 0xFF;
    inc_pc(core);
}

void mul(uint8_t d, uint8_t r, struct CORE *core) {
    // Multiply Unsigned
    // R1:R0 <- r * r (UU)
    // 2 cycle
    uint16_t result = (uint16_t)core->R[d] * (uint16_t)core->R[r];
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void muls(uint8_t d, uint8_t r, struct CORE *core) {
    // Multiply Signed
    // R1:R0 <- r * r (SS)
    // 2 cycle
    int16_t result = (int16_t)core->R[d] * (int16_t)core->R[r];
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void mulsu(uint8_t d, uint8_t r, struct CORE *core) {
    // Multiply Signed with Unsigned
    // R1:R0 <- r * r (SU)
    // 2 cycle
    int16_t result = (int16_t)core->R[d] * (uint16_t)core->R[r];
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void fmul(uint8_t d, uint8_t r, struct CORE *core) {
    // Fractional Multiply Unsigned
    // R1:R0 <- r * r (UU)
    // 2 cycle
    uint16_t result = (uint16_t)core->R[d] * (uint16_t)(core->R[r] << 1);
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void fmuls(uint8_t d, uint8_t r, struct CORE *core) {
    // Fractional Multiply Signed
    // R1:R0 <- r * r (SS)
    // 2 cycle
    int16_t result = (int16_t)core->R[d] * (int16_t)(core->R[r] << 1);
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void fmulsu(uint8_t d, uint8_t r, struct CORE *core) {
    // Fractional Multiply Signed with Unsigned
    // R1:R0 <- r * r (SU)
    // 2 cycle
    int16_t result = (int16_t)core->R[d] * (uint16_t)(core->R[r] << 1);
    core->R[0] = result & 0xFF;
    core->R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}
