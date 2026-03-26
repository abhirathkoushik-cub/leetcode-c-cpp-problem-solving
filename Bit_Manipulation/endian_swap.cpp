// This question is for Reverse BYTES, not BITS.
// Tested on C++ 23 Compiler

#include <iostream>
#include <cstdint>
using namespace std;

// Swap 32-bit endian
#define swap_endian(x) ( \
    (((x) >> 24) & 0x000000FF) | \
    (((x) >> 8)  & 0x0000FF00) | \
    (((x) << 8)  & 0x00FF0000) | \
    (((x) << 24) & 0xFF000000) )

// Swap 16-bit endian
#define swap_16_endian(x) ( \
    (((x) >> 8) & 0x00FF) | \
    (((x) << 8) & 0xFF00) )

// Swap 8-bit endian
#define swap_8_endian(x) ( \
    (((x) >> 4) & 0x0F) | \
    (((x) << 4) & 0xF0) )

// Generic function to swap endianness for any data type using 2 ptr approach
void swap_endian_two_ptr(void* data, size_t size)
{   
    char* start = (char*)data;
    char* end = start + size - 1;
    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    uint32_t num32 = 0x12345678;
    uint16_t num16 = 0xABCD;
    uint8_t  num8  = 0xBC;

    cout << "Original 32-bit: 0x" << hex << num32 << endl;
    cout << "Swapped 32-bit:  0x" << hex << swap_endian(num32) << endl << endl;

    cout << "Original 16-bit: 0x" << hex << num16 << endl;
    cout << "Swapped 16-bit:  0x" << hex << swap_16_endian(num16) << endl << endl;

    // Here, static_cast<int> is used to explicitely define a number, by default 'uint8_t' variable is treated as an alias for 'unsigned char' 
    cout << "Original 8-bit:  0x" << hex << static_cast<int>(num8) << endl;
    cout << "Swapped 8-bit:   0x" << hex << static_cast<int>(swap_8_endian(num8)) << endl << endl;

    // Using the generic function to swap endianness
    swap_endian_two_ptr(&num32, sizeof(num32));
    cout << "Generic swapped 32-bit:  0x" << hex << num32 << endl;

    swap_endian_two_ptr(&num16, sizeof(num16));
    cout << "Generic swapped 16-bit:  0x" << hex << num16 << endl;

    // Generic method does not work for 8-bit data as it is a single byte

    return 0;
}
