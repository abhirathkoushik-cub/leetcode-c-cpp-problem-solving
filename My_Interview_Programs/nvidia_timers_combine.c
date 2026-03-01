#include <stdio.h>
#include <stdint.h>

/* We have to read 2 32-bit registers and combine them to return a 64-bit value */

// Assume these are the Memory-Mapped I/O addresses
#define REG_TIMER_HIGH ((volatile uint32_t*)0x40002000)
#define REG_TIMER_LOW  ((volatile uint32_t*)0x40002004)

uint64_t read_64bit_timer() {
    uint32_t high1, high2, low;

    do {
        // 1. Read the High part first
        high1 = *REG_TIMER_HIGH;
        
        // 2. Read the Low part
        low = *REG_TIMER_LOW;
        
        // 3. Read the High part again to check for rollover
        high2 = *REG_TIMER_HIGH;

    } while (high1 != high2); // If High changed, the Low read is invalid so repeat.

    // Combine them into a single 64-bit value
    return ((uint64_t)high2 << 32) | low; // uint64_t is specified because the end result is 64-bit, and we need to ensure the shift operation works correctly.
}

int main() {
    uint64_t timer_value = read_64bit_timer();
    printf("Current Timer Value: %llu\n", timer_value);
    return 0;
}
