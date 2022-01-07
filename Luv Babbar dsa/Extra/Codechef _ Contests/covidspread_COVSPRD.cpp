#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        // care for d 
        long long int n,d,ans;
        cin>>n>>d;
        
        if(d==0)
        {
            ans=pow(1,d);
        }
        
        else if(d>0 and d<=10)
        {
            ans=pow(2,d);
        }
        
        else if(d<=20)
        {
            int x=d-10;
            long long int ans1 =pow(2,10);
            ans=ans1*pow(3,x);
        }
         
         else
        {
            cout<<n<<endl;
            continue;
        }
        
        // base case 
        if(n<ans)
        {
            cout<<n<<endl;
        }
        
        else
        {
            cout<<ans<<endl;
        }
    }
}
