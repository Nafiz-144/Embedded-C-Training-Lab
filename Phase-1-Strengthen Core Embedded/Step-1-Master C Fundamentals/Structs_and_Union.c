// reg_map_example.c
#include <stdio.h>
#include <stdint.h>

typedef union {
    uint32_t reg;
    struct {
        uint32_t enable  : 1;
        uint32_t mode    : 2;
        uint32_t prescale: 5;
        uint32_t reserved: 24;
    } bits;
} TIMER_CTRL_t;

int main(void){
    TIMER_CTRL_t ctrl;
    ctrl.reg = 0; // clear
    ctrl.bits.enable = 1;
    ctrl.bits.mode = 2;
    ctrl.bits.prescale = 10;
    printf("reg = 0x%08X\n", (unsigned)ctrl.reg);
    return 0;
}
