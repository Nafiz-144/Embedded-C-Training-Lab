#include <stdio.h>
#include <stdlib.h>

int g1 = 10;       // .data section
int g2;            // .bss section
const int c1 = 20; // Flash memory

void func()
{
    int x = 5;                      // Stack
    int *ptr = malloc(sizeof(int)); // Heap
    *ptr = 100;
    printf("x=%d, *ptr=%d\n", x, *ptr);
    free(ptr);
}

int main()
{
    func();
}
