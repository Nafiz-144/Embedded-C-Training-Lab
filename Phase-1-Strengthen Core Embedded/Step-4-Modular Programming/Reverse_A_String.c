#include <stdio.h>

int main()
{

    char s[100];
    printf("Enter your name :");
    scanf("%s", s);
    int i = 0, len = 0;
    char temp;
    // calculate length
    while (s[len] != '\0')
    {
        len++;
    }
    int j = len - 1;
    // string reverse
    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    printf("String Reverse:->%s", s);
    return 0;
}