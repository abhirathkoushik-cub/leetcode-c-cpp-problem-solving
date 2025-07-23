#include <stdio.h>
#include <string.h>

/*
Creating a Macro that toggle each character's case
*/
#define tog_char(c) c ^ ' ' // ASCII of ' ' is 32. Toggling(XOR) between Lower and Uppercase requires +32 and -32 respectively

/*
Creating a function that takes Char pointer
*/
void case_toggle(char *str_ptr)
{
    for(int i=0;i<strlen(str_ptr);i++)
    {
        str_ptr[i] = tog_char(str_ptr[i]);
    }
}

int main()
{
    char str[]="AbhiRath";
    case_toggle(str);
    printf("String after Case Toggle is %s\n", str);
    return 0;
}