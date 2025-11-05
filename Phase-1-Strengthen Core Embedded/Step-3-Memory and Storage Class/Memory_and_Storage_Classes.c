#include <stdio.h>

/* ---------- 1️⃣ extern variable ---------- */
int global_var = 10; // defined globally

/* ---------- 2️⃣ static global variable ---------- */
static int static_global = 100; // visible only inside this file

/* ---------- 3️⃣ const variable ---------- */
const int CONST_VAL = 500; // stored in Flash (read-only memory)

/* ---------- 4️⃣ volatile variable ---------- */
volatile int sensor_flag = 0; // may change anytime (e.g., hardware interrupt)

/* ---------- function using static & auto ---------- */
void counter_function(void)
{
    static int static_local = 0; // stays alive for full program duration
    auto int auto_local = 0;     // created every time function is called
    register int fast_var = 0;   // kept in CPU register if possible

    static_local++;
    auto_local++;
    fast_var++;

    printf("Inside function -> static_local=%d | auto_local=%d | fast_var=%d\n",
           static_local, auto_local, fast_var);
}

/* ---------- extern variable usage from another file simulation ---------- */
void extern_test(void)
{
    extern int global_var; // declaration (already defined above)
    printf("Extern global_var = %d\n", global_var);
}

int main(void)
{
    printf("=== Memory & Storage Classes Demo ===\n\n");

    printf("Global variable = %d\n", global_var);
    printf("Static global variable = %d\n", static_global);
    printf("Const variable = %d\n", CONST_VAL);

    extern_test(); // use extern variable

    // Call counter_function multiple times
    counter_function();
    counter_function();
    counter_function();

    // Simulate volatile variable change (like interrupt flag)
    printf("\nBefore change: sensor_flag = %d\n", sensor_flag);
    sensor_flag = 1; // Suppose interrupt changed this
    printf("After interrupt: sensor_flag = %d\n", sensor_flag);

    return 0;
}
