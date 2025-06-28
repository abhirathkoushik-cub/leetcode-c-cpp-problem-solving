#include <stdio.h>

#define SET_BIT(x,y) ((x) | (1<<(y)))
#define CLEAR_BIT(x,y) ((x) & ~(1<<(y)))

int main()
{
    int num=7;
    printf("%d", CLEAR_BIT(num, 2));
    return 0;
}