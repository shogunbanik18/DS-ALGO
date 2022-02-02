class Solution {
public:
    // brute force 
    // tc:o(nlogn)+o(n*n*n)
    // sc:o(1)+o(n) for set
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>s;
        vector<vector<int>>v;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        s.insert(temp);
                    }
                }
            }
        }
        for(auto x:s)
        {
            v.push_back(x);
        }
        return v;
    }
};
