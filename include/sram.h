#pragma once
#include <stdint.h>
#include <stdbool.h>

#define SRAM_SIZE 2048

struct SRAM {
    uint8_t mem[SRAM_SIZE];
};
