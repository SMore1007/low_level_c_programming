/*

Extract Even Bits Only from 32-bit Register
From a 32-bit register, extract all even-positioned bits (0, 2, 4, …, 30).
Return the compressed value formed by only these bits (shifted to be consecutive).

Example 1

Input: reg = 0b0101 0101 
Output: 0b1111

*/

#include <stdio.h>
#include <stdint.h>

uint32_t extract_even_bits(uint32_t reg){
    
    // create a mask with 1s in even position
    uint32_t mask = 0;
    for(int i = 0; i < 32; i+= 2){
        mask |= (0x1 << i);
    }

    // Apply mask to extract even position bits
    uint32_t filter = reg & mask;

    // compress the even bits (to remove the gaps)
    uint32_t result = 0;
    int k = 0;
    for(int i = 0; i < 32; i+= 2){
        uint32_t bit = (filter >> i) & 1U;
        result |= (bit << k);
        k++;
    }
}