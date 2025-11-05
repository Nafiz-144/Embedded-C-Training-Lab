// practice_funcptr.c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

typedef int (*op_t)(int, int);

int compute(op_t op, int x, int y)
{
    return op(x, y);
}

int main(void)
{
    printf("add: %d\n", compute(add, 3, 4));
    printf("mul: %d\n", compute(mul, 3, 4));
    return 0;
}
