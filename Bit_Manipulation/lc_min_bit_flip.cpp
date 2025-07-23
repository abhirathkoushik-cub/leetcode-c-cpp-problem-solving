
/*
Leetcode: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int bits_diff_count = start ^ goal; // XOR gives the number where Bits of start and goal are Different
        
        int bits_count=0;
        while(bits_diff_count !=0) // Now, the number of Set Bits in the XOR number gives the Minimum Bit Flips Required
        {
            bits_diff_count &= (bits_diff_count-1); // Brian Kernighan's Method of Clearing Rightmost Set Bit
            bits_count++;
        }
        return bits_count;
    }
};