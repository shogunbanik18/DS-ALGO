class Solution {
public:
//   tc:O(nlogn)+o(n)
    int arrayPairSum(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,count=0;
        while(i<n)
        {
            count+=min(nums[i],nums[i+1]);
            i=i+2;
        }
        return count;
    }
};
