#include <stdio.h>

void show()
{
    int x = 10; // auto by default
    printf("x = %d\n", x);
}

int main()
{
    show();
    // printf("%d", x); // Error, কারণ x function এর বাইরে নেই
}
