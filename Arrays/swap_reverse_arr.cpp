#include <iostream>
using namespace std;

void reverse_arr(int arr[], int size)
{
    int start = 0, end = size-1;
    
    // Here, no need of start<=end as the middle element will remain as is
    while(start < end)
    {
        /*
        Using the Inbuilt C++ STL function swap(a, b).
        Both the arrays should be of the same size and type.
        */
        swap(arr[start], arr[end]); 
        start++;
        end--;
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    reverse_arr(arr, n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}