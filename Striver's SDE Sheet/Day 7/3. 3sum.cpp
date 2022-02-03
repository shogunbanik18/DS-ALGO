class Solution {
public:
//     Brute force 
//     tc:o(n^3logm)
//     sc:o(m) unordered set space 
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int n=nums.size();
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
            ans.push_back(x);
        }
        return ans;
    }
    
    // using hashing based approach 
    // check 
    // vector<vector<int>> threeSum(vector<int>& nums)
    // {
    //     int n=nums.size();
    //     vector<vector<int>>v;
    //     unordered_map<int,int>mp;
    //     for(int i=0;i<n;i++)
    //     {
    //         mp[nums[i]]++;
    //     }
    //     for(int i=0;i<n-2;i++)
    //     {
    //         mp[nums[i]]--;
    //         for(int j=i+1;j<n;j++)
    //         {
    //             mp[nums[j]]--;
    //             int target =-(nums[i]+nums[j]);
    //             if(mp.find(target)!=mp.end())
    //             {
    //                 vector<int>temp;
    //                 temp.push_back(nums[i]);
    //                 temp.push_back(nums[j]);
    //                 temp.push_back(nums[target]);
    //                 v.push_back(temp);
    //             }
    //             mp[nums[j]]++;
    //         }
    //         mp[nums[i]]++;
    //     }
    //     return v;
    // } 
    
    // Optimised Approach 
    // avod duplicates +sorting +two pointer approach 
    // tc:o(n*n)
    // sc:o(m) auxiliary stack spaceis o(1)
    // case of avoiding duplicates check ery adjacent elements 
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i==0 or (i>0 and nums[i]!=nums[i-1]))
            {
                int target=-nums[i];
                int j=i+1;
                int k=n-1;
                while(j<k)
                {
                    if(nums[j]+nums[k]==target)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        v.push_back(temp);
                        // Avoiding Duplicates 
                        while(j<k and nums[j]==nums[j+1])
                        {
                            j++;
                        }
                        while(j<k and nums[k]==nums[k-1])
                        {
                            k--;
                        }
                        j++;
                        k--;
                    }
                    else if(nums[j]+nums[k]<target)
                    {
                        j++;
                    }
                    else
                    {
                       k--;
                    }
                }
            }
        }
        return v;
    } 
};



