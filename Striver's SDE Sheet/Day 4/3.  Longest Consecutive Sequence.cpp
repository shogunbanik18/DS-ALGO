class Solution {
public:
    // using brute force 
    // tc:O(nlogn)+o(n)
    // using the kadance arrya technique
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.empty())
        {
            return 0;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int prev=nums[0];
        int ans=1;
        int curr=1;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==prev+1)
            {
                curr++;
            }
            else if(nums[i]!=prev)
            {
                curr=1;
            }
                
            prev=nums[i];
            ans=max(ans,curr);
        }
        return ans;
    }
    
    // most optimal solution 
    // using hashset 
    // tc:O(N)+O(N)+O(N)
     int longestConsecutive(vector<int>& nums)
     {
         set<int>hashSet;
         for(auto num:nums)
         {
             hashSet.insert(num);
         }
         
         int longeststreak=0;
         for(int num:nums)
         {
             if(!hashSet.count(num-1))
             {
                 int currentnum=num;
                 int currentstreak=1;

                 while(hashSet.count(currentnum+1))
                 {
                     currentnum+=1;
                     currentstreak+=1;
                 }
                 longeststreak=max(longeststreak,currentstreak);
             }
         }
         return longeststreak;
     }    
};
