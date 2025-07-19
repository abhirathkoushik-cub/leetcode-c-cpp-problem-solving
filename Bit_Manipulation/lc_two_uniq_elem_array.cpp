
/*
Leetcode: https://leetcode.com/problems/single-number-iii/description/
Given an integer array, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.
Input: [1,2,1,3,2,5] Output: [3,5]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor_res = 0; // long or unsigned int required here as ~xor_res is used in XOR calculation for mask
        
        // XOR all elements in the array to end up with A^B where A and B are the 2 unique numbers
        for(int val:nums)
        {
            xor_res ^= val;
        }

        // Find the right most set bit in xor_res. This will show where bits in A and B are different.
        // long or unsigned required here as ~xor_res is used for calculation
        long mask = xor_res & ~(xor_res-1);

        // Divide original array into 2 groups based on if that Mask bit calculated above is set or not
        int temp_a=0, temp_b=0;
        for(int val:nums)
        {
            if (val & mask)
                temp_a ^= val; // Group where that mask bit is 1. But in the end, duplicates will cancel giving A.
            else
                temp_b ^= val; // Group where that mask bit is 0. But in the end, duplicates will cancel giving B.   
        }

        // Adding A and B into an array to return back
        vector<int> res_arr;
        res_arr.push_back(temp_a);
        res_arr.push_back(temp_b);
        return res_arr;
    }
};