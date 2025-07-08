#include <stdio.h>
#include <stdint.h>

uint8_t rotate_right(uint8_t num, uint8_t nbits)
{
    nbits = nbits & 7; // This is done to keep any nbit number in the range of 0 to 7
    /*
    num >> nbits -> Shift the number to the right, can result in loss of data
    num << (8-nbits) -> Shifts the number to the left, but only those lost during right shift (Wrap Around)
    | opeartion combines both the results
    */
    num = (num >> nbits) | (num << (8 - nbits));
    return num;
}

int main()
{
    uint8_t number=197;
    uint8_t rot_num=4;
    printf("Rotated Number is %u", rotate_right(number,rot_num));
    return 0;
}