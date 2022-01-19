class Solution {
public:
    // brute force 
    // Tc: O(n^2)
    // picking up and counting the occurence of each element
//   Check the count of occurrences of all elements of the array one by one. Start from the first element of the array and count the number of times it occurs in the array. 
//     If the count is greater than the floor of N/2 then return that element as the answer. If not, proceed with the next element in the array and repeat the process.
    
    // using Hashing 
    // tc :O(N)or O(NlogN)
    // s:O(1)
    int majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second>(n/2))
            {
                ans=x.first;
            }
        }
        return ans;
    }
    
    // Moore's voting Algortihm 
    // optimised solution
    // tc:o(n)
    // sc:o(1)
    int majorityElement(vector<int>& nums) 
    {
        int count=0;
        int element=0;
        for(auto x:nums)
        {
            if(count==0)
            {
                element=x;
            }
            if(x==element)
            {
                count+=1;
            }
            else
            {
                count-=1;
            }
        }
        return element;
    }
};
