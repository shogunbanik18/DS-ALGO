class Solution {
public:
    // tc: O( (2^n) *k*(n/2) )
    // sc:o(k*x)
    // using recursion 
    bool ispalindrome(string s,int low,int high)
    {
        while(low<=high)
        {
            if(s[low]!=s[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void f(string s,int ind,vector<string>&ds,vector<vector<string>>&ans)
    {
        if(ind==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(ispalindrome(s,ind,i))
            {
                ds.push_back(s.substr(ind,i-ind+1));
                f(s,i+1,ds,ans);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>>ans;
        vector<string>ds;
        f(s,0,ds,ans);
        return ans;
    }
};


// leetcode 
// using Recursion 
class Solution 
{
    
private:
    
    bool check(int a,int b,string s)
    {
        while(a<b)
        {
            if(s[a]!=s[b])
            {
                return false;
            }
            a++;
            b--;
        }
        
        return true;
    }
    
    void f(int ind, string s,vector<vector<string>>&ans,vector<string>v)
    {
        int n = s.size();
        if(ind == n)
        {
            ans.push_back(v);
        }
        
        for(int i=ind;i<n;i++)
        {
            if(check(ind,i,s))
            {
                v.push_back(s.substr(ind , i- ind + 1 ));
                f(i+1,s,ans,v);
                v.pop_back();
            }
        }
    }
       
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>>ans;
        vector<string>v;
        f(0,s,ans,v);
        return ans;
    }
};
