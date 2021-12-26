
class Solution {
  public:
  
    
    int romanToDecimal(string &str) 
    {
        unordered_map<char,int>roman={{'I',1},{'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int res=0;
        int n=str.length();
        int maxRoman=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(roman[str[i]]>=maxRoman)
            {
                res=res+roman[str[i]];
                maxRoman=roman[str[i]];
            }
             else {
                res =res- roman[str[i]];
            }
        }
        return res;
        // code here
    }
};
