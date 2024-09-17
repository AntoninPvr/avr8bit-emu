#pragma once

#include <stdint.h>
#include <stdbool.h>

#define DATA_SPACE_SIZE 0x8FF
#define PROGMEM_SPACE_SIZE 0x10000

union DATA_SPACE {
    uint8_t data[DATA_SPACE_SIZE]; // too big for stack
    struct {
        uint8_t gp[32]; // not shared with GP in CORE
        uint8_t io_reg[64];
        uint8_t ext_io_reg[160];
        uint8_t sram[2048]; // not shared with SRAM
    };
};

union PROGMEM_SPACE {
    uint8_t data[PROGMEM_SPACE_SIZE];
    uint16_t word[PROGMEM_SPACE_SIZE / 2];
};
