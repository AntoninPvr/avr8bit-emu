/**
 * @file      sreg_utils.h
 * @brief     Functions for manipulating the Status Register (SREG)
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
 * @brief Computes the H flag as a boolean value.
 * 
 * @param Rd The value of the destination register.
 * @param Rr The value of the source register.
 * @return true if the H flag should be set, false otherwise.
 */
bool sreg_H_compute_bool(uint8_t Rd, uint8_t Rr);

/**
 * @brief Computes the Z flag as a boolean value.
 * 
 * @param result The result of the operation.
 * @return true if the Z flag should be set, false otherwise.
 */
bool sreg_Z_compute_bool(uint8_t result);

/**
 * @brief Computes the C flag as a boolean value.
 * 
 * @param Rd The value of the destination register.
 * @param Rr The value of the source register.
 * @return true if the C flag should be set, false otherwise.
 */
bool sreg_C_compute_bool(uint8_t Rd, uint8_t Rr);

/**
 * @brief Computes the N flag as a boolean value.
 * 
 * @param result The result of the operation.
 * @return true if the N flag should be set, false otherwise.
 */
bool sreg_N_compute_bool(uint8_t result);

/**
 * @brief Computes the V flag as a boolean value.
 * 
 * @param Rd The value of the destination register.
 * @param Rr The value of the source register.
 * @param result The result of the operation.
 * @return true if the V flag should be set, false otherwise.
 */
bool sreg_V_compute_bool(uint8_t Rd, uint8_t Rr, uint8_t result);

/**
 * @brief Computes the S flag as a boolean value.
 * 
 * @param N The value of the N flag.
 * @param V The value of the V flag.
 * @return true if the S flag should be set, false otherwise.
 */
bool sreg_S_compute_bool(bool N, bool V);

/**
 * @brief Computes the C flag as an 8-bit value.
 * 
 * @param Rd The value of the destination register.
 * @param Rr The value of the source register.
 * @return The computed C flag.
 */
uint8_t sreg_C_compute(uint8_t Rd, uint8_t Rr);

/**
 * @brief Computes the Z flag as an 8-bit value.
 * 
 * @param result The result of the operation.
 * @return The computed Z flag.
 */
uint8_t sreg_Z_compute(uint8_t result);

/**
 * @brief Computes the N flag as an 8-bit value.
 * 
 * @param result The result of the operation.
 * @return The computed N flag.
 */
uint8_t sreg_N_compute(uint8_t result);

/**
 * @brief Computes the V flag as an 8-bit value.
 * 
 * @param Rd The value of the destination register.
 * @param Rr The value of the source register.
 * @param result The result of the operation.
 * @return The computed V flag.
 */
uint8_t sreg_V_compute(uint8_t Rd, uint8_t Rr, uint8_t result);

/**
 * @brief Computes the S flag as an 8-bit value.
 * 
 * @param N The value of the N flag.
 * @param V The value of the V flag.
 * @return The computed S flag.
 */
uint8_t sreg_S_compute(bool N, bool V);

/**
 * @brief Computes the H flag as an 8-bit value.
 * 
 * @param Rd The value of the destination register.
 * @param Rr The value of the source register.
 * @return The computed H flag.
 */
uint8_t sreg_H_compute(uint8_t Rd, uint8_t Rr);

/**
 * @brief Updates the Status Register (SREG) for arithmetic operations.
 *
 * This function updates the SREG based on the result of an arithmetic operation.
 *
 * @param core Pointer to the CORE structure.
 * @param Rd The destination register value.
 * @param Rr The source register value.
 * @param result The result of the arithmetic operation.
 */
void update_sreg_arithm(struct CORE *core, uint8_t Rd, uint8_t Rr, uint8_t result);

/**
 * @brief Updates the Status Register (SREG) for logical operations.
 *
 * This function updates the SREG based on the result of a logical operation.
 *
 * @param core Pointer to the CORE structure.
 * @param result The result of the logical operation.
 */
void update_sreg_logic(struct CORE *core, uint8_t result);

/**
 * @brief Update the Carry flag (C) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Carry flag.
 */
void update_sreg_C(struct CORE *core, bool state);

/**
 * @brief Update the Zero flag (Z) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Zero flag.
 */
void update_sreg_Z(struct CORE *core, bool state);

/**
 * @brief Update the Negative flag (N) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Negative flag.
 */
void update_sreg_N(struct CORE *core, bool state);

/**
 * @brief Update the Overflow flag (V) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Overflow flag.
 */
void update_sreg_V(struct CORE *core, bool state);

/**
 * @brief Update the Sign flag (S) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Sign flag.
 */
void update_sreg_S(struct CORE *core, bool state);

/**
 * @brief Update the Half Carry flag (H) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Half Carry flag.
 */
void update_sreg_H(struct CORE *core, bool state);

/**
 * @brief Update the Transfer bit (T) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Transfer bit.
 */
void update_sreg_T(struct CORE *core, bool state);

/**
 * @brief Update the Interrupt flag (I) in the status register.
 * 
 * @param core Pointer to the CORE structure.
 * @param state Boolean state to set the Interrupt flag.
 */
void update_sreg_I(struct CORE *core, bool state);
