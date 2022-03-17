// tc: o(n) + o(n) +o(n)
// sc: o(1)
class Solution {
public:
    int myAtoi(string s) 
    {
        int n=s.size();
        if(n==0)
        {
            return 0;
        }
        
        // removing white space from the first only
        // string a ="";
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i] != ' ')
        //     {
        //         a += s[i];
        //     }
        // }
        
         // removing white space from the first only
        int i=0;
        while(i<n and s[i]==' ')
        {
            i++;
        }
        s=s.substr(i);
        
        // checking for parity sign 
        int sign=1;
        long ans=0;
        if(s[0]=='-')
        {
            sign = -1;
        }
                
        // check for alphabets and digits
        int maxi = INT_MAX, mini= INT_MIN;
        i = (s[0]=='-' or s[0]=='+')?1:0;
        
        while(i<n)
        {
            if(s[0]==' ' or !isdigit(s[i]))
            {
                break;
            }
            ans = (ans*10) + (s[i]-'0');
            
            if(sign==-1 and -1*ans<mini)
            {
                return mini;
            }
            
            if(sign==1 and 1*ans>maxi)
            {
                return maxi;
            }
            
            i++;
        }
        
       
        return (int)(ans*sign);
    }
};


