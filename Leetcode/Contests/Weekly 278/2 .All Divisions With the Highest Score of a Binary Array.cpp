// using Prefix sum 
class Solution {
public:
     vector<int> maxScoreIndices(vector<int>& nums) 
     {
         int n=nums.size();
         int left[n],right[n];
         
         int count=0;
         for(int i=0;i<n;i++)
         {
             if(nums[i]==0)
             {
                 count++;
             }
             left[i]=count;
         }
         
         count=0;
         for(int i=n-1;i>=0;i--)
         {
             if(nums[i]==1)
             {
                 count++;
             }
             right[i]=count;
         }
         
         int dp[n+1];
         int mx=-1;
         int val;
         for(int i=0;i<=n;i++)
         {
             if(i==0)
             {
                 val=right[i];
             }
             else if(i==n)
             {
                 val =left[n-1];
             }
             else
             {
                 val =left[i-1]+right[i];
             }
             dp[i]=val;
             mx=max(mx,val);
         }
         
         vector<int>v;
         for(int i=0;i<=n;i++){
            if(dp[i]==mx){
                v.push_back(i);
            }
        }
        
        return v;
     }
    
};
