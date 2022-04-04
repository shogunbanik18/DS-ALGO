// Palindrome Check twice 
// tc : o(n) + o(n)
// sc : o(1)
class Solution {
public:
    
    bool check(string s,int i,int j) 
    {   
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            
            else if(s[i]!=s[j])
            {
                return false;
            }
        }
        
        return true;
    }
    
    
    bool validPalindrome(string s) 
    {
        int n = s.size();
        int i= 0;
        int j = n-1;
        
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            
            else if(s[i]!=s[j])
            {
                if(check(s,i+1,j) or check(s,i,j-1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
