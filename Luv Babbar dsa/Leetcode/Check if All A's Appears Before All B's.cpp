class Solution {
public:
    bool checkString(string s) 
    {
        // for(int i=1;i<s.size();i++)
        // {
        //         if(s[i-1]=='b' and s[i]=='a')
        //         {
        //             return false;
        //         }
        // }
        // return true;
        if(s[0]=='b' and s[1]=='a')
        {
            return false;
        }
        for(int i=1;i<s.size()-1;i++)
        {
            if(s[i]=='b')
            {
                if( s[i+1]=='a')
                {
                    return false;
                }
            }
        }
        return true;
    }
};
