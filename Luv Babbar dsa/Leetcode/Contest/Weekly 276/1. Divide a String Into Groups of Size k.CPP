class Solution {
public:
    vector<string> divideString(string s, int k, char fill)
    {
        vector<string>ans;
        int n=s.length();
        string res=""; 
        for(int i=0;i<n;i++)
        {
            res+=s[i];
            if(res.size()==k)
            {
                ans.push_back(res);
                res="";
            }
        }
        
        if(res.size()!=k and res.size()>0)
        {
            while(res.size()!=k)
            {
                res+=fill;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
