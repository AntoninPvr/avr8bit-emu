#include "arithm_logic.h"

int add(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Add without carry
    // Rd <- Rd + Rr
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] + cpu->R[Rr];
    return 0;
}

int adc(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Add with carry
    // Rd <- Rd + Rr + C
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] + cpu->R[Rr] + cpu->sreg.C;
    return 0;
}

int sub(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Subtract without carry
    // Rd <- Rd - Rr
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] - cpu->R[Rr];
    return 0;
} 

int subi(int8_t Rd, int8_t K, struct CPU *cpu) {
    // Subtract immediate
    // Rd <- Rd - K
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] - K;
    return 0;
}

int sbc(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Subtract with carry
    // Rd <- Rd - Rr - C
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] - cpu->R[Rr] - cpu->sreg.C;
    return 0;
}

int sbci(int8_t Rd, int8_t K, struct CPU *cpu) {
    // Subtract immediate with carry
    // Rd <- Rd - K - C
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] - K - cpu->sreg.C;
    return 0;
}

int and(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Logical AND
    // Rd <- Rd & Rr
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] & cpu->R[Rr];
    return 0;
}

int andi(int8_t Rd, int8_t K, struct CPU *cpu) {
    // Logical AND with immediate
    // Rd <- Rd & K
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] & K;
    return 0;
}

int or(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Logical OR
    // Rd <- Rd | Rr
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] | cpu->R[Rr];
    return 0;
}

int ori(int8_t Rd, int8_t K, struct CPU *cpu) {
    // Logical OR with immediate
    // Rd <- Rd | K
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] | K;
    return 0;
}

int eor(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Logical Exclusive OR
    // Rd <- Rd ^ Rr
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] ^ cpu->R[Rr];
    return 0;
}

int com(int8_t Rd, struct CPU *cpu) {
    // Logical Complement
    // Rd <- $FF - Rd
    // 1 cycle
    cpu->R[Rd] = ~cpu->R[Rd];
    return 0;
}

int neg(int8_t Rd, struct CPU *cpu) {
    // Two's Complement
    // Rd <- $00 - Rd
    // 1 cycle
    cpu->R[Rd] = -cpu->R[Rd];
    return 0;
}

int sbr(int8_t Rd, int8_t K, struct CPU *cpu) {
    // Set Bit in Register
    // Rd <- Rd | K
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] | K;
    return 0;
}

int cbr(int8_t Rd, int8_t K, struct CPU *cpu) {
    // Clear Bit in Register
    // Rd <- Rd & ($FF - K)
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] & ~K;
    return 0;
}

int inc(int8_t Rd, struct CPU *cpu) {
    // Increment
    // Rd <- Rd + 1
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] + 1;
    return 0;
}

int dec(int8_t Rd, struct CPU *cpu) {
    // Decrement
    // Rd <- Rd - 1
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] - 1;
    return 0;
}

int tst(int8_t Rd, struct CPU *cpu) {
    // Test for Zero or Minus
    // Rd <- Rd & Rd
    // 1 cycle
    cpu->R[Rd] = cpu->R[Rd] & cpu->R[Rd];
    return 0;
}

int clr(int8_t Rd, struct CPU *cpu) {
    // Clear Register
    // Rd <- 0
    // 1 cycle
    cpu->R[Rd] = 0;
    return 0;
}

int ser(int8_t Rd, struct CPU *cpu) {
    // Set Register
    // Rd <- $FF
    // 1 cycle
    cpu->R[Rd] = 0xFF;
    return 0;
}

int mul(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Multiply Unsigned
    // R1:R0 <- Rd * Rr (UU)
    // 2 cycle
    uint16_t result = (uint16_t)cpu->R[Rd] * (uint16_t)cpu->R[Rr];
    cpu->R[0] = result & 0xFF;
    cpu->R[1] = (result >> 8) & 0xFF;
    return 0;
}

int muls(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Multiply Signed
    // R1:R0 <- Rd * Rr (SS)
    // 2 cycle
    int16_t result = (int16_t)cpu->R[Rd] * (int16_t)cpu->R[Rr];
    cpu->R[0] = result & 0xFF;
    cpu->R[1] = (result >> 8) & 0xFF;
    return 0;
}

int mulsu(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Multiply Signed with Unsigned
    // R1:R0 <- Rd * Rr (SU)
    // 2 cycle
    int16_t result = (int16_t)cpu->R[Rd] * (uint16_t)cpu->R[Rr];
    cpu->R[0] = result & 0xFF;
    cpu->R[1] = (result >> 8) & 0xFF;
    return 0;
}

int fmul(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Fractional Multiply Unsigned
    // R1:R0 <- Rd * Rr (UU)
    // 2 cycle
    uint16_t result = (uint16_t)cpu->R[Rd] * (uint16_t)(cpu->R[Rr] << 1);
    cpu->R[0] = result & 0xFF;
    cpu->R[1] = (result >> 8) & 0xFF;
    return 0;
}

int fmuls(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Fractional Multiply Signed
    // R1:R0 <- Rd * Rr (SS)
    // 2 cycle
    int16_t result = (int16_t)cpu->R[Rd] * (int16_t)(cpu->R[Rr] << 1);
    cpu->R[0] = result & 0xFF;
    cpu->R[1] = (result >> 8) & 0xFF;
    return 0;
}

int fmulsu(int8_t Rd, int8_t Rr, struct CPU *cpu) {
    // Fractional Multiply Signed with Unsigned
    // R1:R0 <- Rd * Rr (SU)
    // 2 cycle
    int16_t result = (int16_t)cpu->R[Rd] * (uint16_t)(cpu->R[Rr] << 1);
    cpu->R[0] = result & 0xFF;
    cpu->R[1] = (result >> 8) & 0xFF;
    return 0;
}