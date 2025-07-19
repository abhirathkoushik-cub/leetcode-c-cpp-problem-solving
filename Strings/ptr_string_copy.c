
#include <stdio.h>

void copy_str(char *des_str, char *src_str)
{
    // No need of creating temp pointers for this. The des_str and src_str pointers can be used directly. 

    while (*src_str) // Equivalent to while(*src_str != '\0')
    {
        *des_str++ = *src_str++; // Equivalent to *des_str = *src_str; *src_str++; des_str++;
    }
    *des_str='\0'; // Adding null character at the end of string
}

int main()
{
    char str1[]="Abhirath"; 
    char str2[sizeof(str1)]; // Always check that there is enough space for the complete string in the destination
    copy_str(str2, str1);
    printf("Now String 2 is %s\n", str2);
    return 0;
}