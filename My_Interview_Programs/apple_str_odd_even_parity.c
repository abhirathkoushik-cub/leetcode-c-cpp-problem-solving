#include<stdio.h>
#include<ctype.h>
#include<stdint.h>

// My approach using int arr[26] in interview
void check_count(const char* str, int* arr)
{
  if (str == NULL || arr == NULL)
    return;

  while(*str != '\0')
  {
    char temp_str = tolower(*str); // Convert to lowercase for uniformity
    if(temp_str >= 'a' && temp_str <= 'z')
    {
      arr[temp_str-'a'] ^= 1; // Keep toggling the array value (b/n 0 and 1) for that character as we iterate through the string
    }
    str++;
  }
}

// Optimized approach using uint32_t bitmask, 32 bits can store parity information for the 26 characters
void check_count_optimized(const char* str, uint32_t* bitmask)
{
    if (str == NULL || bitmask == NULL)
        return;
    
    while(*str != '\0')
    {
        char temp_str = tolower(*str); // Convert to lowercase for uniformity
        if(temp_str >= 'a' && temp_str <= 'z')
        {
            *bitmask ^= (1 << (temp_str - 'a')); // Toggle the BIT corresponding to the character
        }
        str++;
    }
}


int main(void)
{
    const char *input = "AABBBCDDDDZF";
    int parity[26];

    check_count(input, parity);

    for (int i = 0; i < 26; i++) {
        printf("%c: %s\n", 'A' + i, parity[i] ? "ODD" : "EVEN");
    }

    // Optimized approach using bitmask
    uint32_t bitmask = 0;   
    check_count_optimized(input, &bitmask);
    printf("\nOptimized Approach using Bitmask:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %s\n", 'A' + i, (bitmask & (1 << i)) ? "ODD" : "EVEN");
    }       

    return 0;
}