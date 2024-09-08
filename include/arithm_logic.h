#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "cpu.h"

int add(int8_t Rd, int8_t Rr, struct CPU *cpu);
int adc(int8_t Rd, int8_t Rr, struct CPU *cpu);
int sub(int8_t Rd, int8_t Rr, struct CPU *cpu);
int subi(int8_t Rd, int8_t K, struct CPU *cpu);
int sbc(int8_t Rd, int8_t Rr, struct CPU *cpu);
int sbci(int8_t Rd, int8_t K, struct CPU *cpu);
int and(int8_t Rd, int8_t Rr, struct CPU *cpu);
int andi(int8_t Rd, int8_t K, struct CPU *cpu);
int or(int8_t Rd, int8_t Rr, struct CPU *cpu);
int ori(int8_t Rd, int8_t K, struct CPU *cpu);
int eor(int8_t Rd, int8_t Rr, struct CPU *cpu);
int com(int8_t Rd, struct CPU *cpu);
int neg(int8_t Rd, struct CPU *cpu);
int sbr(int8_t Rd, int8_t K, struct CPU *cpu);
int cbr(int8_t Rd, int8_t K, struct CPU *cpu);
int inc(int8_t Rd, struct CPU *cpu);
int dec(int8_t Rd, struct CPU *cpu);
int tst(int8_t Rd, struct CPU *cpu);
int clr(int8_t Rd, struct CPU *cpu);
int ser(int8_t Rd, struct CPU *cpu);
int mul(int8_t Rd, int8_t Rr, struct CPU *cpu);
int muls(int8_t Rd, int8_t Rr, struct CPU *cpu);
int mulsu(int8_t Rd, int8_t Rr, struct CPU *cpu);
int fmul(int8_t Rd, int8_t Rr, struct CPU *cpu);
int fmuls(int8_t Rd, int8_t Rr, struct CPU *cpu);
int fmulsu(int8_t Rd, int8_t Rr, struct CPU *cpu);