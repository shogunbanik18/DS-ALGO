#include<bits/stdc++.h>
using namespace std;

// print subsequence with a given sum

void printS(int ind,vector<int>&ds,int s,int sum,int arr[],int n)
{
    if(ind==n)
    {
        if(s==sum)
        {
            for(auto x:ds)
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    ds.push_back(arr[ind]);
    s+=arr[ind];
    
    // take 
    printS(ind+1,ds,s,sum,arr,n);
    
    ds.pop_back();
    s-=arr[ind];
    
    // not take 
    printS(ind+1,ds,s,sum,arr,n);
}

int main()
{
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    printS(0,ds,0,sum,arr,n);
    return 0;
}


// Count No. of subsequences 
#include<bits/stdc++.h>
using namespace std;

// print subsequence with a given sum

// declaring global variable 
// bool flag=false;
int printS(int ind,vector<int>&ds,int s,int sum,int arr[],int n)
{
    if(ind==n)
    {
        if(s==sum )
        {
            // flag=true;
            for(auto x:ds)
            {
                cout<<x<<" ";
            }
            cout<<endl;
            return 1;
        }
        return 0;
    }
    
    ds.push_back(arr[ind]);
    s+=arr[ind];
    
    // take 
    int l=printS(ind+1,ds,s,sum,arr,n);
    
    ds.pop_back();
    s-=arr[ind];
    
    // not take 
    int r=printS(ind+1,ds,s,sum,arr,n);
    return l+r;
}

int main()
{
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    int x=printS(0,ds,0,sum,arr,n);
    cout<<"The total Number of pairs are: "<<x<<endl;
    return 0;
}
