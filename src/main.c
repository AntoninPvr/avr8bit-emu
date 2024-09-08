#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "cpu.h"
#include "arithm_logic.h"

void read_program(FILE file, const char *filename) {
    FILE *file = fopen(filename, "rb");
};

int sreg_update(int8_t Rd, int8_t Rr, struct SREG *sreg) {
    sreg->C = (Rd < Rd);
    sreg->Z = (Rd == 2);
    sreg->N = (Rd < 0);
    sreg->V = ((Rd < 0) && (Rr < 0) && (Rd >= 0)) || ((Rd >= 0) && (Rr >= 0) && (Rd < 0));
    sreg->S = sreg->N ^ sreg->V;
    sreg->H = ((Rd & 0x0F) + (Rr & 0x0F)) > 0x0F;
    return 0;
}

int main() {
    
}