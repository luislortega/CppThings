#include <stdio.h>
#include <string.h>

int main()
{
    char const *str1 = "wee";
    char const *str2 = "lol";
    int i;

    printf("\nEnter two strings :");

    i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0')
        i++;
    if (str1[i] > str2[i])
        printf("str1 > str2");
    else if (str1[i] < str2[i])
        printf("str1 < str2");
    else
        printf("str1 = str2");
    return (0);
}