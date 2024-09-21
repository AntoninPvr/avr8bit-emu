#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

/**
 * @brief Triggers a breakpoint in the MCU emulator.
 * 
 * This function is used to simulate a breakpoint in the MCU emulator,
 * halting execution for debugging purposes.
 * 
 * Currently, this function does nothing.
 * 
 * @param core Pointer to the CORE structure representing the MCU state.
 */
void break_point(struct CORE *core);

/**
 * @brief Executes a no-operation instruction.
 * 
 * This function simulates the execution of a NOP (no operation) instruction,
 * which does nothing and simply advances the program counter.
 * 
 * Currently, this function does nothing.
 * 
 * @param core Pointer to the CORE structure representing the MCU state.
 */
void nop(struct CORE *core);

/**
 * @brief Puts the MCU into sleep mode.
 * 
 * This function simulates putting the MCU into a low-power sleep mode,
 * reducing power consumption until an interrupt occurs.
 * 
 * Currently, this function does nothing.
 * 
 * @param core Pointer to the CORE structure representing the MCU state.
 */
void sleep(struct CORE *core);

/**
 * @brief Resets the watchdog timer.
 * 
 * This function simulates resetting the watchdog timer, preventing the
 * MCU from resetting due to a watchdog timeout.
 * 
 * Currently, this function does nothing.
 * 
 * @param core Pointer to the CORE structure representing the MCU state.
 */
void wdr(struct CORE *core);