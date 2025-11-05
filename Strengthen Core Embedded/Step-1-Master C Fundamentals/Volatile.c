#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

volatile int flag = 0; // Step 1: Declare volatile

void set_flag(void)
{
    flag = 1; // Step 3: Set flag in another function
}

int main(void)
{
    printf("Waiting for flag...\n");
    set_flag(); // Simulate external event

    while (flag == 0)
        ; // Step 2: Wait for flag to change

    printf("Flag changed!\n"); // Step 4: Print when flag changes
    return 0;
}