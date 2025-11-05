#include <stdio.h>

extern int led_status; // file1 থেকে ব্যবহার করা হচ্ছে

int main()
{
    led_status = 1;
    printf("%d", led_status);
}
