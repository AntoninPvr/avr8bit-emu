#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"
#include "sreg_utils.h"

void add(uint8_t d, uint8_t r, struct CORE *core);
void adc(uint8_t d, uint8_t r, struct CORE *core);
void adiw(uint8_t d, uint8_t K, struct CORE *core);
void sub(uint8_t d, uint8_t r, struct CORE *core);
void subi(uint8_t d, uint8_t K, struct CORE *core);
void sbc(uint8_t d, uint8_t r, struct CORE *core);
void sbci(uint8_t d, uint8_t K, struct CORE *core);
void sbiw(uint8_t d, uint8_t K, struct CORE *core);
void and(uint8_t d, uint8_t r, struct CORE *core);
void andi(uint8_t d, uint8_t K, struct CORE *core);
void or(uint8_t d, uint8_t r, struct CORE *core);
void ori(uint8_t d, uint8_t K, struct CORE *core);
void eor(uint8_t d, uint8_t r, struct CORE *core);
void com(uint8_t d, struct CORE *core);
void neg(uint8_t d, struct CORE *core);
void sbr(uint8_t d, uint8_t K, struct CORE *core);
void cbr(uint8_t d, uint8_t K, struct CORE *core);
void inc(uint8_t d, struct CORE *core);
void dec(uint8_t d, struct CORE *core);
void tst(uint8_t d, struct CORE *core);
void clr(uint8_t d, struct CORE *core);
void ser(uint8_t d, struct CORE *core);
void mul(uint8_t d, uint8_t r, struct CORE *core);
void muls(uint8_t d, uint8_t r, struct CORE *core);
void mulsu(uint8_t d, uint8_t r, struct CORE *core);
void fmul(uint8_t d, uint8_t r, struct CORE *core);
void fmuls(uint8_t d, uint8_t r, struct CORE *core);
void fmulsu(uint8_t d, uint8_t r, struct CORE *core);
