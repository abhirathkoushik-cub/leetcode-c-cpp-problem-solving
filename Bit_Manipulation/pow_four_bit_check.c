#include <stdio.h>

// Part of Bit Manipulation by Kapil Yadav Doc

/*
3 conditions to check for Power of 4
    1. Positive Number
    2. Check if power of 2 and ensure only 1 bit is set 
    3. Check if the set bit is in the even index position by ANDing with 5(0101) mask
*/
#define pow_four(x) (((x)>0) && !((x) & (x-1)) && ((x) & 0x55555555))


/*
3 conditions to check for Power of 16
    1. Positive Number
    2. Check if power of 2 and ensure only 1 bit is set 
    3. Check if the set bit is in a 4th bit index position by ANDing with 1(0001) mask
*/
#define pow_16(x) (((x)>0) && !((x) & (x-1)) && ((x) & 0x11111111))


int main() {
    int num;
    int test_nums[] = {16, 5, 1, 8, 64, 0, -4, 4096, 256};
    int size = sizeof(test_nums) / sizeof(test_nums[0]);

    for (int i = 0; i < size; i++) {
        num = test_nums[i];
        if (pow_four(num)) {
            printf("%d is a power of 4\n", num);
        } else {
            printf("%d is not a power of 4\n", num);
        }

        if (pow_16(num)) {
            printf("%d is a power of 16\n\n", num);
        } else {
            printf("%d is not a power of 16\n\n", num);
        }
    }

    return 0;
}