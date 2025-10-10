#include <stdio.h>
#include <stdint.h>

#define ERROR 0xFFFFFFFF

/*
Returns a 1 if the number of occurrences of bit_pattern in number num is even otherwise a 0. 
we will consider only the least significant nbits from bit_pattern for checking and counting the occurrence.
Permissible values of nbits: 0 < nbits <= 8.
Num	bit_pattern	nbits	Return value
0        0	      1         1	
45       2        2         1
*/
uint32_t nbits_pattern_parity(int32_t num, uint8_t bit_pattern, size_t nbits)
{
    if (nbits == 0) // nbits cannot be 0, then we cannot extract bits from bit_pattern
        return ERROR;
    
    uint32_t count = 0; 
    
    size_t mask = (1 << nbits) -1; // To set up the mask to & with number. << shift to compare with "nbits" number of bits from bit_pattern 
    printf("Mask is %ld\n", mask);
    
    for(int i=0; i<= 32-nbits; i++) // Here, we cannot use while(num !=0) as input num can be given as 0. "32-nbits" as Sliding Window Size has to Align with "nbits"
    {
        if ((num & mask) == bit_pattern){ // Extracting bits to compare by doing "num & mask" and comparing with the "bit_pattern" input
            count++;
        }
        num = num >> 1; // Shifting the number to obtain the next set of bits (sliding window)
    }
    
    printf("Count is %d\n", count);
    
    if (count == 0) // If count is 0, then the pattern is not found
        return ERROR;
    
    if (count % 2 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int32_t number = 45;
    uint8_t bit_pat = 2;
    size_t num_bits_in_bit_pat = 2;

    /*
    int32_t number = 0;
    uint8_t bit_pat = 0;
    size_t num_bits_in_bit_pat = 1;
    */
    
    if(nbits_pattern_parity(number, bit_pat, num_bits_in_bit_pat) == 1)
    {
        printf("Pattern occurs even times\n");
    }
    else if (nbits_pattern_parity(number, bit_pat, num_bits_in_bit_pat) == 0)
    {
        printf("Pattern occurs odd times\n");
    }
    else
    {
        printf("Error in inputs or pattern not found\n");
    }

    return 0;
}