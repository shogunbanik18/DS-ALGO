class Solution {
public:
    // using hashset 
    // tc:o(nlogn)+o(n)
    // sc:o(n)
    int removeDuplicates(vector<int>& nums) 
    {
        int n=nums.size();
        set<int>set;
        for(int i=0;i<nums.size();i++)
        {
            set.insert(nums[i]);
        }
        int k=set.size();
        int j=0;
        for(auto x:set)
        {
            nums[j]=x;
            j++;
        }
        return k;
    }
    
    // using 2 pointer approach 
    // tc:o(n)
    int removeDuplicates(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        int i=0 ;
        for(int j=1;j<n;j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
