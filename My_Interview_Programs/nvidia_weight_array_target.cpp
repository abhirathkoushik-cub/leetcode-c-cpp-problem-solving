/*
Hamming Weight of a Number refers to the Number of 1's in the binary representation of the number. 

It was also noted as weight count of the number.
Eg:5(2^0 + 2^2) so Weight of 5 is 2. 

In this question, there is a list of numbers along with a target given.
We have the find the number whose weight is closest to the target.
If there are multiple numbers, then return the smallest of the numbers.

Eg: {5,7,2,8} and target=2. Element whose weight is closest to target is 5
Eg: {5,7,2,8} and target=1. Element whose weight is closest to target is 2
*/

#include <iostream>
#include <cstdint>
#include <vector>
#include <climits>
using namespace std;

// This function is used to find the weight of a given number
int weight_func(int number)
{
    int count=0;
    while(number>0)
    {
        if((number&1) == 1) // Checking if the rightmost bit is set
            count++;
        number>>=1; // Shifting the number to the right each time
    }
    return count;
}

// This function is used to compute the weight closest to the target
int closest_weight(vector<int>& num_array, int target)
{
    int min_diff=INT_MAX;  // This variable captures difference between number weight and target
    int num_array_element; // This variable captures the original array value at that point
    
    for(int val:num_array)
    {
        int temp_weight = weight_func(val);  // Find and store the weight of the number
        
        if(abs(temp_weight-target)<min_diff) // Find the least difference from given target
        {
            min_diff = abs(temp_weight-target); 
            num_array_element = val; // Store the original array value at the point of least difference
        }
        
        /* If the difference is the same, then check if the new number is lesser than the number 
           already stored in num_array_element variable */
        else if (abs(temp_weight-target) == min_diff && val < num_array_element)
            num_array_element = val; 
    }
    return num_array_element; // Returning the number from the original array, whose weight difference is the least from target
}

int main()
{
    vector<int> num_array={5,7,8,2};
    int target=5;
    cout<<"Element whose weight is closest to target is "<< closest_weight(num_array, target);
}