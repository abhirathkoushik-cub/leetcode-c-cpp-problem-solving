#include <stdio.h>

void count_char(const char *str) // Use const for input strings
{
    if (str == NULL) return;

    // Use a fixed size for the alphabet, initialize to zero 
    int counts[26] = {0}; 

    const char *ptr = str;
    while (*ptr != '\0')
    {
        // count lowercase a-z
        if (*ptr >= 'a' && *ptr <= 'z') 
        {
            counts[*ptr - 'a']++;
        }

        // convert upper to lowercase and then count
        else if (*ptr >= 'A' && *ptr <= 'Z') 
        {
            counts[(*ptr - 'A' + 'a') - 'a']++;
        }

        ptr++; // Iterate to the next characte
    }

    // Print the counts for the characters
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] > 0)
        {
            printf("%c: %d\n", i + 'a', counts[i]);
        }
    }
}

int main()
{
    char str_test[] = "AAAbbCDDDD";
    count_char(str_test);
    return 0;
}