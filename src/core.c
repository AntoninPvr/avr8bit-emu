#include "core.h"

void inc_pc(struct CORE *core) {
    core->PC = core->PC + 1;
}
