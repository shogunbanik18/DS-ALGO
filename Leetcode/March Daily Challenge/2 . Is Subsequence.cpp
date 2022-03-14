class Solution {
public:
    // using 2 pointer approach 
    // tc:o(n1)+o(n2)
    // sc:o(1)
    bool isSubsequence(string s, string t) 
    {
        int n1=s.size();
        int n2=t.size();
        int i=0,j=0;   
        while(i<n1 and j<n2)
        {
            if(s[i]==t[j])
            {
                i++;
            }
            j++;
        }
        if(i==n1)
        {
            return true;
        }
        return false;
    }
};
