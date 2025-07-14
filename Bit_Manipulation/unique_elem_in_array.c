
/*
In an array where every element repeats twice except 1, find that 1 unique element.
XOR Concepts:
    a ^ 0 = a
    a ^ a = 0
*/

#include <stdio.h>

int find_odd_occurring(int arr[], int n) {
    int result = 0; 
    for (int i = 0; i < n; i++) {
        result = result ^ arr[i]; // a^0=a and a^a=0 used here. In the end, only the unique element will not be cancelled.
    }
    return result;
}

int main() {
    int arr[] = {2, 3, 5, 4, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int odd = find_odd_occurring(arr, n);
    printf("The odd-occurring number is: %d\n", odd);
    return 0;
}