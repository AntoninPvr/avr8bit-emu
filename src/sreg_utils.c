#include "sreg_utils.h"

bool sreg_H_compute_bool(uint8_t Rd, uint8_t Rr) {
    return ((Rd & 0x0F) + (Rr & 0x0F) > 0x0F);
}

bool sreg_Z_compute_bool(uint8_t result) {
    return (result == 0);
}

bool sreg_C_compute_bool(uint8_t Rd, uint8_t Rr) {
    return ((uint16_t)Rd + (uint16_t)Rr > 0xFF);
}

bool sreg_N_compute_bool(uint8_t result) {
    return (result & 0x80);
}

bool sreg_V_compute_bool(uint8_t Rd, uint8_t Rr, uint8_t result) {
    return ((Rd & Rr & ~result) | (~Rd & ~Rr & result));
}

bool sreg_S_compute_bool(bool N, bool V) {
    return (N ^ V);
}

uint8_t sreg_C_compute(uint8_t Rd, uint8_t Rr) {
    return ((uint16_t)Rd + (uint16_t)Rr > 0xFF);
}

uint8_t sreg_Z_compute(uint8_t result) {
    return (result == 0 ? 2 : 0);
}

uint8_t sreg_N_compute(uint8_t result) {
    return (result & 0x80 ? 4 : 0);
}

uint8_t sreg_V_compute(uint8_t Rd, uint8_t Rr, uint8_t result) {
    return ((Rd & Rr & ~result) | (~Rd & ~Rr & result) ? 8 : 0);
}

uint8_t sreg_S_compute(bool N, bool V) {
    return (N ^ V ? 16 : 0);
}

uint8_t sreg_H_compute(uint8_t Rd, uint8_t Rr) {
    return ((Rd & 0x0F) + (Rr & 0x0F) > 0x0F ? 32 : 0);
}

void update_sreg_arithm(struct CORE *core, uint8_t Rd, uint8_t Rr, uint8_t result) {
    core->sreg.C = sreg_C_compute(Rd, Rr);
    core->sreg.Z = sreg_Z_compute(result);
    core->sreg.N = sreg_N_compute(result);
    core->sreg.V = sreg_V_compute(Rd, Rr, result);
    core->sreg.S = sreg_S_compute(core->sreg.N, core->sreg.V);
    core->sreg.H = sreg_H_compute(Rd, Rr);
}

void update_sreg_C(struct CORE *core, bool state) {
    core->sreg.C = state;
}

void update_sreg_Z(struct CORE *core, bool state) {
    core->sreg.Z = state;
}

void update_sreg_N(struct CORE *core, bool state) {
    core->sreg.N = state;
}

void update_sreg_V(struct CORE *core, bool state) {
    core->sreg.V = state;
}

void update_sreg_S(struct CORE *core, bool state) {
    core->sreg.S = state;
}

void update_sreg_H(struct CORE *core, bool state) {
    core->sreg.H = state;
}

void update_sreg_T(struct CORE *core, bool state) {
    core->sreg.T = state;
}

void update_sreg_I(struct CORE *core, bool state) {
    core->sreg.I = state;
}