/*

10. Bit Operations using Macros
In embedded systems, modifying specific bits of control or status registers is a frequent task. You’re given an 8-bit register (uint8_t) and must perform the following bit operations on it:

Set bits 2 and 7
Clear bit 3
Toggle bit 5
Your task is to implement a function that:

Accepts a uint8_t reg as input
Applies all the above operations in the given order
Returns the updated register value
Use proper bitwise macros for maintainability.

*/

#include <stdio.h>
#include <stdint.h>

// Define bitwise macros here
#define SET_BIT(REG, POS) ((REG) |= (0x01 << (POS)))
#define CLEAR_BIT(REG, POS) ((REG) &= (~(0x01 << (POS))));
#define TOGGLE_BIT(REG, POS) ((REG) ^= (0x01 << (POS)));

uint8_t modify_register(uint8_t reg) {
    // Apply operations in order
    SET_BIT(reg, 2);
    SET_BIT(reg, 7);
    CLEAR_BIT(reg, 3);
    TOGGLE_BIT(reg, 5);
    return reg;
}

int main() {
    uint8_t reg;
    scanf("%hhu", &reg);
    printf("%u", modify_register(reg));
    return 0;
}
