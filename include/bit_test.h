#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

void lsl(uint8_t d, struct CORE *core);
void lsr(uint8_t d, struct CORE *core);
void rol(uint8_t d, struct CORE *core);
void ror(uint8_t d, struct CORE *core);
void asr(uint8_t d, struct CORE *core);
void swap(uint8_t d, struct CORE *core);
void sbi(uint8_t IO, uint8_t n, struct CORE *core);
void cbi(uint8_t IO, uint8_t n, struct CORE *core);
void bst(uint8_t d, uint8_t b, struct CORE *core);
void bld(uint8_t d, uint8_t b, struct CORE *core);
void bset(uint8_t s, struct CORE *core);
void bclr(uint8_t s, struct CORE *core);
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
