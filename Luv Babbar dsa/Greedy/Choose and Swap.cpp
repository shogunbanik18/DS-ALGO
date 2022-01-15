// tc :O(NlogN)
// sc :O(N)
class Solution{
public:
    string chooseandswap(string a)
    {
        int n=a.length();
        set<char>s;
        // inseting in the set 
        for(int i=0;i<n;i++)
        {
            s.insert(a[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            s.erase(a[i]);
            if(s.empty())
            {
                break;
            }
            char ch=*s.begin();
            if(ch<a[i])
            {
                int ch2=a[i];
                for(int j=0;j<n;j++)
                {
                    if(a[j]==ch)
                    {
                        a[j]=ch2;
                    }
                    else if(a[j]==ch2)
                    {
                        a[j]=ch;
                    }
                }
                break;
            }
        }
        return a;
        // Code Here
    }
};
