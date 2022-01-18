#include<bits/stdc++.h>
using namespace std;

// more of fibonacci 
int cal(int n)
{
    if(n<=1)
    {
        return n;
    }
    return cal(n-1)+cal(n-2);
}

int countstairs(int index)
{
    return cal(index+1);
}

int main()
{
    int n;
    cin>>n;
    cout<<countstairs(n)<<endl;
    return 0;
}
