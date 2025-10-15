#include <stdio.h>

int counter = 0; // global variable

void increment(void)
{
    counter++;
    printf("Counter = %d\n", counter);
}
