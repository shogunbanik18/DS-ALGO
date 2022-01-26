#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    
    int spaces=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
        {
            spaces+=1;
        }
    }
    int words=spaces+1;
    cout<<words<<endl;
}
