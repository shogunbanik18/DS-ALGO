class Solution {
  public:
    bool ispalin(string S,int start,int end)
    {
        while(start<=end)
        {
            if(S[start]!=S[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
  
    void find(int index,string S,vector<vector<string>>&ans,vector<string>&path)
    {
        if(index==S.size())
        {
            ans.push_back(path);
            return;
        }
        
        string str="";
        for(int i=index;i<S.size();i++)
        {
            str=str+S[i];
            if(ispalin(S,index,i))
            {
                path.push_back(str);
                find(i+1,S,ans,path);
                path.pop_back();
            }
        }
    }
  
    vector<vector<string>> allPalindromicPerms(string S)
    {
        vector<vector<string>>ans;
        vector<string>path;
        find(0,S,ans,path);
        return ans;
        // code here
    }
};
