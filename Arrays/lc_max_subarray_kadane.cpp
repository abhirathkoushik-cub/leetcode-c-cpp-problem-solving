/*
Leetcode: https://leetcode.com/problems/maximum-subarray/

Kadane Algorithm:
If a bigger negative number is added to a smaller positive number, the answer will be negative.
As the objective is to find the maximum value of the array elements, there is no need of a negative result.
So whenever the sum < 0, Reset the sum back to 0 and discard the sum of previous elements.

max_sum will only store the maximum value of the changing values of cur_sum. Hence will indicate the Maximum Subarray Sum. 
*/

#include<iostream>
#include<vector>
#include<algorithm> // For std::max() function
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum=0;
        int max_sum=INT_MIN; // Initialized with Smallest possible integer, as this will be replaced by the maximum value of cur_sum
        for(int val:nums) 
        {
            cur_sum += val; // cur_sum just keeps adding the values of the array
            // Check if the cur_sum is greater than the previous maximum value. Using in-built std::max() function from <algorithm> header file. 
            max_sum = max(cur_sum, max_sum); 
            if(cur_sum < 0)
                cur_sum=0; // Reset the cur_sum if the sum becomes negative, discarding the previous sum
        }
        return max_sum;
    }
};