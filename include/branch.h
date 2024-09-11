#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"
#include "sram.h"

void rjmp(uint8_t k, struct CORE *core);
void ijmp(struct CORE *core);
void jmp(uint32_t k, struct CORE *core);
void rcall(uint8_t k, struct CORE *core, struct SRAM *sram);
void icall(struct CORE *core, struct SRAM *sram);