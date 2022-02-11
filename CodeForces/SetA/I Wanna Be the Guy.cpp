#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   
   set<int>k;
   int p;
   cin>>p;
   int arr[p];
   for(int i=0;i<p;i++)
   {
       cin>>arr[i];
       k.insert(arr[i]);
   }
   
   int q;
   cin>>q;
   int brr[q];
   for(int i=0;i<q;i++)
   {
       cin>>brr[i];
       k.insert(brr[i]);
   }
   
   if(k.size()==n)
   {
       cout<<"I become the guy."<<endl;
   }
   else
   {
       cout<<"Oh, my keyboard!"<<endl;
   }
  
  
}
