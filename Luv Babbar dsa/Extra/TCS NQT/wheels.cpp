#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,w;
    cin>>v>>w;
    
    if(w%2!=0 or w<2 or w<=v)
    {
        cout<<"INVALID INPUT"<<endl;
        return 0;
    }
    
    float x=((4*v)-w)/2;
    cout<<"TW "<<x<<" "<<"FW "<<v-x<<endl;
}
