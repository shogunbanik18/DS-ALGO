class Solution {
public:
    
    string nthPalindrome(int n , int k)
    {
        long long temp = (k & 1) ? (k / 2) : (k / 2 - 1);
        long long palindrome = (long long) pow (10, temp);
        palindrome += n - 1;

        // cout<<palindrome<<endl ;
        
        string str = to_string(palindrome);
    
        if (k & 1)
        {
            palindrome /= 10;
        }
        
        while (palindrome)
        {
            str+= to_string(palindrome % 10);
            palindrome /= 10;
        }
        
        if(str.length() ==k)
        {
            return str;
        }
        return "-1";
    }
    
    
    vector<long long> kthPalindrome(vector<int>& q, int l) 
    {
        vector<long long > ans;
        int n = q.size();
        long long take;
        
        
        for(int i=0; i<n; i++)
        {
            take=0;
            //use stoll 
            take = (long long) stoll (nthPalindrome(q[i],l)); 
            ans.push_back(take);
        }
        
        
        return ans;
    }
};
