#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count0=0;
        int count1=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                count1++;
            }
            else if(s[i]=='0')
            {
                count0++;
            }
        }
        int ans=max(0,min(count0,count1)-1);
        cout<<ans<<endl;
    }
}
