#pragma once

#include <stdint.h>

#include "core.h"
#include "data_space.h"

bool skip_next_instruction = false;

struct AVR_EMU {
    struct CORE core;
    union DATA_SPACE data_space;
    union PROGMEM_SPACE progmem_space;
};