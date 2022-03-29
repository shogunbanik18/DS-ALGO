// using map + Recursion 
// similar to combination sum + hashing 
// tc : o(2^n) Exponential
// sc : o(n) map space  + o(n) stack space
class Solution
{
public:
    
    void solve(int ind, string digits, vector<string>& ans, string res , map<int,string>& mp)
    {
        if(ind==digits.size())
        {
            ans.push_back(res);
            return ;
        }
        
        int num = digits[ind] - '0';
        cout<<num<<endl;
        
        // if()
        
        string str = mp[num];
        int x = str.size();
        
        for(int i=0;i<x;i++)
        {
            res.push_back(str[i]);
            solve(ind + 1,digits,ans,res,mp);
            res.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string res = "";
        
        int n = digits.size();
        if(n==0)
        {
            return ans;
        }
        
        
        map< int,string > mp;
        // mp[0] = "";
        // mp[1] = "";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
//         debug
//         for(auto it : mp)
//         {
//             cout<< it.first << " "<< it.second <<endl;
//         }
        
        int ind=0;
        
       
        
        solve(ind,digits,ans,res,mp);
        return ans;
    }
};

// using Recursion + combinaion sum concept 
class Solution {
public:
    
    void solve(int ind, string digits, vector<string>& ans, string res , vector<string>& mapping)
    {
        if(ind==digits.size())
        {
            ans.push_back(res);
            return ;
        }
        
        // convert the digit to int then check
        int number = digits[ind]-'0';
        string a = mapping[number];
        int x = a.size();
        
        for(int i=0;i<x;i++)
        {
            res.push_back(a[i]);
            solve(ind + 1,digits,ans,res,mapping);
            res.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string res = "";
        int n = digits.size();
        
        if(n==0)
        {
            return ans;
        }
        
        vector<string> mapping = {"" , "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
        
        int ind=0;
        
        solve(ind,digits,ans,res,mapping);
        return ans;
    }
};
