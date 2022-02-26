class Solution {
public:
    // using Brute Force
//     # TLE
    // tc:o(n*k)
    // sc:o(1)
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<=n-k;i++)
        {
            int maxi=nums[i];
            for(int j=i;j<=i+k-1;j++)
            {
                maxi=max(maxi,nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
    
    // optimised time complexity 
    // nge  + deque
    // tc:o(n)
    // sc:o(k) amortised 
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        
        for(int i=0;i<n;i++)
        {
            if(!dq.empty() and dq.front()==i-k)
            {
                dq.pop_front();
            }
            
            while(!dq.empty() and nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
       return ans;
    }
};
