#include<iostream>
#include<string>
using namespace std;

bool check_palindrome(string str)
{
    for(int i=0;i<str.size()/2;i++)
    {
        if(str[i] != str[str.length()-1-i])
            return false;
    }
    return true;
}

int main()
{
    string s1="abcdcba";
    if (check_palindrome(s1))
        cout<<"Yes it is a Palindrome"<<endl;
    else 
        cout<<"No it is not a Palindrome"<<endl;
    return 0;
}
