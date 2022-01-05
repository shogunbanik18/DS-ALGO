// tc :O(N)
// sc: O(N)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // string s ="geeksforgeeks";
    string s="test string";
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    
    
    for(auto x:mp)
    {
        if(x.second>1)
        {
            cout<<x.first<<" "<<x.second<<endl;    
        }
    }
    return 0;
}
