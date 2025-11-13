/*
9. Keep Only the Highest Set Bit
You are given a 16-bit register (uint16_t).
Your task is to:

Return a value where only the highest (leftmost) set bit is retained
All other bits must be cleared

Example-1

Input:  44        // Binary: 0000000000101100  
Output: 32        // Binary: 0000000000100000

*/


#include <stdio.h>
#include <stdint.h>

// Complete the function
uint16_t highest_set_bit(uint16_t reg) {
    uint8_t bitPos = 0;
    for(int i = 15; i >=0; i--){
        if((reg & (0x01 << i))){
            bitPos = i;
            break;
        }
    }

    for(int i = bitPos - 1; i >=0; i--){
        reg &= ~(0x01 << i);
    }
    return reg;
}

int main() {
    uint16_t reg;
    scanf("%hu", &reg);

    uint16_t result = highest_set_bit(reg);
    printf("%hu", result);
    return 0;
}