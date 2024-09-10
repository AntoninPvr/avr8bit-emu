#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

void rjmp(int8_t k, struct CORE *core);
void ijmp(struct CORE *core);
void jmp(int32_t k, struct CORE *core);