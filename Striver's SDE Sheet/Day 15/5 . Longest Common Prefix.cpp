// using sorting and comparision of 1st and last strings  
// tc: o(nlogn) + o(n)
// sc: o(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr)
    {
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        for(auto x:arr )
        {
            cout<<x<<" ";
        }
        cout<<endl;
        
        string ans="";
        
        for(int i=0;i<arr[0].size();i++)
        {
            string x = arr[0];
            string y = arr[n-1];
            
            if(x[i]==y[i])
            {
                ans += x[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
