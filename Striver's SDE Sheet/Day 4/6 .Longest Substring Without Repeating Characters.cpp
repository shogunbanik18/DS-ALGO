class Solution {
public:
    // Brute force 
    // tc:O(N^2)
    // sc:O(N)
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.length();
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int>set;
            for(int j=i;j<n;j++)
            {
                if(set.find(s[j])!=set.end())
                {
                    maxlen=max(maxlen,j-i);
                    break;
                }
                set.insert(s[j]);
            }
        }
        return maxlen;
    }
    
    // using sliding window approach 
    // tc:o(2n)
    // sc:o(n)
//     using unordered map 
//     int lengthOfLongestSubstring(string s) 
//     {
//         int n=s.length();
//         int l=0;
//         int maxlen=INT_MIN;
//         unordered_set<int>set;
//         for(int r=0;r<n;r++)
//         {
//             if(set.find(s[r])!=set.end())
//             {
//                 while(l<r and set.find(s[r])!= set.end())
//                 {
//                     set.erase(s[l]);
//                     l++;
//                 }
//             }
//             set.insert(s[r]);
//             maxlen = max(maxlen, r - l + 1);
//         }
//         return maxlen;
//     } 
    
    // Using sliding window and Hashing 
    // tc:O(2*N)
    // sc:o(n)
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char>set;
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        while(i<n and j<n)
        {
            if(set.find(s[j])==set.end())
            {
                set.insert(s[j]);
                j++;
                ans=max(ans,j-i);
            }
            else
            {
                set.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
    
//     Most optimal Approach
    // using sliding window and Hashing 
    // and better optimisation 
    // tc:O(N)
    // sc:O(N)
    int lengthOfLongestSubstring(string s) 
    {
        // string property 
        vector<int>mp(256,-1);
        int left=0,right=0;
        int n=s.length();
        int len=0;
        while(right<n)
        {
            if(mp[s[right]]!=-1)
            {
                left=max(mp[s[right]]+1,left);
            }
            mp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    } 
};



