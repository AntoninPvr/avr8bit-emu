#include "bit_test.h"

void lsl(uint8_t d, struct CORE *core) {
    // Logical Shift Left
    // r(7) loaded into C
    // r <- r << 1
    // 1 cycle
    core->sreg.C = (core->R[d] & 0x80) >> 7;
    core->R[d] = core->R[d] << 1;
    inc_pc(core);
}

void lsr(uint8_t d, struct CORE *core) {
    // Logical Shift Right
    // r(0) loaded into C
    // r <- r >> 1
    // 1 cycle
    core->sreg.C = core->R[d] & 0x01;
    core->R[d] = core->R[d] >> 1;
    inc_pc(core);
}

void rol(uint8_t d, struct CORE *core) {
    // Rotate Left through Cary
    // r(7) loaded into C
    // r <- r << 1 | C
    // 1 cycle
    bool temp = core->sreg.C;
    core->sreg.C = (core->R[d] & 0x80) >> 7;
    core->R[d] = (core->R[d] << 1) | temp;
    inc_pc(core);
}

void ror(uint8_t d, struct CORE *core) {
    // Rotate Right through Cary
    // r(0) loaded into C
    // r <- r >> 1 | C << 7
    // 1 cycle
    bool temp = core->sreg.C;
    core->sreg.C = core->R[d] & 0x01;
    core->R[d] = (core->R[d] >> 1) | (temp << 7);
    inc_pc(core);
}

void asr(uint8_t d, struct CORE *core) {
    // Arithmetic Shift Right
    // r(0) loaded into C
    // r <- r >> 1
    // 1 cycle
    core->sreg.C = core->R[d] & 0x01;
    core->R[d] = (core->R[d] & 0x80) | (core->R[d] >> 1);
    inc_pc(core);
}

void swap(uint8_t d, struct CORE *core) {
    // Swap Nibbles
    // r <- r(3:0) << 4 | r(7:4)
    // 1 cycle
    core->R[d] = (core->R[d] & 0x0F) << 4 | (core->R[d] & 0xF0) >> 4;
    inc_pc(core);
}

void sbi(uint8_t IO, uint8_t n, struct CORE *core) {
    // Set Bit in I/O Register
    // I/O(n) <- 1
    // 2 cycle
    core->R[IO] = core->R[IO] | (1 << n);
    inc_pc(core);
}

void cbi(uint8_t IO, uint8_t n, struct CORE *core) {
    // Clear Bit in I/O Register
    // I/O(n) <- 0
    // 2 cycle
    core->R[IO] = core->R[IO] & ~(1 << n);
    inc_pc(core);
}

void bst(uint8_t d, uint8_t b, struct CORE *core) {
    // Bit Store from Register to T Flag
    // T <- r(b)
    // 1 cycle
    core->sreg.T = (core->R[d] & (1 << b)) >> b;
    inc_pc(core);
}

void bld(uint8_t d, uint8_t b, struct CORE *core) {
    // Bit Load from T Flag to Register
    // r(b) <- T
    // 1 cycle
    core->R[d] = (core->R[d] & ~(1 << b)) | (core->sreg.T << b);
    inc_pc(core);
}

void bset(uint8_t s, struct CORE *core) {
    // Bit Set in SREG
    // S <- 1
    // 1 cycle
    core->sreg.sreg = core->sreg.sreg | (1 << s);
    inc_pc(core);
}

void bclr(uint8_t s, struct CORE *core) {
    // Bit Clear in SREG
    // S <- 0
    // 1 cycle
    core->sreg.sreg = core->sreg.sreg & ~(1 << s);
    inc_pc(core);
}

void sec(struct CORE *core) {
    // Set Cary Flag
    // C <- 1
    // 1 cycle
    core->sreg.C = 1;
    inc_pc(core);
}

void clc(struct CORE *core) {
    // Clear Cary Flag
    // C <- 0
    // 1 cycle
    core->sreg.C = 0;
    inc_pc(core);
}

void sen(struct CORE *core) {
    // Set Negative Flag
    // N <- 1
    // 1 cycle
    core->sreg.N = 1;
    inc_pc(core);
}

void cln(struct CORE *core) {
    // Clear Negative Flag
    // N <- 0
    // 1 cycle
    core->sreg.N = 0;
    inc_pc(core);
}

void sez(struct CORE *core) {
    // Set Zero Flag
    // Z <- 1
    // 1 cycle
    core->sreg.Z = 1;
    inc_pc(core);
}

void clz(struct CORE *core) {
    // Clear Zero Flag
    // Z <- 0
    // 1 cycle
    core->sreg.Z = 0;
    inc_pc(core);
}

void sei(struct CORE *core) {
    // Set Global Interupt Enable
    // I <- 1
    // 1 cycle
    core->sreg.I = 1;
    inc_pc(core);
}

void cli(struct CORE *core) {
    // Clear Global Interupt Enable
    // I <- 0
    // 1 cycle
    core->sreg.I = 0;
    inc_pc(core);
}

void ses(struct CORE *core) {
    // Set Signed Flag
    // S <- 1
    // 1 cycle
    core->sreg.S = 1;
    inc_pc(core);
}

void cls(struct CORE *core) {
    // Clear Signed Flag
    // S <- 0
    // 1 cycle
    core->sreg.S = 0;
    inc_pc(core);
}

void sev(struct CORE *core) {
    // Set Two's complement overflow flag
    // V <- 1
    // 1 cycle
    core->sreg.V = 1;
    inc_pc(core);
}

void clv(struct CORE *core) {
    // Clear Two's complement overflow flag
    // V <- 0
    // 1 cycle
    core->sreg.V = 0;
    inc_pc(core);
}

void set(struct CORE *core) {
    // Set T Flag
    // T <- 1
    // 1 cycle
    core->sreg.T = 1;
    inc_pc(core);
}

void clt(struct CORE *core) {
    // Clear T Flag
    // T <- 0
    // 1 cycle
    core->sreg.T = 0;
    inc_pc(core);
}

void seh(struct CORE *core) {
    // Set Half Cary Flag
    // H <- 1
    // 1 cycle
    core->sreg.H = 1;
    inc_pc(core);
}

void clh(struct CORE *core) {
    // Clear Half Cary Flag
    // H <- 0
    // 1 cycle
    core->sreg.H = 0;
    inc_pc(core);
}
