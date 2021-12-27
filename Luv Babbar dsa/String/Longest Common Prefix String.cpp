class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans;
        sort(arr,arr+N);
        for(int i=0;i<arr[0].length();i++)
        {
            string x=arr[0];
            string y=arr[N-1];
            if(x[i]==y[i])
            {
                ans.push_back(x[i]);
            }
            else
            {
                break;
            }
        }
        return ans==""?"-1":ans;
        // your code here
    }
};


// Leetcode 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].length();i++)
        {
            string x=strs[0];
            string y=strs[n-1];
            if(x[i]==y[i])
            {
                ans=ans+x[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
