#include<stdio.h>
#include<stdint.h>

typedef struct {
    uint32_t higher_word;
    uint32_t lower_word;
} my_uint64_t;

my_uint64_t g_counter = {0, 0};

my_uint64_t increase_counter(uint32_t value) {
    // Check if the value we are adding is greater than the space left
    if (value > (UINT32_MAX - g_counter.lower_word)) {
        // Then, we trigger exactly ONE carry to the higher word
        g_counter.higher_word += 1;
    }

    // For lower word, we only need to add the value. If it overflows, it wraps around being unsigned int
    g_counter.lower_word += value;

    return g_counter;
}

int main() {
    my_uint64_t result;

    // Test case 1: Simple increment
    result = increase_counter(100);
    printf("Counter after adding 100: Higher Word = %u, Lower Word = %u\n", result.higher_word, result.lower_word);

    // Test case 2: Increment that causes lower_word to overflow
    result = increase_counter(UINT32_MAX - 50); 
    printf("Counter after adding UINT32_MAX - 50: Higher Word = %u, Lower Word = %u\n", result.higher_word, result.lower_word);

    // Test case 3: Only adding in lower word again
    result = increase_counter(200); 
    printf("Counter after adding 200: Higher Word = %u, Lower Word = %u\n", result.higher_word, result.lower_word);

    return 0;
}