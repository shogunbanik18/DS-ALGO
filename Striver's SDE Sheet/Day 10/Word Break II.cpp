
// // using the concept of recursion and backtracking 
// // tc : o(2^n)
// // sc : o(n) stack space
// class Solution 
// {
// public:
    
//     void f(int ind , string s , map<string,int>mp , vector<string> &ans , string ds)
//     {
//         int n = s.size();
//         if(ind==n)
//         {
//             // removing the trailing spaces
//             ds.pop_back();
//             ans.push_back(ds);
//             return;
//         }
        
//         string t = "";
//         for(int i = ind; i<n; i++)
//         {
//             t.push_back(s[i]) ;
//             if( mp.find(t) != mp.end())
//             {
//                 f(i+1,s,mp,ans,ds + t+ " ");
//             }
//         }
//     }
    
//     vector<string> wordBreak(string s, vector<string>& wordDict) 
//     {
//         vector<string>ans;
//         string ds;
        
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
        
//         f(0,s,mp,ans,ds);
//         return ans;
//     }
// };



// using the concept of recursion and backtracking  + Memoisation dp 
// Not 100 % memoised
// tc : o(n*n)
// sc : o(n*n) + o(n) stack space
class Solution 
{
public:
    
    void f(int ind , string s , map<string,int>mp , vector<string> &ans , string ds ,vector<int>&dp)
    {
        int n = s.size();
        if(ind==n)
        {
            // removing the trailing spaces
            ds.pop_back();
            ans.push_back(ds);
            return;
        }
        
        string t = "";
        for(int i = ind; i<n; i++)
        {
            t.push_back(s[i]) ;
            if( mp.find(t) != mp.end())
            {
                f(i+1,s,mp,ans,ds + t+ " ",dp);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string>ans;
        string ds;
        
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
        
        int n = s.size();
        vector<int> dp(n,-1);
        
        f(0,s,mp,ans,ds,dp);
        return ans;
    }
};
