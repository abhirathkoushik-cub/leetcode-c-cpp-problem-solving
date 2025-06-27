
/*
Leetcode: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++) // Iterate through the Main String
        {
            if(haystack[i] == needle[0]) // Check if any character of the Main String is the first of the Target String
            {
                int j=i; // Create a new variable for the Main String index, as it will be modified in the for loop
                for(int k=0;k<needle.size();k++,j++) // Iterate through the Target String while incrementing the Main String Index
                {
                    if(needle[k] != haystack[j]) // If the Target String is not completely in the Main String, break out
                       break;                    // But we cannot return -1 here yet, as the Main String Interation is not completed yet.
                    else if (k == needle.size()-1) // Value of k has incremented upto the size of the Target String without breaking,
                        return i;                  // indicates characters in Main String are matching, return Main String Index.
                }
            }
        }
        return -1; // No complete match found for the full iteration of the Main String, no Target match
    }
};