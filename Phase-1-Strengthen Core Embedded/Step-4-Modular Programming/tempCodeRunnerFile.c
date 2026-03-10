#include <stdio.h>
int main()
{

    int a[1000], n, i, f = 0, p = 0, np = 0;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Enter the element:");
    scanf("%d", &a[i]);
    if (n <= 1)
    {
        printf("Not a prime Number!");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                np++;
            }
            else
            {
                p++;
            }
        }
    }
    printf("Number Of prime Number:", p);
    printf("Number Of not prime Number:", np);
}