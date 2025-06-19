// Leetcode: https://leetcode.com/problems/valid-palindrome/?envType=problem-list-v2&envId=oizxjoit

bool isPalindrome(char* s) {   
    
    // IMP: Dynamic memory allocation for Size of the Answer String (temp)
    size_t len=strlen(s);
    char *temp = (char*)malloc(len+1);

    int i=0;
    while(*s != '\0')
    {
        /* Checking for special characters, other than alpahbets and numbers.
           These will not be copied to the Answer string. */
        if (!isalnum(*s)){ 
            s++;
            continue;
        }
        else{
            temp[i]=tolower(*s); // Lowering the case for character consistency in palindrome check
            i++;
            s++;
        }
    }
    temp[i]='\0'; // IMP: As the size of string might reduce than malloced value, terminate the string to avoid garbage values

    // Checking for a palindrome in the Answer string using 2 variable approach
    int left=0, right=strlen(temp)-1;
    while(left < right){
        if(temp[left] != temp[right])
            return false;
        left++;
        right--;
    }
    return true;
}