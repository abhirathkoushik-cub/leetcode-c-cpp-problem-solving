#include<iostream> 
#include<cstring>

void* myMemMove(void* dest, const void* src, size_t n) {
    char* d = (char*)dest; // Obtain starting address of destination
    const char* s = (const char*)src; // Obtain starting address of source

    if (d == s || n == 0) return dest; // Cannot copy if source and destination are the same or if n is zero

    // Check if the destination is before the source in memory
    if (d < s) {
        // Safe to copy forward as there cannot be any overlap
        size_t i = 0;
        while(i < n) {
            d[i] = s[i];
            i++;
        }
    } else {
        /* Copy backward to prevent overwriting source.
        Here, there may be an overlap between the source and destination,
        or desination may be completely after the source, without overlap.
        In both cases, copying backward ensures that we do not overwrite the source data before it is copied.
        */
       size_t i = n;
       while(i > 0) {
        i--; // Decrement i before copying to avoid out-of-bounds access
        d[i] = s[i]; // Copy from end to start
       }
    }
    return dest;
} 

int main() { 
    char csrc[100] = "Geeksfor";
    myMemMove(csrc+5, csrc, strlen(csrc)+1); 
    printf("%s", csrc); 
    return 0; 
}
