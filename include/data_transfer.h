#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"
#include "data_space.h"

/**
 * @brief Move data from register r to register d.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void mov(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Move word from register pair r to register pair d.
 * 
 * @param d Destination register pair.
 * @param r Source register pair.
 * @param core Pointer to the CORE structure.
 */
void movw(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Load immediate value K into register d.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void ldi(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Load direct from data space using 16-bit address.
 * 
 * @param d Destination register.
 * @param k 16-bit address in data space.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void lds(uint8_t d, int16_t k, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space using X register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_x(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space using X register and post-increment.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_x_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space using X register and pre-decrement.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_x_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space using Y register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_y(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space using Y register and post-increment.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_y_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space using Y register and pre-decrement.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_y_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space to register using Y pointer with displacement.
 * 
 * @param d Destination register.
 * @param q Displacement value.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ldd_y(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space to register using Z pointer.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_z(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space to register using Z pointer and post-increment.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_z_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space to register using Z pointer and pre-decrement.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ld_z_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load indirect from data space to register using Z pointer with displacement.
 * 
 * @param d Destination register.
 * @param q Displacement value.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void ldd_z(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store direct from register to data space.
 * 
 * @param k Address in data space.
 * @param d Source register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void sts(int16_t k, uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store indirect from register to data space using X pointer.
 * 
 * @param d Source register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_x(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store indirect from register to data space using X pointer and post-increment.
 * 
 * @param d Source register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_x_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store indirect from register to data space using X pointer and pre-decrement.
 * 
 * @param d Source register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_x_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store indirect from register to data space using Y pointer.
 * 
 * @param d Source register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_y(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store register to data space using Y pointer and post-increment Y.
 * 
 * @param d The register to store.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_y_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store register to data space using Y pointer and pre-decrement Y.
 * 
 * @param d The register to store.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_y_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store register to data space using Y pointer with displacement.
 * 
 * @param d The register to store.
 * @param q The displacement value.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void std_y(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store register to data space using Z pointer.
 * 
 * @param d The register to store.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_z(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store register to data space using Z pointer and post-increment Z.
 * 
 * @param d The register to store.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_z_inc(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store register to data space using Z pointer and pre-decrement Z.
 * 
 * @param d The register to store.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void st_z_dec(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Store register to data space using Z pointer with displacement.
 * 
 * @param d The register to store.
 * @param q The displacement value.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void std_z(uint8_t d, uint8_t q, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load program memory into register using Z pointer.
 * 
 * @param core Pointer to the CORE structure.
 * @param progmem_space Pointer to the PROGMEM_SPACE union.
 */
void lpm_0(struct CORE *core, union PROGMEM_SPACE *progmem_space);

/**
 * @brief Load program memory into register using Z pointer.
 * 
 * @param d The register to load into.
 * @param core Pointer to the CORE structure.
 * @param progmem_space Pointer to the PROGMEM_SPACE union.
 */
void lpm_z(uint8_t d, struct CORE *core, union PROGMEM_SPACE *progmem_space);

/**
 * @brief Load program memory and post-increment Z register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param progmem_space Pointer to the PROGMEM_SPACE union.
 */
void lpm_z_inc(uint8_t d, struct CORE *core, union PROGMEM_SPACE *progmem_space);

/**
 * @brief Read from I/O space into register.
 * 
 * @param d Destination register.
 * @param A I/O address.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void in(uint8_t d, uint8_t A, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Write from register to I/O space.
 * 
 * @param A I/O address.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void out(uint8_t A, uint8_t r, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Push register onto stack.
 * 
 * @param d Source register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void push(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Pop register from stack.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void pop(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Exchange register with data space.
 * 
 * @param d Register to exchange.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void xch(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load and set data space.
 * 
 * @param d Register to load and set.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void las(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load and clear data space.
 * 
 * @param d Register to load and clear.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void lac(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Load and toggle data space.
 * 
 * @param d Register to load and toggle.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void lat(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);