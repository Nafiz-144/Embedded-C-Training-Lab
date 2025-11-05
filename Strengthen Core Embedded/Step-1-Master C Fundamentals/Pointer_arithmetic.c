// practice_ptr_arith.c
#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // points to arr[0]

    printf("addresses via pointer arithmetic:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("p + %d -> %p, value = %d\n", i, (void *)(p + i), *(p + i));
    }

    // pointer difference
    int *p1 = &arr[4];
    printf("difference p1 - p = %ld\n", (long)(p1 - p)); // 4

    // byte-level pointer
    unsigned char *byte = (unsigned char *)p;
    printf("first byte of arr[0] = %u (platform endian dependent)\n", (unsigned)byte[0]);
    return 0;
}
