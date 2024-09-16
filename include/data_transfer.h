#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"
#include "data_space.h"

void mov(uint8_t d, uint8_t r, struct CORE *core);
void movw(uint8_t d, uint8_t r, struct CORE *core);
void ldi(uint8_t d, uint8_t K, struct CORE *core);
void lds(uint8_t d, int16_t k, struct CORE *core, union DATA_SPACE *data_space);
void ld_x(uint8_t d, struct CORE *core, union DATA_SPACE *data_space);
void ld_x_inc(uint8_t d, struct CORE *core);
void ld_x_dec(uint8_t d, struct CORE *core);
void ld_y(uint8_t d, struct CORE *core);
void ld_y_inc(uint8_t d, struct CORE *core);
void ld_y_dec(uint8_t d, struct CORE *core);
void ldd_y(uint8_t d, uint8_t q, struct CORE *core);
void ld_z(uint8_t d, struct CORE *core);
void ld_z_inc(uint8_t d, struct CORE *core);
void ld_z_dec(uint8_t d, struct CORE *core);
void ldd_z(uint8_t d, uint8_t q, struct CORE *core);
void sts(int16_t k, uint8_t d, struct CORE *core);
void st_x(uint8_t d, struct CORE *core);
void st_x_inc(uint8_t d, struct CORE *core);
void st_x_dec(uint8_t d, struct CORE *core);
void st_y(uint8_t d, struct CORE *core);
void st_y_inc(uint8_t d, struct CORE *core);
void st_y_dec(uint8_t d, struct CORE *core);
void std_y(uint8_t d, uint8_t q, struct CORE *core);
void st_z(uint8_t d, struct CORE *core);
void st_z_inc(uint8_t d, struct CORE *core);
void st_z_dec(uint8_t d, struct CORE *core);
void std_z(uint8_t d, uint8_t q, struct CORE *core);
void lpm_0(struct CORE *core);
void lpm_z(uint8_t d, struct CORE *core);
void lpm_z_inc(uint8_t d, struct CORE *core);
void in(uint8_t d, uint8_t A, struct CORE *core);
void out(uint8_t A, uint8_t r, struct CORE *core);
void push(uint8_t d, struct CORE *core);
void pop(uint8_t d, struct CORE *core);
void xch(uint8_t d, struct CORE *core);
void las(uint8_t d, struct CORE *core);
void lac(uint8_t d, struct CORE *core);
void lat(uint8_t d, struct CORE *core);
