#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t my_atoi(char* str)
{
    if (str == NULL) return 0;

    uint32_t ans = 0;
    while(*str != '\0')
    {
        if ((*str < '0') || (*str > '9')) // Check if the character is a number between 0 and 9
            break;
        ans *= 10;           // First multiply, then add to get the number
        ans += (*str - '0'); // Using ASCII table logic (- '0') to get a number from a character of the same number
        str++;
    }
    return ans;
}

int main()
{
    char num[]="1234b";
    printf("Number returned is %d", my_atoi(num));
    return 0;
}
