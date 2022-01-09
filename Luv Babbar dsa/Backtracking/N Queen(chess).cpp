class Solution{
public:
//   using hashing 
    void solve(int col,int n,vector<vector<int>>&ans,vector<int>&temp,
    vector<int>&leftrow,vector<int>&upperdiag,vector<int>&lowerdiag)
    {
        if (col == n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 and upperdiag[n-1+col-row]==0 and lowerdiag[row+col]==0)
            {
                leftrow[row]=1;
                upperdiag[n-1+col-row]=1;
                lowerdiag[row+col]=1;
                temp.push_back(row+1);
                solve(col+1,n,ans,temp,leftrow,upperdiag,lowerdiag);
                leftrow[row]=0;
                upperdiag[n-1+col-row]=0;
                lowerdiag[row+col]=0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>leftrow(n,0);
        vector<int>lowerdiag(2*n-1,0);
        vector<int>upperdiag(2*n-1,0);
        solve(0,n,ans,temp,leftrow,upperdiag,lowerdiag);
        return ans;
    }
};
