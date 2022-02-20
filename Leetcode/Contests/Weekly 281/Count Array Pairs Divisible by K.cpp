class Solution {
public:
    // Brute Force 
    // tc:o(n^2)
    // sc:o(1)
    long long countPairs(vector<int>& nums, int k) 
    {
        int n=nums.size();
        long long count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((nums[i]*nums[j]%k)==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    // optimised solution 
    // using hashmap and gcd 
    // number theory 
    // tc:o(n)
    // sc:o(n)
    long long countPairs(vector<int>& nums, int k) 
    {
        // all left gcds are stored here 
        unordered_map<int,int>mp;
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n;i++)
        {
            int gcd1= __gcd(nums[i],k);
            int gcd2 =k/gcd1;
            
            // if gcd itself gets divisible by k then 
            // no matter what number you multiply it will 
            // always be divisible 
            if(gcd2==1)
            {
                res+=i;
            }
            else
            {
                for(auto x:mp)
                {
                    if(x.first % gcd2==0)
                    {
                        res+=x.second;
                    }
                }
            }
            mp[gcd1]++;
        }
        return res;
    }
};
