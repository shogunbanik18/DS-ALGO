#include<bits/stdc++.h>
using namespace std;

void print(vector<int>box)
{
    for(int i=0;i<box.size();i++)
    {
        cout<<box[i]<<" ";
    }
}

void swap(vector<int>&box,int a,int b)
{
    int temp=box[a];
    box[a]=box[b];
    box[b]=temp;
}

void bubblesort(vector<int>&box)
{
    int n=box.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(box[j]>box[j+1])
            {
                swap(box,j,j+1);
            }
        }
    }
}

// void bubblesort(vector<int>&box)
// {
//     int n=box.size();
//   for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(box[i]>box[j])
//             {
//                 swap(box,i,j);
//             }
//         }
//     }
// }


int main()
{
    int n=7;
    vector<int>box={1,0,2,0,1,0,2};
    
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>box[i];
    // }
    
    bubblesort(box);
    // sort(box.begin(),box.end());
    print(box);
    return 0;
}
