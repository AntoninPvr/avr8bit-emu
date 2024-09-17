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

void ld_x_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using X as address and post-increment X
    // Rd <- (X)
    // X <- X + 1
    // 2 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.X];
    core->gp.X++;

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_x_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using X as address and post-decrement X
    // X <- X - 1
    // Rd <- (X)
    // 3 cycle

    // Execute instruction
    core->gp.X--;
    core->gp.R[d] = data_space->data[core->gp.X];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_y(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using Y as address
    // Rd <- (Y)
    // 1 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.Y];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_y_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using Y as address and post-increment Y
    // Rd <- (Y)
    // Y <- Y + 1
    // 2 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.Y];
    core->gp.Y++;

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_y_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using Y as address and post-decrement Y
    // Y <- Y - 1
    // Rd <- (Y)
    // 3 cycle

    // Execute instruction
    core->gp.Y--;
    core->gp.R[d] = data_space->data[core->gp.Y];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ldd_y(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect with displacement from data space using Y as address
    // Rd <- (Y + q)
    // 2 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.Y + q];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_z(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using Z as address
    // Rd <- (Z)
    // 1 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.Z];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_z_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using Z as address and post-increment Z
    // Rd <- (Z)
    // Z <- Z + 1
    // 2 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.Z];
    core->gp.Z++;

    // Update SREG
    // NONE

    inc_pc(core);
}

void ld_z_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect from data space using Z as address and post-decrement Z
    // Z <- Z - 1
    // Rd <- (Z)
    // 3 cycle

    // Execute instruction
    core->gp.Z--;
    core->gp.R[d] = data_space->data[core->gp.Z];

    // Update SREG
    // NONE

    inc_pc(core);
}

void ldd_z(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space) {
    // Load indirect with displacement from data space using Z as address
    // Rd <- (Z + q)
    // 2 cycle

    // Execute instruction
    core->gp.R[d] = data_space->data[core->gp.Z + q];

    // Update SREG
    // NONE

    inc_pc(core);
}

void sts(int16_t k, uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store direct to data space
    // k <- Rd
    // 2 cycles

    // Execute instruction
    data_space->data[k] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_x(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using X as address
    // (X) <- Rd
    // 1 cycle

    // Execute instruction
    data_space->data[core->gp.X] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_x_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using X as address and post-increment X
    // (X) <- Rd
    // X <- X + 1
    // 2 cycle

    // Execute instruction
    data_space->data[core->gp.X] = core->gp.R[d];
    core->gp.X++;

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_x_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using X as address and post-decrement X
    // X <- X - 1
    // (X) <- Rd
    // 3 cycle

    // Execute instruction
    core->gp.X--;
    data_space->data[core->gp.X] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_y(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using Y as address
    // (Y) <- Rd
    // 1 cycle

    // Execute instruction
    data_space->data[core->gp.Y] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_y_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using Y as address and post-increment Y
    // (Y) <- Rd
    // Y <- Y + 1
    // 2 cycle

    // Execute instruction
    data_space->data[core->gp.Y] = core->gp.R[d];
    core->gp.Y++;

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_y_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using Y as address and post-decrement Y
    // Y <- Y - 1
    // (Y) <- Rd
    // 3 cycle

    // Execute instruction
    core->gp.Y--;
    data_space->data[core->gp.Y] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void std_y(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect with displacement to data space using Y as address
    // (Y + q) <- Rd
    // 2 cycle

    // Execute instruction
    data_space->data[core->gp.Y + q] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_z(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using Z as address
    // (Z) <- Rd
    // 1 cycle

    // Execute instruction
    data_space->data[core->gp.Z] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_z_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using Z as address and post-increment Z
    // (Z) <- Rd
    // Z <- Z + 1
    // 2 cycle

    // Execute instruction
    data_space->data[core->gp.Z] = core->gp.R[d];
    core->gp.Z++;

    // Update SREG
    // NONE

    inc_pc(core);
}

void st_z_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect to data space using Z as address and post-decrement Z
    // Z <- Z - 1
    // (Z) <- Rd
    // 3 cycle

    // Execute instruction
    core->gp.Z--;
    data_space->data[core->gp.Z] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void std_z(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space) {
    // Store indirect with displacement to data space using Z as address
    // (Z + q) <- Rd
    // 2 cycle

    // Execute instruction
    data_space->data[core->gp.Z + q] = core->gp.R[d];

    // Update SREG
    // NONE

    inc_pc(core);
}

void lpm_0(struct CORE *core, union PROGMEM_SPACE *progmem_space) {
    // Load program memory to R0
    // R0 <- Z
    // 3 cycle

    // Execute instruction
    core->gp.R0 = progmem_space->data[core->gp.Z];

    // Update SREG
    // NONE

    inc_pc(core);
}

void lpm_z(uint8_t d, struct CORE *core, union PROGMEM_SPACE *progmem_space) {    
    // Load program memory to register using Z as address
    // Rd <- (Z)
    // 3 cycle

    // Execute instruction
    core->gp.R[d] = progmem_space->data[core->gp.Z];

    // Update SREG
    // NONE

    inc_pc(core);
}

void lpm_z_inc(uint8_t d, struct CORE *core, union PROGMEM_SPACE *progmem_space) {
    // Load program memory to register using Z as address and post-increment Z
    // Rd <- (Z)
    // Z <- Z + 1
    // 3 cycle

    // Execute instruction
    core->gp.R[d] = progmem_space->data[core->gp.Z];
    core->gp.Z++;

    // Update SREG
    // NONE

    inc_pc(core);
}

void in(uint8_t d, uint8_t A, struct CORE *core, union DATA_SPACE *data_space) {
    // Read from I/O register
    // Rd <- I/O[A]
    // 1 cycle

    // Execute instruction
    core->gp.R[d] = data_space->io_reg[A];

    // Update SREG
    // NONE

    inc_pc(core);
}

void out(uint8_t A, uint8_t r, struct CORE *core, union DATA_SPACE *data_space) {
    // Write to I/O register
    // I/O[A] <- Rr
    // 1 cycle

    // Execute instruction
    data_space->io_reg[A] = core->gp.R[r];

    // Update SREG
    // NONE

    inc_pc(core);
}

void push(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Push register to stack
    // (SP) <- Rr
    // SP <- SP - 1 
    // 2 cycle

    // Execute instruction
    data_space->sram[core->SP] = core->gp.R[d];
    core->SP--;

    // Update SREG
    // NONE

    inc_pc(core);
}

void pop(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Pop register from stack
    // SP <- SP + 1
    // Rd <- (SP)
    // 2 cycle

    // Execute instruction
    core->SP++;
    core->gp.R[d] = data_space->sram[core->SP];

    // Update SREG
    // NONE

    inc_pc(core);
}

void xch(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Exchange register with stack
    // Rd <-> (SP)
    // 2 cycle

    // Execute instruction
    uint8_t temp = core->gp.R[d];
    core->gp.R[d] = data_space->data[core->gp.Z];
    data_space->data[core->gp.Z] = temp;

    // Update SREG
    // NONE

    inc_pc(core);
}

void las(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load and set register
    // Only on SRAM
    // In same time:
    // (Z) <- Rd || (Z)
    // Rd <- (Z)
    // 2 cycle

    // Execute instruction
    uint8_t temp = data_space->data[core->gp.Z];
    data_space->data[core->gp.Z] = core->gp.R[d] || temp;
    core->gp.R[d] = temp;

    // Update SREG
    // NONE

    inc_pc(core);
}

void lac(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load and clear register
    // Only on SRAM
    // In same time:
    // (Z) <- (0xFF - Rd) & (Z)
    // Rd <- (Z)
    // 2 cycle

    // Execute instruction
    uint8_t temp = data_space->data[core->gp.Z];
    data_space->data[core->gp.Z] = (0xFF - core->gp.R[d]) & temp;
    core->gp.R[d] = temp;

    // Update SREG
    // NONE

    inc_pc(core);
}

void lat(uint8_t d, struct CORE *core, union DATA_SPACE *data_space) {
    // Load and toggle register
    // Only on SRAM
    // In same time:
    // (Z) <- Rd ^ (Z)
    // Rd <- (Z)
    // 2 cycle

    // Execute instruction
    uint8_t temp = data_space->data[core->gp.Z];
    data_space->data[core->gp.Z] = core->gp.R[d] ^ temp;
    core->gp.R[d] = temp;

    // Update SREG
    // NONE

    inc_pc(core);
}