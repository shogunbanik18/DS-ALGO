class Solution{   
  public:
    // Function to check if a palindrome pair exists
    // Shaandaar Question 
  
      // tc:O(n^2)*k 
    // wher k is the length of the concatenated string 
    // Brute Force
    // checking for palindrome
    bool checkpalindrome(string res)
    {
        int l=0;
        int r=res.length()-1;
        while(l<=r)
        {
            if(res[l]!=res[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    bool palindromepair(int N, string arr[]) 
    {
        int count=0;
        string res="";
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;i++)
            {
                res=arr[i]+arr[j];
                if(checkpalindrome(res))
                {
                    count++;
                }
            }
        }
        if(count>0)
        {
            return true;
        }
        else
        {
            return false;
        }
        // code here
    }
  
    
    // Most optimal solution
    // check for palindrome 
    bool ispalindrome(string arr)
    {
        int l=0;
        int r=arr.size()-1;
        while(l<=r)
        {
            if(arr[l]!=arr[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    bool palindromepair(int N, string arr[]) 
    {
        // building the map 
        unordered_map<string,int>mp;
        for(int i=0;i<N;i++)
        {
            string key=arr[i];
            mp[key]=i;
        }
        
        // extra edge case 
        if(mp.find("")!=mp.end())
        {
            for(int i=0;i<N;i++)
            {
                if(i==mp[""])
                {
                    continue;
                }
                if(ispalindrome(arr[i]))
                {
                    return 1;
                }
            }
        }
        
        // iterating all the words 
        for(int i=0;i<N;i++)
        {
            int l=arr[i].size();
            for(int j=0;j<l;j++)
            {
                string left=arr[i].substr(0,j);
                string lr=left;
                reverse(lr.begin(),lr.end());
                string right=arr[i].substr(j);
                string rr=right;
                reverse(rr.begin(),rr.end());
                
                if(mp.find(lr)!=mp.end() and ispalindrome(right) and mp[lr]!=i)
                {
                    return 1;
                }
                
                if(mp.find(rr)!=mp.end() and ispalindrome(left) and mp[rr]!=i)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
