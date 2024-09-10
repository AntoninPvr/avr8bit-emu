#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

void add(int8_t d, int8_t r, struct CORE *core);
void adc(int8_t d, int8_t r, struct CORE *core);
void sub(int8_t d, int8_t r, struct CORE *core);
void subi(int8_t d, int8_t K, struct CORE *core);
void sbc(int8_t d, int8_t r, struct CORE *core);
void sbci(int8_t d, int8_t K, struct CORE *core);
void and(int8_t d, int8_t r, struct CORE *core);
void andi(int8_t d, int8_t K, struct CORE *core);
void or(int8_t d, int8_t r, struct CORE *core);
void ori(int8_t d, int8_t K, struct CORE *core);
void eor(int8_t d, int8_t r, struct CORE *core);
void com(int8_t d, struct CORE *core);
void neg(int8_t d, struct CORE *core);
void sbr(int8_t d, int8_t K, struct CORE *core);
void cbr(int8_t d, int8_t K, struct CORE *core);
void inc(int8_t d, struct CORE *core);
void dec(int8_t d, struct CORE *core);
void tst(int8_t d, struct CORE *core);
void clr(int8_t d, struct CORE *core);
void ser(int8_t d, struct CORE *core);
void mul(int8_t d, int8_t r, struct CORE *core);
void muls(int8_t d, int8_t r, struct CORE *core);
void mulsu(int8_t d, int8_t r, struct CORE *core);
void fmul(int8_t d, int8_t r, struct CORE *core);
void fmuls(int8_t d, int8_t r, struct CORE *core);
void fmulsu(int8_t d, int8_t r, struct CORE *core);
