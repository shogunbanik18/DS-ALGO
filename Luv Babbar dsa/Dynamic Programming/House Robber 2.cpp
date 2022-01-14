// Leetcode
class Solution {
public:
    
    // Bottom Up dp with space optimisation 
    // tc:o(2^n)
    // sc:o(1)+O(n)+o(n)
    int maximumrobber(vector<int>&nums)
    {
         int n=nums.size();
         int prev1=nums[0];
         int prev2=0;
         
         for(int i=1;i<n;i++)
         {
             int take =nums[i];
             if(i>1)
             {
                 take+=prev2;
             }
             int nottake=0+prev1;
             int curri=max(take,nottake);
             prev2=prev1;
             prev1=curri;
         }
        return prev1;
    }
    
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        // base case 
        if(n==1)
        {
            return nums[0];
        }
        vector<int>v1,v2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                v1.push_back(nums[i]);
            }
            if(i!=n-1)
            {
                v2.push_back(nums[i]);
            }
        }
        return max(maximumrobber(v1),maximumrobber(v2));   
    }  
};



// Another solution 

long long int maximumNonAdjacentSum(vector<int> &nums)
{
    int n=nums.size();
    long long int prev1=nums[0];
    long long int prev2=0;
    for(int i=1;i<n;i++)
    {
        long long int take=nums[i];
        if(i>1)
        {
            take+=prev2;
        }
        long long int nottake=0+prev1;
        
        long long int curri=max(take,nottake);
        prev2=prev1;
        prev1=curri;
    }
    return prev1;;
    // Write your code here.
}


long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int>v1,v2;
    int n =valueInHouse.size();
    if(n==1)
    {
        return valueInHouse[0];
    }
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            v1.push_back(valueInHouse[i]);
        }
        if(i!=n-1)
        {
            v2.push_back(valueInHouse[i]);
        }
    }
    return max(maximumNonAdjacentSum(v1),maximumNonAdjacentSum(v2));
    
    // Write your code here.
}
