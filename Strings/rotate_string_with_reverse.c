#include <stdio.h>
#include <string.h>

// Reverse a string section from index 'start' to 'end'
void reverse_section(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void rotate_left(char *str, int k) {
    if (str == NULL || *str == '\0') return;

    int n = strlen(str);
    k = k % n; // Wrap k in the range 0 to n-1
    if (k == 0) return;

    /* 3-Reversal Logic:
    1st reverse from 0 to k-1, 
    then reverse from k to n-1, 
    and finally reverse the whole string from 0 to n-1.
    */
    reverse_section(str, 0, k - 1);     // "auQlcomm"
    reverse_section(str, k, n - 1);     // "auQmmocl"
    reverse_section(str, 0, n - 1);     // "lcommQua" (Final String)
}

int main() {
    char str[] = "Qualcomm";
    int k = 3;
    rotate_left(str, k);
    printf("Rotated String: %s\n", str); // Output: "lcommQua"
    return 0;
}
