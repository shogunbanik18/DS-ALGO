// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& matches)
//     {
//         vector<vector<int>>ans;
//         vector<int> winner;
//         vector<int> loser;
        
//         // mp1 for winner 
//         // mp2 for loser 
//         map<int,int> mp1;
//         map<int,int> mp2;
        
//         for(auto x : matches)
//         {
//             auto a = x[0];
//             mp1[a]++;
            
//             auto b = x[1];
//             mp2[a] += 0;
//             mp2[b]++;
//         }
        
// //         // debug 
// //         for(auto x : mp1)
// //         {
// //             cout<<x.first<<" "<<x.second<<endl;
// //         }
// //         cout<<endl;
        
// //          for(auto x : mp2)
// //         {
// //             cout<<x.first<<" "<<x.second<<endl;
// //         }
// //         cout<<endl;
        
//         // for losers with one lost match 
//         for(auto y : mp2)
//         {
//             if(y.second == 1)
//             {
//                 loser.push_back(y.first);
//             }
//         }
        
//         // set<int> set;
//         // for(auto y : mp2)
//         // {
//         //     set.insert(y.first);
//         // }
        
//         // debug
//         // cout<<endl;
//         // for(auto x : set)
//         // {
//         //     cout<<x<<" ";
//         // }
//         // cout<<endl;
        
        
//         // for(auto x : mp1)
//         // {
//         //     if(set.find(x.first) != set.end() )
//         //     {
//         //         mp1.erase(x.first);
//         //     }
//         // }
        
//          for(auto x : mp1)
//         {
//             if(mp2[x.first] == 0 )
//             {
//                 winner.push_back(x.first);
//             }
//         }
      
//         // Debug 
//         // for(auto x : mp1)
//         // {
//         //     cout<<x.first<<" "<<x.second<<endl;
//         // }
//         // cout<<endl;
        
            
//         ans.push_back(winner);
//         ans.push_back(loser);
//         return ans;
//     }
// };

// using map + set 
// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& matches)
//     {
//         vector<vector<int>>ans;
//         vector<int> winner;
//         vector<int> loser;
        
//         // mp1 for winner 
//         // mp2 for loser 
//         map<int,int> mp1;
//         map<int,int> mp2;
        
//         for(auto x : matches)
//         {
//             auto a = x[0];
//             mp1[a]++;
            
//             auto b = x[1];
//             mp2[b]++;
//         }
        
// //         // debug 
// //         for(auto x : mp1)
// //         {
// //             cout<<x.first<<" "<<x.second<<endl;
// //         }
// //         cout<<endl;
        
// //          for(auto x : mp2)
// //         {
// //             cout<<x.first<<" "<<x.second<<endl;
// //         }
// //         cout<<endl;
        
//         // for losers with one lost match 
//         for(auto y : mp2)
//         {
//             if(y.second == 1)
//             {
//                 loser.push_back(y.first);
//             }
//         }
        
//         set<int> set;
//         for(auto y : mp2)
//         {
//             set.insert(y.first);
//         }
        
// //         // debug
// //         cout<<endl;
// //         for(auto x : set)
// //         {
// //             cout<<x<<" ";
// //         }
// //         cout<<endl;
        
        
//         for(auto x : mp1)
//         {
//             if(set.find(x.first) != set.end() )
//             {
//                 mp1.erase(x.first);
//             }
//         }
        
      
// //         // Debug 
// //         for(auto x : mp1)
// //         {
// //             cout<<x.first<<" "<<x.second<<endl;
// //         }
// //         cout<<endl;
        
//         for(auto x : mp1)
//         {
//             winner.push_back(x.first);
//         }
        
            
//         ans.push_back(winner);
//         ans.push_back(loser);
//         return ans;
//     }
// };




class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        vector<vector<int>>ans;
        vector<int> winner;
        vector<int> loser;
        
        set<int> set;
        map<int,int> mp2;
        
        
        for(auto x : matches )
        {
            auto a = x[0];
            set.insert(a);
            
            auto b = x[1];
            set.insert(b);
            mp2[b]++;
        }
        
        // Debug 
//         for(auto x : set)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(auto x : mp2)
//         {
//             cout<<x.first<<" "<<x.second<<endl;
//         }
        
        for(auto x : set)
        {
            if(mp2[x]==1)
            {
                loser.push_back(x);
            }
            
            else if(!mp2[x])
            {
                winner.push_back(x);
            }
        }
            
        ans.push_back(winner);
        ans.push_back(loser);
        return ans;
    }
};
