class Solution {
public:    
    // Naive solution 
    // Tc:O(N^3)
       int maxSubArray(vector<int>& nums)
       {
           int n=nums.size();
           if(n==1)
           {
               return nums[0];
           }

           int sum;
           int max1=INT_MIN;
           for(int i=0;i<n;i++)
           {
               for(int j=i;j<n;j++)
               {
                   sum=0;
                   for(int k=i;k<=j;k++)
                   {
                       sum=sum+nums[k];
                       if(sum>max1)
                       {
                           max1=sum;
                       }
                   }
               }
           }
           return max1;
       }

      // tc: O(N^2)
       int maxSubArray(vector<int>& nums)
       {
           int n=nums.size();
           if(n==1)
           {
               return nums[0];
           }

           int max1=INT_MIN;
           for(int i=0;i<n;i++)
           {
               int currsum=0;
               for(int j=i;j<n;j++)
               {
                   currsum=currsum + nums[j];
                   if(currsum>max1)
                   {
                       max1=currsum;
                   }
               }
           }
           return max1;
       }
    
        // tc:O(N)
        // sc:O(1)
        // kadanes Alogo
        // Maximum subarray Sum 
        int maxSubArray(vector<int>& nums) 
        {        
            int n=nums.size();
            int cursum=0;
            int maxsum=INT_MIN;
            for(int i=0;i<n;i++)
            {
                cursum=cursum+nums[i];
                if(maxsum<cursum)
                {
                    maxsum=cursum;
                }

                if(cursum<0)
                {
                    cursum=0;
                }
            }
            return maxsum;
        }
};
