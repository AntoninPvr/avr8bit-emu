#pragma once

#include <stdint.h>
#include <stdbool.h>

#define DATA_SPACE_SIZE 0x8FF
#define PROGMEM_SPACE_SIZE 0x10000

/**
 * @union DATA_SPACE
 * @brief Represents the data space in the AVR emulator.
 */
union DATA_SPACE {
    uint8_t data[DATA_SPACE_SIZE]; /**< Too big for stack */
    struct {
        uint8_t gp[32]; /**< General purpose registers, not shared with GP in CORE */
        uint8_t io_reg[64]; /**< I/O registers */
        uint8_t ext_io_reg[160]; /**< Extended I/O registers */
        uint8_t sram[2048]; /**< SRAM, not shared with SRAM */
    };
};

/**
 * @union PROGMEM_SPACE
 * @brief Represents the program memory space in the AVR emulator.
 */
union PROGMEM_SPACE {
    uint8_t data[PROGMEM_SPACE_SIZE]; /**< Byte-wise access to program memory */
    uint16_t word[PROGMEM_SPACE_SIZE / 2]; /**< Word-wise access to program memory */
};

