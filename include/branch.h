#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "cpu.h"

int rjmp(int8_t k, struct CPU *cpu);
int ijmp(struct CPU *cpu);