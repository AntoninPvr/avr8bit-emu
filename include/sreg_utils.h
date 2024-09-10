#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

bool sreg_H_compute_bool(uint8_t Rd, uint8_t Rr);
bool sreg_Z_compute_bool(uint8_t result);
bool sreg_C_compute_bool(uint8_t Rd, uint8_t Rr);
bool sreg_N_compute_bool(uint8_t result);
bool sreg_V_compute_bool(uint8_t Rd, uint8_t Rr, uint8_t result);
bool sreg_S_compute_bool(bool N, bool V);
uint8_t sreg_C_compute(uint8_t Rd, uint8_t Rr);
uint8_t sreg_Z_compute(uint8_t result);
uint8_t sreg_N_compute(uint8_t result);
uint8_t sreg_V_compute(uint8_t Rd, uint8_t Rr, uint8_t result);
uint8_t sreg_S_compute(bool N, bool V);
uint8_t sreg_H_compute(uint8_t Rd, uint8_t Rr);
