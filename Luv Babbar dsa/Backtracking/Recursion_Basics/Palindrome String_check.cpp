#include<bits/stdc++.h>
using namespace std;

// TC :o(n)
// SC :o(n)
bool checkpalindrome(string &s)
{
    bool ans=true;
    int n=s.length();
    int l=0;
    int h=n-1;
    
    while(l<h)
    {
        if(s[l]!=s[h])
        {
            ans=false;
            break;
        }
        l++;
        h--;
    }
    return ans;
}

// tc :O(N/2)
// SC: O(N/2)
bool f(int i,string &s)
{
    int n=s.length();
    if(i>=n/2)
    {
        return true;
    }
    if(s[i]!=s[n-1-i])
    {
        return false;
    }
    return f(i+1,s);
}

int main()
{
    string s="MADAM";
    // cout<<checkpalindrome(s)<<endl;
    cout<<f(0,s)<<endl;
    return 0;
}
