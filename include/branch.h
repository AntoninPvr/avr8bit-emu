#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"
#include "sram.h"
#include "data_space.h"
#include "sreg_utils.h"
#include "emulator.h"

/**
 * @brief Perform a relative jump.
 * 
 * @param k The offset for the jump.
 * @param core Pointer to the CORE structure.
 */
void rjmp(uint8_t k, struct CORE *core);

/**
 * @brief Perform an indirect jump.
 * 
 * @param core Pointer to the CORE structure.
 */
void ijmp(struct CORE *core);

/**
 * @brief Perform an absolute jump.
 * 
 * @param k The address to jump to.
 * @param core Pointer to the CORE structure.
 */
void jmp(uint32_t k, struct CORE *core);

/**
 * @brief Perform a relative call to a subroutine.
 * 
 * @param k The offset for the call.
 * @param core Pointer to the CORE structure.
 * @param sram Pointer to the SRAM structure.
 */
void rcall(uint8_t k, struct CORE *core, struct SRAM *sram);

/**
 * @brief Perform an indirect call to a subroutine.
 * 
 * @param core Pointer to the CORE structure.
 * @param sram Pointer to the SRAM structure.
 */
void icall(struct CORE *core, struct SRAM *sram);

/**
 * @brief Perform an extended indirect call to a subroutine.
 * 
 * @param core Pointer to the CORE structure.
 * @param sram Pointer to the SRAM structure.
 */
void eicall(struct CORE *core, struct SRAM *sram);

/**
 * @brief Return from a subroutine.
 * 
 * @param core Pointer to the CORE structure.
 * @param sram Pointer to the SRAM structure.
 */
void ret(struct CORE *core, struct SRAM *sram);

/**
 * @brief Return from an interrupt.
 * 
 * @param core Pointer to the CORE structure.
 * @param sram Pointer to the SRAM structure.
 */
void reti(struct CORE *core, struct SRAM *sram);

/**
 * @brief Compare and skip if equal.
 * 
 * @param d The destination register.
 * @param r The source register.
 * @param core Pointer to the CORE structure.
 */
void cpse(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Compare two registers.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void cp(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Compare two registers with carry.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void cpc(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Compare register with an immediate value.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void cpi(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Skip if bit in register is cleared.
 * 
 * @param r Register.
 * @param b Bit position.
 * @param core Pointer to the CORE structure.
 */
void sbrc(uint8_t r, uint8_t b, struct CORE *core);

/**
 * @brief Skip if bit in register is set.
 * 
 * @param r Register.
 * @param b Bit position.
 * @param core Pointer to the CORE structure.
 */
void sbrs(uint8_t r, uint8_t b, struct CORE *core);

/**
 * @brief Skip if bit in I/O register is cleared.
 * 
 * @param A I/O register address.
 * @param b Bit position.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void sbic(uint8_t A, uint8_t b, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Skip if bit in I/O register is set.
 * 
 * @param A I/O register address.
 * @param b Bit position.
 * @param core Pointer to the CORE structure.
 * @param data_space Pointer to the DATA_SPACE union.
 */
void sbis(uint8_t A, uint8_t b, struct CORE *core, union DATA_SPACE *data_space);

/**
 * @brief Branch if status flag is set.
 * 
 * @param s Status flag.
 * @param k Relative address.
 * @param core Pointer to the CORE structure.
 */
void brbs(uint8_t s, uint8_t k, struct CORE *core);

/**
 * @brief Branch if status flag is cleared.
 * 
 * @param s Status flag.
 * @param k Relative address.
 * @param core Pointer to the CORE structure.
 */
void brbc(uint8_t s, uint8_t k, struct CORE *core);

 /**
    * @brief Branch if equal.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void breq(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if not equal.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brne(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if carry set.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brcs(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if carry cleared.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brcc(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if same or higher.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brsh(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if lower.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brlo(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if minus.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brmi(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if plus.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brpl(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if greater or equal.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brge(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if less than.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brlt(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if half carry set.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brhs(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if half carry cleared.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brhc(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if T flag set.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brts(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if T flag cleared.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brtc(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if overflow set.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brvs(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if overflow cleared.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brvc(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if interrupts enabled.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brie(uint8_t k, struct CORE *core);

 /**
    * @brief Branch if interrupts disabled.
    * 
    * @param k The offset for the branch.
    * @param core Pointer to the core structure.
    */
void brid(uint8_t k, struct CORE *core);