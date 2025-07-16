/*
Leetcode: https://leetcode.com/problems/reverse-bits/
*/

#include<iostream>
using namespace std;

void reverse_bits(uint32_t* num)
{
    uint32_t reversed=0;
    while(*num>0)
    {
        /* FISH SET. FIrst SHift then SET. No branching req to check if 0 or 1 before setting. Set for ALL. */
        reversed = reversed << 1; // Moving the bit position (in the answer variable) to be modified to the left each time. 
        reversed = reversed | ((*num)&1); // *num&1 checks if *num is set at that position. | operation sets the bit in the answer variable. 
        *num = *num>>1; // In each interation, *num is shifted to the right. As the result is stored in another variable, this can be done to *num.
    }
    cout<<"Reversed:"<<reversed<<endl;
}

int main()
{
    uint32_t var = 129;
    // uint32_t var = 5;
    reverse_bits(&var);
    return 0;
}
