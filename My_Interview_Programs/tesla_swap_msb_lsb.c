#include <stdio.h>
#include <stdint.h>

int main()
{
    /*
    Approach-1: Conditional on difference in MSB and LSB bits
    Does not execute when both the bits are equal
    But if loop still has to execute (branch prediction takes place, less real-time effective)
    */

    uint8_t actual_num=0b00000011;
    
    uint8_t num=actual_num;
    printf("Before Swap Approach-1: %u\n\n", (actual_num));
    if((num & (1<<7)) != 0 && (num & (1<<0)) == 0)
    {
        num = num & ~(1<<7); // Clear MSB
        num = num | (1<<0);  // Set LSB
    }
    else if ((num & (1<<7)) == 0 && (num & (1<<0)) != 0)
    {
        num = num | (1<<7);  // Set MSB
        num = num & ~(1<<0); // Clear LSB
    }
    printf("After Swap Approach-1: %u\n\n", (num));
    
    /*
    Approach-2: Complete Bitwise Operations
    Always execute, even when MSB and LSB bits are equal
    But these are still bitwise operations which execute fast, no branching, real-time effective
    */

    uint8_t num1=actual_num;
    printf("Before Swap Approach-2: %u\n\n", (actual_num));
    // Identify MSB and LSB in the number
    uint8_t msb= (num1>>7) & 1; // First rightshift to place msb in lsb position and then &1 to isolate
    uint8_t lsb= num1 & (1<<0);
    
    // Clear both MSB and LSB in the number
    num1 = num1 & ~(1<<7);
    num1 = num1 & ~(1<<0);
    
    // Swap and Set the MSB and LSB
    num1 = num1 | (msb<<0); // MSB value gets set at LSB
    num1 = num1 | (lsb<<7); // LSB value gets set at MSB
    
    printf("After Swap Approach-2: %u\n\n", (num1));
}