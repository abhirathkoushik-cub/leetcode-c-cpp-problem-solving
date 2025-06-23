/*
Leetcode: https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=problem-list-v2&envId=oizxjoit

Binary Search Points
    3 pointers (left, mid, right)
    left <= right
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;

        while (left <= right)
        {
            // Find Middle Value
            int mid = (left + right) / 2;

            // Check if middle value is the target
            if (nums[mid] == target)
                return mid;
            
            // Check Left Portion
            if (nums[left] <= nums[mid])
            {
                // Check if Target Greater than Middle, or less than Leftmost
                if ((target > nums[mid]) || (target < nums[left])) 
                    left = mid + 1; // Implies to leave this portion and check Right Portion
                
                else
                    right = mid - 1; // Checking left portion, which is now condensed
            }

            // Check Right Portion
            else
            {
                if ((target < nums[mid]) || (target > nums[right]))
                    right = mid - 1; // Implies to leave this portion and check Left Portion
                
                else
                    left = mid + 1; // Checking right portion, which is now condensed
            }
        }
        return -1; // Did not find the result
    }
};