#include<bits/stdc++.h>
using namespace std;

int main()
{
//   tc:O(n)
    string str;
    cin>>str;
    
    string res="";
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        res+=tolower(str[i]);
    }
    string final="";
    for(int i=0;i<res.size();i++)
    {
        if(res[i]=='a' or res[i]=='e' or res[i]=='o' or res[i]=='i' or res[i]=='u' or res[i]=='y')
        {
            continue;
        }
        final=final+"."+res[i];
    }
    cout<<final<<endl;
}
