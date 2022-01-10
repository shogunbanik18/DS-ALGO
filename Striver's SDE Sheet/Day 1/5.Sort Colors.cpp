class Solution {
public:
    // Approach 1 :
    // tc : O(NlogN)
    // sc: O(1)
    void sortColors(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
    }
    
    // Approach 2
    // tc: O(N) + O(N)
    // sc: O(N) for vector v
    void sortColors(vector<int>& nums)
    {
        int count1=0,count2=0,count3=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count1++;
            }
            else if(nums[i]==1)
            {
                count2++;
            }
            else
            {
                count3++;
            }
        }
        vector<int>v;
        while(count1--)
        {
            v.push_back(0);
        }
        while(count2--)
        {
            v.push_back(1);
        }
        while(count3--)
        {
            v.push_back(2);
        }
        for(int i=0;i<v.size();i++)
        {
            nums[i]=v[i];
        }
    }    
    
    // using sliding window approach 
    // Dutch National flag algorithm 
    // tc: O(N)
    // sc: O(1)
    void swap1(vector<int>&nums,int a,int b)
    {
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    void sortColors(vector<int>& nums)
    {
        int n=nums.size();
        int mid=0;
        int l=0;
        int r=n-1;
        while(mid<=r)
        {
            if(nums[mid]==0)
            {
                swap1(nums,mid,l);
                mid++;
                l++;
            }
            else if(nums[mid]==2)
            {
                swap1(nums,mid,r);
                r--;
            }
            else
            {
                mid++;
            }
        }
    }
};
