#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    while(t--)
    {
        int n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        int max=0,item;
        int i=0,j;
        while(i<n)
        {
            int count=1;
            j=i+1;
            while(j<n)
            {
                if(arr[i]==arr[j] and j!=i+1)
                {
                    count+=1;
                    if(j<n-1 and arr[j]==arr[j+1])
                    {
                        j+=1;   
                    }
                }
                j+=1;
            }
            if(count>max)
            {
                max=count;
                item=arr[i];
            }
            i+=1;
        }
        cout<<item<<endl;
    }
    return 0;
}
