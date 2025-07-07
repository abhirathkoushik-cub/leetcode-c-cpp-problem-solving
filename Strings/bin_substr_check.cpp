
/*
Check if a string contains all binary codes of size k (From Kapil Yadav Bin Man Notes)

Return True if every binary code of length 'k' is a substring of a given string 's'.
Else Return False.

s="00110110", k=2 then True
s="0110"m k=2 then False as "00" does not exist in string
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool all_codes(string s, int k)
{
    int size = s.size();
    if (k>size)
        return false; 
    
    unordered_set<string> str_set; // We are using 'set' here to remove duplicate entries in the size calculation
    for(int i=0;i<=size-k;i++) // size-k as we want only substrings of size 'k'
    {
        str_set.insert(s.substr(i,k)); // Inserting all substrings of size 'k' into the set
    }
    
    return str_set.size() == (1 << k); // Check if the total size of the set == 2^k. Return True if size matches, else False. 
}

int main()
{
    string temp_str="1000101110";
    int k=3;
    
    if(all_codes(temp_str,k))
        cout<<"All Binary Codes present"<<endl;
    else
        cout<<"All Codes Not Present"<<endl;

    return 0;
}