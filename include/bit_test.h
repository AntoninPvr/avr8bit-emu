#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

void lsl(int8_t d, struct CORE *core);
void lsr(int8_t d, struct CORE *core);
void rol(int8_t d, struct CORE *core);
void ror(int8_t d, struct CORE *core);
void asr(int8_t d, struct CORE *core);
void swap(int8_t d, struct CORE *core);
void sbi(int8_t IO, int8_t n, struct CORE *core);
void cbi(int8_t IO, int8_t n, struct CORE *core);
void bst(int8_t d, int8_t b, struct CORE *core);
void bld(int8_t d, int8_t b, struct CORE *core);
void bset(int8_t s, struct CORE *core);
void bclr(int8_t s, struct CORE *core);
void sec(struct CORE *core);
void clc(struct CORE *core);
void sen(struct CORE *core);
void cln(struct CORE *core);
void sez(struct CORE *core);
void clz(struct CORE *core);
void sei(struct CORE *core);
void cli(struct CORE *core);
void ses(struct CORE *core);
void cls(struct CORE *core);
void sev(struct CORE *core);
void clv(struct CORE *core);
void set(struct CORE *core);
void clt(struct CORE *core);
void seh(struct CORE *core);
void clh(struct CORE *core);
