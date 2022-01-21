class Solution {
public:
    // Brute force 
    // tc:O(N^2)
    // SC:O(1)
//   integer overflow case Handle Properly
    int reversePairs(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;i++)
            {
                if(nums[i]>2*nums[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    // using merge sort divide and conqueur appraoch 
    // tc: o(nlogn)+o(n) for merging+ o(n) for counting
    // sc:o(n) for temp vector
    int merge(vector<int>&nums,int low,int mid,int high)
    {
        int count=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high and nums[i]>2LL*nums[j])
            {
                j++;
            }
            count+=(j-(mid+1));
        }
        
        // normal merging function 
        vector<int>temp;
        int left=low;
        int right=mid+1;
        while(left<=mid and right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        
        while(left<=mid)
        {
             temp.push_back(nums[left++]);
        }
        while(right<=high)
        {
            temp.push_back(nums[right++]);
        }
        
        // copying back to the original array nums
        for(int i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
        return count;
    }
    
    int mergesort(vector<int>&nums,int l,int r)
    {
        if(l>=r)
        {
            return 0;
        }
        int mid=l+(r-l)/2;
        int inv=mergesort(nums,l,mid);
        inv+=mergesort(nums,mid+1,r);
        inv+=merge(nums,l,mid,r);
        return inv;
    }
    
    int reversePairs(vector<int>& nums) 
    {
         int n=nums.size();
         return mergesort(nums,0,n-1);
    }
};
