string firstRepChar(string s)
{
    unordered_set<char>mp;
    string ans="";
    
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(mp.find(c)!=mp.end())
        {
            ans=ans+c;
            return ans;
        }
        else
        {
            mp.insert(c);
        }
    }
    
    if(ans.empty())
    {
        ans="-1";
    }
    return ans;
    //code here.
}
