/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    
    vector<int>v;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            v.push_back(1);
        }
        else if(s[i]=='2')
        {
            v.push_back(2);
        }
        else if(s[i]=='3')
        {
            v.push_back(3);
        }
    }
    sort(v.begin(),v.end());
    
    string res="";
    for(int i=0;i<v.size();i++)
    {
        if(i!=v.size()-1)
        {
            res+=to_string(v[i]);
            res+="+";
        }
        else
        {
            res+=to_string(v[i]);
        }
    }
    cout<<res<<endl;
    // for(auto x:v)
    // {
    //     cout<<x<<" ";
    // }
    return 0;
}
