#include<iostream>
#include<cstring>

void compressString(std::string str)
{
    std::string ans = "";
    for(int start = 0; start < str.length(); start++)
    {
        if (start + 1 < str.length() && str[start] == str[start + 1]) // Safety check for bounds followed by comparing with adjacent character
        {
            int count = 1;
            int temp = start;
            while(temp + 1 < str.length() && str[temp] == str[temp + 1]){ // Same safety check 
                count++;
                temp++;
            }
            ans  = ans + (str[start] + std::to_string(count)); // Append the character and its count to the answer string
            start = temp;
        } else {
            ans += str[start]; // If not repeated, append the character directly to the answer string
        }

    }
    std::cout<<"final string is "<<ans<<std::endl;
}

int main() 
{ 
    std::string temp = "AAABBCDDDD";
    compressString(temp);
    return 0;
}
