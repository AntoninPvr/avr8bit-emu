/**
 * @file      arithm_logic.h
 * @brief     Arithmetic and logic operations
 * @details   Contains all atomic arithmetic and logic operations
 * @author    Antonin Pivard
 * @date      2024
 * @warning   Not tested
 * @copyright GNU General Public License v3.0
 */

#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"
#include "sreg_utils.h"

/**
 * @brief Add without carry
 * @param d Destination register index
 * @param r Source register index
 * @param core Pointer to the CORE structure
 */
void add(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Add with carry.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void adc(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Add immediate to word.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void adiw(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Subtract.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void sub(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Subtract immediate.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void subi(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Subtract with carry.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void sbc(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Subtract immediate with carry.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void sbci(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Subtract immediate from word.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void sbiw(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Logical AND.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void and(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Logical AND with immediate.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void andi(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Logical OR.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void or(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Logical OR with immediate.
 * 
 * @param d Destination register.
 * @param K Immediate value.
 * @param core Pointer to the CORE structure.
 */
void ori(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Perform bitwise exclusive OR between two registers.
 * 
 * @param d Destination register.
 * @param r Source register.
 * @param core Pointer to the CORE structure.
 */
void eor(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Perform one's complement on a register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 */
void com(uint8_t d, struct CORE *core);

/**
 * @brief Perform two's complement (negation) on a register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 */
void neg(uint8_t d, struct CORE *core);

/**
 * @brief Set bits in a register.
 * 
 * @param d Destination register.
 * @param K Constant value to set bits.
 * @param core Pointer to the CORE structure.
 */
void sbr(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Clear bits in a register.
 * 
 * @param d Destination register.
 * @param K Constant value to clear bits.
 * @param core Pointer to the CORE structure.
 */
void cbr(uint8_t d, uint8_t K, struct CORE *core);

/**
 * @brief Increment the value of a register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 */
void inc(uint8_t d, struct CORE *core);

/**
 * @brief Decrement the value of a register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 */
void dec(uint8_t d, struct CORE *core);

/**
 * @brief Test for zero or minus after AND operation.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 */
void tst(uint8_t d, struct CORE *core);

/**
 * @brief Clear a register (set to zero).
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 */
void clr(uint8_t d, struct CORE *core);

/**
 * @brief Set all bits in a register.
 * 
 * @param d Destination register.
 * @param core Pointer to the CORE structure.
 */
void ser(uint8_t d, struct CORE *core);
/**
 * @brief Multiplies two unsigned 8-bit integers and stores the result in the CORE structure.
 * 
 * @param d First operand.
 * @param r Second operand.
 * @param core Pointer to the CORE structure where the result will be stored.
 */
void mul(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Multiplies two signed 8-bit integers and stores the result in the CORE structure.
 * 
 * @param d First operand.
 * @param r Second operand.
 * @param core Pointer to the CORE structure where the result will be stored.
 */
void muls(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Multiplies a signed 8-bit integer with an unsigned 8-bit integer and stores the result in the CORE structure.
 * 
 * @param d First operand (signed).
 * @param r Second operand (unsigned).
 * @param core Pointer to the CORE structure where the result will be stored.
 */
void mulsu(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Multiplies two unsigned 8-bit integers with fractional representation and stores the result in the CORE structure.
 * 
 * @param d First operand.
 * @param r Second operand.
 * @param core Pointer to the CORE structure where the result will be stored.
 */
void fmul(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Multiplies two signed 8-bit integers with fractional representation and stores the result in the CORE structure.
 * 
 * @param d First operand.
 * @param r Second operand.
 * @param core Pointer to the CORE structure where the result will be stored.
 */
void fmuls(uint8_t d, uint8_t r, struct CORE *core);

/**
 * @brief Multiplies a signed 8-bit integer with an unsigned 8-bit integer with fractional representation and stores the result in the CORE structure.
 * 
 * @param d First operand (signed).
 * @param r Second operand (unsigned).
 * @param core Pointer to the CORE structure where the result will be stored.
 */
void fmulsu(uint8_t d, uint8_t r, struct CORE *core);
