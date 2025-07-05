#include <stdio.h>

void i_j_bit_swap(int *num, int i_index, int j_index)
{
    int *temp_ptr=num;
    
    // Obtain the values stored in ith and jth bits
    int i_th_bit = ((*num)>>i_index)&1; // Shift to the right by 'i' index to reach LSB and then &1 to isolate
    int j_th_bit = ((*num)>>j_index)&1;
    
    // Clear both the bits always
    *(num) = (*num) & ~(1<<i_index); 
    *(num) = (*num) & ~(1<<j_index);
    
    // Swap and Set bits
    *(num) = *(num) | (j_th_bit<<i_index); // Here, instead of '1<<n', we are using 'j_bit<<i_index' for the swap
    *(num) = *(num) | (i_th_bit<<j_index);
}

int main()
{
    int num=129; //1000 0001
    int i_index=5;
    int j_index=7;

    i_j_bit_swap(&num, i_index, j_index);
    printf("Number after swap is %d", num); //0010 0001

    return 0;
}