// class Solution {
// public:
//     string getSmallestString(int n, int k) 
//     {
//         string s = "abcdefghijklmnopqrstuvwxyz";
        
//         vector<char> val(26,0);
//         for(int i=0;i<26;i++)
//         {
//             val[i] = s[i];
//         }
        
//         // #Debug
//         // for(auto x:val)
//         // {
//         //     cout<<x<<" ";
//         // }
        
//         for(int i=0;i<n-1;i++)
//         {
//             ans += s[0];
//             k-=i;
//         }
        
//         string ans="";
        
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };

// using greddy approach 
// tc: o(n)
// sc: o(1)
class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            ans+='a';
        }
        
        k = k-n;
        int i = n-1;
        
        while(k>0)
        {
            int temp = min(k,25);
            ans[i] += temp;
            k-=temp;
            i--; 
        }
        
        return ans;
    }
};
