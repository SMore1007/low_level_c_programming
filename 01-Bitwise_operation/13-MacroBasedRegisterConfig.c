/*
13. Macro-Based Register Config Helper
In embedded systems, registers are often configured by setting specific bits. To make the code cleaner and reusable, firmware developers use macros to set fields in a register.

You are given a 16-bit control register layout:

Field	Bits	Position (LSB-first)
ENABLE	1	Bit 0
MODE	2	Bits 1–2
SPEED	3	Bits 3–5
RESERVED	2	Bits 6–7 (must be 0)
 

Your task is to:

Write macros to:
 
Set the ENABLE bit
Set the MODE field
Set the SPEED field
Read ENABLE, MODE, SPEED from input
Use the macros to pack a final 16-bit register value
RESERVED bits (6–7) must be left 0

Example-1

Input: enable = 1, mode = 2, speed = 4
Output: 37
(Binary: 0000 0000 0010 0101)

*/


#include <stdio.h>
#include <stdint.h>

// --- Bit Positions ---
#define ENABLE_POS   0
#define MODE_POS     1
#define SPEED_POS    3

// --- Bit Masks ---
#define ENABLE_MASK  (0x01 << ENABLE_POS)   // 1 bit
#define MODE_MASK    (0x03 << MODE_POS)     // 2 bits
#define SPEED_MASK   (0x07 << SPEED_POS)    // 3 bits

// --- Macros to Set Fields ---
#define SET_ENABLE(val)   ((uint16_t)((val & 0x01) << ENABLE_POS))
#define SET_MODE(val)     ((uint16_t)((val & 0x03) << MODE_POS))
#define SET_SPEED(val)    ((uint16_t)((val & 0x07) << SPEED_POS))

uint16_t build_register(uint8_t enable, uint8_t mode, uint8_t speed) {
    uint16_t reg = 0;

    reg |= SET_ENABLE(enable);
    reg |= SET_MODE(mode);
    reg |= SET_SPEED(speed);

    // RESERVED bits (6–7) left as 0
    return reg;
}

int main() {
    uint8_t enable, mode, speed;
    scanf("%hhu %hhu %hhu", &enable, &mode, &speed);

    uint16_t reg = build_register(enable, mode, speed);
    printf("%u", reg);

    return 0;
}
