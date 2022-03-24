// Greedy Approach 
class Solution
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        
        int count = nums[0];
        
        for(int i=0;i<n;i++)
        {
            count = max(count,nums[i]);
            if(count==0 and i!=n-1)
            {
                return false;
            }
            
            else
            {
                count--;
            }
        }
        return true;
    }
};
