/*
Leetcode: https://leetcode.com/problems/counting-bits/
Desc: Obtain the number of set bits in each number in the range upto the given number.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            int count=0; // Resetting the count for each iteration
            int j=i; // As the value of 'i' gets modified in while loop, copying the value to a new number 'j'
            while(j!=0)
            {
                if((j&1)==1) // Using '&' operation to check if the rightmost bit is set
                    count++;
                j=j>>1; // Using '>>' operator to keep moving the bits of the number to the right
            }
            ans.push_back(count);
        }
        return ans;
    }
};