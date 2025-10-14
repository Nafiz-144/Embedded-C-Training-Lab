// enum_example.c
#include <stdio.h>

enum systemstate {
    idle,
    running,
    error
};

int main(){
    int input; // temporary variable for reading input
    enum systemstate current_state;

    // Read input into an int, then cast to enum
    if(scanf("%d", &input) != 1){
        printf("Invalid input.\n");
        return 1;
    }
    current_state = (enum systemstate)input;

    if (current_state == idle) {
        printf("System is idle.\n");
    } else if (current_state == running) {
        printf("System is running.\n");
    } else if (current_state == error) {
        printf("System is in error state.\n");
    } else {
        printf("Unknown state.\n");
    }

    return 0;
}
