class Solution {
public:
    // Brute force
    // using set 
    // using 3 pointer + binary search(stL) 
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        
        set<vector<int>>sv;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int x = (long long)target - (long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                    if(binary_search(nums.begin()+k+1,nums.end(),x))
                    {
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(x);
                        sort(v.begin(),v.end());
                        sv.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>res(sv.begin(),sv.end());
        return res;
    }
    
    
    // using two pointer appraoch 
    // task of eliminating duplicates
    // Concept of checking duplicates
    // tc :O(N^3) 
    // sc:O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>res;
        if(nums.empty())
        {
            return res;
        }
        int n =nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int target3= target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                int target2=target3-nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r)
                {
                    int sum=nums[l]+nums[r];
                    if(sum<target2)
                    {
                        l++;
                    }
                    else if(sum>target2)
                    {
                        r--;
                    }
                    else
                    {
                        vector<int>v(4,0);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[l];
                        v[3]=nums[r];
                        res.push_back(v);
                        
                        // Processing the duplicates 
                        // checking for duplicates 
                        while(l<r and nums[l]==v[2])
                        {
                            l++;
                        }
                        
                        // processing the duplicates
                        while(l<r and nums[r]==v[3])
                        {
                            r--;
                        }
                    }
                }
                while(j+1<n and nums[j+1]==nums[j])
                    {
                        j++;
                    }
            }
            while(i+1<n and nums[i+1]==nums[i])
                    {
                        i++;
                    }
        }
        return res;
    }
};
