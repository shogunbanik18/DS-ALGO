#include<bits/stdc++.h>

// tc:o(n) + o(n)
// sc:o(n)
vector<int> nextGreater(vector<int> &arr, int n) 
{
    stack <int> st;
    vector<int>ans(n,0);
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() and arr[i]>=st.top())
        {
            st.pop();
        }
     	if(i<n)
        {
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            else
            {
                ans[i]=-1;
            }
        }
        st.push(arr[i]);
    }
	return ans;
}

// Leetcode 
class Solution {
public:
    // use of unordered map and stack 
    // tc:o(n)+o(n)+o(nlogn)
    // sc:o(n)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();
        
        unordered_map<int,int>mp;
        stack<int>st;
        for(int j=n2-1;j>=0;j--)
        {
            while(!st.empty() and nums2[j]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[nums2[j]]=-1;
            }
            else
            {
                mp[nums2[j]]=st.top();
            }
            st.push(nums2[j]);
        }
        
        vector<int>ans;
        for(auto x:nums1)
        {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};


// nge 1  gfg 
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long>st;
        vector<long long> v(n,0);
        
        // traversing from the back 
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                v[i] = -1;
            }
            else
            {
                v[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        return v;
    
    }
};
