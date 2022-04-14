// longest increasing subsequence
// longest (differnece ==1 ) subsequence

// tc : o(n^2) + o(nlogn)
// sc : o(1)

class Solution 
{
public:
    
    bool compare(string &s1 ,string &s2)
    {
        if(s1.size()!=s2.size() + 1 )
        {
            return false;
        }
        int i = 0;
        int j = 0;
        
        while(i<s1.size())
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            
            else
            {
                i++;
            }
        }
        
        if(i==s1.size() and j ==s2.size() )
        {
            return true;
        }
        return false;
    }
    
    static bool comp(string &s1 ,string& s2)
    {
        return s1.size()< s2.size();
    }
    
    int longestStrChain(vector<string>& nums) 
    {
        
        sort(nums.begin(),nums.end(),comp);
        
        int n = nums.size();
        vector<int> dp (n,1);
        
      
        int maxi = 1;
        
        for(int ind = 1 ; ind <n;ind++)
        {
            for(int prevind = 0; prevind< ind ; prevind++)
            {
                if(compare(nums[ind] ,nums[prevind]) and 1 + dp[prevind] >dp[ind] )
                {
                    dp[ind] = 1 + dp[prevind];
                   
                }
            }
            if(dp[ind]>maxi)
            {
                maxi = dp[ind];
            }
        }
        
        return maxi;
    }
};
