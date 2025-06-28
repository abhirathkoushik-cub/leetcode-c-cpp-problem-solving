#include <stdio.h>

void memcpy_func(int *arr1, int *arr2, int size)
{
    int *ptr1=arr1;
    int *ptr2=arr2;
    
    while(size>0)
    {
        /*
            Copying values from pointer1 (arr1) to pointer2 (arr2)
            Equivalently: 
                *ptr1 = *ptr2;
                ptr1 = ptr1 + 1;
                ptr2 = ptr2 + 1;
        */
        *ptr2++ = *ptr1++; 
        size--;
    }
    
}

int main()
{
    int arr[5]={1,3,5,7,9};
    int arr2[5];
    int size = sizeof(arr)/sizeof(arr[0]);
    
    memcpy_func(arr, arr2, size);
    
    for(int i=0;i<size;i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}