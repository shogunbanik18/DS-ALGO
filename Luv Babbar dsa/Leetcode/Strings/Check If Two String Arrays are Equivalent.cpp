class Solution {
public:
    // tc:o(n)+o(m)+o(n+m)
    // sc:o(1)
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        bool ans=true;
        string str1="";
        string str2="";
        for(int i=0;i<word1.size();i++)
        {
            str1+=word1[i];
        }
        for(int i=0;i<word2.size();i++)
        {
            str2+=word2[i];
        }
        if(str1.size()!=str2.size())
        {
            ans=false;
        }
        for(int i=0;i<str1.size();i++)
        {
            if(str1[i]!=str2[i])
            {
                ans=false;
            }
        }
        return ans;
    }
};
