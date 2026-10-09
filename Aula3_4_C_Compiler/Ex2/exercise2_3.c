#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* str);

int main(void)
{
    char string[] = "Ola Mundo";

    printf("\n String Inicial:  %s", string);
    reverseString(string);
    printf("\n String Reversed: %s\n", string);

    return 0;
}

void reverseString(char* str)
{
    if (str == NULL || *str == '\0') return;

    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}