#include <stdio.h>
#include <string.h>

int count_odd_arr(int *arr, int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] %2 != 0)
            count++;
    }
    return count;
}

int count_ch_in_str(char *str_temp, char find_ch)
{
    int count=0;
    for(int i=0;i<strlen(str_temp);i++)
    {
        if(str_temp[i] == find_ch)
            count++;
    }
    return count;
}

int main()
{
    int arr_temp[]={1,2,3,4,5,6};
    int n = sizeof(arr_temp)/sizeof(arr_temp[0]);
    printf("Number of odd numbers is  %d\n", count_odd_arr(arr_temp, n));

    char temp_str[]="abhirath";
    char tar_str='h';
    printf("Number of %c character in %s is %d", tar_str, temp_str, count_ch_in_str(temp_str, tar_str));
    return 0;
}