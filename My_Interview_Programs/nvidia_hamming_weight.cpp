/*
Hamming Weight of a Number refers to the Number of 1's in the binary representation of the number. 

It was also noted as weight count of the number.
Eg:5(2^0 + 2^2) so Weight of 5 is 2. 
7(2^0 + 2^1 + 2^2) so Weight of 7 is 3.
8(2^3) so Weight of 8 is 1.

This question confuses you as bit manipulation may not be your first thought to solve this.
But if we observe the binary representation of each of the numbers, we notice that the bits are set at exactly those positions included in the sum.
So we just need the count of the number of set bits in a given number.

Also we are using uint8_t as the question specified that the number is only in the range 0 to 255.
*/

#include <iostream>
#include <cstdint>
using namespace std;

uint8_t weight_func(uint8_t number)
{
    uint8_t count=0;
    while(number>0)
    {
        if((number&1) == 1) // Checking if the rightmost bit is set
            count++;
        number>>=1; // Shifting the number to the right each time
    }
    return count;
}

int main()
{
    uint8_t num=7;
    /*
    In C++, 'uint8_t' is considered as a typedef to 'unsigned char' by default.
    Hence, it might print non-printable ASCII characters as well.
    Cast the result specifically to 'int' to print the required numbers. 
    static_cast<int>()
    */
    cout<<"Weight of number is "<< static_cast<int>(weight_func(num)); 
}
