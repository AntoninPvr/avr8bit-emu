#include "mcu_control.h"

void break_point(struct CORE *core) {
    // Breakpoint
    // 1 cycle
    return 0;
}

void nop(struct CORE *core) {
    // No operation
    // 1 cycle
    return 0;
}

void sleep(struct CORE *core) {
    // Sleep
    // 1 cycle
    return 0;
}

void wdr(struct CORE *core) {
    // Watchdog Reset
    // 1 cycle
    return 0;
}