/*
Leetcode: https://leetcode.com/problems/find-anagram-mappings/description/
Input: nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
Output: [1,4,3,2,0]
*/

#include<iostream>
#include <map> 
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {

        map<int,int> temp; // Creating a map to store each element with index {element:index} in nums2
        vector<int> ans; // Creating a vector to store the index values of nums2 relative to nums1
        
        for(int i=0;i<nums2.size();i++)
        {
            temp.insert({nums2[i], i}); // Map stores {element:index} of nums2
        }

        for(int j=0;j<nums1.size();j++)
        {
            // Using 'auto' here as return is an iterator to key-value pair. Let compiler deduce the type automcatically.
            auto it = temp.find(nums1[j]); // Iterate through the Map to find nums1 element as Keys of the Map {element:index}
            ans.push_back(it->second); // In {element:index}, once the element is found, add its index to the Answer Vector
        }

        return ans;
    }
};