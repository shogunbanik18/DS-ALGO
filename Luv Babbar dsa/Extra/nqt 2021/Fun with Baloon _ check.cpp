#include<bits/stdc++.h>
using namespace std;

void baloons(vector<char>&b)
{
    int flag=0;
    vector<char>v;
    
    unordered_map<char,int>mp;
    
    for(int i=0;i<b.size();i++)
    {
        mp[b[i]]++;
    }
    
    for(auto x:mp)
    {
        if(x.second % 2!=0)
        {
            flag=1;
            v.push_back(x.first);
        }
    }
    
    if(flag==1)
    {
        cout<<v[0]<<endl;
    }
    else
    {
        cout<<"All are even"<<endl;
    }
}

int main()
{
    vector<char>b ={'r','g','b','b','g','y','y'};
    // vector<char>b;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>b[i];
    // }
    baloons(b);
    return 0;
}
