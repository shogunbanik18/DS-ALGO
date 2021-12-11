#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int x,y,p,q;
        cin>>x>>y>>p>>q;
        
       
        int f1= x+p*10;
        int f2 =y+q*10;
        
        // cout<<f1<<" "<<f2<<endl;
        
        if(f1==f2)
        {
            cout<<"Draw"<<endl;
        }
        
        else if(f1<f2)
        {
            cout<<"Chef"<<endl;
        }
        else
        {
            cout<<"Chefina"<<endl;
        }
    }
}
