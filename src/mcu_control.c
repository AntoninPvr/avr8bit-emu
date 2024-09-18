#include "mcu_control.h"

/**
 * @brief Breakpoint
 * @param core Pointer to the CORE structure
 * @return 0
 */
void break_point(struct CORE *core) {
}

void nop(struct CORE *core) {
    // No operation
    // 1 cycle
}

void sleep(struct CORE *core) {
    // Sleep
    // 1 cycle
}

void wdr(struct CORE *core) {
    // Watchdog Reset
    // 1 cycle
}