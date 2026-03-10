#include <stdio.h>

int main()
{
    int a[1000], n, i, j, f;
    int p = 0, np = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        f = 0;

        if (a[i] <= 1)
        {
            np++;
            continue;
        }

        for (j = 2; j < a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                f = 1;
                break;
            }
        }

        if (f == 0)
        {
            p++;
        }

        else
        {
            np++;
        }
    }

    printf("Number Of Prime Numbers: %d\n", p);
    printf("Number Of Not Prime Numbers: %d\n", np);

    return 0;
}