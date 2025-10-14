// sizes_example.c
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void) {
    printf("sizeof(uint8_t)  = %zu\n", sizeof(uint8_t));
    printf("sizeof(int8_t)   = %zu\n", sizeof(int8_t));
    printf("sizeof(uint16_t) = %zu\n", sizeof(uint16_t));
    printf("sizeof(int32_t)  = %zu\n", sizeof(int32_t));
    printf("UINT8_MAX = %u\n", (unsigned)UINT8_MAX);
    printf("INT8_MIN  = %d\n", INT8_MIN);
    printf("INT32_MAX = %d\n", INT32_MAX);
    return 0;
}
