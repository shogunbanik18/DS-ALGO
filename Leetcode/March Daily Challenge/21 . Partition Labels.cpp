// class Solution {
// public:
//     vector<int> partitionLabels(string s) 
//     {
//         vector<int>ans; 
        
//         // using frequency array 
//         int n = s.size();
//         vector<int> freq(26,0);
//         for(int i=0;i<n;i++)
//         {
//             freq[s[i]-'a']++;
//         }
        
//         int i=0,last=0;
//         int flag=1;
        
//         while(i<n)
//         {
//             freq[s[i]-'a']--;
            
//             int j=i;
//             while(j>=0)
//             {
//                 if(freq[s[j]-'a']!=0)
//                 {
//                     // cout<<freq[s[j]-'a']<<" ";
//                     flag=0;
//                     break;
//                 }
//                 j--;
//             }
            
//             if(flag==1)
//             {
//                 ans.push_back(i+1-last);
//                 last = i+1;
//             }
            
//             flag=1;
//             i++;
//         }
        
//         return ans;   
//     }
// };


// // using two pointer approach 
// // tc : o(n)
// // sc:o(1)
// // class Solution {
// // public:
// //     vector<int> partitionLabels(string s) 
// //     {
// //         vector<int>ans; 
        
// //         // using frequency array 
// //         int n = s.size();
// //         vector<int> freq(26,0);
        
// //         for(int i=0;i<n;i++)
// //         {
// //             freq[s[i]-'a']=i;
// //         }
        
// //         int start=0,end=0;
        
// //         for(int i=0;i<n;i++)
// //         {
// //             end = max(end,freq[s[i]-'a']);
            
// //             if(i==end)
// //             {
// //                 ans.push_back(i-start+1);
// //                 start = i+1;
// //             }
// //         }
        
// //         return ans;   
// //     }
// // };

// using map + traversal
// tc : o(n)
// sc:o(1)
// class Solution {
// public:
//     vector<int> partitionLabels(string s) 
//     {
//         vector<int>ans;
        
//         map<char,int>mp;
//         int n = s.size();
//         for(int i=0;i<n;i++)
//         {
//             mp[s[i]] = i;
//         }
        
//         // Debug 
//         // for(auto x : mp )
//         // {
//         //     cout<<x.first<<" "<<x.second<<endl;
//         // }
        
//         int prev = -1;
//         int maxi = 0;
        
//         for(int i=0;i<n;i++)
//         {
//             maxi = max(maxi, mp[s[i]] );
            
//             if(i==maxi)
//             {
//                 ans.push_back(maxi-prev);
//                 prev = maxi;
//             }
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int>ans;
        
        map<char,int>mp;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]] = i;
        }
        
        // Debug 
        // for(auto x : mp )
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        int prev = 0;
        int maxi = 0;
        
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, mp[s[i]] );
            
            if(i==maxi)
            {
                ans.push_back(i+1-prev);
                prev = i+1;
            }
        }
        
        return ans;
    }
};
