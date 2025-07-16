
/*
Convert from a Hex to a String without using any in-built functions
*/

#include<stdio.h>
#include<ctype.h> // Used for tolower()

int main()
{
    int num=0x2025ABCD;

    char temp_str[10]; 
    int i=0;
    while(num>0)
    {
        // 0x0000000F mask ensures that only the LSB integer is considered each time
        int nibble = num&0x0000000F;

        if(nibble < 10) // IMP: If digit(0-9) then ASCII conversion from int to char is '0' + nibble
        {
            temp_str[i]= '0' + nibble; 
        }
        else
        {
            temp_str[i] = (tolower(nibble)) + 'a' - 10; // IMP: If (a-f) of Hex, then ASCII conversion to char is nibble + 'a' - 10
        }
        
        num = num >> 4; // Shifting by 4 as this is a 32-bit integer, so each digit is a 4-bit shift
        i++;
    }
    temp_str[i]='\0'; // Once all the digits are stored, we end the string to prevent junk values
    
    /* In temp_str, the characters are stored in the reverse order, 
      so we reverse this string using 2-pointer approach */
    char *end=&temp_str[i-1]; // Use index 'i' to point to the last character of the string, before '\0'
    char *start=temp_str; 
    char swap; 
    while(start < end)
    {
        swap = *start;
        *start = *end;
        *end = swap;
        start++;
        end--;
    }
    printf("%s", temp_str);
}