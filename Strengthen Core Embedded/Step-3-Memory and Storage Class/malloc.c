#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;

    p = (int *)malloc(4); // 4 bytes allocate করা হলো (একটা int এর জন্য)
    *p = 10;

    printf("Value = %d\n", *p);

    free(p); // Memory free করা হলো
    return 0;
}
