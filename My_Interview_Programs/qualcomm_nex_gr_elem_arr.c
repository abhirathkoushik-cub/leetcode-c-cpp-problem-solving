#include <stdio.h>

/*
Given an array, find the next greater element (to the right) for each element in the array. 
If there is no greater element, then the next greater element for x is -1.
Ex: Input: arr[] = {4, 5, 2, 10, 8, 11}
    Output: NGE for 4 is 5
            NGE for 5 is 10
            NGE for 2 is 10
            NGE for 10 is 11
            NGE for 8 is 11
            NGE for 11 is -1
*/

#define MAX 1000

// Brute Force Approach: O(n^2)
void nextGreaterBrute(int arr[], int n) {
    int result[n];

    for (int i = 0; i < n; i++) {
        result[i] = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                result[i] = arr[j];
                break;
            }
        }
    }

    printf("Brute Force Result:\n");
    for (int i = 0; i < n; i++)
        printf("arr[%d] = %d  -->  NGE = %d\n", i, arr[i], result[i]);
}

// Optimal Approach: O(n) using Stack
void nextGreaterOptimal(int arr[], int n) {
    int result[n];
    int stack[MAX]; 
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= arr[i]) // Pop elements from stack while they are <= current element
            top--;
    
        result[i] = -1; // Default value if no greater element is found
        if (top != -1)
            result[i] = stack[top]; // Top of stack is the next greater element for arr[i]
        stack[++top] = arr[i]; // Push current element onto stack
    }

    printf("Optimal (Stack) Result:\n");
    for (int i = 0; i < n; i++)
        printf("arr[%d] = %d  -->  NGE = %d\n", i, arr[i], result[i]);
}

int main() {
    int arr[] = {4, 5, 2, 10, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterBrute(arr, n);
    printf("\n");
    nextGreaterOptimal(arr, n);

    return 0;
}