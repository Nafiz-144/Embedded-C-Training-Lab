// bitwise_demo.c
#include <stdio.h>
#include <stdint.h>

void print8(uint8_t v){
    for(int i=7;i>=0;i--) putchar((v>>i)&1 ? '1' : '0');
}

int main(void){
    uint8_t a = 0x5A; // 01011010
    uint8_t b = 0x3C; // 00111100

    printf("a = 0x%02X  ", a); print8(a); putchar('\n');
    printf("b = 0x%02X  ", b); print8(b); putchar('\n');

    printf("a & b = 0x%02X  ", (uint8_t)(a & b)); print8(a & b); putchar('\n');
    printf("a | b = 0x%02X  ", (uint8_t)(a | b)); print8(a | b); putchar('\n');
    printf("a ^ b = 0x%02X  ", (uint8_t)(a ^ b)); print8(a ^ b); putchar('\n');
    printf("~a    = 0x%02X  ", (uint8_t)(~a)); print8((uint8_t)~a); putchar('\n');

    // Mask usage
    uint8_t mask = (1<<3); // bit-3 mask
    printf("set bit3: a | mask = 0x%02X\n", (uint8_t)(a | mask));
    printf("clear bit3: a & ~mask = 0x%02X\n", (uint8_t)(a & ~mask));
    printf("toggle bit3: a ^ mask = 0x%02X\n", (uint8_t)(a ^ mask));

    return 0;
}
