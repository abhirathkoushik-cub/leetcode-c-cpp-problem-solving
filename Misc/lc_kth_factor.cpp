
/*
Leetcode: https://leetcode.com/problems/the-kth-factor-of-n/
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> temp;
        for(int i=1;i<=n;i++)
        {
            if(n % i == 0)
            {
                temp.push_back(i);
            }
        }
        if (k > temp.size())
            return -1;
        else
            return temp[k-1]; 
    }
};
