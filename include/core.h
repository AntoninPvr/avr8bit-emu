#pragma once
#include <stdint.h>
#include <stdbool.h>

union SREG{
    uint8_t sreg;
    struct {
        bool C: 1; // Cary flag
        bool Z: 1; // Zero flag
        bool N: 1; // Negative flag
        bool V: 1; // Two's complement overflow flag
        bool S: 1; // Sign bit, S = N ^ V
        bool H: 1; // Half cary flag
        bool T: 1; // Transfer bit used by BLD and BST instructions
        bool I: 1; // Global voiderupt enable/disable flag
    };
};

union GP {
    uint8_t R[32];
    struct {
        uint8_t R0;
        uint8_t R1;
        uint8_t R2;
        uint8_t R3;
        uint8_t R4;
        uint8_t R5;
        uint8_t R6;
        uint8_t R7;
        uint8_t R8;
        uint8_t R9;
        uint8_t R10;
        uint8_t R11;
        uint8_t R12;
        uint8_t R13;
        uint8_t R14;
        uint8_t R15;
        uint8_t R16;
        uint8_t R17;
        uint8_t R18;
        uint8_t R19;
        uint8_t R20;
        uint8_t R21;
        uint8_t R22;
        uint8_t R23;
        uint8_t R24;
        uint8_t R25;
        uint16_t X;
        uint16_t Y;
        uint16_t Z;
    };
};

struct CORE {
    union GP gp;    // general purpose registers
    uint32_t PC;
    uint16_t SP;
    union SREG sreg;
};

void inc_pc(struct CORE *core);
