#include <stdio.h>
#include <string.h>

void concat(char[], char[]);
int stringLenght(char *cadena);

int main()
{
    char s1[50] = "lol";
    char s2[30] = "weyy";
    concat(s1, s2);
    printf("\nConcated string is :%s", s1);
    return (0);
}

void concat(char s1[], char s2[])
{
    int i, j;
    i = strlen(s1);
    for (j = 0; s2[j] != '\0'; i++, j++)
    {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
}

int stringLenght(char *cadena)
{
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; ++i){
        contador = contador + 1;
    }
    return contador;
}