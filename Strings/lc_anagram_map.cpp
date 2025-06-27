/*
Leetcode: https://leetcode.com/problems/valid-anagram/?envType=problem-list-v2&envId=oizxjoit
*/

#include<iostream>
#include <unordered_map> // For unordered_map<char,int>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Check and return False if size of the strings are not same
        if (s.size() != t.size())
            return false;
        
        // Creating a Map for each character and its frequency in the string
        unordered_map<char,int> freq;

        // Traverse the first string
        for (char c:s)
        {
            ++freq[c]; // Increment the frequency count for every character
        }

        // Traverse the second string
        for (char c:t)
        {
            --freq[c]; // Decrement the frequency count from the Same Map
        }

        // Traverse through the Map
        for(const auto& Key:freq)
        {
            if(Key.second != 0) // Check if the frequency of any character is not 0,
                return false;   // Indicates that it is not an anagram
        }
        return true; // If frequencies of all characters are 0, then its an anagram
    }
};
