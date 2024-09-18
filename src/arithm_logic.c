#include "arithm_logic.h"

void add(uint8_t d, uint8_t r, struct CORE *core) {
    /**
     * @brief Add without carry
     * 
     * Rd <- Rd + Rr
     * 1 cycle
     * 
     * @param d Destination register index
     * @param r Source register index
     * @param core Pointer to the CORE structure
     */
	uint8_t R_tmp = core->gp.R[d];

    // Execute instruction
    core->gp.R[d] = core->gp.R[d] + core->gp.R[r];

    // Update SREG
    update_sreg_arithm(core, R_tmp, core->gp.R[r], core->gp.R[d]);

    inc_pc(core);
}

void adc(uint8_t d, uint8_t r, struct CORE *core) {
    // Add with cary
    // Rd <- Rd + Rr + C
    // 1 cycle

    uint8_t R_tmp = core->gp.R[d];

    // Execute instruction
    core->gp.R[d] = core->gp.R[d] + core->gp.R[r] + core->sreg.C;

    // Update SREG
    update_sreg_arithm(core, R_tmp, core->gp.R[r], core->gp.R[d]);

    inc_pc(core);
}

void adiw(uint8_t d, uint8_t K, struct CORE *core) {
    // Add immediate to word
    // Rd:Rd+1 <- Rd:Rd+1 + K
    // 2 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    uint16_t Rd = core->gp.R[d] | (core->gp.R[d + 1] << 8);
    uint16_t result = Rd + K;
    core->gp.R[d] = result & 0xFF;
    core->gp.R[d + 1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void sub(uint8_t d, uint8_t r, struct CORE *core) {
    // Subtract without cary
    // Rd <- Rd - Rr
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] - core->gp.R[r];
    
    // Update SREG
    update_sreg_arithm(core, R_tmp, core->gp.R[r], core->gp.R[d]);

    inc_pc(core);
}

void subi(uint8_t d, uint8_t K, struct CORE *core) {
    // Subtract immediate
    // Rd <- Rd - K
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] - K;

    // Update SREG
    update_sreg_arithm(core, R_tmp, K, core->gp.R[d]);

    inc_pc(core);
}

void sbc(uint8_t d, uint8_t r, struct CORE *core) {
    // Subtract with cary
    // Rd <- Rd - Rr - C
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] - core->gp.R[r] - core->sreg.C;

    // Update SREG
    update_sreg_arithm(core, R_tmp, core->gp.R[r], core->gp.R[d]);

    inc_pc(core);
}

void sbci(uint8_t d, uint8_t K, struct CORE *core) {
    // Subtract immediate with cary
    // Rd <- Rd - K - C
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] - K - core->sreg.C;

    // Update SREG
    update_sreg_arithm(core, R_tmp, K, core->gp.R[d]);

    inc_pc(core);
}

void sbiw(uint8_t d, uint8_t K, struct CORE *core) {
    // Subtract immediate from word
    // Rd:Rd+1 <- Rd:Rd+1 - K
    // 2 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    uint16_t Rd = core->gp.R[d] | (core->gp.R[d + 1] << 8);
    uint16_t result = Rd - K;
    core->gp.R[d] = result & 0xFF;
    core->gp.R[d + 1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void and(uint8_t d, uint8_t r, struct CORE *core) {
    // Logical AND
    // Rd <- Rd & Rr
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] & core->gp.R[r];

    // Update SREG
    update_sreg_logic(core, core->gp.R[d]);

    inc_pc(core);
}

void andi(uint8_t d, uint8_t K, struct CORE *core) {
    // Logical AND with immediate
    // Rd <- Rd & K
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] & K;

    // Update SREG
    update_sreg_logic(core, core->gp.R[d]);

    inc_pc(core);
}

void or(uint8_t d, uint8_t r, struct CORE *core) {
    // Logical OR
    // Rd <- Rd | Rr
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] | core->gp.R[r];

    // Update SREG
    update_sreg_logic(core, core->gp.R[d]);

    inc_pc(core);
}

void ori(uint8_t d, uint8_t K, struct CORE *core) {
    // Logical OR with immediate
    // Rd <- Rd | K
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] | K;

    // Update SREG
    update_sreg_logic(core, core->gp.R[d]);

    inc_pc(core);
}

void eor(uint8_t d, uint8_t r, struct CORE *core) {
    // Logical Exclusive OR
    // Rd <- Rd ^ Rr
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] ^ core->gp.R[r];

    // Update SREG
    update_sreg_logic(core, core->gp.R[d]);
    
    inc_pc(core);
}

void com(uint8_t d, struct CORE *core) {
    // Logical Complement
    // Rd <- $FF - Rd
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = ~core->gp.R[d];

    // Update SREG
    update_sreg_logic(core, core->gp.R[d]);
    update_sreg_C(core, true);
    
    inc_pc(core);
}

void neg(uint8_t d, struct CORE *core) {
    // Two's Complement
    // Rd <- $00 - Rd
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = -core->gp.R[d];
    inc_pc(core);
}

void sbr(uint8_t d, uint8_t K, struct CORE *core) {
    // Set Bit in Register
    // Rd <- Rd | K
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] | K;
    inc_pc(core);
}

void cbr(uint8_t d, uint8_t K, struct CORE *core) {
    // Clear Bit in Register
    // Rd <- Rd & ($FF - K)
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] & ~K;
    inc_pc(core);
}

void inc(uint8_t d, struct CORE *core) {
    // Increment
    // Rd <- Rd + 1
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] + 1;
    inc_pc(core);
}

void dec(uint8_t d, struct CORE *core) {
    // Decrement
    // Rd <- Rd - 1
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] - 1;
    inc_pc(core);
}

void tst(uint8_t d, struct CORE *core) {
    // Test for Zero or Minus
    // Rd <- Rd & Rd
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = core->gp.R[d] & core->gp.R[d];
    inc_pc(core);
}

void clr(uint8_t d, struct CORE *core) {
    // Clear Register
    // Rd <- 0
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = 0;
    inc_pc(core);
}

void ser(uint8_t d, struct CORE *core) {
    // Set Register
    // Rd <- $FF
    // 1 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    core->gp.R[d] = 0xFF;
    inc_pc(core);
}

void mul(uint8_t d, uint8_t r, struct CORE *core) {
    // Multiply Unsigned
    // R1:R0 <- Rd * Rr (UU)
    // 2 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    uint16_t result = (uint16_t)core->gp.R[d] * (uint16_t)core->gp.R[r];
    core->gp.R[0] = result & 0xFF;
    core->gp.R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void muls(uint8_t d, uint8_t r, struct CORE *core) {
    // Multiply Signed
    // R1:R0 <- Rd * Rr (SS)
    // 2 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    int16_t result = (int16_t)core->gp.R[d] * (int16_t)core->gp.R[r];
    core->gp.R[0] = result & 0xFF;
    core->gp.R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void mulsu(uint8_t d, uint8_t r, struct CORE *core) {
    // Multiply Signed with Unsigned
    // R1:R0 <- Rd * Rr (SU)
    // 2 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    int16_t result = (int16_t)core->gp.R[d] * (uint16_t)core->gp.R[r];
    core->gp.R[0] = result & 0xFF;
    core->gp.R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void fmul(uint8_t d, uint8_t r, struct CORE *core) {
    // Fractional Multiply Unsigned
    // R1:R0 <- Rd * Rr (UU)
    // 2 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    uint16_t result = (uint16_t)core->gp.R[d] * (uint16_t)(core->gp.R[r] << 1);
    core->gp.R[0] = result & 0xFF;
    core->gp.R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void fmuls(uint8_t d, uint8_t r, struct CORE *core) {
    // Fractional Multiply Signed
    // R1:R0 <- Rd * Rr (SS)
    // 2 cycle

	uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    int16_t result = (int16_t)core->gp.R[d] * (int16_t)(core->gp.R[r] << 1);
    core->gp.R[0] = result & 0xFF;
    core->gp.R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}

void fmulsu(uint8_t d, uint8_t r, struct CORE *core) {
    // Fractional Multiply Signed with Unsigned
    // R1:R0 <- Rd * Rr (SU)
    // 2 cycle

    uint8_t R_tmp = core->gp.R[d];

	// Execute instruction 
    int16_t result = (int16_t)core->gp.R[d] * (uint16_t)(core->gp.R[r] << 1);
    core->gp.R[0] = result & 0xFF;
    core->gp.R[1] = (result >> 8) & 0xFF;
    inc_pc(core);
}
