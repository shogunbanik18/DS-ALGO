class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int maxcount=0;
        for(auto x:sentences)
        {
            int count=0;
            for(auto ch:x)
            {
                if(ch==' ')
                {
                    count++;
                }
            }
            maxcount=max(maxcount,count+1);
        }
        return maxcount;
    }
};
