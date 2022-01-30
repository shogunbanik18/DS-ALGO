class Solution {
public:
    // Brute force 
    // tc:O(N)
    // sc: O(n)
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(k>n)
        {
            k=k%n;
        }
        int count=n-k-1;
        vector<int>v;
        for(int i=count+1;i<n;i++)
        {
            v.push_back(nums[i]);
        }
        for(int i=0;i<=count;i++)
        {
            v.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=v[i];
        }
    }
    
    // tc:O(n)
    // sc:o(1)
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(k>n)
        {
            k=k%n;
        }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
    
    tc:O(N)
    sc:o(1)
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(k>n)
        {
            k=k%n;
        }
        int count=n-k;
        reverse(nums.begin(),nums.begin()+count);
        reverse(nums.begin()+count,nums.end());
        reverse(nums.begin(),nums.end());
    }
    
};
