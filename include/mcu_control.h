#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

void break_point(struct CORE *core);
void nop(struct CORE *core);
void sleep(struct CORE *core);
void wdr(struct CORE *core);