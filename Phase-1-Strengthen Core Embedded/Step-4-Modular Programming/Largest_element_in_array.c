#include <stdio.h>
int main()
{

    int a[100], n;
    printf("Enter the number of element:");
    scanf("%d", &n);
    printf("Enter the array elemnt:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("The maximum value :%d", max);
}