# AVR-EMU

Simple avr emulator 

**Work in progress**
This project is still in development and not ready for use. Not all instructions are implemented yet. There are still large amounts of potentials flaws and bugs.

## Implemented

Core:

- 32 8bit General purpose register
- SREG flags register
- 16bit SP stack pointer
- 16bit PC program counter

- SRAM memory

## Arithmetic and logic instructions

| mnemonic | description | status |
| --- | --- | --- |
| `ADC` | Add with carry | ❌ |
| `ADD` | Add without carry | ❌ |
| `ADIW` | Add immediate to word | ❌ |
| `SUB` | Subtract without carry | ❌ |
| `SUBI` | Subtract immediate | ❌ |
| `SBC` | Subtract with carry | ❌ |
| `SBCI` | Subtract immediate with carry | ❌ |
| `SBIW` | Subtract immediate from word | ❌ |
| `AND` | Logical AND | ❌ |
| `ANDI` | Logical AND with immediate | ❌ |
| `OR` | Logical OR | ❌ |
| `ORI` | Logical OR with immediate | ❌ |
| `EOR` | Logical Exclusive OR | ❌ |
| `COM` | One's complement | ❌ |
| `NEG` | Two's complement | ❌ |
| `SBR` | Set bits in register | ❌ |
| `CBR` | Clear bits in register | ❌ |
| `INC` | Increment | ❌ |
| `DEC` | Decrement | ❌ |
| `TST` | Test for zero or minus | ❌ |
| `CLR` | Clear register | ❌ |
| `SER` | Set all bits in register | ❌ |
| `MUL` | Multiply unsigned | ❌ |
| `MULS` | Multiply signed | ❌ |
| `MULSU` | Multiply signed with unsigned | ❌ |
| `FMUL` | Fractional multiply unsigned | ❌ |
| `FMULS` | Fractional multiply signed | ❌ |
| `FMULSU` | Fractional multiply signed with unsigned | ❌ |
| `DES` | Data encryption | ❌ |

## Branch instruction

| mnemonic | description | status |
| --- | --- | --- |
| `RJMP` | Relative jump | ❌ |
| `IJMP` | Indirect jump | ❌ |
| `EIJMP` | Extended indirect jump | ❌ |
| `JMP` | Jump | ❌ |
| `RCALL` | Relative call subroutine | ❌ |
| `ICALL` | Indirect call subroutine | ❌ |
| `EICALL` | Extended indirect call subroutine | ❌ |
| `CALL` | Call subroutine | ❌ |
| `RET` | Return from subroutine | ❌ |
| `RETI` | Return from interrupt | ❌ |
| `CPSE` | Compare, skip if equal | ❌ |
| `CP` | Compare | ❌ |
| `CPC` | Compare with carry | ❌ |
| `CPI` | Compare with immediate | ❌ |
| `SBRC` | Skip if bit in register cleared | ❌ |
| `SBRS` | Skip if bit in register set | ❌ |
| `SBIC` | Skip if bit in I/O register cleared | ❌ |
| `SBIS` | Skip if bit in I/O register set | ❌ |
| `BRBS` | Branch if status flag set | ❌ |
| `BRBC` | Branch if status flag cleared | ❌ |
| `BREQ` | Branch if equal | ❌ |
| `BRNE` | Branch if not equal | ❌ |
| `BRCS` | Branch if carry set | ❌ |
| `BRCC` | Branch if carry cleared | ❌ |
| `BRSH` | Branch if same or higher | ❌ |
| `BRLO` | Branch if lower | ❌ |
| `BRMI` | Branch if minus | ❌ |
| `BRPL` | Branch if plus | ❌ |
| `BRGE` | Branch if greater or equal (signed) | ❌ |
| `BRLT` | Branch if less than (signed) | ❌ |
| `BRHS` | Branch if half carry or carry set | ❌ |
| `BRHC` | Branch if half carry or carry cleared | ❌ |
| `BRTS` | Branch if T flag set | ❌ |
| `BRTC` | Branch if T flag cleared | ❌ |
| `BRVS` | Branch if overflow set | ❌ |
| `BRVC` | Branch if overflow cleared | ❌ |
| `BRIE` | Branch if interrupt enabled | ❌ |
| `BRID` | Branch if interrupt disabled | ❌ |

## Data transfer instructions

| mnemonic | description | status |
| --- | --- | --- |
| `MOV` | Copy register | ❌ |
| `MOVW` | Copy register pair | ❌ |
| `LDI` | Load immediate | ❌ |
| `LDS` | Load direct from data space | ❌ |
| `LD` | Load indirect from data space | ❌ |
| `LDD` | Load indirect with displacement | ❌ |
| `STS` | Store direct to data space | ❌ |
| `ST` | Store indirect to data space | ❌ |

## Bit and bit-test instructions

| mnemonic | description | status |
| --- | --- | --- |
| `LSL` | Logical shift left | ❌ |
| `LSR` | Logical shift right | ❌ |
| `ROL` | Rotate left through carry | ❌ |
| `ROR` | Rotate right through carry | ❌ |
| `ASR` | Arithmetic shift right | ❌ |
| `SWAP` | Swap nibbles | ❌ |
| `SBI` | Set bit in I/O register | ❌ |
| `CBI` | Clear bit in I/O register | ❌ |
| `BST` | Bit store from register to T | ❌ |
| `BLD` | Bit load from T to register | ❌ |
| `BSET` | Flag set | ❌ |
| `BCLR` | Flag clear | ❌ |
| `SEC` | Set carry flag | ❌ |
| `CLC` | Clear carry flag | ❌ |
| `SEN` | Set negative flag | ❌ |
| `CLN` | Clear negative flag | ❌ |
| `SEZ` | Set zero flag | ❌ |
| `CLZ` | Clear zero flag | ❌ |
| `SEI` | Set interrupt flag | ❌ |
| `CLI` | Clear interrupt flag | ❌ |
| `SES` | Set signed flag | ❌ |
| `CLS` | Clear signed flag | ❌ |
| `SEV` | Set overflow flag | ❌ |
| `CLV` | Clear overflow flag | ❌ |
| `SET` | Set T flag | ❌ |
| `CLT` | Clear T flag | ❌ |
| `SEH` | Set half carry flag | ❌ |
| `CLH` | Clear half carry flag | ❌ |

## MCU control instructions

| mnemonic | description | status |
| --- | --- | --- |
| `BREAK` | Break | ✅ |
| `NOP` | No operation | ✅ |
| `SLEEP` | Sleep | ❌ |
| `WDR` | Watchdog reset | ❌ |