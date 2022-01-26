#include<bits/stdc++.h>
using namespace std;

// tc:O(N)
// sc:O(1)
int main()
{
    string s;
    cin>>s;
    
    bool ans=true;
    int i=0;
    int j=s.length()-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            ans=false;
            break;
        }
        i++;
        j--;
    }
    cout<<ans<<endl;
}
