#include<bits/stdc++.h>
using namespace std;
// tc:O(N)/
// sc:o(1)
int main()
{
    string str;
    getline(cin,str);
    
    string s="";
    for(int i=0;i<str.length();i++)
    {
        s+=tolower(str[i]);
    }
    
    int spaces=0,vowels=0,consontants=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            spaces++;
        }
        else if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')
        {
            vowels++;
        }
        else
        {
            consontants++;
        }
    }
    cout<<"vowels: "<<vowels<<endl;
    cout<<"spaces: "<<spaces<<endl;
    cout<<"consontants: "<<consontants<<endl;
    return 0;
}
