// tc: o(n*n)

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
    {
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        for(auto x :dig)
        {
            vis[x[0]][x[1]]=1;
        }
        
        int count=0;
        for(auto x :artifacts)
        {
            int x1 =x[0];
            int y1 =x[1];
            int x2 =x[2];
            int y2 =x[3];
            
            bool flag =true;
            for(int i=x1;i<=x2;i++)
            {
                for(int j=y1;j<=y2;j++)
                {
                    if(vis[i][j]==0)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            count+= flag;
        }
        return count;
        
    }
};
