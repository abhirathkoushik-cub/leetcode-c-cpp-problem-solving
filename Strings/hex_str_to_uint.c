
/*
Returns an Unsigned Integer represented by the Hex String.
Case should not matter. All error checks has to be done.
Input:Output
0x12    : 18
0x0012  : 18
0XfF78  : 65400
*/

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define ERROR 0xFFFFFFFF

uint32_t hexstr_to_uint(const char *str)
{
    if (str == NULL)
        return ERROR;
    if(str[0] != '0' || tolower(str[1]) != 'x') // Checking if initial 2 character of the hex string is '0x'
        return ERROR;
    
    const char *temp_str=&str[2]; // Starting temp_str to interate from 3rd character onwards
    int char_count=0;
    uint32_t final_num=0;
    while(*temp_str != '\0')
    {
        int num = 0;
        char temp_ch=tolower(*temp_str); // Converting all to lowercase to make sure case does not matter
        if ((int)temp_ch >=48 && (int)temp_ch <=57) // Checking if character is a digit between 0(ASCII 48) and 9(ASCII 57)
        {
            num = temp_ch - '0'; // -'0' is standard ASCII way of converting from String Int to Int
        }
        else if ((int)temp_ch >=97 && (int)temp_ch <=102) // Checking if character is a character between a(ASCII 97) and f(ASCII 102)
        {
            num = temp_ch - 'a' + 10; // Subtracts 97 and then adds 10 to get the respective decimal for the hex character
        }
        else
            return ERROR;
        final_num = (final_num << 4) | num; // In the answer variable, we shift by 4 bits (next digit in hex number) and then set the num value
        char_count++;
        temp_str++;
    }
    
    if(char_count<1 || char_count>8) // Check if other than 0x, we have only 8 characters in the string, based on the capacity of uint32 
        return ERROR;
        
    return final_num;
}

int main()
{
    const char hex_str[]="0x01Fa";
    printf("Interger from this string is %u", hexstr_to_uint(hex_str));
    return 0;
}