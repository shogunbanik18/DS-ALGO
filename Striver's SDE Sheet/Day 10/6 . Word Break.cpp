// // using Recursion + Backtracking TLE
// // tc : o(2^n)
// // sc : o(n) stack space
// class Solution
// {
// public:
    
//     bool f(int ind , string s , map<string,int>&mp )
//     {
//         int n = s.size();
//         if(ind==n)
//         {
//             return true;
//         }
        
//         for(int  i = ind ; i <n; i++)
//         {
//             if( mp.find(s.substr(ind , i-ind+1 )) != mp.end() and f(i+1 ,s, mp)==true)
//             {
//                 return true;
//             }
//         }
        
//         return false;
//     }
    
//     bool wordBreak(string s, vector<string>& wordDict)
//     {
//         map<string,int> mp;
        
//         for(auto x : wordDict)
//         {
//             mp[x]++;
//         }
        
//         // debug
//         // for(auto x : mp)
//         // {
//         //     cout<<x.first<<" "<<x.second<<endl;
//         // }
        
//         return f(0,s,mp);
        
//     }
// };


// // using Optimisation using Memoisation dp
// // tc : o(n*n)
// // sc : o(n*n) + o(n) stack space
// class Solution
// {
// public:
    
//     bool f(int ind , string s , map<string,int>&mp ,vector<int> &dp)
//     {
//         int n = s.size();
//         if(ind==n)
//         {
//             return true;
//         }
        
//         if(dp[ind]!=-1)
//         {
//             return dp[ind];
//         }
        
//         for(int  i = ind ; i <n; i++)
//         {
//             if( mp.find(s.substr(ind , i-ind+1 )) != mp.end() and f(i+1 ,s, mp , dp )==true)
//             {
//                 return dp[ind] = true;
//             }
//         }
        
//         return dp[ind] = false;
//     }
    
//     bool wordBreak(string s, vector<string>& wordDict)
//     {
//         map<string,int> mp;
        
//         for(auto x : wordDict)
//         {
//             mp[x]++;
//         }
        
//         // debug
//         // for(auto x : mp)
//         // {
//         //     cout<<x.first<<" "<<x.second<<endl;
//         // }
        
//         // changing parameters 
//         int n = s.size();
//         vector<int>dp(n,-1);
        
//         return f(0,s,mp,dp);
        
//     }
// };


// using Optimisation using Tabulation dp
// tc : o(n*n)
// sc : o(n*n)
class Solution
{
public:
    
    bool f(int ind , string s , map<string,int>&mp ,vector<int> &dp)
    {
        int n = s.size();
        if(ind==n)
        {
            return true;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        for(int  i = ind ; i <n; i++)
        {
            if( mp.find(s.substr(ind , i-ind+1 )) != mp.end() and f(i+1 ,s, mp , dp )==true)
            {
                return dp[ind] = true;
            }
        }
        
        return dp[ind] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict)
    {
        map<string,int> mp;
        
        for(auto x : wordDict)
        {
            mp[x]++;
        }
        
        // debug
        // for(auto x : mp)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        // changing parameters 
        int n = s.size();
        vector<int>dp(n,-1);
        
        return dp[0],s,mp,dp);
        
    }
};
