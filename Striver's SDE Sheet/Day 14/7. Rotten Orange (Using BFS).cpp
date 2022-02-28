// using BFS (queue)
// tc: o(n*n)*4
// sc:o(n*n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        if(grid.empty())
        {
            return 0;
        }
        
        int m=grid.size();
        int n=grid[0].size();
        
        int total=0;
        int days=0;
        int count=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    total++;
                }
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        // directions 
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        
        while(!q.empty())
        {
            int k=q.size();
            count+=k;
            while(k--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nx =x+dx[i];
                    int ny =y+dy[i];
                    if(nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]!=1)
                    {
                        continue;
                    }
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())
            {
                days++;
            }
        }
        return total==count?days:-1;
    }
};
