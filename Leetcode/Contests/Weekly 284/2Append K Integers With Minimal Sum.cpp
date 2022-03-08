class Solution {
public:
    
    // tricky problem 
    // causes tle due to large value of k 
//     long long minimalKSum(vector<int>& nums, int k) 
//     {
//         map<int,int>mp;
//         for(auto x:nums)
//         {
//             mp[x]++;
//         }
        
//         // for(auto y:mp)
//         // {
//         //     cout<<y.first<< " "<<y.second<<endl;
//         // }
        
//         long long sum=0,count=0;
//         int n=nums.size();
//         for(int i=1;i<=1e8-1;i++)
//         {
//             if(mp.find(i)==mp.end() and count<k)
//             {
//                 sum+=i;
//                 count++;
//             }
//         }
//         return sum;
//     }
    
    // method 
    // find the minimum sum of k elements by the formula k*k+1/2
    // traverse through the set and find the elemts les than or equal to k 
    long long minimalKSum(vector<int>& nums, int k) 
    {
        long long sum= ((long) k)*((long)(k+1))/2;
        set<int>st(nums.begin(),nums.end());
        for(auto x:st)
        {
            if(x<=k)
            {
                // if a number was added that already existed in nums, remove that and add next number (k+1)
                sum+= (1+k)-x;
                k++;
            }
            else
            {
                break;
            }
        }
        return sum;
    }
};
