/*

Write a C program to extract a nibble (4-bit value) from an 8-bit register.

The user provides an 8-bit integer (register value) and a nibble position (0 for lower nibble, 1 for upper nibble).
Your task is to extract and print the nibble’s decimal value.
Input Format

An 8-bit integer (0-255) representing the register value.
A nibble position (0 for lower, 1 for upper).
Output Format

The extracted 4-bit value (0-15).


Example-1

Input: reg = 0xAB, pos = 0
Output: 11
(0xAB → lower nibble = 0xB = 11)

*/


#include <stdio.h>
#include <stdint.h>

unsigned char extractNibble(unsigned char reg, int pos)
{
    uint8_t nibble;
    if(pos == 0){
       nibble  = (reg & 0x0F);
    }else{
        nibble = (reg & 0xF0) >> 4;
    }
    return nibble;
}

int main()
{
    unsigned char reg;
    int pos;
    scanf("%hhu %d", &reg, &pos);
    printf("%d", extractNibble(reg, pos));
    return 0;
}