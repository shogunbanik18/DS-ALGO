  // using the concept of array preprocessing 
    // tc:o(n)+o(n)+o(n)
    // sc:o(1)
class Solution {
public:
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
};
