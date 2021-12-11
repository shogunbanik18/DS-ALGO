#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n,k;
        string s ;
        cin>>n>>k;
        cin>>s;
        
        int ans=0;
        int count =0;
        
        int i=1;
        
       for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                count=0;
            }
            
            if(s[i]=='0')
            {
                count++;
            }
               
            if(count==k)
            {
                count=0;
                ans=ans+1;
            }
            
        }
        cout<<ans<<endl;
    }
}
