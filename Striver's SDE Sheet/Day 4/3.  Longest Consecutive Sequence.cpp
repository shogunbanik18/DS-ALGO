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
    
//     most optimal solution 
    
    
//     Approach: We will first push all are elements in the HashSet. Then we will run a for loop and check for any number(x) 
//         if it is the starting number of the consecutive sequence by checking if the HashSet contains (x-1) or not. If ‘x’ is the starting 
//             number of the consecutive sequence we will keep searching for the numbers
//         y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present in the HashSet. Using this 
//                 we can calculate the length of the longest consecutive subsequence. 
   
     // using hashset 
    // tc:o(n)+o(n)+o(n)
    // sc:o(n)
     int longestConsecutive(vector<int>& nums)
     {    
            int n=nums.size();
            unordered_set<int>s;
            for(auto a:nums)
            {
                s.insert(a);
            }

            int maxi=0;
            for(auto x:nums)
            {
                if(!(s.find(x-1)!=s.end()))
                {
                    int currentnum=x;
                    int currentstreak=1;

                    while(s.find(currentnum+1)!=s.end())
                    {
                        currentnum+=1;
                        currentstreak+=1;
                    }
                    maxi=max(maxi,currentstreak);
                }
            }
            return maxi;
     }
    
};



// using optimised approach 
// tc : o(n)
// sc : o(n)
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        
        for(auto x : nums)
        {
            mp[x]++;
        }
        
        for(auto x : nums)
        {
            if(mp.find(x-1)!=mp.end())
            {
                continue;
            }
            
            else
            {
                int size = 1;
                int p = x +1;
                while(mp.find(p)!=mp.end())
                {
                    p+=1;
                    size++;
                }
                ans = max(ans,size);
            }
        }
        return ans;
    }
};
