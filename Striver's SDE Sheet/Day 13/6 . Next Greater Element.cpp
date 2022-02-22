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
