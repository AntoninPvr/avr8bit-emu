#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

void mov(int8_t d, int8_t r, struct CORE *core);
void movw(int8_t d, int8_t r, struct CORE *core);
void ldi(int8_t d, int8_t K, struct CORE *core);
void lds(int8_t d, int16_t k, struct CORE *core);
void ld_x(int8_t d, struct CORE *core);
void ld_x_inc(int8_t d, struct CORE *core);
void ld_x_dec(int8_t d, struct CORE *core);
void ld_y(int8_t d, struct CORE *core);
void ld_y_inc(int8_t d, struct CORE *core);
void ld_y_dec(int8_t d, struct CORE *core);
void ldd_y(int8_t d, int8_t q, struct CORE *core);
void ld_z(int8_t d, struct CORE *core);
void ld_z_inc(int8_t d, struct CORE *core);
void ld_z_dec(int8_t d, struct CORE *core);
void ldd_z(int8_t d, int8_t q, struct CORE *core);
void sts(int16_t k, int8_t d, struct CORE *core);
void st_x(int8_t d, struct CORE *core);
void st_x_inc(int8_t d, struct CORE *core);
void st_x_dec(int8_t d, struct CORE *core);
void st_y(int8_t d, struct CORE *core);
void st_y_inc(int8_t d, struct CORE *core);
void st_y_dec(int8_t d, struct CORE *core);
void std_y(int8_t d, int8_t q, struct CORE *core);
void st_z(int8_t d, struct CORE *core);
void st_z_inc(int8_t d, struct CORE *core);
void st_z_dec(int8_t d, struct CORE *core);
void std_z(int8_t d, int8_t q, struct CORE *core);
void lpm_0(struct CORE *core);
void lpm_z(int8_t d, struct CORE *core);
void lpm_z_inc(int8_t d, struct CORE *core);
void in(int8_t d, int8_t A, struct CORE *core);
void out(int8_t A, int8_t r, struct CORE *core);
void push(int8_t d, struct CORE *core);
void pop(int8_t d, struct CORE *core);
void xch(int8_t d, struct CORE *core);
void las(int8_t d, struct CORE *core);
void lac(int8_t d, struct CORE *core);
void lat(int8_t d, struct CORE *core);
