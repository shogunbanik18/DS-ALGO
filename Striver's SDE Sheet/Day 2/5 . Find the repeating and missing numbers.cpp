#include<bits/stdc++.h>
using namespace std;

// using extra space method subs array 
//  Using Count Sort
// Hashing 
// Intuition + Approach:
// tc:O(N)+o(N)
// sc:o(n)
vector<int> find_missing_repeating(vector<int> array)
{
    int n=array.size();
    vector<int>ans;
    vector<int>subs(n+1,0);
    for(int i=0;i<n;i++)
    {
        subs[array[i]]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(subs[i]>1 or subs[i]==0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// Using Maths 
// tc: O(N) 
// Space Complexity: O(1) As we are NOT USING EXTRA SPACE
// Intuition + Approach:
vector<int> find_missing_repeating(vector<int> array)
{
    vector<int>ans;
    long long int n=array.size();
    long long int s=(n*(n+1))/2;
    long long int p=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++)
    {
        s-=array[i];
        p-=array[i]*array[i];
    }
    int missing =(s+p/s)/2;
    int repeating=missing-s;
    ans.push_back(missing);
    ans.push_back(repeating);
    return ans;
}

// xor method 
// again 
// using xor approach 
vector<int> find_missing_repeating(vector<int> arr)
{
    int xor1;
    int set_bit_no;
    int i;
    int x=0;
    int y=0;
    int n=arr.size();
    
    xor1=arr[0];
    for(int i=1;i<n;i++)
    {
        xor1=xor1^arr[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        xor1=xor1^i;
    }
    
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] and set_bit_no)
        {
            x=x^arr[i];
        }
         else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }
    
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }
    
     int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0)
        return {y, x};
    
    return {x, y};
}

int main()
{
    vector<int>array={3,1,2,5,3};
    vector<int>arr= find_missing_repeating(array);
    for(auto x:arr)
    {
        cout<<x<<" ";
    }
}
