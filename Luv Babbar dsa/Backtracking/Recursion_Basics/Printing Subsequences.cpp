#include<bits/stdc++.h>
using namespace std;

// tc :2^n *n
// sc:O(N)
void print_subsequence(int ind,vector<int>&ds,vector<int>&arr,int n)
{
    if(ind==n)
    {
        for(auto x:ds)
        {
            cout<<x<<" ";
        }
        if(ds.size()==0)
        {
            cout<<" "<<endl;
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    // take 
    print_subsequence(ind+1,ds,arr,n);
    
    // not take condition 
    ds.pop_back();
    print_subsequence(ind+1,ds,arr,n);
}

int main()
{
    vector<int>arr ={3,1,2};
    int n=arr.size();
    vector<int>ds;
    print_subsequence(0,ds,arr,n);
    return 0;
}
