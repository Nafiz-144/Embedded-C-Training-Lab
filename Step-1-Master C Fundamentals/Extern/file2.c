#include <stdio.h>

extern int counter; // variable declared in another file
extern void increment(void);

int main(void)
{
    increment();
    increment();
    printf("Final Counter = %d\n", counter);
    return 0;
}
