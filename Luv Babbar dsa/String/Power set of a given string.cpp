#include<bits/stdc++.h>
using namespace std;

// tc: O(2^n)
void powerset(string s,int i,string curr)
{
    if(i==s.length())
    {
        cout<<curr<<" ";
        return;
    }
    powerset(s,i+1,curr+s[i]);
    powerset(s,i+1,curr);
}

int main()
{
    string s;
    cin>>s;
    string curr=" ";
    powerset(s,0,curr);
    return 0;
}
