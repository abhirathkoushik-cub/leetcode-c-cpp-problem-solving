/*
Leetcode: https://leetcode.com/problems/single-number/
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0; // As a ^ 0 = a, initial value 0 does not affect the result
        for(int val:nums) // Using 'for each loop' to access Vector elements directly
        {
            ans = ans ^ val; // Using XOR bit manipulation for finding the unique element, a ^ a = 0
        }
        return ans;
    }
};