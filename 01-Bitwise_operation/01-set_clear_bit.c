#include <stdio.h>
#include <stdint.h>

uint8_t modifyBit(uint8_t reg, int pos, int mode){
    if(mode == 1){
        reg |= (0x1U << pos);
    }else{
        reg &= ~(0x1U << pos);
    }
    return reg;
}

int main()
{
    uint8_t reg;
    int pos, mode;
    scanf("%hhu %d %d", &reg, &pos, &mode);
    printf("%d", modifyBit(reg, pos, mode));
    return 0;
}