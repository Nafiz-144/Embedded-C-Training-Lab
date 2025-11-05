#include <stdio.h>

void counter()
{
    static int count = 0;
    count++;
    printf("Count = %d\n", count);
}

int main()
{
    counter(); // 1
    counter(); // 2
    counter(); // 3
}
