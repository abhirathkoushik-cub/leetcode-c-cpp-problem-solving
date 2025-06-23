// Tested on C++ 23 Compiler

#include <iostream>
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
    cout << "Swapped 8-bit:   0x" << hex << static_cast<int>(swap_8_endian(num8)) << endl;

    return 0;
}
