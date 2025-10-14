#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Demonstration of the 'volatile' keyword in C
// 'volatile' tells the compiler that the value of the variable can change at any time
// and prevents the compiler from optimizing out repeated accesses to the variable.
volatile int flag = 0; // Declare 'flag' as volatile so every access reads from memory

// This function simulates an external event that sets the flag variable.
// In embedded systems, this could be an interrupt or hardware event.
void simulate_external_set(void){
    flag = 1;
}

int main(void){
    printf("wait for flag...\n");
    // Wait for the flag to be set by an external event
    // Without 'volatile', the compiler might optimize this loop away
    while(flag == 0){
        // In a real embedded system, another process or interrupt would set 'flag'.
        // Here, we simulate the event by calling the function directly.
        simulate_external_set();
    }
    printf("flag set, exiting\n");
    return 0;
}
