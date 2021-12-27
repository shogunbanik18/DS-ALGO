class Solution {
public:
    
    int gcd2(int a,int b)
    {
        if(a==0 or b==0)
        {
            return 0;
        }
        else if(a==b)
        {
            return a;
        }
        else if(a>b)
        {
            return gcd2(a-b,b);
        }
        else
        {
            return gcd2(a,b-a);
        }
    }
    
    int gcd1(int a,int b)
    {
        if(a==0)
        {
            return b;
        }
        return gcd1(b%a,a);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        int n=deck.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[deck[i]]++;
        }
         
        int res=mp[deck[0]];

        for(auto x:mp)
        {
            res=gcd1(x.second,res);
        }
        if(res<2)
        {
            return false;
        }
        return true;
    }
};
