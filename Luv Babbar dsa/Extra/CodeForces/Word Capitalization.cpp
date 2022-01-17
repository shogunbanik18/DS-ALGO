#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    string res="";
    res += towupper(s[0]);
    for(int i=1;i<s.size();i++)
    {
        res+=s[i];
    }
    cout<<res<<endl;
}
