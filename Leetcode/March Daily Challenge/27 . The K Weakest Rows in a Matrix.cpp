// // using pair ds
// // tc : o(n*n) + o(vlogv) + o(v)
// // sc : o(n) + o(n) 
// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
//     {
//         int n = mat.size();
//         int m = mat[0].size();
//         vector<pair<int,int>>v;
        
//         for(int i=0;i<n;i++)
//         {
//             int count=0;
//             for(int j=0;j<m;j++)
//             {
//                 if(mat[i][j]==1)
//                 {
//                     count++;
//                 }
//             }
//             v.push_back({count,i});
//         }
        
        
//         // debug
//         // for(auto x : v)
//         // {
//         //     cout<<x.first<<" "<<x.second<<endl;
//         // }
        
//         sort(v.begin(),v.end());
        
//          // debug
//         // for(auto x : v)
//         // {
//         //     cout<<x.first<<" "<<x.second<<endl;
//         // }
        
//         vector<int>ans;
//         for(int i=0;i<v.size();i++)
//         {
//             if(k>0)
//             {
//                 ans.push_back(v[i].second);
//                 k--;
//             }
//         }
        
//         return ans;
//     }
// };



// using pair ds + binary Search 
// tc : o(n*n) + o(logv) + o(v)
// sc : o(n) + o(n) 
class Solution 
{
private:
    
    int search(vector<int>& arr)
    {
        int l=0;
        int h = arr.size() -1 ;
        
        while(l<=h)
        {
            int mid = (h+l)/2;
            
            if(arr[mid]==0)
            {
                h = mid-1;
            }
            
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        int n = mat.size();
        // int m = mat[0].size();
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({search(mat[i]),i});
        }
        
        
        // debug
        // for(auto x : v)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        sort(v.begin(),v.end());
        
         // debug
        // for(auto x : v)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        vector<int>ans;
        for(auto x : v)
        {
            if(k>0)
            {
                ans.push_back(x.second);
                k--;
            }
        }
        
        return ans;
    }
};
