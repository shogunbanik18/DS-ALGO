class Solution {
public:
    // int mostWordsFound(vector<string>& sentences) 
    // {
    //     int maxcount=0;
    //     for(auto x:sentences)
    //     {
    //         int count=0;
    //         for(auto ch:x)
    //         {
    //             if(ch==' ')
    //             {
    //                 count++;
    //             }
    //         }
    //         maxcount=max(maxcount,count+1);
    //     }
    //     return maxcount;
    // }
    
    // using stl 
    int mostWordsFound(vector<string>& sentences) 
    {
        int maxcount=0;
        for(auto x:sentences)
        {
            int cnt =count(x.begin(),x.end(),' ')+1;
            maxcount=max(maxcount,cnt);
        }
        return maxcount;
    }
};
