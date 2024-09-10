#pragma once
#include <stdint.h>
#include <stdbool.h>

union SREG{
    uint8_t sreg;
    struct {
        bool C: 1; // Carry flag
        bool Z: 1; // Zero flag
        bool N: 1; // Negative flag
        bool V: 1; // Two's complement overflow flag
        bool S: 1; // Sign bit, S = N ^ V
        bool H: 1; // Half carry flag
        bool T: 1; // Transfer bit used by BLD and BST instructions
        bool I: 1; // Global voiderrupt enable/disable flag
    };
};

struct CORE {
    uint8_t R[32]; // 32 8-bit registers
    int32_t PC;
    int16_t SP;
    union SREG sreg;
};

void inc_pc(struct CORE *core);