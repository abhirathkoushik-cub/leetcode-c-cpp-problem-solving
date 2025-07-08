/*
    Returns an unsigned integer represented by the binary string input. The binary string is in format '0b1001'.
    Input:0b00      Output:0
    Input:0b05100   Output:ERROR
    Input:0b110     Output:6
*/

#include <stdio.h>
#include <stdint.h>

#define ERROR 0xFFFFFFFF

uint32_t binstr_to_uint(const char *str)
{
    if (str == NULL)
        return ERROR;
    if (str[0] != '0' || str[1] != 'b') // Checking if first 2 characters of string is in format '0b'
        return ERROR;

    const char *temp_str=&str[2]; // Iterating the string starting from 3rd character
    uint32_t num=0;
    int count_check=0;
    while (*temp_str != '\0')
    {
        if(*temp_str == '0' || *temp_str == '1'){
            num = (num << 1) | (*temp_str - '0'); // Shifting num to the left by 1 bit, then converting the character to digit (-'0' ASCII method)
        } else{
            return ERROR;
        }
        temp_str++;
        count_check++; 
    }
    
    if (count_check < 1 || count_check > 32) // Check if the count of binary digits in string is between 1 and 32
        return ERROR;
        
    return num;
}

int main()
{
    const char bin_str[]="0b1001";
    printf("String converted to UINT 32 is 0x%x", binstr_to_uint(bin_str));
    return 0;
}