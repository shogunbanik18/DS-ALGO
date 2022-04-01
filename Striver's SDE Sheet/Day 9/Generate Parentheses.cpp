// // intuition generate and check 
// class Solution
// {
// public:
    
//     bool isvalid(string &s)
//     {
//         stack<char>st;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]=='(')
//             {
//                 st.push(s[i]);
//             }
            
//             else if(s[i]==')')
//             {
//                 if(!st.empty() and st.top()=='(')
//                 {
//                     st.pop();
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
        
//         if(!st.empty())
//         {
//             return false;
//         }
//         return true;
//     }
    
    
//     void f(int ind , vector<string> &ans , string ds,int n)
//     {
//         if(ind==2*n)
//         {
//             if(isvalid(ds))
//             {
//                  ans.push_back(ds);
//             }
//         }
        
//         ds.push_back('(');
//         f(ind+1 , ans , ds ,n);
//         ds.pop_back();
//     }
    
//     vector<string> generateParenthesis(int n)
//     {
//         vector<string> ans;
//         string ds="";
//         f(0,ans,ds,n);
//         return ans;
//     }
// };

// intuition generate and check open and close brackets accordingly 
// using recursion
// tc : o(2^n)
// sc : o(n) stack space
class Solution
{
public:
    
    void f(int open,int close , vector<string>&ans , string ds,int n)
    {
        int ind = ds.length();
        if(ind==2*n)
        {
            ans.push_back(ds);
            return ;
        }
        
        
        if(open<n)
        {
            f(open+1, close, ans, ds + "(", n);
        }
        
        if(close<open)
        {
            f(open, close+1, ans, ds + ")" ,n);
        }
    }
    
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string ds="";
        f(0,0,ans,ds,n);
        return ans;
    }
};
