class Solution {
public:
    // using count sort method 
    // tc:o(n)+o(n)
    // sc:o(n)
    int missingNumber(vector<int>& nums)
    {    
        int n=nums.size();
        vector<int>v(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            v[nums[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0)
            {
                ans=i;
            }
        }
        return ans;
    }
};
