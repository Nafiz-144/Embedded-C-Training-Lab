// enum_example.c
#include <stdio.h>

enum systemstate
{
    IDLE = 1,
    RUNNING,
    ERROR
};
/*
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
*/
int main(void)
{
    enum systemstate current_state;
    int choice;

    printf("Enter rocket state (1=IDLE, 2=RUNNING, 3=ERROR): ");
    scanf("%d", &choice);

    current_state = (enum systemstate)choice;

    switch (current_state)
    {
    case IDLE:
        printf("🚀 Rocket is in IDLE state.\n");
        break;

    case RUNNING:
        printf("🚀 Rocket is RUNNING.\n");
        break;

    case ERROR:
        printf("⚠️ Rocket is in ERROR state!\n");
        break;

    default:
        printf("❌ Invalid input! Please enter 1–3.\n");
        break;
    }

    return 0;
}