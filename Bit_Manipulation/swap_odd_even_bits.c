#include <stdio.h>

#define odd_mask 0x55555555 //01010101 pattern for 32-bit int
#define even_mask 0xAAAAAAAA //10101010 pattern for 32-bit int

int main()
{
    int num=275; //0001 0001 0011
    
    int even_part = num & even_mask; // This operation will only get the even indexes that are set
    even_part >>=1; // We want to swap even indexes to odd, lower even indexes -> higher odd indexes so Right Shift

    int odd_part = num & odd_mask; // This operation will only get the odd indexes that are set
    odd_part <<=1; // We want to swap odd indexes to even, higher odd indexes -> lower even indexes so Left Shift
    
    int ans=0;
    ans |= even_part; // In ans variable, this will set the even indexes
    ans |= odd_part;  // In ans variable, this will set the odd indexes
    
    printf("%d", ans); //0010 0010 0011
    return 0;
}