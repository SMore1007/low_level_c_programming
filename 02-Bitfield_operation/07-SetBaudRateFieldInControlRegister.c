/*

Set Baud Rate Field in Control Register
You are working with a 32-bit UART control register. The baud rate is controlled by 4 bits located at position 8 (i.e., bits 8 to 11). 
Write a function to update the baud rate field with a new 4-bit value. All other bits in the register must remain unchanged.


Example 1

Input: reg = 0b0000 0000 0000 0000 0000 0000 0000 0000, baud = 0b1010  
Output: 0b0000 0000 0000 0000 0000 1010 0000 0000

*/

#include <stdio.h>
#include <stdint.h>

uint32_t set_baud_rate(uint32_t reg, uint8_t baud) {
    // clear that 4 bits first 
    reg &= ~(0xF << 8);
    // assign the baud value to the reg from the 8th bit position
    reg |= (baud << 8);
    return reg;
}

int main() {
    uint32_t reg;
    uint8_t baud;
    scanf("%u %hhu", &reg, &baud);
    printf("%u", set_baud_rate(reg, baud));
    return 0;
}