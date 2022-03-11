// Using gcd ,lcm and deuqe
class Solution {
public:
    long long gcd1(long long a,long long b)
    {
        if(a>b)
        {
            swap(a,b);
        }
        
        if(b==0)
        {
            return a;
        }
        return gcd(a,b%a);
    }
    
    long long lcm1(long long a,long long b)
    {
        long long ans= (a*b)/gcd(a,b);
        return ans;
    }
    
//     vector<int> replaceNonCoprimes(vector<int>& nums) 
//     {
//         vector<int>v;
//         int n=nums.size();
//         deque<int>dq;
        
//         for(int i=0;i<n;i++)
//         {
//             dq.push_back(nums[i]);
            
//             while(dq.size()>1)
//             {
//                 int gcd = gcd1(dq[dq.size()-1],dq[dq.size()-2]);
//                 if(gcd==1)
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     int ans = lcm(dq[dq.size()-1],dq[dq.size()-2]);
//                     dq.pop_back();
//                     dq[dq.size()-1]=ans;
//                 }
//             }
//         }
//         for(auto x:dq)
//         {
//             v.push_back(x);
//         }
//         return v;
    
    // using stack ds 
     vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<int>v;
        int n=nums.size();
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
            
            while(!st.empty() and gcd1(curr,st.top())>1)
            {
                curr=lcm1(curr,st.top());
                st.pop();
            }
            st.push(curr);
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

