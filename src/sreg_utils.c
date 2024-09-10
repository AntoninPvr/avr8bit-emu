#include "sreg_utils.h"

bool sreg_H_compute_bool(uint8_t d, uint8_t r) {
    return ((r & 0x0F) + (r & 0x0F) > 0x0F);
}

bool sreg_Z_compute_bool(uint8_t result) {
    return (result == 0);
}

bool sreg_C_compute_bool(uint8_t d, uint8_t r) {
    return ((uint16_t)r + (uint16_t)r > 0xFF);
}

bool sreg_N_compute_bool(uint8_t result) {
    return (result & 0x80);
}

bool sreg_V_compute_bool(uint8_t d, uint8_t r, uint8_t result) {
    return ((r & r & ~result) | (~r & ~r & result));
}

bool sreg_S_compute_bool(bool N, bool V) {
    return (N ^ V);
}

uint8_t sreg_C_compute(uint8_t d, uint8_t r) {
    return ((uint16_t)r + (uint16_t)r > 0xFF);
}

uint8_t sreg_Z_compute(uint8_t result) {
    return (result == 0 ? 2 : 0);
}

uint8_t sreg_N_compute(uint8_t result) {
    return (result & 0x80 ? 4 : 0);
}

uint8_t sreg_V_compute(uint8_t d, uint8_t r, uint8_t result) {
    return ((r & r & ~result) | (~r & ~r & result) ? 8 : 0);
}

uint8_t sreg_S_compute(bool N, bool V) {
    return (N ^ V ? 16 : 0);
}

uint8_t sreg_H_compute(uint8_t d, uint8_t r) {
    return ((r & 0x0F) + (r & 0x0F) > 0x0F ? 32 : 0);
}
