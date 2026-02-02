/*
If you have several functions
uint8 func0(uint8 input_arg)
uint8 func1(uint8 input_arg)
…
uint8 func10(uint8 input_arg)
 
Implement a solution that will execute funcx() where “x” is the value of another variable
*/

#include <stdio.h>
#include <stdint.h>

uint8_t func0(uint8_t input_arg)
{
    printf("%d from 0", input_arg);
}

uint8_t func1(uint8_t input_arg)
{
    printf("%d from 1", input_arg);
}

uint8_t func2(uint8_t input_arg)
{
    printf("%d from 2", input_arg);
}

int main()
{
    int x = 0; uint8_t temp = 5;

    uint8_t (*func_arr[])(uint8_t) = {func0, func1, func2}; // Declaring an Array of Function Pointers

    func_arr[x](temp); // Calling the function to be executed through index of the Array of Function Pointers

    return 0;
}
