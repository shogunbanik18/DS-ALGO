class Solution {
public:
    int myAtoi(string s) 
    {
        int n=s.length();
        // base case check 
        if(n==0)
        {
            return 0;
        }
        
        int i=0;
        while(i<n and s[i]==' ')
        {
            i++;
        }
        s=s.substr(i);
        
        long ans=0;
        int sign=+1;
        
        if(s[0]=='-')
        {
            sign=-1;
        }
        
        int MAX=INT_MAX,MIN=INT_MIN;
        i=(s[0] =='+' or s[0]=='-')?1:0;
        
        while(i<n)
        {
            if(s[0]==' ' or !isdigit(s[i]))
            {
                break;
            }
            ans=ans*10+s[i]-'0';
            if(sign==-1 and -1*ans<MIN )
            {
                return MIN;
            }
             if(sign==1 and 1*ans>MAX )
            {
                return MAX;
            }
            i++;
        }
        return (int)(sign*ans);
    }
     
    // int myAtoi(string s) 
    // {
    //     // using inbuilt stl
    //     int x=stoi(s);
    //     return x;
    // }
};
