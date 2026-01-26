#include <stdio.h>
#include <stdint.h>

int is_little_endian(void)
{
    uint64_t num = 1;
    
    // Cast the address of 'num' to a pointer of a single byte. This forces Compiler to only read 1st byte (lowest memory address)
    uint8_t *first_byte_ptr = (uint8_t *)&num;
    
    if (*first_byte_ptr == 1) {
        printf("Little Endian\n"); // Lowest address holds the Least Significant Byte (0x01)
        return 1;
    } else {
        printf("Big Endian\n");    // Lowest address holds the Most Significant Byte (0x00)
        return 0;
    }
}

int main()
{
    is_little_endian();
    return 0;
}