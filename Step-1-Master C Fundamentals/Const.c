// const_demo.c
#include <stdio.h>

int main(void){
    const int a = 10;
    // a = 20; // compile error — cannot assign to const
    const int *p1 = &a; // pointer to const int
    // *p1 = 5; // compile error

    int b = 30;
    int * const p2 = &b; // const pointer to int (pointer itself cannot change)
    *p2 = 40; // allowed
    // p2 = &a; // compile error

    printf("a=%d, b=%d\n", a, b);
    return 0;
}
