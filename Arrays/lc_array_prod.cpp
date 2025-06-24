
/*
Leetcode: https://leetcode.com/problems/product-of-array-except-self/?envType=problem-list-v2&envId=oizxjoit
Product of Array Except Self
Input: [1,2,3,4], Output: [24,12,8,6]
Solved in O(n) TC and O(n) SC
*/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Prefix vector will have product of all values before 'i' index
        vector<int> prefix_arr(n, 1);

        // Suffix vector will have produt of all values after 'i' index
        vector<int> suffix_arr(n, 1); 

        // Answer vector will have prefix * suffix for each 'i' index
        vector<int> ans_arr(n, 1); 
        
        // Filling the Prefix Vector
        // Start from index 1 as we do not need this calculation for the first element
        for(int i=1;i<n;i++)
        {
            prefix_arr[i] = prefix_arr[i-1] * nums[i-1];
        }
        
        // Filing the Suffix Vector, in reverse order
        // Starting from n-2 index as we do not need this calculation for the last element
        for(int i=n-2;i>=0;i--)
        {
            suffix_arr[i] = suffix_arr[i+1] * nums[i+1];
        }

        // Filling Result Vector with prefix * suffix for each element
        for(int i=0;i<n;i++)
        {
            ans_arr[i] = prefix_arr[i] * suffix_arr[i];

        }

        return ans_arr;
    }
};