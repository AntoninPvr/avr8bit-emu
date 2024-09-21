/**
 * @file      bit_test.h
 * @brief     Bit testings and manipulations
 * @details   Contains all atomic bit testings and manipulations
 * @author    Antonin Pivard
 * @date      2024
 * @warning   Not tested
 * @copyright GNU General Public License v3.0
 */

#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

/**
 * @brief Logical Shift Left.
 * 
 * @param d The register to be shifted.
 * @param core Pointer to the CORE structure.
 */
void lsl(uint8_t d, struct CORE *core);

/**
 * @brief Logical Shift Right.
 * 
 * @param d The register to be shifted.
 * @param core Pointer to the CORE structure.
 */
void lsr(uint8_t d, struct CORE *core);

/**
 * @brief Rotate Left through Carry.
 * 
 * @param d The register to be rotated.
 * @param core Pointer to the CORE structure.
 */
void rol(uint8_t d, struct CORE *core);

/**
 * @brief Rotate Right through Carry.
 * 
 * @param d The register to be rotated.
 * @param core Pointer to the CORE structure.
 */
void ror(uint8_t d, struct CORE *core);

/**
 * @brief Arithmetic Shift Right.
 * 
 * @param d The register to be shifted.
 * @param core Pointer to the CORE structure.
 */
void asr(uint8_t d, struct CORE *core);

/**
 * @brief Swap nibbles in a register.
 * 
 * @param d The register to be swapped.
 * @param core Pointer to the CORE structure.
 */
void swap(uint8_t d, struct CORE *core);

/**
 * @brief Set Bit in I/O Register.
 * 
 * @param IO The I/O register.
 * @param n The bit to be set.
 * @param core Pointer to the CORE structure.
 */
void sbi(uint8_t IO, uint8_t n, struct CORE *core);

/**
 * @brief Clear Bit in I/O Register.
 * 
 * @param IO The I/O register.
 * @param n The bit to be cleared.
 * @param core Pointer to the CORE structure.
 */
void cbi(uint8_t IO, uint8_t n, struct CORE *core);

/**
 * @brief Bit Store from Register to T Flag in SREG.
 * 
 * @param d The register.
 * @param b The bit to be stored.
 * @param core Pointer to the CORE structure.
 */
void bst(uint8_t d, uint8_t b, struct CORE *core);

/**
 * @brief Bit Load from T Flag in SREG to Register.
 * 
 * @param d The register.
 * @param b The bit to be loaded.
 * @param core Pointer to the CORE structure.
 */
void bld(uint8_t d, uint8_t b, struct CORE *core);

/**
 * @brief Set Bit in SREG.
 * 
 * @param s The bit to be set.
 * @param core Pointer to the CORE structure.
 */
void bset(uint8_t s, struct CORE *core);

/**
 * @brief Clear Bit in SREG.
 * 
 * @param s The bit to be cleared.
 * @param core Pointer to the CORE structure.
 */
void bclr(uint8_t s, struct CORE *core);

/**
 * @brief Set Carry Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void sec(struct CORE *core);

/**
 * @brief Clear Carry Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void clc(struct CORE *core);

/**
 * @brief Set Negative Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void sen(struct CORE *core);

/**
 * @brief Clear Negative Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void cln(struct CORE *core);

/**
 * @brief Set Zero Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void sez(struct CORE *core);

/**
 * @brief Clear Zero Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void clz(struct CORE *core);

/**
 * @brief Set Global Interrupt Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void sei(struct CORE *core);

/**
 * @brief Clear Global Interrupt Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void cli(struct CORE *core);

/**
 * @brief Set Signed Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void ses(struct CORE *core);

/**
 * @brief Clear Signed Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void cls(struct CORE *core);

/**
 * @brief Set Overflow Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void sev(struct CORE *core);

/**
 * @brief Clear Overflow Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void clv(struct CORE *core);

/**
 * @brief Set T Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void set(struct CORE *core);

/**
 * @brief Clear T Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void clt(struct CORE *core);

/**
 * @brief Set Half Carry Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void seh(struct CORE *core);

/**
 * @brief Clear Half Carry Flag.
 * 
 * @param core Pointer to the CORE structure.
 */
void clh(struct CORE *core);
