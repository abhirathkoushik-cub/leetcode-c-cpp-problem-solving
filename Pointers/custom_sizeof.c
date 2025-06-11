#include <stdio.h>

/* 
(ptr)+1 advances the pointer by 1 object size (depending on the input type)
(char*)(ptr+1) gives the memory address of 1 object size past ptr, in bytes
Subtracting two (char*) pointers gives the number of bytes between them,
which will be the object size.
*/
#define custom_sizeof_ptr(ptr) ((char*)((ptr)+1) - (char*)(ptr))

int main()
{
    int a;
    // double a;
	
    // %zu indicates type size_t and unsigned decimal value. 
    // size_t is type-safe and works in both 32-bit or 64-bit platforms.
    printf("Size of a is %zu\n", custom_sizeof_ptr(&a));
    return 0;
}
