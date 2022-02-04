class Solution {
public:
    // Using Brute force 
    // tc:o(n*n)
    // sc:o(1)
    int trap(vector<int>& height) 
    {
        int n=height.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int j=i;
            int leftmax=0,rightmax=0;
            while(j>=0)
            {
                leftmax=max(leftmax,height[j]);
                j--;
            }
            
            j=i;
            while(j<n)
            {
                rightmax=max(rightmax,height[j]);
                j++;
            }
            ans+=min(leftmax,rightmax)-height[i];
        }
        return ans;
    }
    
    // using the concept of array preprocessing 
    // tc:o(n)+o(n)+o(n)
    // sc:o(n)+o(n)
    int trap(vector<int>& height) 
    {
        int n=height.size();
        int left[n],right[n];
        
        int maxi=0;
        left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],height[i]);
        }
        
        int maxi2=0;
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }

    // using 2 pointer approach 
    // tc:o(n)
    // sc:o(1)
     int trap(vector<int>& height)
     {
         int n=height.size();
         int l=0;
         int r=n-1;
         int leftmax=0,rightmax=0;
         int res=0;
         while(l<=r)
         {
            if(height[l]<=height[r])
            {
                if(height[l]>=leftmax)
                {
                    leftmax=height[l];
                }
                else
                {
                    res+=leftmax-height[l];    
                }
                l++;
            }
            else
               {
                   if(height[r]>=rightmax)
                   {
                       rightmax=height[r];
                   }
                   else
                   {
                       res+=rightmax-height[r];
                   }
                   r--;
               }
         }
          return res;
     }
};
