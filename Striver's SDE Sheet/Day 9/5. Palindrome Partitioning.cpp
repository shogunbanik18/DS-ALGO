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


