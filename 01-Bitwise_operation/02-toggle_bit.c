/*

2. Bit Toggle
Write a C program to toggle the 5th bit (0-based index) of a given integer.

The program should take an integer N as input.
It should toggle the 5th bit of N (i.e., flip the bit at position 5: if 0, make it 1; if 1, make it 0).
Note: The 5th bit is at position 5(0-based indexing). For example, in the binary number 100100, the 5th bit is 1.

 

Example

Input: 10
Explanation:
Binary representation of 10 is 00001010.
Toggling the 5th bit (position 5) results in 00101010, which is 42 in decimal.
Expected Output: 42
 
*/

#include <stdio.h>
#include <stdint.h>

uint8_t toggleBit(uint8_t Reg){
    return Reg ^= (0x01 << 5);
}


int main(){
    uint8_t Reg;
    printf("Enter reg value: ");
    scanf("%x", &Reg);
    printf("After Toggle: %x", toggleBit(Reg));
    return 0;
}