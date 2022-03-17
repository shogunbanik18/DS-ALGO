// using map ds 
class Solution {
public:
    int romanToInt(string s) 
    {
        map<char,int>mp;
        
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        
        for(auto x: mp)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        
        int n=s.size();
        int sum=0,num;
        
        int i=0;
        while(i<n)
        {
            if(mp[s[i]] > mp[s[i+1]] or i==n-1)
            {
                num = mp[s[i]];
                i +=1;
            }
            else
            {
                num = mp[s[i+1]]- mp[s[i]];
                i+=2;
            }
            sum += num;
        }
        
        return sum;
    }
};
