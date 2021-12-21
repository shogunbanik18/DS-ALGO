class Solution
{
    public:
    
    // using vector method 
    string reverseWords(string S)
    {
        vector<string>v;
        string str="";
        int n=-1;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='.')
            {
                v.push_back(str);
                v.push_back(".");
                str="";
            }
            else
            {
                str+=S[i];
            }
        }
        
        // for last element 
        v.push_back(str);
        str="";
        for(int i=v.size()-1;i>=0;i--){
           str+=v[i];
       }
       return str;
    }
};
