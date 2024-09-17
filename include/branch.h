#pragma once
#include <stdint.h>
#include <stdbool.h>

#include "core.h"
#include "sram.h"
#include "data_space.h"

void rjmp(uint8_t k, struct CORE *core);
void ijmp(struct CORE *core);
void jmp(uint32_t k, struct CORE *core);
void rcall(uint8_t k, struct CORE *core, struct SRAM *sram);
void icall(struct CORE *core, struct SRAM *sram);
void eicall(struct CORE *core, struct SRAM *sram);
void ret(struct CORE *core, struct SRAM *sram);
void reti(struct CORE *core, struct SRAM *sram);
void cpse(uint8_t d, uint8_t r, struct CORE *core);
void cp(uint8_t d, uint8_t r, struct CORE *core);
void cpc(uint8_t d, uint8_t r, struct CORE *core);
void cpi(uint8_t d, uint8_t K, struct CORE *core);
void sbrc(uint8_t r, uint8_t b, struct CORE *core);
void sbrs(uint8_t r, uint8_t b, struct CORE *core);
void sbic(uint8_t A, uint8_t b, struct CORE *core, union DATA_SPACE *data_space);
void sbis(uint8_t A, uint8_t b, struct CORE *core, union DATA_SPACE *data_space);
void brbs(uint8_t s, uint8_t k, struct CORE *core);
void brbc(uint8_t s, uint8_t k, struct CORE *core);
void breq(uint8_t k, struct CORE *core);
void brne(uint8_t k, struct CORE *core);
void brcs(uint8_t k, struct CORE *core);
void brcc(uint8_t k, struct CORE *core);
void brsh(uint8_t k, struct CORE *core);
void brlo(uint8_t k, struct CORE *core);
void brmi(uint8_t k, struct CORE *core);
void brpl(uint8_t k, struct CORE *core);
void brge(uint8_t k, struct CORE *core);
void brlt(uint8_t k, struct CORE *core);
void brhs(uint8_t k, struct CORE *core);
void brhc(uint8_t k, struct CORE *core);
void brts(uint8_t k, struct CORE *core);
void brtc(uint8_t k, struct CORE *core);
void brvs(uint8_t k, struct CORE *core);
void brvc(uint8_t k, struct CORE *core);
void brie(uint8_t k, struct CORE *core);
void brid(uint8_t k, struct CORE *core);