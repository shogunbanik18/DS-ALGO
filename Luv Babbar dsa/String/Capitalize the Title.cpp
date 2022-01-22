class Solution {
public:
    string capitalizeTitle(string title) 
    {  
        int n=title.size();
        string ans,temp;
        for(int i=0;i<n;i++)
        {
            if(title[i]==' ')
            {
                string ss;
                if(temp.size()<=2)
                {
                    for(int j=0;j<temp.size();j++)
                    {
                         ss+=tolower(temp[j]);
                    }
                }
                else
                {
                    ss+=toupper(temp[0]);
                     for(int j=1;j<temp.size();j++)
                    {
                         ss+=tolower(temp[j]);
                    }
                }
               temp="";
                ans+=ss;
                ans+=' ';
            }
            else
            {
                temp+=title[i];
            }
        }
        
        if(temp.size()<=2)
                {
                    for(int j=0;j<temp.size();j++)
                    {
                         ans+=tolower(temp[j]);
                    }
                }
                else
                {
                    ans+=toupper(temp[0]);
                     for(int j=1;j<temp.size();j++)
                    {
                         ans+=tolower(temp[j]);
                    }
                }
        return ans;
    }
    
    // string capitalizeTitle(string title)
    // {
    //     string s=title;
    //     for(int i=0,j=0;i<=s.size();++i)
    //     {
    //         if(i==s.size() or s[i]==' ')
    //         {
    //             if(i-j>2)
    //             {
    //                  s[j]=toupper(s[j]);
    //             }
    //             j=j+1;
    //         }
    //         else
    //         {
    //             s[i]=tolower(s[i]);
    //         }
    //     }
    //     return s;
    // }
}; 

