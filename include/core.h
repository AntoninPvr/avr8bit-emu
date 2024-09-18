#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * @union SREG
 * @brief Status Register
 */
union SREG {
    uint8_t sreg; /**< Status register as a single byte */
    struct {
        bool C: 1; /**< Carry flag */
        bool Z: 1; /**< Zero flag */
        bool N: 1; /**< Negative flag */
        bool V: 1; /**< Two's complement overflow flag */
        bool S: 1; /**< Sign bit, S = N ^ V */
        bool H: 1; /**< Half carry flag */
        bool T: 1; /**< Transfer bit used by BLD and BST instructions */
        bool I: 1; /**< Global interrupt enable/disable flag */
    };
};

/**
 * @union GP
 * @brief General Purpose Registers
 */
union GP {
    uint8_t R[32]; /**< General purpose registers as an array */
    struct {
        uint8_t R0;  /**< General purpose register 0 */
        uint8_t R1;  /**< General purpose register 1 */
        uint8_t R2;  /**< General purpose register 2 */
        uint8_t R3;  /**< General purpose register 3 */
        uint8_t R4;  /**< General purpose register 4 */
        uint8_t R5;  /**< General purpose register 5 */
        uint8_t R6;  /**< General purpose register 6 */
        uint8_t R7;  /**< General purpose register 7 */
        uint8_t R8;  /**< General purpose register 8 */
        uint8_t R9;  /**< General purpose register 9 */
        uint8_t R10; /**< General purpose register 10 */
        uint8_t R11; /**< General purpose register 11 */
        uint8_t R12; /**< General purpose register 12 */
        uint8_t R13; /**< General purpose register 13 */
        uint8_t R14; /**< General purpose register 14 */
        uint8_t R15; /**< General purpose register 15 */
        uint8_t R16; /**< General purpose register 16 */
        uint8_t R17; /**< General purpose register 17 */
        uint8_t R18; /**< General purpose register 18 */
        uint8_t R19; /**< General purpose register 19 */
        uint8_t R20; /**< General purpose register 20 */
        uint8_t R21; /**< General purpose register 21 */
        uint8_t R22; /**< General purpose register 22 */
        uint8_t R23; /**< General purpose register 23 */
        uint8_t R24; /**< General purpose register 24 */
        uint8_t R25; /**< General purpose register 25 */
        uint16_t X;  /**< Register pair X (R26:R27) */
        uint16_t Y;  /**< Register pair Y (R28:R29) */
        uint16_t Z;  /**< Register pair Z (R30:R31) */
    };
};

/**
 * @struct CORE
 * @brief Core structure containing general purpose registers, program counter, stack pointer, and status register.
 */
struct CORE {
    union GP gp;    /**< General purpose registers */
    uint32_t PC;    /**< Program counter */
    uint16_t SP;    /**< Stack pointer */
    union SREG sreg; /**< Status register */
};

void inc_pc(struct CORE *core);